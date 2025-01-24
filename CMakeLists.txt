ccmake_minimum_required(VERSION 3.28)
project(Term4Lab4)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "D:/qt/6.7.3/lib/cmake")

find_package(Qt6 REQUIRED COMPONENTS
        Core
        Gui
        Widgets
)

# Define the executable
add_executable(Term4Lab4
        main.cpp
        headers/data_structures/HashTable.h
        headers/algorithms.h
        headers/tests.h
        headers/UI.h
)

# Link libraries
target_link_libraries(Term4Lab4 PRIVATE
        Qt6::Core
        Qt6::Gui
        Qt6::Widgets
)