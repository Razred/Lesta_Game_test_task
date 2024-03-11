cmake_minimum_required(VERSION 3.23)
project(Wargame)

set(CMAKE_CXX_STANDARD 20)

add_executable(Wargame
        src/Task_2/circle_buffer_array.h
        src/Task_2/circle_buffer_list.h
        test/test_circle_array.h
        test/test_circle_list.h
        test/test.cpp
        test/test.cpp src/Task_3/Quick_sort.h)
