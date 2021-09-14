cmake_minimum_required(VERSION 3.10)
project(LanguageNutter VERSION 1.0)

set( CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR} ) 
find_package(CURL REQUIRED)

add_executable(LanguageNutter src/main.cpp src/languagenut/authed_request.cpp src/languagenut/login.cpp src/languagenut/account.cpp src/languagenut/init.cpp src/languagenut/achievements.cpp src/languagenut/assignments.cpp src/languagenut/ranking.cpp src/languagenut/skills.cpp src/languagenut/user_data.cpp src/languagenut/curriculum.cpp src/languagenut/curriculums.cpp src/languagenut/module_ids.cpp src/languagenut/exam_levels.cpp)
include_directories(${CURL_INCLUDE_DIR} ${Taglib_INCLUDE_DIRS} "include" "src")
target_link_libraries(LanguageNutter ${CURL_LIBRARIES} ${Taglib_LIBRARIES})