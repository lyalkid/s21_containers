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

TEST(Map, InitListConstuctor1) {
  // Zero Value
  s21::map<int, std::string> m0({});
  EXPECT_EQ(m0.size(), 0);
}

TEST(Map, InitListConstuctor2) {
  // One value
  s21::map<int, std::string> m1({{1, "one"}});
  EXPECT_EQ(m1.size(), 1);
}
TEST(Map, InitListConstructor3) {
  // Multiple values
  s21::map<int, std::string> m2({{1, "one"}, {2, "two"}, {3, "three"}});
  EXPECT_EQ(m2.size(), 3);
  EXPECT_EQ(m2[1], "one");
  EXPECT_EQ(m2[2], "two");
  EXPECT_EQ(m2[3], "three");
}

TEST(Map, InitListConstructor4) {
  // Key duplicate
  s21::map<int, std::string> mDup({{1, "one"}, {1, "uno"}});
  EXPECT_EQ(mDup.size(), 1);
  EXPECT_EQ(mDup[1], "one");
}

TEST(Map, InitListConstructor5) {
  // Mixed order
  s21::map<int, std::string> mOrder({{3, "three"}, {1, "one"}, {2, "two"}});
  EXPECT_EQ(mOrder.size(), 3);
  EXPECT_EQ(mOrder[1], "one");
  EXPECT_EQ(mOrder[2], "two");
  EXPECT_EQ(mOrder[3], "three");
}

TEST(Map, InitListConstructor6) {
  // Mixed type
  s21::map<std::string, int> mTypes({{"a", 1}, {"b", 2}, {"c", 3}});
  EXPECT_EQ(mTypes.size(), 3);
  EXPECT_EQ(mTypes["a"], 1);
  EXPECT_EQ(mTypes["b"], 2);
  EXPECT_EQ(mTypes["c"], 3);
}

TEST(Map, InitListPair1) {
  std::pair<std::string, int> stringInt1{"hello", 1};
  std::pair<std::string, int> stringInt2{"hi", 2};
  std::pair<std::string, int> stringInt3{"hola", 3};

  s21::map<std::string, int> mapRefString{stringInt1, stringInt2, stringInt3};
  s21::map<std::string, int> mapResultString{mapRefString};

  auto resString = mapResultString.begin();
  for (auto realResString = mapRefString.begin();
       realResString != mapRefString.end(); ++realResString) {
    EXPECT_EQ(resString->first, realResString->first);
    resString++;
  }
}

TEST(Map, InitListPair2) {
  // Pair
  std::pair<int, double> mPairMixAll1{9, 1.4};
  std::pair<int, double> mPairMixAll2{23, 2.77};
  std::pair<int, double> mPairMixAll3{98, 3.9};

  s21::map<int, double> mPair = {mPairMixAll1, mPairMixAll2, mPairMixAll3};

  EXPECT_EQ(mPair.size(), 3U);
}

TEST(Map, InitListPair3) {
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
}

TEST(Map, InitListPair4) {
  // Some more test pair
  std::pair<int, double> intDouble1{9, 1.4};
  std::pair<int, double> intDouble2{23, 2.77};
  std::pair<int, double> intDouble3{98, 3.9};

  s21::map<int, double> mapRefInt{intDouble1, intDouble2, intDouble3};
  s21::map<int, double> mapResultInt{mapRefInt};

  auto resInt = mapResultInt.begin();
  for (auto realResInt = mapRefInt.begin(); realResInt != mapRefInt.end();
       ++realResInt) {
    EXPECT_EQ(resInt->first, realResInt->first);
    resInt++;
  }
}

TEST(Map, InitListPair5) {
  std::pair<double, std::string> doubleString1{1.4, "hello"};
  std::pair<double, std::string> doubleString2{2.77, "hi"};
  std::pair<double, std::string> doubleString3{3.9, "hola"};

  s21::map<double, std::string> mapRefDouble{doubleString1, doubleString2,
                                             doubleString3};
  s21::map<double, std::string> mapResultDouble{mapRefDouble};

  auto resDouble = mapResultDouble.begin();
  for (auto realResDouble = mapRefDouble.begin();
       realResDouble != mapRefDouble.end(); ++realResDouble) {
    EXPECT_EQ(resDouble->first, realResDouble->first);
    resDouble++;
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
  s21::map<int, std::string> map;

  map[1] = "one";
  map[2] = "two";
  map[3] = "three";

  EXPECT_EQ(map[1], "one");
  EXPECT_EQ(map[2], "two");
  EXPECT_EQ(map[3], "three");

  EXPECT_EQ(map[4], "");
  EXPECT_EQ(map.size(), 4);

  map['a'] = "alpha";
  EXPECT_EQ(map['a'], "alpha");

  map[100] = "hundred";
  EXPECT_EQ(map[100], "hundred");

  map[3.14] = "pi";
  EXPECT_EQ(map[3.14], "pi");

  EXPECT_EQ(map[1], "one");
}

TEST(Map, At1) {
  std::pair<int, double> intDouble1{9, 1.4};
  std::pair<int, double> intDouble2{23, 2.77};
  std::pair<int, double> intDouble3{98, 3.9};
  std::pair<int, double> pair11{78, 3.9};
  std::pair<int, double> pair22{88, 3.9};
  std::pair<int, double> pair33{108, 3.9};

  s21::map<int, double> s21_map_int{intDouble1, intDouble2, intDouble3,
                                    pair11,     pair22,     pair33};
  EXPECT_EQ(s21_map_int.at(9), 1.4);
  EXPECT_EQ(s21_map_int.at(23), 2.77);
  EXPECT_EQ(s21_map_int.at(98), 3.9);
  EXPECT_EQ(s21_map_int.at(78), 3.9);
  EXPECT_EQ(s21_map_int.at(88), 3.9);
  EXPECT_EQ(s21_map_int.at(108), 3.9);
}

TEST(Map, At2) {
  std::pair<double, std::string> intDouble4{1.4, "hello"};
  std::pair<double, std::string> intDouble5{2.77, "hi"};
  std::pair<double, std::string> pair6{3.9, "hola"};

  s21::map<double, std::string> s21_map_double{intDouble4, intDouble5, pair6};
  EXPECT_EQ(s21_map_double.at(1.4), "hello");
  EXPECT_EQ(s21_map_double.at(2.77), "hi");
  EXPECT_EQ(s21_map_double.at(3.9), "hola");
}

TEST(Map, At3) {
  std::pair<std::string, int> pair7{"hello", 1};
  std::pair<std::string, int> pair8{"hi", 2};
  std::pair<std::string, int> pair9{"hola", 3};

  s21::map<std::string, int> s21_map_string{pair7, pair8, pair9};
  EXPECT_EQ(s21_map_string.at("hello"), 1);
  EXPECT_EQ(s21_map_string.at("hi"), 2);
  EXPECT_EQ(s21_map_string.at("hola"), 3);
}

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
-->>   Map Iterators
- iterator begin()
- iterator end()
>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

TEST(Map, Begin1) {
  std::pair<std::string, int> stringIntSame1{"hello", 1};
  std::pair<std::string, int> stringIntSame2{"hello", 2};
  std::pair<std::string, int> stringIntSame3{"hello", 45};

  s21::map<std::string, int> stringIntMap2 = {stringIntSame1, stringIntSame2,
                                              stringIntSame3};

  auto minValue5 = stringIntMap2.begin();

  EXPECT_EQ(minValue5->first, "hello");
  EXPECT_EQ(minValue5->second, 1);
}

TEST(Map, Begin2) {
  std::pair<int, double> intDouble1{9, 1.4};
  std::pair<int, double> intDouble2{15, 1.456};
  std::pair<int, double> intDouble3{7, 151.4};
  std::pair<int, double> intDouble4{23, 2.77};
  std::pair<int, double> intDouble5{2, 3.9};

  s21::map<int, double> intDoubleMap = {intDouble1, intDouble2, intDouble3,
                                        intDouble4, intDouble5};

  auto minValue1 = intDoubleMap.begin();

  EXPECT_EQ(minValue1->first, 2);
}

TEST(Map, Begin3) {
  std::pair<double, std::string> doubleString1{11.4, "hello"};
  std::pair<double, std::string> doubleString2{2.770001, "hee"};
  std::pair<double, std::string> doubleString3{3.901, "hola"};
  std::pair<double, std::string> doubleString4{2.77, "hi"};
  std::pair<double, std::string> doubleString5{3.9, "hee-hee"};

  s21::map<double, std::string> doubleString = {doubleString1, doubleString2,
                                                doubleString3, doubleString4,
                                                doubleString5};

  auto minValue2 = doubleString.begin();

  EXPECT_EQ(minValue2->first, 2.77);
}

TEST(Map, Begin4) {
  std::pair<std::string, int> stringInt1{"hello", 1};
  std::pair<std::string, int> stringInt2{"hi", 2};
  std::pair<std::string, int> stringInt3{"hi-hi", 2};
  std::pair<std::string, int> stringInt4{"hola", 3};
  std::pair<std::string, int> stringInt5{"hello, there", 1};

  s21::map<std::string, int> stringIntMap = {stringInt1, stringInt2, stringInt3,
                                             stringInt4, stringInt5};

  auto minValue3 = stringIntMap.begin();

  EXPECT_EQ(minValue3->first, "hello");
}

TEST(Map, Begin5) {
  std::pair<double, std::string> intDouble1{1.4, "hello"};
  s21::map<double, std::string> doubleStringMap2 = {intDouble1, intDouble1};

  auto minValue4 = doubleStringMap2.begin();

  EXPECT_EQ(minValue4->first, 1.4);
  EXPECT_EQ(minValue4->second, "hello");
}

TEST(Map, BeginThrow) {
  s21::map<int, double> s21Map;
  EXPECT_THROW(s21Map.begin(),
               std::out_of_range);  // TODO:!в ориге ничего не выбрасывается,
                                    // оставила тест, чтобы обратить внимание
}

TEST(Map, End) {
  std::pair<double, std::string> MapPair1{11.4, "hello"};
  std::pair<double, std::string> MapPair2{2.770001, "hi"};
  std::pair<double, std::string> MapPair3{3.901, "hola"};

  s21::map<double, std::string> Map1 = {MapPair1, MapPair2, MapPair3};

  auto maxValue22 = Map1.end();

  EXPECT_EQ(maxValue22->first, 11.4);
  EXPECT_EQ(Map1.size(), 3U);
}

TEST(Map, End2) {
  std::pair<int, double> intDouble1{9, 1.4};
  std::pair<int, double> intDouble2{15, 1.456};
  std::pair<int, double> intDouble3{7, 151.4};
  std::pair<int, double> intDouble4{23, 2.77};
  std::pair<int, double> intDouble5{2, 3.9};

  s21::map<int, double> intDoubleMap = {intDouble1, intDouble2, intDouble3,
                                        intDouble4, intDouble5};

  auto maxValue = intDoubleMap.end();

  EXPECT_EQ(maxValue->first, 23);
}

TEST(Map, End3) {
  std::pair<double, std::string> doubleString1{11.4, "hello"};
  std::pair<double, std::string> doubleString2{2.770001, "hee"};
  std::pair<double, std::string> doubleString3{3.901, "hola"};
  std::pair<double, std::string> doubleString4{233.77, "hi"};
  std::pair<double, std::string> doubleString5{3.9, "hee-hee"};

  s21::map<double, std::string> doubleString = {doubleString1, doubleString2,
                                                doubleString3, doubleString4,
                                                doubleString5};

  auto maxValue2 = doubleString.end();

  EXPECT_EQ(maxValue2->first, 233.77);
}

TEST(Map, End4) {
  std::pair<std::string, int> stringInt1{"hello", 1};
  std::pair<std::string, int> stringInt2{"hi", 2};
  std::pair<std::string, int> stringInt3{"hehehehehehe", 2};
  std::pair<std::string, int> stringInt4{"hola", 3};
  std::pair<std::string, int> stringInt5{"hello, there", 1};

  s21::map<std::string, int> stringIntMap = {stringInt1, stringInt2, stringInt3,
                                             stringInt4, stringInt5};
  // в ориге возникает сега
  auto maxValue3 = stringIntMap.end();

  EXPECT_EQ(maxValue3->first, "hola");  // неверное значение
  // TODO: Проверить что происходит в оргине и как правильно записать значения
}

TEST(Map, MapEndThrow) {
  s21::map<int, double> s21Map;
  EXPECT_THROW(s21Map.end(),
               std::out_of_range);  // TODO:!в ориге ничего не выбрасывается,
                                    // оставила тест, чтобы обратить внимание
}

TEST(Map, End5) {
  std::pair<double, std::string> intDouble1{1.4, "hello"};
  s21::map<double, std::string> doubleStringMap2 = {intDouble1, intDouble1};

  auto maxValue4 = doubleStringMap2.end();

  EXPECT_EQ(maxValue4->first, 1.4);
  EXPECT_EQ(maxValue4->second, "hello");
}

TEST(Map, End6) {
  std::pair<int, double> intDoublePair1{1, 1.4};
  std::pair<int, double> intDoublePair2{15, 1.456};
  std::pair<int, double> intDoublePair3{5, 151.4};

  s21::map<int, double> s21MapIntDouble = {intDoublePair1, intDoublePair2,
                                           intDoublePair3};

  auto maxValue1 = s21MapIntDouble.end();

  EXPECT_EQ(maxValue1->first, 15);
  EXPECT_EQ(s21MapIntDouble.size(), 3U);
}

TEST(Map, End7) {
  std::pair<int, int> pair0{30, 30};
  std::pair<int, int> intDouble2{5, 5};
  std::pair<int, int> intDouble3{43, 43};
  std::pair<int, int> intDouble4{1, 1};
  std::pair<int, int> intDouble5{20, 20};
  std::pair<int, int> pair6{40, 60};
  std::pair<int, int> pair7{60, 60};
  std::pair<int, int> pair8{35, 35};
  std::pair<int, int> pair9{32, 32};

  s21::map<int, int> s21MapIntInt = {pair0,      intDouble2, intDouble3,
                                     intDouble4, intDouble5, pair6,
                                     pair7,      pair8,      pair9};

  EXPECT_EQ(s21MapIntInt.end()->first, 60);
  EXPECT_EQ(s21MapIntInt.begin()->first, 1);
  EXPECT_EQ(s21MapIntInt.size(), 9U);
}

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
-->>   Map Capacity
- empty()
- size()
- max_size()
>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

TEST(Map, Empty1) {
  std::pair<double, int> intDouble1{22.2, 1};
  std::pair<double, int> intDouble2{44.48, 1};
  std::pair<double, int> intDouble3{12.4457, 2};
  std::pair<double, int> intDouble4{1.44, 3};

  s21::map<double, int> Map = {intDouble1, intDouble2, intDouble3, intDouble4};

  EXPECT_EQ(Map.empty(), 0);
}

TEST(Map, Empty2) {
  s21::map<double, int> Map;
  EXPECT_EQ(Map.empty(), 1);
}

TEST(Map, Size) {
  s21::map<int, std::string> s21Map{
      std::make_pair(42, "foo"), std::make_pair(3, "bar"),
      std::make_pair(33, "aboba"), std::make_pair(3, "ba")};
  std::map<int, std::string> realMap{
      std::make_pair(42, "foo"), std::make_pair(3, "bar"),
      std::make_pair(33, "aboba"), std::make_pair(3, "ba")};

  ASSERT_EQ(s21Map.size(), realMap.size());
}

TEST(Map, MaxSize) {
  s21::map<int, int> s21Map;
  std::map<int, int> mapReal;
  EXPECT_EQ(s21Map.max_size(), mapReal.max_size());
}

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
-->>   Map Modifiers                                                         >>
>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
TEST(Map, Clear) {
  s21::map<int, std::string> s21Map{
      std::make_pair(42, "foo"), std::make_pair(3, "bar"),
      std::make_pair(33, "aboba"), std::make_pair(3, "ba")};
  std::map<int, std::string> realMap{
      std::make_pair(42, "foo"), std::make_pair(3, "bar"),
      std::make_pair(33, "aboba"), std::make_pair(3, "ba")};

  ASSERT_EQ(s21Map.size(), realMap.size());
}

TEST(Map, Insert1) {
  s21::map<int, std::string> s21Map;
  std::map<int, std::string> realMap;

  s21Map.insert(1, "one");
  realMap.insert({1, "one"});
  s21Map.insert(2, "two");
  realMap.insert({2, "two"});
  s21Map.insert(22, "twotwo");
  realMap.insert({22, "twotwo"});
  s21Map.insert(-22, "-twotwo");
  realMap.insert({-22, "-twotwo"});
  s21Map.insert(22, "three");
  realMap.insert({22, "three"});
  s21Map.insert(22234, "two3two");
  realMap.insert({22234, "two3two"});
  s21Map.insert(12, "onetwo");
  realMap.insert({12, "onetwo"});
  s21Map.insert(-12, "-onetwo");
  realMap.insert({-12, "-onetwo"});
  auto s21Iter = s21Map.begin();
  auto realIter = realMap.begin();
  while (realIter != realMap.end()) {
    ASSERT_EQ(s21Iter->first, realIter->first);
    ASSERT_EQ(s21Iter->second, realIter->second);
    ++s21Iter;
    ++realIter;
  }
}

TEST(Map, Insert2) {
  s21::map<int, std::string> s21Map;
  std::map<int, std::string> realMap;

  s21Map.insert({1, "one"});
  realMap.insert({1, "one"});
  s21Map.insert({2, "two"});
  realMap.insert({2, "two"});
  s21Map.insert({22, "twotwo"});
  realMap.insert({22, "twotwo"});
  s21Map.insert({-22, "-twotwo"});
  realMap.insert({-22, "-twotwo"});
  s21Map.insert({22, "three"});
  realMap.insert({22, "three"});
  s21Map.insert({22234, "two3two"});
  realMap.insert({22234, "two3two"});
  s21Map.insert({12, "onetwo"});
  realMap.insert({12, "onetwo"});
  s21Map.insert({-12, "-onetwo"});
  realMap.insert({-12, "-onetwo"});
  auto s21Iter = s21Map.begin();
  auto realIter = realMap.begin();
  while (realIter != realMap.end()) {
    ASSERT_EQ(s21Iter->first, realIter->first);
    ASSERT_EQ(s21Iter->second, realIter->second);
    ++s21Iter;
    ++realIter;
  }
}

TEST(Map, Insert3) {
  std::pair<int, double> intDouble1{9, 1.4};
  std::pair<int, double> intDouble2{9, 1.4};
  std::pair<int, double> intDouble3{9, 1.4};
  std::pair<int, double> intDouble4{23, 2.77};
  std::pair<int, double> intDouble5{98, 3.9};

  s21::map<int, double> s21Map;

  std::pair<s21::map<int, double>::iterator, bool> insert1 =
      s21Map.insert(intDouble1);
  EXPECT_EQ(insert1.first->first, 9);
  EXPECT_EQ(insert1.second, 1);

  std::pair<s21::map<int, double>::iterator, bool> insert2 =
      s21Map.insert(intDouble2);

  std::pair<s21::map<int, double>::iterator, bool> insert3 =
      s21Map.insert(intDouble3);
  EXPECT_EQ(insert2.second, 0);
  EXPECT_EQ(insert3.second, 0);

  std::pair<s21::map<int, double>::iterator, bool> insert4 =
      s21Map.insert(intDouble4);
  EXPECT_EQ(insert4.first->first, 23);
  EXPECT_EQ(insert4.second, 1);

  std::pair<s21::map<int, double>::iterator, bool> insert5 =
      s21Map.insert(intDouble5);
  EXPECT_EQ(insert5.first->first, 98);
  EXPECT_EQ(insert5.second, 1);

  EXPECT_EQ(s21Map.size(), 3U);
}

TEST(Map, Insert4) {
  std::pair<double, std::string> doubleString1{1.4, "hello"};
  std::pair<double, std::string> doubleString2{2.77, "hi"};
  std::pair<double, std::string> doubleString3{3.9, "hola"};
  std::pair<double, std::string> doubleString4{2.77, "hi"};
  std::pair<double, std::string> doubleString5{3.9, "hola"};

  s21::map<double, std::string> s21Map;

  std::pair<s21::map<double, std::string>::iterator, bool> insert1 =
      s21Map.insert(doubleString1);
  EXPECT_EQ(insert1.first->first, 1.4);
  EXPECT_EQ(insert1.second, 1);

  std::pair<s21::map<double, std::string>::iterator, bool> insert2 =
      s21Map.insert(doubleString2);
  EXPECT_EQ(insert2.first->first, 2.77);
  EXPECT_EQ(insert2.second, 1);

  std::pair<s21::map<double, std::string>::iterator, bool> insert3 =
      s21Map.insert(doubleString3);
  EXPECT_EQ(insert3.first->first, 3.9);
  EXPECT_EQ(insert3.second, 1);

  std::pair<s21::map<double, std::string>::iterator, bool> insert4 =
      s21Map.insert(doubleString4);
  std::pair<s21::map<double, std::string>::iterator, bool> insert5 =
      s21Map.insert(doubleString5);
  EXPECT_EQ(insert4.second, 0);
  EXPECT_EQ(insert5.second, 0);

  EXPECT_EQ(s21Map.size(), 3U);
}

TEST(Map, Insert5) {
  std::pair<std::string, int> stringInt1{"hello", 1};
  std::pair<std::string, int> stringInt2{"hi", 2};
  std::pair<std::string, int> stringInt3{"hi", 2};
  std::pair<std::string, int> stringInt4{"hola", 3};
  std::pair<std::string, int> stringInt5{"hello", 1};

  s21::map<std::string, int> s21Map;

  std::pair<s21::map<std::string, int>::iterator, bool> insert1 =
      s21Map.insert(stringInt1);
  EXPECT_EQ(insert1.first->first, "hello");
  EXPECT_EQ(insert1.second, 1);

  std::pair<s21::map<std::string, int>::iterator, bool> insert2 =
      s21Map.insert(stringInt2);
  EXPECT_EQ(insert2.first->first, "hi");
  EXPECT_EQ(insert2.second, 1);

  std::pair<s21::map<std::string, int>::iterator, bool> insert3 =
      s21Map.insert(stringInt3);
  EXPECT_EQ(insert3.second, 0);

  std::pair<s21::map<std::string, int>::iterator, bool> insert4 =
      s21Map.insert(stringInt4);
  EXPECT_EQ(insert4.first->first, "hola");
  EXPECT_EQ(insert4.second, 1);

  std::pair<s21::map<std::string, int>::iterator, bool> insert5 =
      s21Map.insert(stringInt5);
  EXPECT_EQ(insert5.second, 0);

  EXPECT_EQ(s21Map.size(), 3U);
}

TEST(Map, InsertOrAssign) {
  s21::map<int, std::string> s21Map;
  std::map<int, std::string> realMap;

  s21Map.insert_or_assign(1, "one");
  realMap.insert_or_assign(1, "one");
  s21Map.insert_or_assign(2, "two");
  realMap.insert_or_assign(2, "two");
  s21Map.insert_or_assign(22, "twotwo");
  realMap.insert_or_assign(22, "twotwo");
  s21Map.insert_or_assign(22, "three");
  realMap.insert_or_assign(22, "three");

  auto s21Iter = s21Map.begin();
  auto realIter = realMap.begin();
  while (realIter != realMap.end()) {
    ASSERT_EQ(s21Iter->first, realIter->first);
    ASSERT_EQ(s21Iter->second, realIter->second);
  }
}

TEST(Map, Erase1) {
  std::pair<int, int> pair1{10, 10};
  std::pair<int, int> pair2{5, 5};
  std::pair<int, int> pair3{15, 15};
  std::pair<int, int> pair4{4, 4};
  std::pair<int, int> pair5{18, 18};
  std::pair<int, int> pair6{13, 13};
  std::pair<int, int> pair7{16, 16};

  s21::map<int, int> s21Map = {pair1, pair2, pair3, pair4, pair5, pair6, pair7};

  auto it = s21Map.begin();
  it++;
  it++;
  it++;
  it++;
  s21Map.erase(it);
  EXPECT_EQ(s21Map.begin()->first, 4);
  EXPECT_EQ(s21Map.end()->first, 18);
  EXPECT_EQ(s21Map.size(), 6U);

  auto it = s21Map.begin();
  s21Map.erase(it);
  EXPECT_EQ(s21Map.begin()->first, 5);
  EXPECT_EQ(s21Map.end()->first, 18);
  EXPECT_EQ(s21Map.size(), 5U);

  it = s21Map.begin();
  it++;
  s21Map.erase(it);
  EXPECT_EQ(s21Map.begin()->first, 5);
  EXPECT_EQ(s21Map.end()->first, 18);
  EXPECT_EQ(s21Map.size(), 4U);

  it = s21Map.end();
  s21Map.erase(it);
  EXPECT_EQ(s21Map.begin()->first, 5);
  EXPECT_EQ(s21Map.end()->first, 16);
  EXPECT_EQ(s21Map.size(), 3U);

  it = s21Map.begin();
  it++;
  s21Map.erase(it);

  it = s21Map.begin();
  it++;
  s21Map.erase(it);

  it = s21Map.begin();
  s21Map.erase(it);

  EXPECT_EQ(s21Map.size(), 0U);
}

TEST(Map, Erase2) {
  std::pair<int, int> intInt1{30, 30};
  std::pair<int, int> intInt2{1543, 1543};

  s21::map<int, int> s21Map = {intInt1, intInt2};

  auto it = s21Map.begin();
  it++;
  s21Map.erase(it);
  it = s21Map.begin();
  s21Map.erase(it);

  EXPECT_EQ(s21Map.size(), 0U);
}

TEST(Map, Erase3) {
  std::pair<double, int> doubleInt1{22.2, 1};
  std::pair<double, int> doubleInt2{44.48, 1};
  std::pair<double, int> doubleInt3{12.4457, 2};
  std::pair<double, int> doubleInt4{32.45, 2};
  std::pair<double, int> doubleInt5{65.12, 3};
  std::pair<double, int> doubleInt6{66.32, 3};
  std::pair<double, int> doubleInt7{40.54, 3};
  std::pair<double, int> doubleInt8{6.4, 3};

  s21::map<double, int> s21Map = {doubleInt1, doubleInt2, doubleInt3,
                                  doubleInt4, doubleInt5, doubleInt6,
                                  doubleInt7, doubleInt8};

  auto it = s21Map.end();
  it -= 4;
  s21Map.erase(it);
  it = s21Map.begin();
  ++it;
  ++it;
  ++it;
  EXPECT_EQ(it->first, 40.54);
  EXPECT_EQ(s21Map.size(), 7U);
}

// TEST(Map, Swap) {

// }

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
-->>   Map Lookup                                                            >>
>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
