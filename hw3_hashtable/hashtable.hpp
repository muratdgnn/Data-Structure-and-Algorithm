
#ifndef hashtable_hpp
#define hashtable_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <list>
using namespace std;




template<class Key, class Value>
class HashTable{
    
private:
    
    struct DocumentItem {
        string documentName;
        int count;
        DocumentItem* next;
        DocumentItem* prev;

        
        DocumentItem(const string & dName= string(), const int & c= int(), DocumentItem* n= nullptr, DocumentItem* p= nullptr)
        : documentName(dName), count(c), next(n), prev(p){}
    };
    struct WordItem {
        string word;
        string condition;
        DocumentItem* item;
        
        
    };
    
    int c = 0;
    
    size_t tableSize = 53;
    
    int totalWord = 0;
    
    vector<WordItem>Table;
    
    int hash(const Value &word);
    
    bool isPrime(int x);
    
    void rehash();
    
    int position(const Value &x);
    
    
    
    
public:
    HashTable();
    
    void insert(const Value & x, const string &file);
    
    double loadFactor();
    
    void empty();
    
    void final_load();
    
    void find(const Value &x, string documentNameOrder);
    
    void time(string file);
    
    
    bool dot();
};

#endif /* hashtable_hpp */
