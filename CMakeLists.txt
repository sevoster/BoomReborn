cmake_minimum_required(VERSION 3.1.0)

project(BoomRebornQt LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5 COMPONENTS Core Quick REQUIRED)

set(SOURCES main.cpp)
set(RESOURCES qml.qrc)

add_executable(${PROJECT_NAME} ${SOURCES} ${RESOURCES})

target_link_libraries(${PROJECT_NAME} Qt5::Core Qt5::Quick)
target_link_libraries(${PROJECT_NAME} data_model)

add_subdirectory(components)
