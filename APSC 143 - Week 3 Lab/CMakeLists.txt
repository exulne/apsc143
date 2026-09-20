cmake_minimum_required(VERSION 3.22.1)
project(APSC143_Lab02 C)

set(CMAKE_C_STANDARD 11)

if (EXISTS "${PROJECT_SOURCE_DIR}/src/task1.c")
    add_executable(task_1 src/task1.c)
endif()

if (EXISTS "${PROJECT_SOURCE_DIR}/src/task2.c")
    add_executable(task_2 src/task2.c)
    target_link_libraries(task_2 m)
endif()
