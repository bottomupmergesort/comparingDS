#ifndef SORTED_ARRAY_DICT_HPP
#define SORTED_ARRAY_DICT_HPP
#include "dict.hpp"

template <typename T>
void swap(T& a, T& b)
{
    T tmp = a;
    a = b;
    b = tmp;
}

template <typename T, typename T2>
class ArrayDict : Dict<T, T2> {
    private:
    struct node {
        T key;
        T2 value;
        node(T k, T2 v) : key(k), value(v) { }
        node() { }
       /* node operator=(node& other) {
            key = other.key;
            value = other.value;
            return *this;
        }*/
    };
    void sort_arr()
    {
        int i, j;
        node v;
        for (i = 0; i < N; i++)
        {
            j = i;
            v = arr[j];
            while ((j>0) && (arr[j-1].key > v.key))
            {
                arr[j] = arr[j-1];
                j--;
            }
            arr[j] = v;
        }
    }
    node *arr;
    T2 nullItem; //for failed searches;
    int N;
    public:
    ArrayDict()
    {
        arr = new node[1000]; //One problem with using array based dictionary: statically sized arrays.
        N = 0;
        nullItem = NULL;
    }
    void insert(T key, T2 value)
    {
        if (N < 1000)
        {
            arr[N++] = node(key, value);
            sort_arr();
        }
    }
    int size()
    {
        return N;
    }
    T2 find(T key)
    {
        int h = N;
        int l = 0;
        while (l < h)
        {
            int mid = (l+h) / 2;
            if (key == arr[mid].key)
                return arr[mid].value;
            if (key < arr[mid].key) h = mid - 1;
            else l = mid + 1;
        }
        return nullItem;
    }
    void remove(T key)
    {
        int to_del = find(key);
        swap(arr[to_del], arr[N--]);
        sort_arr();
    }
};

#endif