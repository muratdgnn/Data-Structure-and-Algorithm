
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cctype>
#include "Tree.hpp"
#include "Tree.cpp"
using namespace std;

int main(){
    
    AVLSearchTree<string, WordItem *> myTree;
    int w =0;
    int file_num;
    cout<<"Enter number of input files: ";
    cin>>file_num;
    string arr[file_num]; // adding file names to array
    while(w<file_num)
    {
        string a, word,file;
        cout<<"Enter "<<w+1<<". file name: ";
        cin >> file;
        arr[w] = file;
        ifstream input(file);
        
        if (input.fail()) {
            cout << "Failed to open file." << endl;
            return 1;
        }
        while (getline(input, a))
        {
            istringstream line(a);
            while (line >> word) {
                DocumentItem* items = new DocumentItem(file, 1);

                for(char & q : word)
                {
                    if(isupper(q)){
                        q = tolower(q);
                    }
                }
                if(myTree.Search2(word,items) == false)
                {
                    myTree.Insert(word, items);
                }
                
                
            }
        }
        input.close();
        w++;
    }

    cout<<endl;
    int t =0;
    string z;
    string words;
    while(true)
    {
        
        cout<<"Enter queried words in one line: ";
        if(t==0)
        {
            cin.ignore(); // use cin.ignore() one time
            t=1;
        }
        
        getline(cin , words);
        
        int y =0;// for finding the file name in array
        int r =0;// if file has word put dot end of line 
        bool check = false;// if it is equal to false at the end of Search, it prints "No document contains the given query"
        bool check_remove = false;
        string remove= words.substr(0,6);
        
        if(remove == "REMOVE")
        {
            check_remove = true;
            string removed_word = words.substr(7);
            for(char & q : removed_word)
            {
                if(isupper(q)){
                    q = tolower(q);
                }
            }
            myTree.Remove(removed_word);
            cout<<removed_word<<" has been REMOVED"<<endl;
            
        }
        while(y < file_num && check_remove == false)
        {
            stringstream ss(words);
            
            while(ss >>z)
            {
                for(char & q : z)
                {
                    if(isupper(q)){
                        q = tolower(q);
                    }
                }
                
                if(myTree.Search(z, arr[y]) == true)
                {
                    r++;
                    check = true;
                    
                }
                
            }
            if(r > 0)
            {
                cout<<"."<<endl;
            }
            
            myTree.make_asd_0();// for printing document name one time for each line asd private object asd used in private Search function
            r=0;
            y++;
        }
        
        if(words == "ENDOFINPUT")
        {
            break;
        }
        
        if(check == false && check_remove == false && words != "ENDOFINPUT")
        {
            cout<<"No document contains the given query"<<endl;
            
        }
        cout<<endl;
    }
    
    
    return 0;
}
