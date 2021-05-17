cmake_minimum_required(VERSION 3.0.0)

set(CMAKE_CXX_STANDARD 11)

get_filename_component(project_id ${CMAKE_CURRENT_SOURCE_DIR} NAME)
string(REPLACE " " "_" project_id ${project_id})

project(${project_id})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

file(GLOB sources ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cc ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c)

file(GLOB includes ${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h)

add_executable(${PROJECT_NAME} ${sources} ${includes})