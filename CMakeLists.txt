cmake_minimum_required(VERSION 3.7)
project(dos-app)

set (CMAKE_RANLIB ${CMAKE_FIND_ROOT_PATH}/djgpp/i586-pc-msdosdjgpp/bin/ranlib)
set (CMAKE_CXX_COMPILER_RANLIB ${CMAKE_FIND_ROOT_PATH}/djgpp/i586-pc-msdosdjgpp/bin/ranlib)

set(CMAKE_GENERATOR Ninja)
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

set(CMAKE_DEBUG_POSTFIX d)

add_compile_options(-Wall -std=c++23 -save-temps -U __STRICT_ANSI__ -Wno-array-bounds -fext-numeric-literals)
# -march=pentium3 -msse

add_compile_options(
    "$<$<CONFIG:RELEASE>:-DRELEASE>"
    "$<$<CONFIG:DEBUG>:-DDEBUG>"
)

add_compile_options(
    "$<$<CONFIG:RELEASE>:-O3>"
)

#dxe's will need an export list
add_link_options(
    "$<$<CONFIG:RELEASE>:-s>"
)

#add_compile_options(-D MOCK)

set (ENV{DJDIR} "${CMAKE_FIND_ROOT_PATH}/djgpp/")
set (ENV{DXE_LD_LIBRARY_PATH} "${CMAKE_FIND_ROOT_PATH}/djgpp/lib/gcc/i586-pc-msdosdjgpp/12.1.0/")
message("Environment variable DJDIR: $ENV{DJDIR}")
message("Environment variable DXE_LD_LIBRARY_PATH: $ENV{DXE_LD_LIBRARY_PATH}")

include_directories(include)

add_library(has
            src/math/flt/flt.cpp
            src/math/flt/m44.cpp
            src/math/fp/fp.cpp
            src/math/fp/fptables.cpp
            src/math/fp/m44.cpp
            src/system/pci.cpp
            src/system/pit.cpp
            src/testing/log.cpp
           )

add_library(hassup
            support/allocatr.cpp
            support/env.cpp
           )

add_executable(test
               tests/test.cpp
              )

#libraries are linked in reverse order
target_link_libraries(test
                      hassup
                      has
                     )
