set (PLAT_SOURCE 
                linux_base.cpp
                linux_base.hpp
                gl_app.cpp
                gl_app.hpp)

find_library(X11_LIBRARY X11 glfw3 GL pthread Xrandr Xi dl)

add_library(PLAT_APP ${PLAT_SOURCE})
target_link_libraries(PLAT_APP ${X11_LIBRARY})