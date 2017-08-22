cmake_minimum_required(VERSION 3.8)
project(Data_Structures)

set(CMAKE_CXX_STANDARD 14)

set(
        SOURCE_FILES
        tester.tpp
        tester.h
        exceptions.tpp
        exceptions.h
        linked_lists/node.h
        linked_lists/singly_linked_list.h
        linked_lists/singly_linked_list.tpp
        linked_lists/doubly_linked_list.h
        linked_lists/doubly_linked_list.tpp
        linked_lists/circular_singly_linked_list.h
        linked_lists/circular_singly_linked_list.tpp
        linked_lists/circular_doubly_linked_list.h
        linked_lists/circular_doubly_linked_list.tpp
        main.cpp
)

add_executable(Data_Structures ${SOURCE_FILES})