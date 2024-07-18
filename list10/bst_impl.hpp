#ifndef BST_IMPL
#define BST_IMPL

#include <iostream>
#include "bst.hpp"
using namespace std;

template<typename T, typename Compare>
void bst<T, Compare>::insert(node*& current, T value){
    if (current == nullptr){
        current = new node(value);
    }
    else if (comp(value, current->value)){
        insert(current->left, value);
    }
    else{
        insert(current->right, value);
    }
}
template<typename T, typename Compare>
typename bst<T, Compare>::node* bst<T, Compare>::findMin(node* current){
    if(current->left == nullptr) return current;
    else findMin(current->left);
}
template<typename T, typename Compare>
typename bst<T, Compare>::node* bst<T, Compare>::remove(node* current, T value){
    if (current == nullptr) return nullptr;
    else if (comp(value, current->value)){
        current->left = remove(current->left, value);
    }
    else if (comp(current->value, value)){
        current->right = remove(current->right, value);
    }
    else{
        if (current->left == nullptr){
            node* temp = current->right;
            delete current;
            return temp;
        }
        else if (current->right == nullptr){
            node* temp = current->left;
            delete current;
            return temp;
        }
        else{
            node* temp = findMin(current->right);
            current->value = temp->value;
            current->right = remove(current->right, current->value);
        }
    }
    return current;
}
template<typename T, typename Compare>
typename bst<T, Compare>::node* bst<T, Compare>::find(node* current, T value) const {
    if (current == nullptr || current->value == value) return current;
    else if (comp(value, current->value)) {
        return find(current->left, value);
    }
    else {
        return find(current->right, value);
    }
}
template<typename T, typename Compare>
void bst<T, Compare>::copyTree(node*& this_tree, node* other_tree){
    if (other_tree == nullptr) this_tree == nullptr;
    else {
        this_tree = new node(other_tree->value);
        copyTree(this_tree->left, other_tree->left);
        copyTree(this_tree->right, other_tree->right);
    }
}
template<typename T, typename Compare>
void bst<T, Compare>::deleteTree(node* current){
    if (current != nullptr){
        deleteTree(current->left);
        deleteTree(current->right);
        delete current;
    }
}
template<typename T, typename Compare>
void bst<T, Compare>::print(node* current, ostream& os) const {
    if (current == nullptr) return;
    print(current->left, os);
    os << current->value << " ";
    print(current->right, os);
}
template<typename T, typename Compare>
bst<T, Compare>::bst() : root(nullptr), comp(Compare()) {}

template<typename T, typename Compare>
bst<T, Compare>::bst(const initializer_list<T>& list) : root(nullptr), comp(Compare()) {
    for (const auto& v : list){
        insert(root, v);
    }
}
template<typename T, typename Compare>
bst<T, Compare>::bst(const bst& other) : root(nullptr), comp(other.comp) {
    copyTree(root, other.root);
}
template<typename T, typename Compare>
bst<T, Compare>::bst(bst&& other) noexcept : root(other.root), comp(other.comp) {
    deleteTree(other.root);
}
template<typename T, typename Compare>
bst<T, Compare>& bst<T, Compare>::operator=(const bst& other){
    if (this != &other){
        deleteTree(root);
        root = nullptr;
        copyTree(root, other.root);
    }
    return *this;
}
template<typename T, typename Compare>
bst<T, Compare>& bst<T, Compare>::operator=(bst&& other) noexcept{
    if (this != &other){
        deleteTree(root);
        root = other.root;
        deleteTree(other.root);
    }
    return *this;
}

template<typename T, typename Compare>
void bst<T, Compare>::insert(T value){
    insert(root, value);
}
template<typename T, typename Compare>
void bst<T, Compare>::remove(T value){
    root = remove(root, value);
}
template<typename T, typename Compare>
bool bst<T, Compare>::find(T value){
    return find(root, value) != nullptr;
}
template<typename T, typename Compare>
bst<T, Compare>::~bst(){
    deleteTree(root);
}

#endif




