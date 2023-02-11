cmake_minimum_required(VERSION 3.20...3.25)

if(${CMAKE_VERSION} VERSION_LESS 3.20)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

project (moob LANGUAGES CXX)
source_group(TREE ${PROJECT_SOURCE_DIR})

set (CMAKE_C_STANDARD 11)
set (CMAKE_CXX_STANDARD 20)

if (UNIX)
    if (APPLE)
        set (TARGET_PLAT "Apple")
    elseif (${CMAKE_SYSTEM_NAME} MATCHES "FreeBSD")
        set (TARGET_PLAT "FreeBSD")
    else()
        set (TARGET_PLAT "Linux")
    endif(APPLE)
elseif(WIN32)
    set (TARGET_PLAT, "Windows")
endif(UNIX)

if(MSVC)
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /D _CRT_SECURE_NO_WARNINGS /MP /utf-8")
endif(MSVC)

set (CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -DDEBUG -D_DEBUG")
set (CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DDEBUG -D_DEBUG")

list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")

include_directories("${PROJECT_SOURCE_DIR}/")
include_directories("${PROJECT_SOURCE_DIR}/plat")
include_directories("${PROJECT_SOURCE_DIR}/frame")
include_directories("${PROJECT_SOURCE_DIR}/common")

add_subdirectory(game)
add_subdirectory(frame)
add_subdirectory(plat)
add_subdirectory(common)
add_subdirectory(third)