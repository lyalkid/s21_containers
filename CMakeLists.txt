cmake_minimum_required(VERSION 3.22)
project(containers)

set(CMAKE_CXX_STANDARD 17)

 # Добавляем поддержку Google Test
 find_package(GTest REQUIRED)

 # Подключаем библиотеки Google Test
 include_directories(${GTEST_INCLUDE_DIRS})

# Главный исполняемый файл проекта
add_executable(containers

)

 # Тесты
 add_executable(tests


 )

 # Линковка с Google Test
 target_link_libraries(tests PRIVATE ${GTEST_LIBRARIES} pthread)
