
#ifndef CONTAINERS_BTREE_ITERATOR_H
#define CONTAINERS_BTREE_ITERATOR_H

#include "../../stack/stack.h"
#include "btree_node.h"

namespace s21 {
template <typename Key, typename T>
class map;

template <typename K, typename V>
class btree_node;

template <typename K, typename V>
class btree;

template <typename K, typename V>
class btree_iterator {
 public:
  using node_type = btree_node<K, V>;
  using node_ptr = std::shared_ptr<node_type>;
  using value_type = std::pair<const K, V>;
  using reference = value_type &;
  using pointer = value_type *;

  // default constructor
  btree_iterator()
      : data(std::make_pair(K{}, V{})),
        current_node_(nullptr),
        root_(nullptr) {};

  // init iterator
  btree_iterator(node_type *node) : current_node_(node) {
    if (node)
      data = std::make_pair(K{node->data.first}, V{node->data.second});
    else
      data = std::make_pair(K{}, V{});
  };

  // copy constructor
  btree_iterator(const btree_iterator &other)
      : data(std::make_pair(K{other.data.first}, V{other.data.second})),
        current_node_(other.current_node_),
        root_(other.root_) {};

  // move constructor
  btree_iterator(btree_iterator &&other) noexcept {
    data = std::move(other.data);
    current_node_ = std::move(other.current_node_);
    root_ = std::move(other.root_);

    other.data = std::make_pair(K{}, V{});
    other.current_node_ = nullptr;
    root_ = nullptr;
  };

  // destructor
  ~btree_iterator() = default;

  // constructor for end
  btree_iterator(node_type *current_node, node_ptr root)
      : data(std::make_pair(K{}, V{})),
        current_node_(current_node),
        root_(root) {};

  btree_iterator &operator=(const btree_iterator &other) {
    if (this != &other) {
      data = other.data;
      current_node_ = other.current_node_;
      root_ = other.root_;
    }
    return *this;
  }

  btree_iterator &operator=(btree_iterator &&other) noexcept {
    if (this != &other) {
      data = std::move(other.data);
      current_node_ = std::move(other.current_node_);
      root_ = std::move(other.root_);
      other.data = std::make_pair(K{}, V{});
      other.current_node_ = nullptr;
      root_ = nullptr;
    }
    return *this;
  }

  // increment
  btree_iterator &operator++() {
    if (current_node_ != nullptr)
      current_node_ = current_node_->next(current_node_);
    return *this;
  }

  btree_iterator operator++(int) {
    //    btree_iterator temp = *this;
    ++(*this);
    return *this;
  }

  // decrement
  btree_iterator &operator--() {
    if (current_node_ == nullptr) {
      current_node_ = root_->findMax(root_.get());
    } else {
      current_node_ = current_node_->prev(current_node_);
    }
    return *this;
  }

  btree_iterator operator--(int) {
    //    btree_iterator temp = *this;
    --(*this);

    return *this;
  }

  bool operator==(const btree_iterator &other) {
    return current_node_ == other.current_node_;
  }

  bool operator!=(const btree_iterator &other) {
    return current_node_ != other.current_node_;
  }

  reference operator*() const { return data; }

  value_type *operator->() const { return &(data); }

  friend class btree<K, V>;
  friend class btree_node<K, V>;

 private:
  std::pair<const K, V> data;

  // protected:

  node_type *current_node_;
  node_ptr root_;
};

}  // namespace s21
#include "../impl/btree_iterator.tpp"

/*
 * ====================[ Build | containers | Debug
]==============================
/Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake --build
/Users/sionapae/CPP2_s21_containers-1/cmake-build-debug --target containers -j 4
[1/2] Building CXX object
CMakeFiles/containers.dir/src/map_with_unique_ptr/main.cpp.o FAILED:
CMakeFiles/containers.dir/src/map_with_unique_ptr/main.cpp.o
/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++
-g -std=gnu++17 -isysroot
/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX14.2.sdk
-mmacosx-version-min=13.6 -fcolor-diagnostics -MD -MT
CMakeFiles/containers.dir/src/map_with_unique_ptr/main.cpp.o -MF
CMakeFiles/containers.dir/src/map_with_unique_ptr/main.cpp.o.d -o
CMakeFiles/containers.dir/src/map_with_unique_ptr/main.cpp.o -c
/Users/sionapae/CPP2_s21_containers-1/src/map_with_unique_ptr/main.cpp In file
included from
/Users/sionapae/CPP2_s21_containers-1/src/map_with_unique_ptr/main.cpp:7: In
file included from
/Users/sionapae/CPP2_s21_containers-1/src/map_with_unique_ptr/include/btree.h:10:
/Users/sionapae/CPP2_s21_containers-1/src/map_with_unique_ptr/include/btree_iterator.h:36:12:
error: object of type 'std::pair<const int, int>' cannot be assigned because its
copy assignment operator is implicitly deleted data =
std::make_pair(K{node->data.first}, V{node->data.second});
           ^
/Users/sionapae/CPP2_s21_containers-1/src/map_with_unique_ptr/include/../impl/s21_map.tpp:94:12:
note: in instantiation of member function 's21::btree_iterator<int,
int>::btree_iterator' requested here iterator
it(tree_->find_helper(tree_->bt_root_, key).get());
           ^
/Users/sionapae/CPP2_s21_containers-1/src/map_with_unique_ptr/include/../impl/s21_map.tpp:83:10:
note: in instantiation of member function 's21::map<int, int>::insert_helper'
requested here return insert_helper(key, obj);
         ^
/Users/sionapae/CPP2_s21_containers-1/src/map_with_unique_ptr/main.cpp:120:19:
note: in instantiation of member function 's21::map<int, int>::insert' requested
here auto res = tree.insert(10, 100);
                  ^
/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX14.2.sdk/usr/include/c++/v1/__utility/pair.h:75:5:
note: copy assignment operator is implicitly deleted because 'pair<const int,
int>' has a user-declared move constructor pair(pair&&) = default;
    ^
In file included from
/Users/sionapae/CPP2_s21_containers-1/src/map_with_unique_ptr/main.cpp:7: In
file included from
/Users/sionapae/CPP2_s21_containers-1/src/map_with_unique_ptr/include/btree.h:10:
/Users/sionapae/CPP2_s21_containers-1/src/map_with_unique_ptr/include/btree_iterator.h:49:10:
error: object of type 'std::pair<const int, int>' cannot be assigned because its
copy assignment operator is implicitly deleted data = std::move(other.data);
         ^
/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX14.2.sdk/usr/include/c++/v1/__utility/pair.h:75:5:
note: in instantiation of member function 's21::btree_iterator<int,
int>::btree_iterator' requested here pair(pair&&) = default;
    ^
/Users/sionapae/CPP2_s21_containers-1/src/map_with_unique_ptr/include/../impl/s21_map.tpp:83:10:
note: in instantiation of member function 's21::map<int, int>::insert_helper'
requested here return insert_helper(key, obj);
         ^
/Users/sionapae/CPP2_s21_containers-1/src/map_with_unique_ptr/main.cpp:120:19:
note: in instantiation of member function 's21::map<int, int>::insert' requested
here auto res = tree.insert(10, 100);
                  ^
/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX14.2.sdk/usr/include/c++/v1/__utility/pair.h:75:5:
note: copy assignment operator is implicitly deleted because 'pair<const int,
int>' has a user-declared move constructor pair(pair&&) = default;
    ^
In file included from
/Users/sionapae/CPP2_s21_containers-1/src/map_with_unique_ptr/main.cpp:7: In
file included from
/Users/sionapae/CPP2_s21_containers-1/src/map_with_unique_ptr/include/btree.h:10:
/Users/sionapae/CPP2_s21_containers-1/src/map_with_unique_ptr/include/btree_iterator.h:53:16:
error: object of type 'std::pair<const int, int>' cannot be assigned because its
copy assignment operator is implicitly deleted other.data = std::make_pair(K{},
V{});
               ^
/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX14.2.sdk/usr/include/c++/v1/__utility/pair.h:75:5:
note: copy assignment operator is implicitly deleted because 'pair<const int,
int>' has a user-declared move constructor pair(pair&&) = default;
    ^
In file included from
/Users/sionapae/CPP2_s21_containers-1/src/map_with_unique_ptr/main.cpp:8: In
file included from
/Users/sionapae/CPP2_s21_containers-1/src/map_with_unique_ptr/include/s21_map.h:73:
/Users/sionapae/CPP2_s21_containers-1/src/map_with_unique_ptr/include/../impl/s21_map.tpp:75:12:
error: no matching constructor for initialization of 'iterator' (aka
'btree_iterator<int, int>') iterator it(tree_->find_helper(tree_->bt_root_,
value.first).get()); ^  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/Users/sionapae/CPP2_s21_containers-1/src/map_with_unique_ptr/include/../impl/s21_map.tpp:64:11:
note: in instantiation of member function 's21::map<int, int>::insert' requested
here return (insert(std::make_pair(key, T())).first)->second;
          ^
/Users/sionapae/CPP2_s21_containers-1/src/map_with_unique_ptr/main.cpp:129:17:
note: in instantiation of member function 's21::map<int, int>::operator[]'
requested here auto op = tree[10];
                ^
/Users/sionapae/CPP2_s21_containers-1/src/map_with_unique_ptr/include/btree_iterator.h:42:3:
note: candidate constructor not viable: no known conversion from 'element_type
*' (aka 's21::btree_node<int, int> *') to 'const btree_iterator<int, int>' for
1st argument btree_iterator(const btree_iterator &other)
  ^
/Users/sionapae/CPP2_s21_containers-1/src/map_with_unique_ptr/include/btree_iterator.h:28:3:
note: candidate constructor not viable: requires 0 arguments, but 1 was provided
  btree_iterator()
  ^
/Users/sionapae/CPP2_s21_containers-1/src/map_with_unique_ptr/include/btree_iterator.h:62:3:
note: candidate constructor not viable: requires 2 arguments, but 1 was provided
  btree_iterator(node_type *current_node, node_ptr root)
  ^
/Users/sionapae/CPP2_s21_containers-1/src/map_with_unique_ptr/include/btree_iterator.h:78:12:
error: object of type 'std::pair<const int, int>' cannot be assigned because its
copy assignment operator is implicitly deleted data = std::move(other.data);
           ^
/Users/sionapae/CPP2_s21_containers-1/src/map_with_unique_ptr/main.cpp:139:10:
note: in instantiation of member function 's21::btree_iterator<int,
int>::operator=' requested here for (i = tree.begin(); i != tree.end(); i++) {
         ^
/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX14.2.sdk/usr/include/c++/v1/__utility/pair.h:75:5:
note: copy assignment operator is implicitly deleted because 'pair<const int,
int>' has a user-declared move constructor pair(pair&&) = default;
    ^
In file included from
/Users/sionapae/CPP2_s21_containers-1/src/map_with_unique_ptr/main.cpp:7: In
file included from
/Users/sionapae/CPP2_s21_containers-1/src/map_with_unique_ptr/include/btree.h:10:
/Users/sionapae/CPP2_s21_containers-1/src/map_with_unique_ptr/include/btree_iterator.h:81:18:
error: object of type 'std::pair<const int, int>' cannot be assigned because its
copy assignment operator is implicitly deleted other.data = std::make_pair(K{},
V{});
                 ^
/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX14.2.sdk/usr/include/c++/v1/__utility/pair.h:75:5:
note: copy assignment operator is implicitly deleted because 'pair<const int,
int>' has a user-declared move constructor pair(pair&&) = default;
    ^
In file included from
/Users/sionapae/CPP2_s21_containers-1/src/map_with_unique_ptr/main.cpp:7: In
file included from
/Users/sionapae/CPP2_s21_containers-1/src/map_with_unique_ptr/include/btree.h:10:
/Users/sionapae/CPP2_s21_containers-1/src/map_with_unique_ptr/include/btree_iterator.h:128:43:
error: cannot initialize return object of type 'value_type *' (aka 'pair<const
int, int> *') with an rvalue of type 'const std::pair<const int, int> *'
  value_type *operator->() const { return &(data); }
                                          ^~~~~~~
/Users/sionapae/CPP2_s21_containers-1/src/map_with_unique_ptr/main.cpp:140:19:
note: in instantiation of member function 's21::btree_iterator<int,
int>::operator->' requested here std::cout << i->first << std::endl;
                  ^
7 errors generated.
ninja: build stopped: subcommand failed.

 * */
#endif  // CONTAINERS_BTREE_ITERATOR_H
