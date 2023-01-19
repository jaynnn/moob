set (PLAT_SOURCE 
                win_base.cpp
                win_base.hpp
                gl_app.cpp
                gl_app.hpp
                d2d_app.hpp
                d2d_app.cpp)

find_library(D2D1_LIB D2D1)

add_library(PLAT_APP ${PLAT_SOURCE})

target_link_libraries(PLAT_APP ${D2D1_LIB})