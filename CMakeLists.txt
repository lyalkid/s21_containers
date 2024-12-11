cmake_minimum_required(VERSION 3.22)
project(containers)

set(CMAKE_CXX_STANDARD 17)

 # Добавляем поддержку Google Test
 find_package(GTest REQUIRED)

 # Подключаем библиотеки Google Test
 include_directories(${GTEST_INCLUDE_DIRS})

# Главный исполняемый файл проекта
add_executable(containers
        src/map_with_unique_ptr/main.cpp
        src/map_with_unique_ptr/include/btree_node.h
        src/set/set.tpp
)

 # Тесты
 add_executable(tests
         src/map_with_unique_ptr/tests/btree_test.cpp
         src/map_with_unique_ptr/tests/test_main.cpp
         src/map_with_unique_ptr/tests/test_map.cpp
         src/set/testSet.cpp

 )

 # Линковка с Google Test
 target_link_libraries(tests PRIVATE ${GTEST_LIBRARIES} pthread)
