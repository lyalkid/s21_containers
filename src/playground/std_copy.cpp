#include <iostream>
#include <iterator>
#include <vector>

using namespace std;
//copy(<первый>, <последний>, <операции>);
//операции:вывод элементов, добавление элементов, копирование элементов
// вывод: copy(ilist.begin(), ilist.end(), ostream_iterator<int>(cout," "));
// добавление: copy(<первый>,<последний>, inserter(<имя контейнера>, <итератор>));
//copy(map_first.begin(), map_first.end(), inserter(map_second, map_second.begin()));
//back_inserter(), front_inserter
// копирование: copy(ilist.begin(), ilist.end(), ivec.begin());
int main() {
  setlocale(0, "");

  vector <int> v;       // создали два
  vector <int> answer;  // вектора

  v.push_back(1);  
  v.push_back(2);  
  v.push_back(3);  

  answer.push_back(0);
  answer.push_back(10);
    
  cout << "вектор answer до использования copy: ";
  copy(answer.begin(), answer.end(), ostream_iterator<int>(cout , " "));
  cout << endl;  

  vector <int> :: iterator it = answer.begin(); // сделали итератор it который
  it++;                                         // указывает на начала answer
                                                  
  copy(v.begin(), v.end(), it);   // изменили значения 
    
  cout << "вектор answer после оперирования методом copy: ";
  copy(answer.begin(), answer.end(), ostream_iterator<int>(cout , " "));  // вывели все
                                                                       // элементы
  system("pause");
  return 0;
}