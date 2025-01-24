cmake_minimum_required(VERSION 3.30)
project(Term4Lab4)

set(CMAKE_CXX_STANDARD 17)


set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR D:/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(D:/SFML/include/SFML)
target_link_libraries(Term4Lab4 sfml-system sfml-window sfml-graphics sfml-audio)


add_executable(Term4Lab4
        main.cpp
        headers/data_structures/HashTable.h
        headers/algorithms.h
        headers/tests.h
        headers/UI.h
)

