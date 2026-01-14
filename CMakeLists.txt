cmake_minimum_required(VERSION 3.16)

project(
    vst3_study
    VERSION 0.1.0
    LANGUAGES C CXX
)

# ------------------------------------------------------------
# C++ standard
# ------------------------------------------------------------
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# ------------------------------------------------------------
# Diagnostics
# ------------------------------------------------------------
message(STATUS "Project: ${PROJECT_NAME}")
message(STATUS "Version: ${PROJECT_VERSION}")
message(STATUS "System: ${CMAKE_SYSTEM_NAME}")
message(STATUS "Processor: ${CMAKE_SYSTEM_PROCESSOR}")

# ------------------------------------------------------------
# VST3 SDK
# ------------------------------------------------------------
set(VST3_SDK_PATH ${CMAKE_SOURCE_DIR}/external/vst3sdk)

# Disable GUI and SDK examples
set(SMTG_ENABLE_VSTGUI_SUPPORT OFF CACHE BOOL "" FORCE)
set(SMTG_ENABLE_VST3_SAMPLES OFF CACHE BOOL "" FORCE)
set(SMTG_ENABLE_VST3_HOSTING_EXAMPLES OFF CACHE BOOL "" FORCE)
set(SMTG_ENABLE_VST3_PLUGIN_EXAMPLES OFF CACHE BOOL "" FORCE)

# Add VST3 SDK
add_subdirectory(${VST3_SDK_PATH} external/vst3sdk-build)

# ------------------------------------------------------------
# (Temporary) Validation executable
# ------------------------------------------------------------
# This target was used to validate the Windows cross-compilation
# pipeline and may be removed later.
add_executable(hello_win src/hello.cpp)

# Link runtime statically to avoid external DLL dependencies
target_link_options(hello_win PRIVATE
    -static-libstdc++
    -static-libgcc
)
