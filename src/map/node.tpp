#include "node.h"

// Constructors
template <typename T>
Node<T>::Node() {
  value = 0;
  right = nullptr;
  left = nullptr;
}

template <typename T>
Node<T>::Node(T value) {
  this->value = value;
  right = nullptr;
  left = nullptr;
}

// Destructor
template <typename T>
Node<T>::~Node() {}


// Getter, setters
template <typename T>
T Node<T>::get_value() {
  return value;
}


