# plugin/CMakeLists.txt

set(PLUGIN_SOURCES
    processor.cpp
    controller.cpp
    entry.cpp
)

smtg_add_vst3plugin(PassThroughFX ${PLUGIN_SOURCES})

target_include_directories(PassThroughFX PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)
