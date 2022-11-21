cmake_minimum_required(VERSION 3.23)
project(Store)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")

include_directories(D:/mysql/include)
link_directories(D:/mysql/lib)


add_subdirectory(dao)
add_subdirectory(entity)
add_subdirectory(controller)
add_subdirectory(view)

file(GLOB_RECURSE SRC_DIR_LIST "entity/*.cpp" "controller/*.cpp" "dao/*.cpp" "view/*.cpp")


add_executable(Store main.cpp  ${SRC_DIR_LIST})

target_link_libraries(Store dao entity controller view)