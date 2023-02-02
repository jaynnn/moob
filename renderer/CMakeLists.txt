

if(WIN32)
    set (RENDER_API_SOURCE 
            d2d_api.cpp
            d2d_api.hpp)
    find_library(d2d1_LIBRARY d2d1)
    add_library(RENDER_API_LIB ${RENDER_API_SOURCE})
    target_link_libraries(RENDER_API_LIB ${d2d1_LIBRARY})
elseif(UNIX)
else()
endif()
