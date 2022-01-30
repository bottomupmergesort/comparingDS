#ifndef LIST_DICT_HPP
#define LIST_DICT_HPP
#include "dict.hpp"

template <typename T, typename T2>
class ListDict : public Dict<T, T2> {
    private:
    struct node {
        T key;
        T2 value;
        node* next;
        node(T k, T2 v) : key(k), value(v) { next = nullptr; }
        node() { next = nullptr; }
    };
    node* head;
    int N;
    T2 nullItem; //for returning in failed searches.
    public:
    ListDict()
    {
        head = nullptr;
        N = 0;
        nullItem = NULL;
    }
    bool empty()
    {
        return head == nullptr;
    }
    void insert(T key, T2 value)
    {
        node* n = new node(key, value);
        if (n)
        {
            N++;
        } else {
            std::cout<<"Error: Out of memory.\n";
            return;
        }
        if (empty())
        {
            head = n;
            return;
        }
        n->next = head->next;
        head->next = n;
    }
    T2 find(T key)
    {
        for (node* itr = head; itr != nullptr; itr = itr->next)
        {
            if (key == itr->key)
                return itr->value;
        }
        return nullItem;
    }
    void remove(T key)
    {
        if (head->key == key)
        {
            head = head->next;
            N--;
            return;
        }
        for (node* itr = head; itr != nullptr; itr = itr->next)
        {
            if (key == itr->next->key)
            {
                itr->next = itr->next->next;
                N--;
                return;
            }
        }
    }
    int size()
    {
        return N;
    }
};


#endif