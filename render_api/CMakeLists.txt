

if(WIN32)
    set (RENDER_API_SOURCE 
            d2d_api.cpp
            d2d_api.hpp)
elseif(UNIX)
else()
endif()

add_library(RENDER_API_LIB ${RENDER_API_SOURCE})

target_link_libraries(RENDER_API_LIB d2d1)