
include_directories("include")
link_directories("lib")

find_library(THIRD_WINDOWS_LIB glfw3.lib)
link_libraries(glfw3.lib)