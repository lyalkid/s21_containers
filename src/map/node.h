#ifndef NODE_H
#define NODE_H

template <typename T>
class Node {
 private:
  T value;
  Node* right;
  Node* left;

 public:
  Node(/* args */);
  Node(T value);
  Node(T value, Node* right, Node* left);
  Node(T value, Node* right);


  // getters, setters
  T get_value();
  Node* get_r();
  Node* get_l();
  void set_value(T value);

  ~Node();
};

template <typename T>
T Node<T>::get_value() {
  return value;
}
template <typename T>
void Node<T>::set_value(T value) {
  this->value = value;
}

template <typename T>
Node<T>* Node<T>::get_r() {
  return right;
}

template <typename T>
Node<T>* Node<T>::get_l() {
  return left;
}
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

template <typename T>
Node<T>::Node(T value, Node* right, Node* left) {
  this->value = value;
  this->left = left;
  this->right = right;
}

//

template <typename T>
Node<T>::~Node() {}

#endif