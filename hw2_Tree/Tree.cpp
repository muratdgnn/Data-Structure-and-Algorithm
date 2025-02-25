

#include "Tree.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cctype>
using namespace std;

template <class Key, class Value>
AVLSearchTree<Key, Value>::AVLSearchTree()
{
    root = nullptr;
}

template <class Key, class Value>
void AVLSearchTree<Key, Value>::Insert(Value x,string word, DocumentItem *item)
{
   
    if(x == NULL) {
        
        
        x= new WordItem;
        x->word = word;
        x->item = item;
        x->left = nullptr;
        x->right = nullptr;
        root = x;
    }
    
    else if(word <= x->word) {
        if(x->left == nullptr)
        {
            WordItem* q = new WordItem;
            q->word = word;
            q->item = item;
            q->left = nullptr;
            q->right = nullptr;
            x->left = q;
        }
        else{
            Insert(x->left, word, item);
        }
        
        
    }
    
    else if(word >= x->word){
        if(x->right == nullptr)
        {
            WordItem* q = new WordItem;
            q->word = word;
            q->item = item;
            q->left = nullptr;
            q->right = nullptr;
            x->right = q;
        }
        else{
            Insert(x->right, word, item);
        }
        
    }
}

template <class Key, class Value>
void AVLSearchTree<Key, Value>::Insert(string word, DocumentItem *item)
{
    Insert(root, word, item);
}

template <class Key, class Value>
bool AVLSearchTree<Key, Value>:: Search(Value x, string word, string file_name)
{
    if(x == NULL) {
        
        return false;
    }
    else if(x->word == word) {
        DocumentItem * as = x->item;
        while(as->prev != nullptr)
        {
            as = as->prev;
        }
        
        while(as->next != nullptr && as->documentName != file_name)
        {
            as = as->next;
        }
        if(asd == 0 && as->documentName == file_name)
        {
            cout<<"in Document "<<file_name;
            asd++;
        }
        
        if(as->documentName == file_name)
        {
            
            cout<<", "<<x->word<<" found "<<as->count<<" times";
            return true;
        }
        else{return false;}

    }
    else if(word <= x->word) {
        
        return Search(x->left,word, file_name);
    }
    else {
        
        return Search(x->right,word, file_name);
    }
}

template <class Key, class Value>
bool AVLSearchTree<Key, Value>::Search(string word, string file_name)
{
    if(Search(root, word, file_name) == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <class Key, class Value>
bool AVLSearchTree<Key, Value>::Search2(Value x, string word, DocumentItem *it)
{
    if(x == NULL)
    {
        return false;
    }
    else if(x->word == word) {
        if(it->documentName != x->item->documentName)
        {
            DocumentItem * temp = new DocumentItem(it->documentName, 1, nullptr, x->item);
            x->item->next = temp;
            x->item = x->item->next;
        }
        else{
            x->item->count = x->item->count + 1;
        }
        return true;
        
    }
    else if(word <= x->word){
        
        return Search2(x->left,word,it);
    }
    else {
        
        return Search2(x->right,word,it);
    }
}

template <class Key, class Value>
bool AVLSearchTree<Key, Value>::Search2(string word, DocumentItem *it)
{
    if(Search2(root, word, it) == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <class Key, class Value>
Value AVLSearchTree<Key,Value>::Min(Value x)
{
    x = x->right;
    while(x->left != nullptr){
        x = x->left;
    }
    return x;
}

template <class Key, class Value>
Value AVLSearchTree<Key, Value>::Min()
{
    return Min(root);
}
template <class Key, class Value>
void AVLSearchTree<Key, Value>::Remove(Value x,string word)
{
    if(x== nullptr)
    {
        
    }
    else if(word < x->word){
        
        Remove(x->left,word);
    }
    else if(word > x->word){
        
        Remove(x->right,word);
    }
    else{
        if(x->left == nullptr && x->right == nullptr)
        {
            delete x;
            x = nullptr;
        }
        else if(x->left == nullptr)
        {
            Value temp = x;
            x = x->right;
            delete temp;
        }
        else if(x->right == nullptr)
        {
            Value temp = x;
            x = x->left;
            delete temp;
        }
        else{
            Value temp = Min();
            x->word = temp->word;
            Remove(x->right,temp->word);
        }
    }
}
template <class Key, class Value>
void AVLSearchTree<Key, Value>::Remove(string word)
{
    Remove(root, word);
}
    
template <class Key, class Value>
void AVLSearchTree<Key, Value>::make_asd_0(){
    asd =0;
}

