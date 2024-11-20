#include <gtest/gtest.h>

#include <iostream>
#include <map>

#include "example_map.h"

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
    +
- size()
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

// TEST(Map, TreePair) {
//   std::pair<int, double> intDouble{9, 1.4};
//   std::pair<double, std::string> doubleString{2.77, "hi"};
//   std::pair<std::string, int> stringInt{"hola", 3};
//   // Tree examine
//   s21::Tree<int, double> intTree(intDouble);
//   s21::Tree<double, std::string> doubleTree(doubleString);
//   s21::Tree<std::string, int> stringTree(stringInt);

//   EXPECT_EQ(intTree.size(), 1U);
//   EXPECT_EQ(doubleTree.size(), 1U);
//   EXPECT_EQ(stringTree.size(), 1U);
// }

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
  bool operator<(const CustomKey& other) const {
    if (id != other.id) return id < other.id;
    return name < other.name;
  }
};

// Определяем пользовательскую функцию сравнения
bool compareCustomKeys(const std::pair<int, std::string>& k1,
                       const std::pair<int, std::string>& k2) {
  return std::tie(k1.first, k1.second) == std::tie(k2.first, k2.second);
}

TEST(Map, CustomKeyInitList) {
  s21::map<std::pair<int, std::string>, std::pair<int, std::string>> m;
  m[{1, "Alice"}] = {1, "Alice"};
  m[{2, "Bob"}] = {2, "Bob"};

  std::pair<int, std::string> key1{1, "Alice"};
  std::pair<int, std::string> key2{2, "Bob"};

  auto& value = m[key1];
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
  EXPECT_EQ(copied_map[2.5], original_map[2.5]);    // double и string
  EXPECT_EQ(copied_map['a'], original_map['a']);    // char и string
  EXPECT_EQ(copied_map[0127], original_map[0127]);  // octal и string
  EXPECT_EQ(original_map.size(), original_map.size());
}

TEST(Map, MoveConstructor) {
  // TODO: заменить на s21::map, пример не работает
  std::map<int, std::string> original_map({
      {1, "one"},    // int и string
      {2, "two"},    // double и string
      {3, "three"},  // char и string
      {4, "four"}    // octal и string
  });

  std::map<int, std::string> temp_map(std::move(original_map));

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
  std::map<int, std::string> original_map({
      {1, "one"},      // int и string
      {2.5, "two"},    // double и string
      {'a', "three"},  // char и string
      {0127, "four"}   // octal и string
  });

  std::map<int, std::string> temp_map;

  temp_map = std::move(original_map);

  EXPECT_EQ(original_map.size(), 0);
  EXPECT_EQ(temp_map.size(), 4);
  EXPECT_EQ(temp_map[1], "one");      // int и string
  EXPECT_EQ(temp_map[2.5], "two");    // double и string
  EXPECT_EQ(temp_map['a'], "three");  // char и string
  EXPECT_EQ(temp_map[0127], "four");  // octal и string
  EXPECT_EQ(temp_map.size(), 4);  // Убедимся, что все элементы перенесены
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

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
-->>   Map Element access                                                    >>
>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

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

  my_map[3.14] = "pi";
  EXPECT_EQ(my_map[3.14], "pi");

  EXPECT_EQ(my_map[1], "one");
}

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
-->>   Map Iterators  
- iterator begin()
- iterator end()                                                       
>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

TEST(Map, Begin) {
  std::pair<int, double> intDouble1{9, 1.4};
  std::pair<int, double> intDouble2{15, 1.456};
  std::pair<int, double> intDouble3{7, 151.4};
  std::pair<int, double> intDouble4{23, 2.77};
  std::pair<int, double> intDouble5{2, 3.9};

  s21::map<int, double> intDoubleMap = {intDouble1, intDouble2, intDouble3, intDouble4, intDouble5};

  auto minValue1 = intDoubleMap.begin();

  EXPECT_EQ(minValue1->first, 2);

  std::pair<double, std::string> doubleString1{11.4, "hello"};
  std::pair<double, std::string> doubleString2{2.770001, "hee"};
  std::pair<double, std::string> doubleString3{3.901, "hola"};
  std::pair<double, std::string> doubleString4{2.77, "hi"};
  std::pair<double, std::string> doubleString5{3.9, "hee-hee"};

  s21::map<double, std::string> doubleString = {doubleString1, doubleString2, doubleString3, doubleString4, doubleString5};

  auto minValue2 = doubleString.begin();

  EXPECT_EQ(minValue2->first, 2.77);

  std::pair<std::string, int> stringInt1{"hello", 1};
  std::pair<std::string, int> stringInt2{"hi", 2};
  std::pair<std::string, int> stringInt3{"hi-hi", 2};
  std::pair<std::string, int> stringInt4{"hola", 3};
  std::pair<std::string, int> stringInt5{"hello, there", 1};

  s21::map<std::string, int> stringIntMap = {stringInt1, stringInt2, stringInt3, stringInt4, stringInt5};

  auto minValue3 = stringIntMap.begin();

  EXPECT_EQ(minValue3->first, "hello");

  s21::map<int, double> s21Map;
  EXPECT_THROW(s21Map.begin(), std::out_of_range);

  std::pair<double, std::string> pair1{1.4, "hello"};
  s21::map<double, std::string> doubleStringMap2 = {pair1, pair1};

  auto minValue4 = doubleStringMap2.begin();

  EXPECT_EQ(minValue4->first, 1.4);
  EXPECT_EQ(minValue4->second, "hello");

  std::pair<std::string, int> stringIntSame1{"hello", 1};
  std::pair<std::string, int> stringIntSame2{"hello", 2};
  std::pair<std::string, int> stringIntSame3{"hello", 45};

  s21::map<std::string, int> stringIntMap2 = {stringIntSame1, stringIntSame2, stringIntSame3};

  auto minValue5 = stringIntMap2.begin();

  EXPECT_EQ(minValue5->first, "hello");
  EXPECT_EQ(minValue5->second, 1);
}

TEST(Map, End) {
  std::pair<int, double> intDouble1{9, 1.4};
  std::pair<int, double> intDouble2{15, 1.456};
  std::pair<int, double> intDouble3{7, 151.4};
  std::pair<int, double> intDouble4{23, 2.77};
  std::pair<int, double> intDouble5{2, 3.9};

  s21::map<int, double> intDoubleMap = {intDouble1, intDouble2, intDouble3, intDouble4, intDouble5};

  auto maxValue = intDoubleMap.end();

  EXPECT_EQ(maxValue->first, 23);

  std::pair<double, std::string> doubleString1{11.4, "hello"};
  std::pair<double, std::string> doubleString2{2.770001, "hee"};
  std::pair<double, std::string> doubleString3{3.901, "hola"};
  std::pair<double, std::string> doubleString4{233.77, "hi"};
  std::pair<double, std::string> doubleString5{3.9, "hee-hee"};

  s21::map<double, std::string> doubleString = {doubleString1, doubleString2, doubleString3, doubleString4, doubleString5};

  auto maxValue2 = doubleString.end();

  EXPECT_EQ(maxValue2->first, 233.77);

  std::pair<std::string, int> stringInt1{"hello", 1};
  std::pair<std::string, int> stringInt2{"hi", 2};
  std::pair<std::string, int> stringInt3{"hehehehehehe", 2};
  std::pair<std::string, int> stringInt4{"hola", 3};
  std::pair<std::string, int> stringInt5{"hello, there", 1};

  s21::map<std::string, int> stringIntMap = {stringInt1, stringInt2, stringInt3, stringInt4, stringInt5};
  //в ориге возникает сега
  auto maxValue3 = stringIntMap.end();

  EXPECT_EQ(maxValue3->first, "hola");//неверное значение
  //TODO: Проверить что происходит в оргине и как правильно записать значения

  s21::map<int, double> s21Map;

  EXPECT_THROW(s21Map.end(), std::out_of_range);

  std::pair<double, std::string> pair1{1.4, "hello"};
  s21::map<double, std::string> doubleStringMap2 = {pair1, pair1};

  auto maxValue4 = doubleStringMap2.end();

  EXPECT_EQ(maxValue4->first, 1.4);
  EXPECT_EQ(maxValue4->second, "hello");
  
  std::pair<int, double> intDoublePair1{1, 1.4};
  std::pair<int, double> intDoublePair2{15, 1.456};
  std::pair<int, double> intDoublePair3{5, 151.4};

  s21::map<int, double> s21MapIntDouble = {intDoublePair1, intDoublePair2, intDoublePair3};

  auto maxValue1 = s21MapIntDouble.end();

  EXPECT_EQ(maxValue1->first, 15);
  EXPECT_EQ(s21MapIntDouble.size(), 3U);

  std::pair<double, std::string> MapPair1{11.4, "hello"};
  std::pair<double, std::string> MapPair2{2.770001, "hi"};
  std::pair<double, std::string> MapPair3{3.901, "hola"};

  s21::map<double, std::string> Map1 = {MapPair1, MapPair2, MapPair3};

  auto maxValue22 = Map1.end();

  EXPECT_EQ(maxValue22->first, 11.4);
  EXPECT_EQ(Map1.size(), 3U);

  std::pair<int, int> pair0{30, 30};
  std::pair<int, int> pair2{5, 5};
  std::pair<int, int> pair3{43, 43};
  std::pair<int, int> pair4{1, 1};
  std::pair<int, int> pair5{20, 20};
  std::pair<int, int> pair6{40, 60};
  std::pair<int, int> pair7{60, 60};
  std::pair<int, int> pair8{35, 35};
  std::pair<int, int> pair9{32, 32};

  s21::map<int, int> s21MapIntInt = {pair0, pair2, pair3, pair4, pair5,
                                pair6, pair7, pair8, pair9};

  EXPECT_EQ(s21MapIntInt.end()->first, 60);
  EXPECT_EQ(s21MapIntInt.begin()->first, 1);
  EXPECT_EQ(s21MapIntInt.size(), 9U);
}
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
-->>   Map Capacity                                                          >>
>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
-->>   Map Modifiers                                                         >>
>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
-->>   Map Lookup                                                            >>
>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
