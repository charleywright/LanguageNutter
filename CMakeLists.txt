cmake_minimum_required(VERSION 3.10)
project(LanguageNutter VERSION 1.0)

set( CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR} ) 
find_package(CURL REQUIRED)

add_executable(LanguageNutter src/main.cpp)
include_directories(${CURL_INCLUDE_DIR} ${Taglib_INCLUDE_DIRS} "include")
target_link_libraries(LanguageNutter ${CURL_LIBRARIES} ${Taglib_LIBRARIES})