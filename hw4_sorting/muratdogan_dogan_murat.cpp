#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cctype>
#include <vector>
#include "Sort.hpp"
#include "Sort.cpp"
#include <chrono>
#include <ctime>
using namespace std;


int main() {

    string file;
    cout<<"Please enter the contact file name:"<<endl;
    cin>>file;
    
    string word;
      
    cout<<"Please enter the word to be queried:"<<endl;
    
    cin.ignore();
    getline(cin,word);
    
    string item, a;
    ifstream input(file);
    
    vector<string> info;
    if (input.fail()) {
        cout << "Failed to open file." << endl;
        return 1;
    }
    while(getline(input, item))
    {
        info.push_back(item);
    }
    cout<<endl;
    cout<<"Sorting the vector copies"<<endl;
    cout<<"----------------------"<<endl;
    cout<<"----------------------"<<endl;


    Sort<string> sor;
    
    vector<string> temp1 = info;
    int N = 100; 
    
    auto start2 = chrono::high_resolution_clock::now();
    for (int i = 0; i < N; i++)
    {
        sor.quick_sort(temp1);
    }
    auto quick_sort_time = chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now() -start2);
    cout<<"Quick Sort Time: "<<quick_sort_time.count() / N <<" Nanoseconds"<<endl;
    
    
    temp1 = info;
    int N2 = 100;
    auto start = chrono::high_resolution_clock::now();
    for (int i = 0; i < N2; i++)
    {
        temp1 = info;
        sor.insertion_sort(temp1);
    }
    auto insertion_time = chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now() -start);
    cout<<"Insertion Sort Time: "<<insertion_time.count() / N2 <<" Nanoseconds"<<endl;


    
    temp1 = info;
    
    int N4 = 100;
    auto start4 = chrono::high_resolution_clock::now();
    for (int i = 0; i < N4; i++)
    {
        temp1 = info;
        sor.merge_sort(temp1);
    }
    auto merge_time = chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now() -start4);
    cout<<"Merge Sort Time: "<<merge_time.count() / N4 <<" Nanoseconds"<<endl;
    
    temp1 = info;
    
    int N3 = 100;
    auto start3 = chrono::high_resolution_clock::now();
    for (int i = 0; i < N3; i++)
    {
        temp1 = info;
        sor.heap_sort(temp1);
    }
    auto heap_time = chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now() -start3);
    cout<<"Heap Sort Time: "<<heap_time.count() / N3 <<" Nanoseconds"<<endl;
    
    cout<<endl;
    cout<<"Searching for "<<word<<endl;
    cout<<"----------------------"<<endl;
    cout<<"----------------------"<<endl;
    
   
    sor.upper(temp1);

    int N5 = 100;
    auto start5 = chrono::high_resolution_clock::now();
    for (int i = 0; i < N5; i++)
    {
        sor.binary_search(temp1, word);
    }
    auto binary_search_time = chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now() -start5);
    cout<<"Binary Search Time: "<<binary_search_time.count() / N5 <<" Nanoseconds"<<endl;
    
    cout<<endl;
    cout<<"Search results for Sequential Search:"<<endl;
    
    int N6 = 100;
    auto start6 = chrono::high_resolution_clock::now();
    for (int i = 0; i < N6; i++)
    {
        sor.sequential_search(temp1, word);
    }
    auto sequential_search_time = chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now() -start6);
    cout<<endl<<"Sequential Search Time: "<<sequential_search_time.count() / N6 <<" Nanoseconds"<<endl;
    
    cout<<endl;
    cout<<"SpeedUp between Search Algorithms"<<endl;
    cout<<"----------------------"<<endl;
    cout<<"----------------------"<<endl;
    cout<<"(Sequential Search/ Binary Search) SpeedUp = "<<static_cast<double>(sequential_search_time.count()) / binary_search_time.count()<<endl;
    cout<<endl;
    cout<<"SpeedUps between Sorting Algorithms"<<endl;
    cout<<"----------------------"<<endl;
    cout<<"----------------------"<<endl;
    
    cout<<"(Insertion Sort/ Quick Sort) SpeedUp = "<<static_cast<double>(insertion_time.count()) / quick_sort_time.count()<<endl;
    cout<<"(Merge Sort / Quick Sort) SpeedUp = "<<static_cast<double>(merge_time.count()) / quick_sort_time.count()<<endl;
    cout<<"(Heap Sort / Quick Sort) SpeedUp = "<<static_cast<double>(heap_time.count()) / quick_sort_time.count()<<endl;
     
    return 0;
}
