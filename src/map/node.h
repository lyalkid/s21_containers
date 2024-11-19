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

  // getters, setters
  T get_value();
  Node* get_r();
  Node* get_l();
  void set_value(T value);


  ~Node();
};

#include "node.tpp"
#endif