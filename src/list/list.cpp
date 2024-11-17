#include "list.h"

namespace s21{
    template <class T>
//List Functions
    s21::list<T>::list() : size_(0), head(nullptr), tail(nullptr){}

    template<class T>
    s21::list<T>::~list() {
    Node *current = head;
    while(current){
        Node *next = current->pNext;
        delete current;
        current = next;
    }
    }
}
//List Modifiers


