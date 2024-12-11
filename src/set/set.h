
#ifndef S21_SET_H
#define S21_SET_H

#include "../map_with_unique_ptr/include/btree.h"

namespace s21 {
    template<typename Key, typename V>
    class set {
    public:
        using key_type = Key;
        using mapped_type = std::pair<key_type, bool>;;
        using value_type = Key;
        using node_type = btree_node<Key, V>;
        using reference = value_type &;
        using const_reference = const value_type &;
        using iterator = btree_iterator<Key, V>;
        using const_iterator = const iterator;
        using size_type = size_t;
        using insert_type = std::pair<iterator, bool>;
        using insert_many_type = s21::vector<std::pair<iterator, bool>>;
        using tree_type = btree<Key, V>;

        set() {
            tree_ = std::make_shared<tree_type>();
            size_ = 0;
        }

        set(std::initializer_list<value_type> const &items) : set() {
            auto it = items.begin();
            while (it != items.end()) {
                // std::cout << "im in items"<< std::endl;
                insert(*it++);
            }
        }

        set(const set &m) : tree_(m.tree_), size_(m.size_) {}

        set(set &&m) noexcept {
            tree_ = std::move(m.tree_);
            size_ = std::move(m.size_);

            // todo: во всех конструкторах перемещения сделать обнуление параметров
            m.tree_ = nullptr;
            m.size_ = 0;
        }

        set &operator=(const set &other) {
            if (this != &other) {
                tree_ = other.tree_;
                size_ = other.size_;
            }
            return *this;
        }

        set &operator=(set &&other) noexcept {
            if (this != &other) {
                tree_ = std::move(other.tree_);
                size_ = std::move(other.size_);

                // todo: во всех операторах перемещения сделать обнуление параметров
                other.tree_ = nullptr;
                other.size_ = 0;
            }
            return *this;
        }

        ~set() = default;


        iterator begin() { return tree_->begin(); }

        iterator end() { return tree_->end(); }

        bool empty() const { return size_ == 0 || tree_ == nullptr; }

        size_type size() const { return size_; }

        size_type max_size() const { return tree_->max_size(); }

        void clear() {
            tree_->clear();
            size_ = 0;
        }


        std::pair<iterator, bool> insert(const value_type &value);

        void erase(iterator pos) {
            if (pos != end()) {
                tree_->remove(pos->first);
                size_ = tree_->size();

                //  pos.current_node_.reset();
            }
        }

        void swap(set &other) {
            std::swap(tree_, other.tree_);
            std::swap(size_, other.size_);
        }

        void merge(set &other) {
            for (auto iter = other.begin(); !other.empty() && iter != other.end();
                 iter++) {
                if (!contains(iter.current_node_->data.first)) {
                    insert(iter.current_node_->data.first);
                    other.erase(iter);
                }
            }
        }


        iterator find(const Key &key){
            return tree_->search(key);
        }

        bool contains(const Key &key){
            return (tree_ != nullptr && tree_->contains(key));
        }

    private:
        size_type size_;
        shared_ptr<tree_type> tree_;

        insert_type insert_helper(const key_type &key, const V &obj);
    };
}  // namespace s21
#include "set.tpp"

#endif