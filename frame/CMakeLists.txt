add_subdirectory(base)
add_subdirectory(interface)
add_subdirectory(mgr)
add_subdirectory(util)

add_library(FRAME_LIB INTERFACE)

target_link_libraries(FRAME_LIB INTERFACE
        FRAME_BASE
        FRAME_MGR
        FRAME_UTIL
)
