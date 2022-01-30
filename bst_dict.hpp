#ifndef BST_DICT_HPP
#define BST_DICT_HPP
#include "dict.hpp"

template <typename T, typename T2>
class TreeDict : Dict<T, T2>
{
    struct node {
        T key;
        T2 value;
        node* left;
        node* right;
        node(T k, T2 v) : key(k), value(v) {  left = nullptr; right = nullptr; }
        node() { }
    };
    node* root;
    int N;
    T2 nullItem;
    public:
    TreeDict()
    {
        N = 0;
        root = nullptr;
    }
    int size()
    {
        return N;
    }
    bool empty() { root == nullptr; }
    void insert(T key, T2 value)
    {
        node* x = root;
        node* p = x;
        while (x != nullptr)
        {
            p = x;
            x = (key < x->key) ? x->left:x->right;
        }
        x = new node(key, value);
        if (root == nullptr)
        {
            root = x;
            return;
        }
        if (key < p->key) p->left = x;
        else p->right = x;
    }
    T2 find(T key)
    {
        node *x = root;
        while (x != nullptr)
        {
            if (key == x->key)
               return x->value;
            x = (key < x->key) ? x->left:x->right;
        }
        return nullItem;
    }
    void remove(T key)
    {
        //removed for brevity
    }
};


#endif