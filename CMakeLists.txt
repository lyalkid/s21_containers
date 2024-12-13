cmake_minimum_required(VERSION 3.22)
project(containers)

set(CMAKE_CXX_STANDARD 17)

 # Добавляем поддержку Google Test
 find_package(GTest REQUIRED)

 # Подключаем библиотеки Google Test
 include_directories(${GTEST_INCLUDE_DIRS})

# Главный исполняемый файл проекта
add_executable(containers
        src/s21btree/btree.h
        src/s21btree/btree.tpp
        src/s21btree/btree_iterator.h
        src/s21_containersplus.h
        src/main.cpp

)

 # Тесты
 add_executable(tests
         src/s21tests/test_array.cpp
         src/s21tests/test_btree.cpp
         src/s21tests/test_list.cpp
         src/s21tests/test_main.cpp
         src/s21tests/test_map.cpp
         src/s21tests/test_multiset.cpp
         src/s21tests/test_queue.cpp
         src/s21tests/test_set.cpp
         src/s21tests/test_stack.cpp
         src/s21tests/test_vector.cpp

 )

 # Линковка с Google Test
 target_link_libraries(tests PRIVATE ${GTEST_LIBRARIES} pthread)
