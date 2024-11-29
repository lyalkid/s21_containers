#include "stack.h"

template <class T>
s21::stack<T>::stack() : size_(0), head_(nullptr){}

template <class T>
s21::stack<T>::stack(const std::initializer_list<value_type> &items): size_(0), head_(nullptr)
{
 for(const auto &item : items){
     push(item);
 }
}

template <class T>
s21::stack<T>::stack(const stack &s) {
 Node *current = s.head_;
 while (current){
     push(current->data_);
     current = current->pNext;
 }
}

template <class T>
s21::stack<T>::stack(stack &&s): size_(s.size_), head_(s.head_) {
 s.size_ = 0;
 s.head_ = nullptr;
}

template <class T>
s21::stack<T>::~stack(){
    clear();
}

template <class T>
s21::stack<T> &s21::stack<T>::operator=(stack &&s) {
    if(this != s){
     this->head_ = s.head_;
     this->size_ = s.size_;

     s.head_ = nullptr;
     s.size_ = 0;
    }
    return  *this;
}

template <class T>
s21::stack<T> &s21::stack<T>::operator=(const stack &s) {
    if(this != &s){
     this->clear();

     Node *current = s.head_;
     while (current != nullptr){
         this->push(current->data_);
         current = current->pNext;
     }
    }
    return *this;
}

template <class T>
const T &s21::stack<T>::top(){
    return head_->data_;
}

template <class T>
bool s21::stack<T>::empty(){
    return size_ == 0 ? true : false;
}

template <class T>
size_t s21::stack<T>::size() {
    return size_;
}

template <class T>
void s21::stack<T>::push(const_reference value){
    Node *new_node = new Node(value, head_);
    if(head_ == nullptr){
     head_ = new_node;
    }else{
     new_node->pNext = head_;
     head_ = new_node;
    }
    ++size_;
}

template <class T>
void s21::stack<T>::pop(){
    Node *next_node = head_->pNext;
    delete head_;
    head_ = next_node;
}


template <class T>
void s21::stack<T>::swap(stack& other){
    std::swap(head_, other.head_);
    std::swap(size_, other.size_);
}

template <class T>
void s21::stack<T>::clear(){
    Node *current = head_;
    while (current != nullptr){
        Node *next_node = current->pNext;
        delete current;
        current = next_node;
    }
    head_ = nullptr;
    size_ = 0;
}