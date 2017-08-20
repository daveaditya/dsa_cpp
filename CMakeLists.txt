cmake_minimum_required(VERSION 3.8)
project(Data_Structures)

set(CMAKE_CXX_STANDARD 14)

set(
        SOURCE_FILES main.cpp linked_lists/node.h linked_lists/singly_linked_list.h linked_lists/singly_linked_list.tpp linked_lists/circular_singly_linked_list.h linked_lists/circular_singly_linked_list.tpp linked_lists/doubly_linked_list.h linked_lists/doubly_linked_list.tpp
)

add_executable(
        Data_Structures ${SOURCE_FILES}
)

#
#link_directories(
#        linked_lists
#        array_list
#        queue
#        stack
#)