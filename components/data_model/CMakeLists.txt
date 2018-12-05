cmake_minimum_required(VERSION 3.1.0)

set(TARGET_NAME data_model)

add_library(${TARGET_NAME} STATIC datamodel.cpp datamodel.h)

target_include_directories(${TARGET_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(${TARGET_NAME} PUBLIC Qt5::Core Qt5::Gui)
