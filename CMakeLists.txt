cmake_minimum_required(VERSION 3.8)
project(Data_Structures)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES main.cpp node.cpp SinglyLinkedList.cpp)
add_executable(Data_Structures ${SOURCE_FILES})