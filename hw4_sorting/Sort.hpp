#ifndef Sort_hpp
#define Sort_hpp


#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
using namespace std;

template <class Key>
class Sort
{
private:
    vector<Key>vec;
    int a = 0;
    int s = 0;

public:
    
    void insertion_sort(vector<Key>&x);
    void print(vector<Key>&x);
    void swap(Key &item1, Key &item2);
    void quick_sort(vector<Key>&x);
    void quick_sort(vector<Key>&x, int left, int right);
    void heap_sort(vector<Key>&x);
    void perc_down(vector<Key>&x, int i, int q);
    void merge_sort(vector<Key>&x);
    void merge(vector<Key>&left, vector<Key>&right, vector<Key>&x);
    void upper(vector<Key>&x);
    void binary_search(vector<string>&x, string word);
    void sequential_search(vector<string>&x, string word);
};




#endif /* Sort_hpp */
