#ifndef BST_HPP
#define BST_HPP

#include <iostream>
using namespace std;

template<typename T, typename Compare = less<T>>
class bst{
private:
    struct node{
        T value;
        node* left;
        node* right;
        node(T value) : value(value), left(nullptr), right(nullptr) {}
    };

    node* root;
    Compare comp;

    void insert(node*& current, T value);
    node* findMin(node* current);
    node* remove(node* current, T value);
    node* find(node* current, T value) const;
    void copyTree(node*& this_tree, node* other_tree);
    void deleteTree(node* current);
    void print(node* current, ostream& os) const ;
public:
    bst();
    bst(const initializer_list<T>& list);
    bst(const bst& other);
    bst(bst&& other) noexcept;
    bst& operator=(const bst& other);
    bst& operator=(bst&& other) noexcept;
    template<typename U, typename C>
    friend ostream& operator<<(ostream& os, const bst<U, C>& tree);
    void insert(T value);
    void remove(T value);
    bool find(T value);
    ~bst();
};

template<typename T, typename Compare>
ostream& operator<<(ostream& os, const bst<T, Compare>& tree) {
    tree.print(tree.root, os);
    return os;
}

template<typename T>
struct deref_less {
    bool operator()(const T *a, const T *b) const {
        return *a < *b;
    };
};
template<typename T>
struct deref_greater {
    bool operator()(const T *a, const T *b) const {
        return *a > * b;
    }
};

#include "bst_impl.hpp"

#endif

