#include <iostream>
#include <chrono>
#include "sorted_array_dict.hpp"
#include "list_dict.hpp"
#include "bst_dict.hpp"
using namespace std;


void usinglist()
{
    ListDict<int, int> dict;
    for (int i = 0; i < 1000; i++)
        dict.insert(rand()%1000, rand()%1000);

    cout<<"Inserts: "<<dict.size()<<"\n";
    int success = 0;
    for (int i = 0; i < 500; i++)
    {
        if (dict.find(rand() % 500))
          success++;
    }
    cout<<"Successful searches: "<<success<<"\n";
}

void usingarray()
{
        ArrayDict<int, int> dict;
    for (int i = 0; i < 1000; i++)
        dict.insert(rand()%1000, rand()%1000);

    cout<<"Inserts: "<<dict.size()<<"\n";
    int success = 0;
    for (int i = 0; i < 500; i++)
    {
        if (dict.find(rand() % 500))
          success++;
    }
    cout<<"Successful searches: "<<success<<"\n";
}

void usingbst()
{
    TreeDict<int, int> dict;
    for (int i = 0; i < 1000; i++)
        dict.insert(rand()%1000, rand()%1000);

    cout<<"Inserts: "<<dict.size()<<"\n";
    int success = 0;
    for (int i = 0; i < 500; i++)
    {
        if (dict.find(rand() % 500))
          success++;
    }
    cout<<"Successful searches: "<<success<<"\n";
}

void timed_run(void (*example)())
{
    auto t1 = std::chrono::system_clock::now();
    example();
    auto t2 = std::chrono::system_clock::now();
    std::chrono::duration<double, std::milli> timing = t2 - t1;
    cout<<"Time: "<<timing.count()<<"\n";
}

int main()
{
    cout<<"Linked list: \n";
    timed_run(usinglist);
    cout<<"Sorted array: \n";
    timed_run(usingarray);
    cout<<"Binary Search Tree: \n";
    timed_run(usingbst);
    return 0;
}