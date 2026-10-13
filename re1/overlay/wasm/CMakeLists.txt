# Emscripten (WebAssembly) build of the RE1 decomp. Configure with:
#   emcmake cmake -S wasm -B build/web -DCMAKE_BUILD_TYPE=Release
# Reuses the shared source list of the upstream CMakeLists.txt so it never drifts, and
# swaps the Linux-only pieces:
#   ffmpeg video -> platform/web/video_stub.cpp, crash log -> crash_stub.cpp,
#   <ucontext.h> -> platform/web/shim (emscripten fibers), GL loader -> GLES3.
cmake_minimum_required(VERSION 3.16)
project(residentevil_web CXX C)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
get_filename_component(RE1_ROOT "${CMAKE_CURRENT_LIST_DIR}/.." ABSOLUTE)

file(READ "${RE1_ROOT}/CMakeLists.txt" _upstream)
# The shared list sits between "set(RE1_SOURCES" and the platform-specific append.
string(FIND "${_upstream}" "set(RE1_SOURCES" _start)
string(FIND "${_upstream}" "list(APPEND RE1_SOURCES" _end)
math(EXPR _len "${_end} - ${_start}")
string(SUBSTRING "${_upstream}" ${_start} ${_len} _block)
string(REGEX REPLACE "#[^
]*" "" _block "${_block}")
string(REGEX MATCHALL "src/[A-Za-z0-9_/]+\.cpp" _shared "${_block}")
list(LENGTH _shared _n)
if(_n LESS 80)
    message(FATAL_ERROR "could not extract the shared source list (${_n} files)")
endif()

set(RE1_WEB_SOURCES ${_shared}
    src/platform/linux/platform.cpp
    src/platform/linux/input.cpp
    src/platform/linux/audio.cpp
    src/platform/linux/config.cpp
    src/platform/linux/stubs.cpp
    src/platform/linux/main.cpp
    src/platform/web/video_stub.cpp
    src/platform/web/crash_stub.cpp
    src/marni/MarniDX_GL.cpp
    src/marni/MarniGLFuncs.cpp)
list(TRANSFORM RE1_WEB_SOURCES PREPEND "${RE1_ROOT}/")

add_executable(residentevil ${RE1_WEB_SOURCES})
target_include_directories(residentevil PRIVATE ${RE1_ROOT}/src ${RE1_ROOT}/src/platform/web/shim)
target_compile_options(residentevil PRIVATE -w -sUSE_SDL=2)
target_link_options(residentevil PRIVATE
    -sUSE_SDL=2
    -sASYNCIFY
    -sASYNCIFY_STACK_SIZE=262144
    -sINITIAL_MEMORY=268435456
    -sALLOW_MEMORY_GROWTH=1
    -sMAXIMUM_MEMORY=2147483648
    -sSTACK_SIZE=1048576
    -sMIN_WEBGL_VERSION=2 -sMAX_WEBGL_VERSION=2
    -sFULL_ES3=1
    -sFORCE_FILESYSTEM=1
    -sEXPORTED_RUNTIME_METHODS=FS,callMain
    -sEXIT_RUNTIME=0
    -sINVOKE_RUN=0
    -sEMULATE_FUNCTION_POINTER_CASTS=1
    -sERROR_ON_UNDEFINED_SYMBOLS=1)
set_target_properties(residentevil PROPERTIES SUFFIX ".js")
