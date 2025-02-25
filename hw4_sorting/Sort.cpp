#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
#include "Sort.hpp"
using namespace std;


template<class Key>
void Sort<Key>::insertion_sort(vector<Key> &x)
{
    int q;
    for(int pass=1; pass < x.size(); pass++)
    {
        Key temp = x[pass];
        for(q = pass; q > 0 && temp < x[q-1]; q--)
        {
            x[q] = x[q-1];
        }
        x[q] = temp;
    }
}


template<class Key>
void Sort<Key>::print(vector<Key> &x)
{
    for(int i= 0; i<x.size(); i++)
    {
        cout<<x[i]<<endl;
    }
}

template<class Key>
void Sort<Key>::quick_sort(vector<Key> &x)
{
    quick_sort(x, 0, x.size()-1);
}


template<class Key>
void Sort<Key>::quick_sort(vector<Key> &x, int left, int right)
{
    
    if(left + 10 <= right)
    {
        int pivot = (left + (right - left) / 2);
        

        int i = left;
        int j = right;
        
        while(i <= j)
        {
            while(x[i++] < x[pivot]) {  }
            
            while(x[j--] > x[pivot]) { }
            if(i <= j)
            {
                swap(x[i], x[j]);
            }
            
        }
        
        swap(x[i], x[x.size()-1]);
        
        if(left < j){quick_sort(x,left,j);}
        if(i < right){quick_sort(x,i,right);}
    }
    else
    {
        insertion_sort(x);
    }
     
}

template<class Key>
void Sort<Key>::swap(Key &item1, Key &item2)
{
    Key temp = item1;
    item1 = item2;
    item2 = temp;
}






template<class Key>
void Sort<Key>::heap_sort(vector<Key> &x)
{
    for(int i = (x.size()/2)-1; i>=0; i--)
    {
        perc_down(x, i, x.size());
    }
    
    for(int j=x.size()-1; j>0; j--)
    {
        swap(x[0], x[j]);
        perc_down(x, 0, j);
    }
}

template<class Key>
void Sort<Key>::perc_down(vector<Key> &x, int i, int q)
{
    int child;
    Key temp;
    
    for(temp=x[i]; 2*i+1<q; i=child)
    {
        child = 2*i+1;
        if(child != q-1 && x[child]<x[child+1])
        {
            child++;
        }
        if(x[child] > temp)
        {
            x[i] = x[child];
        }
        else
        {
            break;
        }
        
    }
    x[i] = temp;

}

template<class Key>
void Sort<Key>::merge_sort(vector<Key> &x)
{
    if(x.size() <= 1) {return;}
    
    int center = x.size() /2;
    vector<Key>left;
    vector<Key>right;
        
    for(int i = 0; i < x.size(); i++)
    {
        if(i < center)
        {
            left.push_back(x[i]);
        }
        else
        {
            right.push_back(x[i]);
        }
    }
    
    merge_sort(left);
    merge_sort(right);
    merge(left, right, x);

}

template<class Key>
void Sort<Key>::merge(vector<Key> &left, vector<Key> &right, vector<Key> &x)
{
    int q = 0;// for main
    int l = 0;// for left
    int r = 0;// for right
    
    while(l < left.size() && r < right.size())
    {
        if(left[l] < right[r])
        {
            x[q] = left[l];
            q = q+1;
            l = l+1;
            
        }
        else
        {
            x[q] = right[r];
            q = q+1;
            r = r+1;
        }
    }
    while(l < left.size())
    {
        x[q] = left[l];
        q = q+1;
        l = l+1;
    }
    while(r < right.size())
    {
        x[q] = right[r];
        q = q+1;
        r = r+1;
    }
}


template<class Key>
void Sort<Key>::upper(vector<Key> &x)
{
    for(int i = 0; i< x.size(); i++)
    {
        for(char & q : x[i])
        {
            if(q == '+')
            {
                break;
            }
            if(islower(q))
            {
                q = toupper(q);
            }
        }
    }
}


template<class Key>
void Sort<Key>::binary_search(vector<string> &x, string word)
{
    for(char & q : word)
    {
        if(islower(q))
        {
            q = toupper(q);
        }
        
    }
     
    int length = word.length();

    int left = 0;
    int right = x.size()-1;
    int center = left +(right - left) / 2;
    int b = 0;
    int y = 0;
    bool check = false;

    
    while(left <=right)
    {
        if(word != x[center].substr(0,length))
        {
            center = left +(right - left) / 2;
        }
        else
        {
            
            center++;
            if(word != x[center].substr(0,length))
            {
                break;
            }
        }
        
        if(word == x[center].substr(0,length))
        {
            check = true;
            while(b== 0)
            {
                y++;
                if(word != x[center-y].substr(0,length))
                {
                    b++;
                    y = y-1;
                    center = center -y;
                    break;
                }
                
            }
            if(a == 0)
            {
                cout<<x[center]<<endl;
            }
        }
        else if(word < x[center].substr(0,length))
        {
            right = center-1;
        }
        else
        {
            left = center+1;
        }
    }
    
    
    if(check == false && a == 0)
    {
        cout<<word<<" does NOT exist in the dataset"<<endl;
    }
    a++;
}

template<class Key>
void Sort<Key>::sequential_search(vector<string> &x, string word)
{
    
    for(char & q : word)
    {
        if(islower(q))
        {
            q = toupper(q);
        }
    }
    
    int length = word.length();
    bool check = false;
    for(int i = 0; i<x.size(); i++)
    {
        if(x[i].substr(0,length) == word && s == 0)
        {
            check = true;
            cout<<x[i]<<endl;
        }
    }
    if(check == false && s == 0)
    {
        cout<<word<<" does NOT exist in the dataset"<<endl;
    }
    s++;
}
