add_executable(MOOB main.cpp)
target_link_libraries(MOOB 
    FRAME_BASE
    FRAME_MGR
    FRAME_UTIL
    PLAT_APP)