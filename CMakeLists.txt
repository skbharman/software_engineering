cmake_minimum_required(VERSION 3.2)

project(ProjectName)

set(CXX_STANDARD 20)

include_directories(include)

file(GLOB SRC_LIST
"${PROJECT_SOURCE_DIR}/include/*.h"
"${PROJECT_SOURCE_DIR}/src/*.cpp"
)

add_executable(${PROJECT_NAME} ${SRC_LIST})