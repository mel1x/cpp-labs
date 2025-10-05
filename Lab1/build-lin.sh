#!/usr/bin/env bash
set -u

echo "Building all taskN.cpp files for Linux..."
echo

mkdir -p "lin-builds"

JOBS="$(nproc || echo 4)"
CXX_BIN="${CXX_BIN:-g++}"
CXXFLAGS="-std=c++23 -O2 -pipe -Wall -Wextra -Wpedantic"
LDFLAGS=""

# Сформировать команду компилятора как массив: [ccache, g++] или просто [g++]
if command -v ccache >/dev/null 2>&1; then
  COMPILER=(ccache "$CXX_BIN")
else
  COMPILER=("$CXX_BIN")
fi

ok_list=()
fail_list=()

compile_one() {
  local dir="$1"
  local taskname src out
  taskname="$(basename "$dir")"
  src="${dir%/}/${taskname}.cpp"
  out="lin-builds/${taskname}.out"

  [[ -f "$src" ]] || { echo "SKIP: $src not found"; return 0; }

  echo "Compiling $src ..."
  if "${COMPILER[@]}" $CXXFLAGS "$src" -o "$out" $LDFLAGS; then
    echo "SUCCESS: $src -> $out"
    return 0
  else
    echo "ERROR: Failed to compile $src"
    return 1
  fi
}

# Параллельный запуск
while IFS= read -r -d '' dir; do
  while (( $(jobs -rp | wc -l) >= JOBS )); do
    wait -n
  done
  compile_one "$dir" &
  pids+=("$!")
  names+=("$dir")
done < <(find . -maxdepth 1 -type d -name 'task*' -print0)

# Ожидание результатов
for i in "${!pids[@]}"; do
  if wait "${pids[$i]}"; then
    ok_list+=("${names[$i]}")
  else
    fail_list+=("${names[$i]}")
  fi
done

chmod +x lin-builds/*.out 2>/dev/null || true

echo
echo "Build finished."
echo "OK:   ${#ok_list[@]}"
echo "FAIL: ${#fail_list[@]}"
((${#fail_list[@]})) && printf 'Failed:\n- %s\n' "${fail_list[@]}"