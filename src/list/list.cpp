#include "list.h"

namespace s21{
    template <class T>
//List Functions
    s21::list<T>::list() : size_(0), head(nullptr), tail(nullptr){}

    template <class T>
    s21::list<T>::list(const std::initializer_list<value_type> &items) : size_(0), head(nullptr), tail(nullptr){
        for(const auto& item : items){
            push_back(item);
        }
    }

    template <class T>
    s21::list<T>::list(const list &l){
    if(l.head == nullptr){
            head = nullptr;
            tail = nullptr;
            size_ = 0;
    }else{
            head = new Node;

    }




    }

    template<class T>
    s21::list<T>::~list() {
    Node *current = head;
    while(current){
        Node *next = current->pNext;
        delete current;
        current = next;
    }
    }


    //List Modifiers
    template <class T>
    void s21::list<T>::push_back(const_reference value) {
    Node *new_node = head;
    if(head == nullptr){
        head = tail = new_node;
    }else{
        tail->pNext = new_node;
        new_node->pPrev = tail;
        tail = new_node;
    }
    ++size_;
    }

    template <class T>
    void s21::list<T>::pop_back(){
    if(head == nullptr){
        throw std::out_of_range("Empty list");
    }
    if(head == tail){
        delete head;
        head = tail = nullptr;
    }else{
        Node *tmp = tail->pPrev;
        delete tail;
        tmp->pNext = nullptr;
        tail = tmp;
    }
    --size_;
    }

    template <class T>
    void s21::list<T>::push_front(const_reference value){
    Node *new_node = head;
    if(head == nullptr){
        head = tail = new_node;
    }else{
        head->pPrev = new_node;
        new_node->pNext = head;
        head = new_node;
    }
    ++size_;
    }

    template <class T>
    void s21::list<T>::pop_front(){
    if(head == nullptr){
        throw std::out_of_range("Empty list");
    }
    if(head==tail){
       delete head;
       head = tail = nullptr;
    }else{
       Node *tmp = head->pNext;
       delete head;
       tmp->pPrev = nullptr;
       head = tmp;
    }
    --size_;
    }


}//namespace s21



