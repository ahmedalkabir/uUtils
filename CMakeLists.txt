cmake_minimum_required(VERSION 3.8)
project(uUtilsTest)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES src/ufile.c src/ulist.c src/ustring.c src/uvector.c)

add_library(uUtils STATIC ${SOURCE_FILES})

target_include_directories(uUtils PUBLIC ${PROJECT_SOURCE_DIR}/include)

set(BINARY_FILES test.c)

add_executable(uUtilsTest ${BINARY_FILES})

target_link_libraries(uUtilsTest PRIVATE uUtils)

