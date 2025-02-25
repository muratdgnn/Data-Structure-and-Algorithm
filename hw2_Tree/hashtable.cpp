#include "hashtable.hpp"
#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;



template <class Key, class Value>
HashTable<Key,Value>::HashTable()
{
    Table.resize(tableSize);
    empty();
}

template <class Key, class Value>
bool HashTable<Key, Value>::isPrime(int x)
{
    if(x == 2 || x == 3)
    {
        return true;
    }
    if(x == 1 || x % 2 == 0)
    {
        return false;
    }
    
    for(int i = 3; i*i <= x; i+=2)
    {
        if(x % i == 0)
        {
            return false;
        }
    }
    return true;
}

template <class Key, class Value>
int HashTable<Key, Value>::hash(const Value &word)
{
    int num = 0;
    
    for(int i = 0; i<word.length(); i++)
    {
        num = num * 37 + word[i];
    }
    num = num % tableSize;
    
    return num;
}



template<class Key, class Value>
int HashTable<Key,Value>::position(const Value &x)
{
   
    
    
    int pos = hash(x);
    while(Table[pos].condition != "empty" && Table[pos].word != x)
    {
        pos++;
        if(pos == tableSize)
        {
            pos = 0;
        }
    }
    
    return pos;
    
}

template<class Key, class Value>
void HashTable<Key,Value>::empty()
{
    for(int i = 0; i< Table.size(); i++)
    {
        Table[i].condition = "empty";
    }
    
}

template<class Key, class Value>
void HashTable<Key,Value>::insert(const Value &x, const string &file)
{
    int pos = position(x);
    if(Table[pos].condition == "empty")
    {
        Table[pos].word = x;
        Table[pos].condition = "full";
        Table[pos].item = new DocumentItem(file,1);
        
        totalWord++;
    }
    
    
    
    else
    {
        if(file == Table[pos].item->documentName)
        {
            Table[pos].item->count++;
        }
        else
        {
            DocumentItem * temp = new DocumentItem(file, 1, nullptr, Table[pos].item);
            Table[pos].item->next = temp;
            Table[pos].item = Table[pos].item->next;
        }
    }
    
    
    
    if(loadFactor() > 0.9)
    {
        size_t oldSize = tableSize;
        cout<<"rehashed..."<<endl;
        rehash();
        cout<<"previous table size:"<<oldSize<<", new table size: "<<tableSize<<", current unique word count "<<totalWord<<", current load factor: "<<loadFactor()<<endl;
        
    }
}

template<class Key, class Value>
double HashTable<Key,Value>::loadFactor()
{
    return static_cast<double>(totalWord) / tableSize;
}

template<class Key, class Value>
void HashTable<Key,Value>::final_load()
{
    cout<<endl<<"After preprocessing, the unique word count is "<<totalWord<<". Current load ratio is "<<loadFactor()<<endl;
}

template<class Key, class Value>
void HashTable<Key,Value>::rehash()
{
    vector<WordItem>oldTable = Table;
    
    tableSize = tableSize*2;
    while(isPrime(tableSize) == false)
    {
        tableSize++;
    }
    Table.resize(tableSize);
    for(int i =0; i< Table.size(); i++)
    {
        Table[i].condition = "empty";
    }
    for(int q =0; q<oldTable.size(); q++)
    {
        if(oldTable[q].condition == "full")
        {
            Table[q].word = oldTable[q].word;
            Table[q].condition = "full";
            
            while(oldTable[q].item->next != nullptr)
            {
                Table[q].item->documentName = oldTable[q].item->documentName;
                Table[q].item->count = oldTable[q].item->count;
                oldTable[q].item = oldTable[q].item->next;
                Table[q].item = Table[q].item->next;
            }
            
        }
    }
}

template<class Key, class Value>
void HashTable<Key,Value>::find(const Value &x, string documentNameOrder)
{
    
    
    bool check = false;
    int pos = position(x);
    if(Table[pos].condition == "full")
    {
        
        while(Table[pos].item != nullptr)
        {
            if(Table[pos].item->documentName == documentNameOrder)
            {
                check = true;
                break;
            }
            Table[pos].item = Table[pos].item->next;
        }
        if(check == true)
        {
            if(c == 0)
            {
                cout<<"in Document "<<Table[pos].item->documentName;
                c++;
            }
            cout<<", "<<x<<" found "<<Table[pos].item->count<<" times";
        }
        
        
    }
    
}

template<class Key, class Value>
void HashTable<Key,Value>::time(string file)
{
    
    insert("xyz",file);
}

template<class Key, class Value>
bool HashTable<Key,Value>::dot()
{
    if(c > 0)
    {
        c = 0;
        return true;
    }
    else
    {
        return false;
    }
}


