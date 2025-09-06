cmake_minimum_required(VERSION 3.23)
project(mixUtils VERSION 0.1.0)

file(GLOB_RECURSE MIXUTILS_HEADERS CONFIGURE_DEPENDS
     "${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp")
file(GLOB_RECURSE MIXUTILS_SOURCES CONFIGURE_DEPENDS
     "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

add_library(mixutils STATIC)
add_library(mix::utils ALIAS mixutils)

target_sources(mixutils
    PRIVATE
        ${MIXUTILS_SOURCES}
    PUBLIC
        FILE_SET HEADERS
        BASE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/include
        FILES ${MIXUTILS_HEADERS}
)

target_include_directories(mixutils
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

target_compile_features(mixutils PUBLIC cxx_std_20)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR}
             FILES ${MIXUTILS_SOURCES} ${MIXUTILS_HEADERS})