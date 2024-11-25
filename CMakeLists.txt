cmake_minimum_required(VERSION 3.29)

# Set the project name
project(PimplInnerWorker CXX)

option(ENABLE_QT "Compile with Qt support" OFF)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)


# Include directories
include_directories(src)

# Add executable
add_executable(PimplWithWorker
    src/main.cpp
    src/MyClass.cpp
    src/MyClass.h
)

if(ENABLE_QT)

    set(CMAKE_AUTOMOC ON)
    set(CMAKE_AUTORCC ON)
    set(CMAKE_AUTOUIC ON)
    find_package(Qt6 REQUIRED COMPONENTS Core Widgets Gui)

    # Add Qt executable
    add_executable(PimplWithQtWorker ${SOURCES_QT}
        src/Qt/main.cpp
        src/Qt/MyQtClass.cpp
        src/Qt/MyQtClass.h
    )
    target_link_libraries(PimplWithQtWorker PRIVATE Qt6::Core Qt6::Widgets Qt6::Gui)
    message(STATUS "Target 'PimplWithQtWorker' created with Qt support.")
endif()

target_compile_definitions(PimplWithWorker PRIVATE WITHOUT_QT)
if(ENABLE_QT)
    target_compile_definitions(PimplWithQtWorker PRIVATE WITH_QT)
endif()
