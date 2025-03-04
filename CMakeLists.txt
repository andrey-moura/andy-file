#Require a minimum version
cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 20)

project(uva-file)

add_library(uva-file OBJECT
	${CMAKE_CURRENT_LIST_DIR}/src/file.cpp
)

include_directories(${CMAKE_CURRENT_LIST_DIR})

# install(TARGETS uva-file EXPORT uva-fileTargets)
# install(EXPORT uva-fileTargets
#     FILE uva-fileTargets.cmake
#     DESTINATION lib/cmake/uva-file
# )
# install(TARGETS uva-file DESTINATION lib)
# install(FILES ${CMAKE_CURRENT_LIST_DIR}/uva/file.hpp DESTINATION include/uva)