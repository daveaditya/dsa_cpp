cmake_minimum_required(VERSION 3.8)
project(Data_Structures)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES
        main.cpp
        tester.cpp
        linked_lists/singly_linked_list.tpp
        linked_lists/circular_singly_linked_list.tpp
        linked_lists/doubly_linked_list.tpp
        linked_lists/circular_doubly_linked_list.tpp
        queue/linked_queue.tpp
        queue/array_queue.tpp
        queue/linked_circular_queue.tpp
        queue/linked_deque.tpp
        queue/array_deque.tpp
        queue/priority_queue.tpp
        stack/linked_stack.tpp
        stack/array_stack.tpp

        #[[tester.h
        exceptions.h
        linked_lists/node.h
        linked_lists/singly_linked_list.h
        linked_lists/circular_singly_linked_list.h
        linked_lists/doubly_linked_list.h
        linked_lists/circular_doubly_linked_list.h
        queue/linked_queue.h
        queue/array_queue.h
        queue/linked_circular_queue.h
        queue/linked_deque.h
        queue/array_deque.h
        queue/priority_queue.h
        stack/linked_stack.h
        stack/array_stack.h]]
)

add_executable(Data_Structures ${SOURCE_FILES})

#[[file(
        GLOB_RECURSE HEADER_FILES Data_Structures/*.h
)]]

#[[
include_directories(
        linked_lists
        queue
        stack
        Data_Structures
)]]
