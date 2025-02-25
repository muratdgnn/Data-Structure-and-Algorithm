
#ifndef Tree_hpp
#define Tree_hpp


#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cctype>
using namespace std;

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
    DocumentItem* item;
    WordItem* left;
    WordItem* right;
    
};

template <class Key, class Value>
class AVLSearchTree
{
private:
    Value root;
    int asd=0; // for printing document name one time for each line
    
    void Insert(Value x,string word,DocumentItem* item);
    bool Search2(Value x,string word,DocumentItem* item);//search if word inserted in different file
    bool Search(Value x,string word, string file_name);// search if the word is in tree then print word, file name and count
    void Remove(Value x,string word);
    Value Min(Value x); // for remove, if there are 2 children then find minimum in right subtree
public:
    AVLSearchTree();
    
    void Insert(string word, DocumentItem* item);
    bool Search2(string word, DocumentItem*it);//search if word inserted in different file
    bool Search(string word, string file_name);// search if the word is in tree then print word, file name and count
    Value Min();// for remove, if there are 2 children then find minimum in right subtree
    void Remove(string word);
    
    void make_asd_0();
};

#endif /* Tree_hpp */
