#Require a minimum version
cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 20)

project(andy-file)

add_library(andy-file OBJECT
	${CMAKE_CURRENT_LIST_DIR}/src/file.cpp
)

include_directories(${CMAKE_CURRENT_LIST_DIR})

# install(TARGETS andy-file EXPORT andy-fileTargets)
# install(EXPORT andy-fileTargets
#     FILE andy-fileTargets.cmake
#     DESTINATION lib/cmake/andy-file
# )
# install(TARGETS andy-file DESTINATION lib)
# install(FILES ${CMAKE_CURRENT_LIST_DIR}/andy/file.hpp DESTINATION include/andy)