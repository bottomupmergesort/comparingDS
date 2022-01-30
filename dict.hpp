#ifndef DICT_HPP
#define DICT_HPP

//virtual class defining the dictionary
//abstract data ty[e interface
template <typename T, typename T2>
class Dict {
    public:
    virtual void insert(T key, T2 value) = 0;
    virtual void remove(T key) = 0;
    virtual T2 find(T key) = 0;
    virtual int size() = 0;
};

#endif