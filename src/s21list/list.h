#ifndef CPP_S21_CONTAINERS_1_SRC_LIST_LIST_H_
#define CPP_S21_CONTAINERS_1_SRC_LIST_LIST_H_

#include <iostream>
#include <limits>

namespace s21 {
    template <typename T>
class list {
public:

    //list Member type
    using ValueType = T;
    using Reference = T&;
    using ConstReference = const T&;
    using SizeType = std::size_t;

    //iterator
    class listIterator;
    using iterator = list<T>::listIterator;
    using ConstIterator = const list<T>::listIterator;

    //list Functions
    list();
    list(SizeType n);
    list(std::initializer_list<ValueType> const& items);
    list(const list& l) noexcept;
    list(list&& l) noexcept;
    ~list();

    //Operators
    list &operator=(const list& l);
    list &operator=(list&& l);
    bool operator==(list const& l);
    bool operator!=(list const& l);

    //list Element access
    ConstReference front() const;
    ConstReference back() const;

    //list Iterators
    iterator begin();
    iterator end();

    //list Capacity
    bool empty() const;
    SizeType size() const;
    SizeType max_size() const;

    //list Modifiers
    void clear();
    iterator insert(iterator pos, ConstReference value);
    void erase(iterator pos);
    void push_back(ConstReference value);
    void pop_back();
    void push_front(ConstReference value);
    void pop_front();
    void swap(list & other) noexcept;
    void merge(list & other) noexcept;
    void splice(ConstIterator pos, list & other);
    void reverse() noexcept;
    void unique();
    void sort();

protected:
    //list' node
    class Node{
    public:
        T data_;
        Node* p_next_;
        Node*p_prev_;
        Node(const T& data = T(), Node *p_next = nullptr, Node *p_prev = nullptr)
            : data_(data), p_next_(p_next), p_prev_(p_prev){}
    };
    Node *head_;
    Node *tail_;
    SizeType size_;

public:
    //iterator
    class listIterator {
    public:
        listIterator(Node* node = nullptr) : current_(node) {};

        Reference operator *() const {return current_->data_;}
//TODO:: добавить обработку на итерацию с последнего/первого элемента
        listIterator& operator++(){
        if(current_) current_ = current_->p_next_;
        return *this;
    }

    listIterator& operator--(){
        if(current_) current_ = current_->p_prev_;
        return *this;
    }

    Node* GetCurrent() const { return current_;}

    bool operator==(const iterator& other) const {return current_ == other.current_;}
    bool operator!=(const iterator& other) const {return current_ != other.current_;}

private:
        Node*current_;
    };
};
} // namespace s21

#include "list.tpp"

#endif // CPP_S21_CONTAINERS_1_SRC_LIST_LIST_H_
