cmake_minimum_required(VERSION 3.4.1)

file(GLOB CTEST src/main/cpp/*.c )
file(GLOB CPLUS src/main/cpp/*.cpp )

add_library(
        native-lib
        SHARED
        ${CTEST}
        ${CPLUS})

target_link_libraries(
        native-lib
        log)