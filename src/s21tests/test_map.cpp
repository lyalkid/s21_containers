#include <gtest/gtest.h>

#include <iostream>
#include <map>

#include "../s21map/map.h"

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
-->>    Map Member functions

- map()
- map(std::initializer_list<value_type> const &items)
- map(const map &m)
- map(map &&m)
- ~map()
- operator=(map &&m)
    +
- T& operator[](const Key& key) - !!! для проверки значений !!!
>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

TEST(Map, EmptyConstructor) {
  s21::map<int, int> intM;
  s21::map<double, double> doubleM;
  s21::map<std::string, std::string> stringM;

  EXPECT_EQ(intM.size(), 0U);
  EXPECT_EQ(doubleM.size(), 0U);
  EXPECT_EQ(stringM.size(), 0U);
}

TEST(Map, InitListConstuctor) {
  // Zero Value
  s21::map<int, std::string> m0({});
  EXPECT_EQ(m0.size(), 0);

  // One value
  s21::map<int, std::string> m1({{1, "one"}});
  EXPECT_EQ(m1.size(), 1);

  // Multiple values
  s21::map<int, std::string> m2({{1, "one"}, {2, "two"}, {3, "three"}});
  EXPECT_EQ(m2.size(), 3);
  EXPECT_EQ(m2[1], "one");
  EXPECT_EQ(m2[2], "two");
  EXPECT_EQ(m2[3], "three");

  // Key duplicate
  s21::map<int, std::string> mDup({{1, "one"}, {1, "uno"}});
  EXPECT_EQ(mDup.size(), 1);
  EXPECT_EQ(mDup[1], "one");

  // Mixed order
  s21::map<int, std::string> mOrder({{3, "three"}, {1, "one"}, {2, "two"}});
  EXPECT_EQ(mOrder.size(), 3);
  EXPECT_EQ(mOrder[1], "one");
  EXPECT_EQ(mOrder[2], "two");
  EXPECT_EQ(mOrder[3], "three");

  // Mixed type
  s21::map<std::string, int> mTypes({{"a", 1}, {"b", 2}, {"c", 3}});
  EXPECT_EQ(mTypes.size(), 3);
  EXPECT_EQ(mTypes["a"], 1);
  EXPECT_EQ(mTypes["b"], 2);
  EXPECT_EQ(mTypes["c"], 3);
}
//
TEST(Map, TreePair) {
  std::pair<int, double> intDouble{9, 1.4};
  std::pair<double, std::string> doubleString{2.77, "hi"};
  std::pair<std::string, int> stringInt{"hola", 3};
  // Tree examine
  s21::btree<int, double> intTree(intDouble);
  s21::btree<double, std::string> doubleTree(doubleString);
  s21::btree<std::string, int> stringTree(stringInt);
  //
  EXPECT_EQ(intTree.size(), 1U);
  EXPECT_EQ(doubleTree.size(), 1U);
  EXPECT_EQ(stringTree.size(), 1U);
}
//
TEST(Map, InitListPair) {
  // Pair
  std::pair<int, double> mPairMixAll1{9, 1.4};
  std::pair<int, double> mPairMixAll2{23, 2.77};
  std::pair<int, double> mPairMixAll3{98, 3.9};

  s21::map<int, double> mPair = {mPairMixAll1, mPairMixAll2, mPairMixAll3};

  EXPECT_EQ(mPair.size(), 3U);

  // Mixed pair double
  std::pair<int, double> intDouble{9, 1.4};
  std::pair<double, std::string> doubleString{2.77, "hi"};
  std::pair<std::string, int> stringInt{"hola", 3};

  s21::map<int, double> intMap{intDouble};
  s21::map<double, std::string> doubleMap{doubleString};
  s21::map<std::string, int> stringMap{stringInt};

  EXPECT_EQ(intMap.size(), 1U);
  EXPECT_EQ(doubleMap.size(), 1U);
  EXPECT_EQ(stringMap.size(), 1U);

  // Some more test pair
  std::pair<int, double> pair1{9, 1.4};
  std::pair<int, double> pair2{23, 2.77};
  std::pair<int, double> pair3{98, 3.9};

  s21::map<int, double> mapRefInt{pair1, pair2, pair3};
  s21::map<int, double> mapResultInt{mapRefInt};

  std::pair<double, std::string> pair4{1.4, "hello"};
  std::pair<double, std::string> pair5{2.77, "hi"};
  std::pair<double, std::string> pair6{3.9, "hola"};

  s21::map<double, std::string> mapRefDouble{pair4, pair5, pair6};
  s21::map<double, std::string> mapResultDouble{mapRefDouble};

  std::pair<std::string, int> pair7{"hello", 1};
  std::pair<std::string, int> pair8{"hi", 2};
  std::pair<std::string, int> pair9{"hola", 3};

  s21::map<std::string, int> mapRefString{pair7, pair8, pair9};
  s21::map<std::string, int> mapResultString{mapRefString};

  auto it_res_int = mapResultInt.begin();
  for (auto it_ref_int = mapRefInt.begin(); it_ref_int != mapRefInt.end();
       ++it_ref_int) {
    EXPECT_EQ(it_res_int->first, it_ref_int->first);
    it_res_int++;
  }

  auto it_res_double = mapResultDouble.begin();
  for (auto it_ref_double = mapRefDouble.begin();
       it_ref_double != mapRefDouble.end(); ++it_ref_double) {
    EXPECT_EQ(it_res_double->first, it_ref_double->first);
    it_res_double++;
  }

  auto it_res_string = mapResultString.begin();
  for (auto it_ref_string = mapRefString.begin();
       it_ref_string != mapRefString.end(); ++it_ref_string) {
    EXPECT_EQ(it_res_string->first, it_ref_string->first);
    it_res_string++;
  }
}

struct CustomKey {
  int id;
  std::string name;
  bool operator<(const CustomKey &other) const {
    if (id != other.id) return id < other.id;
    return name < other.name;
  }
};

// Определяем пользовательскую функцию сравнения
bool compareCustomKeys(const std::pair<int, std::string> &k1,
                       const std::pair<int, std::string> &k2) {
  return std::tie(k1.first, k1.second) == std::tie(k2.first, k2.second);
}

TEST(Map, CustomKeyInitList) {
  s21::map<std::pair<int, std::string>, std::pair<int, std::string>> m;
  m[{1, "Alice"}] = {1, "Alice"};
  m[{2, "Bob"}] = {2, "Bob"};

  std::pair<int, std::string> key1{1, "Alice"};
  std::pair<int, std::string> key2{2, "Bob"};

  auto &value = m[key1];
  EXPECT_EQ(value.first, 1);
  EXPECT_EQ(value.second, "Alice");

  EXPECT_TRUE(compareCustomKeys(m[{1, "Alice"}], {1, "Alice"}));
  EXPECT_TRUE(compareCustomKeys(m[{2, "Bob"}], {2, "Bob"}));
}

TEST(Map, CopyConstructor) {
  s21::map<int, std::string> original_map({
      {1, "one"},      // int и string
      {2.5, "two"},    // double и string
      {'a', "three"},  // char и string
      {0127, "five"}   // octal и string
  });

  s21::map<int, std::string> copied_map(original_map);

  EXPECT_EQ(copied_map.size(), original_map.size());

  EXPECT_EQ(copied_map[1], original_map[1]);        // int и string
  EXPECT_EQ(copied_map[2], original_map[2]);        // double и string
  EXPECT_EQ(copied_map['a'], original_map['a']);    // char и string
  EXPECT_EQ(copied_map[0127], original_map[0127]);  // octal и string
  EXPECT_EQ(original_map.size(), original_map.size());
}

TEST(Map, MoveConstructor) {
  // TODO: заменить на s21::map, пример не работает
  s21::map<int, std::string> original_map({
      {1, "one"},    // int и string
      {2, "two"},    // double и string
      {3, "three"},  // char и string
      {4, "four"}    // octal и string
  });

  s21::map<int, std::string> temp_map(std::move(original_map));

  // temp_map = std::move(original_map);

  EXPECT_EQ(original_map.size(), 0);
  EXPECT_EQ(temp_map.size(), 4);
  EXPECT_EQ(temp_map[1], "one");
  EXPECT_EQ(temp_map[2], "two");
  EXPECT_EQ(temp_map[3], "three");
  EXPECT_EQ(temp_map[4], "four");
  EXPECT_EQ(temp_map.size(), 4);
}

TEST(Map, MoveConstructorMixKeyType) {
  // TODO: заменить на s21::map, пример не работает
  // Mix key type
  s21::map<int, std::string> original_map({
      {1, "one"},      // int и string
      {2.5, "two"},    // double и string
      {'a', "three"},  // char и string
      {0127, "four"}   // octal и string
  });

  s21::map<int, std::string> temp_map;

  temp_map = std::move(original_map);

  EXPECT_EQ(original_map.size(), 0);
  EXPECT_EQ(temp_map.size(), 4);
  EXPECT_EQ(temp_map[1], "one");      // int и string
  EXPECT_EQ(temp_map[2], "two");      // double и string
  EXPECT_EQ(temp_map['a'], "three");  // char и string
  EXPECT_EQ(temp_map[0127], "four");  // octal и string
  EXPECT_EQ(temp_map.size(), 4);      // Убедимся, что все элементы перенесены
}

TEST(Map, MoveAssignmentOperator) {
  s21::map<int, std::string> original_map({{1, "one"}, {2, "two"}});
  s21::map<int, std::string> empty_map;

  empty_map = std::move(original_map);

  // Проверяем, что оригинальный map пуст
  EXPECT_EQ(original_map.size(), 0);
  EXPECT_EQ(empty_map.size(), 2);
  EXPECT_EQ(empty_map[1], "one");
  EXPECT_EQ(empty_map[2], "two");
}

TEST(Map, CopyAssignmentOperator) {
  // TODO: написать оператор сравнения для copy(&m), сравнила с оригом

  s21::map<int, std::string> original_map({{1, "one"}, {2, "two"}});
  s21::map<int, std::string> empty_map;

  empty_map = original_map;

  EXPECT_EQ(empty_map.size(), original_map.size());
  EXPECT_EQ(empty_map[1], original_map[1]);
  EXPECT_EQ(empty_map[2], original_map[2]);
  EXPECT_EQ(original_map.size(), original_map.size());
}

///*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//-->>   Map Element access >>
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

TEST(Map, AccessElement) {
  s21::map<int, std::string> my_map;

  my_map[1] = "one";
  my_map[2] = "two";
  my_map[3] = "three";

  EXPECT_EQ(my_map[1], "one");
  EXPECT_EQ(my_map[2], "two");
  EXPECT_EQ(my_map[3], "three");

  EXPECT_EQ(my_map[4], "");
  EXPECT_EQ(my_map.size(), 4);

  my_map['a'] = "alpha";
  EXPECT_EQ(my_map['a'], "alpha");

  my_map[100] = "hundred";
  EXPECT_EQ(my_map[100], "hundred");

  my_map[3] = "pi";
  EXPECT_EQ(my_map[3], "pi");

  EXPECT_EQ(my_map[1], "one");
}

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
-->>   Map Iterators                                                         >>
>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
-->>   Map Capacity                                                          >>
>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
-->>   Map Modifiers                                                         >>
>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
-->>   Map Lookup                                                            >>
>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

bool compare(std::map<int, int> &m, s21::map<int, int> &s) {
  bool res = true;
  auto std_it = m.begin();
  auto my_it = s.begin();
  auto std_size = m.size();
  auto my_size = s.size();
  if (std_size != my_size)
    res = false;
  else {
    while (std_size != 0) {
      auto std_first = std_it->first;
      auto my_first = my_it->first;
      if (std_first != my_first) {
        res = false;
        break;
      }
      std_it++;
      my_it++;

      std_size--;
    }
  }
  return res;
}

TEST(map_erase_suite, erase_no_child) {
  std::map<int, int> std_a;
  s21::map<int, int> a;

  a.insert(1, 0);
  a.insert(2, 0);
  a.insert(3, 0);
  auto std_itr_1 = std_a.insert({1, 0}).first;
  auto std_itr_2 = std_a.insert({2, 0}).first;
  auto std_itr_3 = std_a.insert({3, 0}).first;

  // -----------------------------------------
  a.erase(a.find({1, 0}));
  std_a.erase(std_itr_1);
  EXPECT_EQ(compare(std_a, a), true);

  // -----------------------------------------

  a.erase(a.find({3, 0}));
  std_a.erase(std_itr_3);
  EXPECT_EQ(compare(std_a, a), true);

  // -----------------------------------------
  a.erase(a.find({2, 0}));
  std_a.erase(std_itr_2);

  EXPECT_EQ(a.empty(), std_a.empty());
}

TEST(map_erase_suite, erase_one_child) {
  std::map<int, int> std_a;
  s21::map<int, int> a;

  std_a.insert({5, 0});
  std_a.insert({3, 0});
  std_a.insert({7, 0});
  std_a.insert({1, 0});
  std_a.insert({8, 0});

  a.insert(5, 0);
  a.insert(3, 0);
  a.insert(7, 0);
  a.insert(1, 0);
  a.insert(8, 0);

  a.erase(a.find({3, 0}));
  std_a.erase(std_a.find(3));
  EXPECT_EQ(compare(std_a, a), true);

  a.erase(a.find({7, 0}));
  std_a.erase(std_a.find(7));
  EXPECT_EQ(compare(std_a, a), true);

  a.erase(a.find({1, 0}));
  std_a.erase(std_a.find(1));
  EXPECT_EQ(compare(std_a, a), true);

  a.erase(a.find({5, 0}));
  std_a.erase(std_a.find(5));
  EXPECT_EQ(compare(std_a, a), true);
}

TEST(map_erase_suite, erase_two_child) {
  std::map<int, int> std_a;
  s21::map<int, int> a;
  std_a.insert({5, 0});
  std_a.insert({3, 0});
  std_a.insert({7, 0});
  std_a.insert({1, 0});
  std_a.insert({2, 0});
  std_a.insert({8, 0});
  std_a.insert({6, 0});

  a.insert(5, 0);
  a.insert(3, 0);
  a.insert(7, 0);
  a.insert(1, 0);
  a.insert(2, 0);
  a.insert(6, 0);
  a.insert(8, 0);

  a.erase(a.find({3, 0}));
  std_a.erase(std_a.find(3));
  EXPECT_EQ(compare(std_a, a), true);

  a.erase(a.find({7, 0}));
  std_a.erase(std_a.find(7));
  EXPECT_EQ(compare(std_a, a), true);

  a.erase(a.find({5, 0}));
  std_a.erase(std_a.find(5));
  EXPECT_EQ(compare(std_a, a), true);
}

TEST(map_constructor_suite, default_constructor) {
  std::map<int, int> std_a;
  s21::map<int, int> a;

  EXPECT_EQ(a.empty(), std_a.empty());
  EXPECT_EQ(a.size(), std_a.size());
}

TEST(map_constructor_suite, copy_constructor) {
  std::map<int, int> std_a;
  s21::map<int, int> a;

  std_a.insert({1, 1});
  std_a.insert({3, 2});
  std_a.insert({4, 2});

  a.insert(1, 1);
  a.insert(3, 2);
  a.insert(4, 2);

  std::map<int, int> std_b(std_a);
  s21::map<int, int> b(a);

  EXPECT_EQ(b.empty(), std_b.empty());
  EXPECT_EQ(b.size(), std_b.size());
  EXPECT_EQ(compare(std_b, b), true);
}

TEST(map_constructor_suite, initializer_constructor) {
  std::map<int, int> std_a = {{1, 0}, {2, 0}, {3, 0}};

  s21::map<int, int> a = {{1, 0}, {2, 0}, {3, 0}};

  EXPECT_EQ(a.empty(), std_a.empty());
  EXPECT_EQ(a.size(), std_a.size());

  EXPECT_EQ(compare(std_a, a), true);
}

TEST(map_constructor_suite, move_constructor) {
  std::map<int, int> std_a = {{1, 0}, {2, 0}, {3, 0}};

  s21::map<int, int> a = {{1, 0}, {2, 0}, {3, 0}};

  std::map<int, int> std_b(std::move(std_a));
  s21::map<int, int> b(std::move(a));

  EXPECT_EQ(b.empty(), std_b.empty());
  EXPECT_EQ(b.size(), std_b.size());

  EXPECT_EQ(compare(std_b, b), true);
}

TEST(map_constructor_suite, move_operator) {
  std::map<int, int> std_a = {{1, 0}, {2, 0}, {3, 0}};

  s21::map<int, int> a = {{1, 0}, {2, 0}, {3, 0}};

  std::map<int, int> std_b = std::move(std_a);
  s21::map<int, int> b = std::move(a);

  EXPECT_EQ(b.empty(), std_b.empty());
  EXPECT_EQ(b.size(), std_b.size());

  EXPECT_EQ(compare(std_b, b), true);
}

TEST(map_iterator_suite, begin) {
  std::map<int, int> std_a = {{1, 0}, {2, 0}, {3, 0}};
  s21::map<int, int> a = {{1, 0}, {2, 0}, {3, 0}};

  EXPECT_EQ((*a.begin()).first, (*std_a.begin()).first);
  EXPECT_EQ((*a.begin()).second, (*std_a.begin()).second);
}

TEST(map_iterator_suite, end) {
  std::map<int, int> std_a = {{1, 0}, {2, 0}, {3, 0}};
  s21::map<int, int> a = {{1, 0}, {2, 0}, {3, 0}};

  EXPECT_EQ((*a.end()).first, 0);
  EXPECT_EQ((*a.end()).second, 0);
}

TEST(map_constructor_suite, initializer_constructor_2) {
  std::map<int, int> std_a = {};

  s21::map<int, int> a = {};

  EXPECT_EQ(a.empty(), std_a.empty());
  EXPECT_EQ(a.size(), std_a.size());

  EXPECT_EQ(compare(std_a, a), true);
}

TEST(map_constructor_suite, move_constructor_2) {
  std::map<int, int> std_a;

  s21::map<int, int> a;

  std_a.insert({1, 1});
  std_a.insert({2, 0});
  std_a.insert({3, 0});
  std_a.insert({4, 10});
  std_a.insert({12, 4});
  std_a.insert({10, 0});
  std_a.insert({1, 8});
  std_a.insert({21, 1});
  std_a.insert({12, 9});
  std_a.insert({100, 9});

  a.insert({1, 1});
  a.insert({2, 0});
  a.insert({3, 0});
  a.insert({4, 10});
  a.insert({12, 4});
  a.insert({10, 0});
  a.insert({1, 8});
  a.insert({21, 1});
  a.insert({12, 9});
  a.insert({100, 9});

  std::map<int, int> std_b(std::move(std_a));
  s21::map<int, int> b(std::move(a));

  EXPECT_EQ(b.empty(), std_b.empty());
  EXPECT_EQ(b.size(), std_b.size());

  EXPECT_EQ(compare(std_b, b), true);
}

TEST(map_constructor_suite, move_operator_2) {
  std::map<int, int> std_a = {};

  s21::map<int, int> a = {};

  std::map<int, int> std_b = std::move(std_a);
  s21::map<int, int> b = std::move(a);

  EXPECT_EQ(b.empty(), std_b.empty());
  EXPECT_EQ(b.size(), std_b.size());

  EXPECT_EQ(compare(std_b, b), true);
}

TEST(map_modifiers_suite, clear_1) {
  std::map<int, int> std_a = {{1, 1}, {2, 0}, {3, 0}, {4, 0}, {5, 0}};

  s21::map<int, int> a = {{1, 1}, {2, 0}, {3, 0}, {4, 0}, {5, 0}};

  std_a.clear();
  a.clear();

  EXPECT_EQ(a.empty(), std_a.empty());
  EXPECT_EQ(a.size(), std_a.size());
}

TEST(map_modifiers_suite, clear_2) {
  std::map<int, int> std_a;
  s21::map<int, int> a;

  std_a.clear();
  a.clear();

  EXPECT_EQ(a.empty(), std_a.empty());
  EXPECT_EQ(a.size(), std_a.size());
}

TEST(map_modifiers_suite, insert) {
  std::map<int, int> std_a;
  s21::map<int, int> a;

  std_a.insert({1, 1});
  std_a.insert({2, 0});
  std_a.insert({3, 0});
  std_a.insert({4, 10});
  std_a.insert({12, 4});
  std_a.insert({10, 0});
  std_a.insert({1, 8});
  std_a.insert({21, 1});
  std_a.insert({12, 9});
  std_a.insert({100, 9});

  a.insert({1, 1});
  a.insert({2, 0});
  a.insert({3, 0});
  a.insert({4, 10});
  a.insert({12, 4});
  a.insert({10, 0});
  a.insert({1, 8});
  a.insert({21, 1});
  a.insert({12, 9});
  a.insert({100, 9});

  EXPECT_EQ(compare(std_a, a), true);
}

TEST(mapConstructorTest, DefaultConstructor) {
  s21::map<int, std::string> m;
  EXPECT_EQ(m.size(), 0);
  EXPECT_TRUE(m.empty());
}

TEST(mapConstructorTest, InitializerListConstructor) {
  s21::map<int, std::string> m{{1, "one"}, {2, "two"}, {3, "three"}};
  EXPECT_EQ(m.size(), 3);
  EXPECT_FALSE(m.empty());
  EXPECT_EQ(m.at(1), "one");
  EXPECT_EQ(m.at(2), "two");
  EXPECT_EQ(m.at(3), "three");
}

TEST(mapConstructorTest, CopyConstructor) {
  s21::map<int, std::string> m{{1, "one"}, {2, "two"}, {3, "three"}};
  s21::map<int, std::string> copy_m(m);
  EXPECT_EQ(copy_m.size(), 3);
  EXPECT_FALSE(copy_m.empty());
  EXPECT_EQ(copy_m.at(1), "one");
}
// Test the insert(key, value) function
TEST(mapTest, InsertKeyValue) {
  s21::map<int, std::string> map;
  // Insert a single key-value pair
  map.insert(1, "one");
  // Check that the size is correct
  EXPECT_EQ(map.size(), 1);
  // Check that the inserted key-value pair is in the map
  EXPECT_EQ(map.contains(1), true);
  EXPECT_EQ(map[1], "one");
  // Insert another key-value pair
  map.insert(2, "two");
  // Check that the size is correct
  EXPECT_EQ(map.size(), 2);
  // Check that both inserted key-value pairs are in the map
  EXPECT_EQ(map.contains(1), true);
  EXPECT_EQ(map[1], "one");
  EXPECT_EQ(map.contains(2), true);
  EXPECT_EQ(map[2], "two");
}
// Test the insert(pair) function
TEST(mapTest, InsertPair) {
  s21::map<int, std::string> map;
  // Insert a single key-value pair using a pair object
  map.insert(std::make_pair(1, "one"));
  // Check that the size is correct
  EXPECT_EQ(map.size(), 1);
  // Check that the inserted key-value pair is in the map
  EXPECT_EQ(map.contains(1), true);
  EXPECT_EQ(map[1], "one");
  // Insert another key-value pair using a pair object
  map.insert(std::make_pair(2, "two"));
  // Check that the size is correct
  EXPECT_EQ(map.size(), 2);
  // Check that both inserted key-value pairs are in the map
  EXPECT_EQ(map.contains(1), true);
  EXPECT_EQ(map[1], "one");
  EXPECT_EQ(map.contains(2), true);
  EXPECT_EQ(map[2], "two");
}
TEST(mapTest, InsertOrAssign) {
  s21::map<int, std::string> map;
  // Insert a new element with a key that does not exist.
  auto [it1, inserted1] = map.insert_or_assign(1, "one");
  EXPECT_TRUE(inserted1);
  EXPECT_EQ(it1->first, 1);
  EXPECT_EQ(it1->second, "one");
  // Insert a new element with a key that already exists.
  auto [it2, inserted2] = map.insert_or_assign(1, "ONE");
  EXPECT_FALSE(inserted2);
  EXPECT_EQ(it2->first, 1);
  EXPECT_EQ(it2->second, "ONE");
  // Insert multiple elements.
  map.insert_or_assign(2, "two");
  map.insert_or_assign(3, "three");
  map.insert_or_assign(4, "four");
  map.insert_or_assign(5, "five");
  EXPECT_EQ(map.size(), 5);
  EXPECT_EQ(map[1], "ONE");
  EXPECT_EQ(map[2], "two");
  EXPECT_EQ(map[3], "three");
  EXPECT_EQ(map[4], "four");
  EXPECT_EQ(map[5], "five");
}
TEST(mapTest, AtAndOperatorBrackets) {
  s21::map<int, std::string> map = {{1, "one"}, {2, "two"}, {3, "three"}};

  EXPECT_EQ(map.at(1), "one");
  EXPECT_EQ(map[2], "two");
  //  try {
  //      ASSERT_THROW(map.at(4), std::out_of_range);
  //  }catch (std::out_of_range& ex){
  //      int c;
  //  }

  map[4] = "four";
  EXPECT_EQ(map[4], "four");
  map[2] = "TWO";
  EXPECT_EQ(map[2], "TWO");
}

TEST(mapTest, EmptyAndSize) {
  s21::map<int, std::string> empty_map;
  s21::map<int, std::string> map = {{1, "one"}, {2, "two"}, {3, "three"}};

  EXPECT_TRUE(empty_map.empty());
  EXPECT_EQ(empty_map.size(), 0);

  EXPECT_FALSE(map.empty());
  EXPECT_EQ(map.size(), 3);
}

TEST(mapTest, MaxSize) {
  s21::map<int, std::string> s21_map;
  std::map<int, std::string> std_map;

  // Max size is implementation-dependent, but it should be greater than 0
  EXPECT_GE(s21_map.max_size(), 0);
}
TEST(mapTest, Erase) {
  s21::map<int, std::string> map;

  map.insert({1, "one"});
  map.insert({2, "two"});
  map.insert({3, "three"});
  map.insert({5, "five"});

  // Erase an existing element.
  auto it1 = map.begin()++;
  map.erase(it1);
  EXPECT_EQ(map.size(), 3);
  EXPECT_FALSE(map.contains(1));
}

TEST(mapTest, Swap) {
  s21::map<int, std::string> map1;
  map1.insert({1, "one"});
  map1.insert({2, "two"});

  s21::map<int, std::string> map2;
  map2.insert({3, "three"});
  map2.insert({4, "four"});

  map1.swap(map2);

  EXPECT_EQ(map1.size(), 2);
  EXPECT_TRUE(map1.contains(3));
  EXPECT_TRUE(map1.contains(4));

  EXPECT_EQ(map2.size(), 2);
  EXPECT_TRUE(map2.contains(1));
  EXPECT_TRUE(map2.contains(2));
}

TEST(mapTest, Merge) {
  s21::map<int, std::string> map1;
  map1.insert({1, "one"});
  map1.insert({2, "two"});

  s21::map<int, std::string> map2;
  map2.insert({3, "three"});
  map2.insert({4, "four"});

  map1.merge(map2);

  EXPECT_EQ(map1.size(), 4);
  EXPECT_TRUE(map1.contains(1));
  EXPECT_TRUE(map1.contains(2));
  EXPECT_TRUE(map1.contains(3));
  EXPECT_TRUE(map1.contains(4));
}

TEST(mapTest, Contains) {
  s21::map<int, std::string> map;

  map.insert({1, "one"});
  map.insert({2, "two"});
  EXPECT_TRUE(map.contains(2));
  EXPECT_FALSE(map.contains(3));
}

TEST(map_modifiers_suite, swap) {
  s21::map<int, int> a = {{1, 1}, {2, 0}, {3, 0}, {4, 0}, {5, 5}};

  s21::map<int, int> b = {{11, 1}, {12, 0}, {13, 0}, {14, 0}, {15, 5}};

  s21::map<int, int> b_swap = {{1, 1}, {2, 0}, {3, 0}, {4, 0}, {5, 5}};

  s21::map<int, int> a_swap = {{11, 1}, {12, 0}, {13, 0}, {14, 0}, {15, 5}};

  a.swap(b);
  auto a_itr = a.begin();
  auto a_swap_itr = a_swap.begin();
  for (; a_itr != a.end(); ++a_itr, ++a_swap_itr) {
    EXPECT_EQ(*a_itr, *a_swap_itr);
  }

  auto b_itr = b.begin();
  auto b_swap_itr = b_swap.begin();
  for (; b_itr != b.end(); ++b_itr, ++b_swap_itr) {
    EXPECT_EQ(*b_itr, *b_swap_itr);
  }
}

TEST(map_modifiers_suite, merge) {
  s21::map<int, int> a = {{1, 1}, {2, 0}, {3, 0}, {4, 0}, {5, 5}};
  s21::map<int, int> b = {{1, 1},  {2, 0},  {3, 0},  {4, 0},  {5, 5},
                          {11, 1}, {12, 0}, {13, 0}, {14, 0}, {15, 5}};

  s21::map<int, int> result = {{1, 1},  {2, 0},  {3, 0},  {4, 0},  {5, 5},
                               {11, 1}, {12, 0}, {13, 0}, {14, 0}, {15, 5}};

  a.merge(b);
  auto a_itr = a.begin();
  auto result_itr = result.begin();
  for (; a_itr != a.end(); ++a_itr, ++result_itr) {
    EXPECT_EQ(*a_itr, *result_itr);
  }
}

TEST(map_modifiers_suite, merge_empty) {
  s21::map<int, int> a = {{1, 1}, {2, 0}, {3, 0}, {4, 0}, {5, 5}};
  s21::map<int, int> b;
  s21::map<int, int> result = {{1, 1}, {2, 0}, {3, 0}, {4, 0}, {5, 5}};

  a.merge(b);
  auto a_itr = a.begin();
  auto result_itr = result.begin();
  for (; a_itr != a.end(); ++a_itr, ++result_itr) {
    EXPECT_EQ(*a_itr, *result_itr);
  }
}

TEST(map_modifiers_suite, merge_both_empty) {
  s21::map<int, int> a;
  s21::map<int, int> b;
  s21::map<int, int> result;

  a.merge(b);
  auto a_itr = a.begin();
  auto result_itr = result.begin();
  for (; a_itr != a.end(); ++a_itr, ++result_itr) {
    EXPECT_EQ(*a_itr, *result_itr);
  }
}

TEST(map_lookup_suite, contains) {
  s21::map<int, int> a = {{1, 1}, {2, 0}, {3, 0}, {4, 0}, {5, 5}};

  EXPECT_TRUE(a.contains(1));
  EXPECT_TRUE(a.contains(2));
  EXPECT_TRUE(a.contains(3));
  EXPECT_TRUE(a.contains(4));
  EXPECT_TRUE(a.contains(5));

  EXPECT_FALSE(a.contains(8));
  EXPECT_FALSE(a.contains(6));
  EXPECT_FALSE(a.contains(123));
}

TEST(map_element_access, braces_and_at) {
  s21::map<int, int> a;
  std::map<int, int> std_a;

  std_a.insert({1, 1});
  std_a.insert({2, 34});
  std_a.insert({3, 234});

  a.insert({1, 1});
  a.insert({2, 34});
  a.insert({3, 234});

  EXPECT_EQ(a.empty(), std_a.empty());
  EXPECT_EQ(a.size(), std_a.size());

  auto std_itr = std_a.begin();
  auto itr = a.begin();

  for (int i = 1; std_itr != std_a.end(); ++std_itr, ++itr, ++i) {
    EXPECT_EQ(a.at(i), std_a.at(i));
    EXPECT_EQ(a[i], std_a[i]);
    EXPECT_EQ((*itr).first, (*std_itr).first);
    EXPECT_EQ((*itr).second, (*std_itr).second);
  }
}

TEST(map_modifiers_insert, insert_or_assign) {
  s21::map<int, int> a;
  std::map<int, int> std_a;

  a.insert_or_assign(1, 1);
  a.insert_or_assign(2, 1);
  a.insert_or_assign(1, 11);
  a.insert_or_assign(2, 22);
  a.insert_or_assign(3, 1);

  std_a.insert_or_assign(1, 1);
  std_a.insert_or_assign(2, 1);
  std_a.insert_or_assign(1, 11);
  std_a.insert_or_assign(2, 22);
  std_a.insert_or_assign(3, 1);

  EXPECT_EQ(a.empty(), std_a.empty());
  EXPECT_EQ(a.size(), std_a.size());
  EXPECT_EQ(compare(std_a, a), true);
}
TEST(map_modifiers_insert, InsertManyMethodTest) {
  s21::map<int, std::string> a;
  a.insert_many(std::make_pair(10, "ten"), std::make_pair(11, "eleven"),
                std::make_pair(12, "twelve"));
  EXPECT_EQ(a.size(), 3);
  EXPECT_EQ(a.at(10), "ten");
  EXPECT_EQ(a.at(11), "eleven");
  EXPECT_EQ(a.at(12), "twelve");
}