#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cctype>
#include "hashtable.hpp"
#include "hashtable.cpp"
#include "Tree.hpp"
#include "Tree.cpp"
#include <cmath>
#include <chrono>
#include <ctime>
using namespace std;


int main() {
    
    HashTable<int , string> table;
    AVLSearchTree<string, WordItem *> tree;
    int file_num;
    cout<<"Enter number of input files: ";
    cin>>file_num;
    string arr[file_num];
    int z = 0;
    while(z<file_num)
    {
        string file;
        cout<<"Enter "<<z+1<<". file name: ";
        cin>>file;
        arr[z] = file;
        z++;
    }
    int o = 0;
    while(o < file_num)
    {
        string a, word;
        ifstream input(arr[o]);
        while (getline(input, a))
        {
            istringstream line(a);
            while (line >> word)
            {
                int f = 0;
                bool check = false;
                bool check2 = false;
                for(char & i : word)
                {
                    if(!((i>64 && i < 91) || (i>96 && i<123)))
                    {
                        if(word.find(i) == word.length()-1)
                        {
                            word = word.substr(0, word.length()-1);
                            check2 = true;
                        }
                        else{
                            i = ' ';
                            f++;
                            check = true;
                        }
                        
                    }
                }
                for(char & q : word)
                {
                    if(isupper(q)){
                        q = tolower(q);
                    }
                }
                DocumentItem* items = new DocumentItem(arr[o], 1);
                if(check == true && f == 1 && check2 == false)
                {
                    for(int y=0; y<word.length(); y++)
                    {
                        if(word[y] ==' ')
                        {
                            table.insert(word.substr(0,y), arr[o]);
                            table.insert(word.substr(y+1), arr[o]);
                            
                            
                            if(tree.Search2(word.substr(0,y), items) == false)
                            {
                                tree.Insert(word.substr(0,y), items);
                            }
                            if(tree.Search2(word.substr(y+1), items) == false)
                            {
                                tree.Insert(word.substr(y+1), items);
                            }
                        }
                    }
                }
                else if(check == true && f == 2 && check2 == false)
                {
                    int pos1=0, pos2=0;
                    for(int y2=0; y2<word.length(); y2++)
                    {
                        if(word[y2] ==' ' && pos1 == 0)
                        {
                            pos1 = y2;
                        }
                        else if(word[y2] ==' ' && pos1 != 0)
                        {
                            pos2 = y2;
                        }
                    }
                    table.insert(word.substr(0,pos1), arr[o]);
                    table.insert(word.substr(pos1+1,pos2-pos1), arr[o]);
                    table.insert(word.substr(pos2+1), arr[o]);
                    
                    
                    if(tree.Search2(word.substr(0,pos1), items) == false)
                    {
                        tree.Insert(word.substr(0,pos1), items);
                    }
                    
                    if(tree.Search2(word.substr(pos1+1,pos2-pos1), items) == false)
                    {
                        tree.Insert(word.substr(pos1+1,pos2-pos1), items);
                    }
                    
                    if(tree.Search2(word.substr(pos2+1), items) == false)
                    {
                        tree.Insert(word.substr(pos2+1), items);
                    }


                }
                else
                {
                    table.insert(word, arr[o]);
                    
                    if(tree.Search2(word, items) == false)
                    {
                        tree.Insert(word, items);
                    }
                }
            }
        }
        o++;
        
    }

    table.final_load();
    cout<<endl;
    
    
    string zz, z2;
    string words;
    
    
    
    cout<<"Enter queried words in one line: ";
    
    
    cin.ignore();
    
    
    getline(cin , words);
    
    for(char & e : words)
    {
        if(!((e>64 && e < 91) || (e>96 && e<123)))
        {
            if(words.find(e) == words.length()-1)
            {
                words = words.substr(0, words.length()-1);
            }
            else
            {
                e = ' ';
            }
        }
    }
    
    int y =0;// for finding the file name in array
    int r =0;// if file has word put dot end of line
    bool check = false;// if it is equal to false at the end of Search, it prints "No document contains the given query"
    bool check_remove = false;
    
    
    while(y < file_num && check_remove == false)
    {
        stringstream ss(words);
        
        while(ss >>zz)
        {
            for(char & q : zz)
            {
                if(isupper(q)){
                    q = tolower(q);
                }
            }
            
            if(tree.Search(zz, arr[y]) == true)
            {
                r++;
                check = true;
                
            }
            
        }
        if(r > 0)
        {
            cout<<"."<<endl;
        }
        
        tree.make_asd_0();// for printing document name one time for each line asd private object asd used in private Search function
        r=0;
        y++;
    }
    

    
    if(check == false && check_remove == false)
    {
        cout<<"No document contains the given query"<<endl;
        
    }
    cout<<endl;
    
    
    
    string worrd = words;
    y = 0;
    while(y < file_num)
    {
        stringstream s(worrd);
        
        
        while(s >> z2)
        {
            for(char & q2 : z2)
            {
                if(isupper(q2)){
                    q2 = tolower(q2);
                }
            }
            
            table.find(z2, arr[y]);
            
        }
        if(table.dot() == true)
        {
            cout<<"."<<endl;

        }
        y++;
    }
    
    if(check == false && check_remove == false)
    {
        cout<<"No document contains the given query"<<endl;
        
    }
    
    
    
    
    int k = 20;
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < k; i++)
    {
        tree.item(arr[0]);        // QueryDocuments(with BST);
    }
    auto BSTTime = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() -start);
    cout << "\nTime: " << BSTTime.count() / k << "\n";
    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < k; i++)
    {
        table.time(arr[0]);      // QueryDocuments (with hashtable);
    }
    auto HTTime = std::chrono::duration_cast<std::chrono::nanoseconds>
                            (std::chrono::high_resolution_clock::now() - start);
    cout << "\nTime: " << HTTime.count() / k << "\n";
    
    
    cout<<endl<<"Speed up: "<<static_cast<double> (BSTTime.count()) / HTTime.count() <<endl;

   
    return 0;
}
