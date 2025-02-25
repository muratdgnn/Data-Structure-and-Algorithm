
#include "linkedlist.h"
#include <iostream>
#include <string>
#include <random>
using namespace std;


template <class T>
stack<T>::stack(int q, int w)
{
    top = nullptr;
    row = q;
    col = w;
}

template <class T>
void stack<T>::cell_number()
{
    int size = row*col;
    arr = new int [size];
    for(int i=0; i<size;i++)
    {
        arr[i] = 0;
    }
}

template <class T>
bool stack<T>::check()
{
    int x = 0;
    int size = row*col;
    for(int i=0; i<size; i++)
    {
        if(arr[i] == 0)
        {
            x = 1;
        }
        
    }
    if(x == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}


template <class T>
void stack<T>::push()
{
    
    linkedlist * q1, *q2;
    
    top = new linkedlist(" ",1);
    arr[0] = 1;
    q1 = top;
    
    top->value = "|___|";
    
    
    int random_number = 0;
    int random_num[2];
    int random_num2[3];
    int random_num3[4];
    
    
    
    while(check() != true)
    {
        
        bool check_unvisited = false;
        
        while(check_unvisited == false)
        {
            
            int a = top->checker % col;
            
            
            
            if(top->checker == (row-1)*col +1)
            {
                
                random_num[0] = top->checker+1;
                random_num[1] = top->checker-col;
                
                
                
                random_device rd;
                mt19937 gen(rd());
                uniform_int_distribution<int>dist(0, 1);
                int index = dist(gen);
                random_number = random_num[index];
                
                
            }
            else if(top->checker == row*col)
            {
                
                random_num[0] = top->checker-1;
                random_num[1] = top->checker-col;
            
                random_device rd;
                mt19937 gen(rd());
                uniform_int_distribution<int>dist(0, 1);
                int index = dist(gen);
                random_number = random_num[index];
                
                
            }
            else if(top->checker == 1)
            {
                
                random_num[0] = 2;
                random_num[1] = 1+col;
                
                
                random_device rd;
                mt19937 gen(rd());
                uniform_int_distribution<int>dist(0, 1);
                int index = dist(gen);
                random_number = random_num[index];
                
                
                
            }
            else if(top->checker == col)
            {
                
                random_num[0] = top->checker-1;
                random_num[1] = top->checker+col;
               
                
                random_device rd;
                mt19937 gen(rd());
                uniform_int_distribution<int>dist(0, 1);
                int index = dist(gen);
                random_number = random_num[index];
                
                
            }
            else if(a == 1)
            {
                
                random_num2[0] = top->checker+1;
                random_num2[1] = top->checker-col;
                random_num2[2] = top->checker+col;
                
                
                
                random_device rd;
                mt19937 gen(rd());
                uniform_int_distribution<int>dist(0, 2);
                int index = dist(gen);
                random_number = random_num2[index];
                
                
            }
            else if(a == 0)
            {
                
                random_num2[0] = top->checker-1;
                random_num2[1] = top->checker-col;
                random_num2[2] = top->checker+col;
                
                
                random_device rd;
                mt19937 gen(rd());
                uniform_int_distribution<int>dist(0, 2);
                int index = dist(gen);
                random_number = random_num2[index];
                
               
            }
            else if(top->checker < col)
            {
                
                random_num2[0] = top->checker+1;
                random_num2[1] = top->checker-1;
                random_num2[2] = top->checker+col;
                
                
                random_device rd;
                mt19937 gen(rd());
                uniform_int_distribution<int>dist(0, 2);
                int index = dist(gen);
                random_number = random_num2[index];
                
                
            }
            else if(top->checker > (row-1)*col)
            {
                
                random_num2[0] = top->checker+1;
                random_num2[1] = top->checker-col;
                random_num2[2] = top->checker-1;
                
                
                random_device rd;
                mt19937 gen(rd());
                uniform_int_distribution<int>dist(0, 2);
                int index = dist(gen);
                random_number = random_num2[index];
                
                
            }
            else
            {
                
                random_num3[0] = top->checker+1;
                random_num3[1] = top->checker-col;
                random_num3[2] = top->checker+col;
                random_num3[3] = top->checker-1;
                
                
                random_device rd;
                mt19937 gen(rd());
                uniform_int_distribution<int>dist(0, 3);
                int index = dist(gen);
                random_number = random_num3[index];
                
                
            }
            if(arr[random_number-1] ==0)
            {
                
                int s = top->checker;
                string s2 = top->value;
                check_unvisited = true;
                q2 = new linkedlist(" ",random_number,nullptr,q1);
                q1->next = q2;
                q1 = q1->next;
                top = q1;
                
                if(top->checker % col == 1)
                {
                    top->value = "|___|";
                }
                else{
                    top->value = "___|";
                }
                
                
                
                
                arr[random_number-1] = random_number;
                
                
                if(top->checker - s == col* -1)
                {
                    while(top->prev->checker != s)
                    {
                        top = top->prev;
                    }
                    if(s % col == 1)
                    {
                        if(top->prev->value == "|____")
                        {
                            top->prev->value = "|    ";
                        }
                        else
                        {
                            top->prev->value = "|   |";
                        }
                        
                    }
                    else{
                        if(top->prev->value == "____")
                        {
                            top->prev->value = "    ";
                        }
                        else
                        {
                            top->prev->value = "   |";
                        }
                    }
                    
                    
                }
                else if(top->checker - s == col)
                {
                    if(top->checker % col == 1)
                    {
                        if(top->value == "|____")
                        {
                            top->value = "|    ";
                        }
                        else
                        {
                            top->value = "|   |";
                        }
                        
                    }
                    else{
                        if(top->value == "____")
                        {
                            top->value = "    ";
                        }
                        else
                        {
                            top->value = "   |";
                        }
                        
                    }
                    
                }
                else if(top->checker - s == 1)
                {
                    while(top->prev->checker != s)
                    {
                        top = top->prev;
                    }
                    if(s % col == 1)
                    {
                        if(top->prev->value == "|   |")
                        {
                            top->prev->value = "|    ";
                        }
                        else
                        {
                            top->prev->value = "|____";
                        }
                        
                    }
                    else{
                        if(top->prev->value == "   |")
                        {
                            top->prev->value = "    ";
                        }
                        else
                        {
                            top->prev->value = "____";
                        }
                        
                    }
                    
                }
                else if(top->checker - s == -1)
                {
                    if(top->checker % col == 1)
                    {
                        if(top->value == "|   |")
                        {
                            top->value = "|    ";
                        }
                        else
                        {
                            top->value = "|____";
                        }
                        
                    }
                    else{
                        if(top->value == "   |")
                        {
                            top->value = "    ";
                        }
                        else
                        {
                            top->value = "____";
                        }
                        
                    }
                    
                }
                while(top->next != nullptr)
                {
                    top = top->next;
                }
                
            }
            
        }
        while(pop_check(top) == true)
        {
            
            if(check() != true)
            {
                pop();
                
            }
            else
            {
                break;
            }
            
        }
   
    }
    top2 = top;

}

template <class T>
void stack<T>::pop()
{
    
    linkedlist * oldTop = top;
    
    top = top->prev;
    
    
}
        
template <class T>
void stack<T>::sorted()
{
    

    linkedlist * sort = nullptr;
    linkedlist * node;
    
    linkedlist * aq = top;
    int r = 1;
    
    while(r < (row*col)+1)
        
    {
        
        while(aq !=nullptr)
        {
            
            if(aq->checker == r)
            {
                break;
            }
            aq = aq->prev;
        }
        
        if(sort == nullptr)
        {
            
            sort = new linkedlist(aq->value,aq->checker);
        }
        else
        {
            node = new linkedlist(aq->value,aq->checker,nullptr,sort);
            sort->next = node;
            sort = sort->next;
        }
        aq = top;
        r++;
    }
    top = sort;
    
}

template <class T>
bool stack<T>::pop_check(linkedlist *q)
{
    int random_num3[4];
    int u=0;
    if((top->checker % col) != 1) // add to left
    {
        random_num3[u] = top->checker -1;
        u = u+1;
    }
    if((top->checker % col) != 0) // add to right
    {
        random_num3[u] = top->checker +1;
        u = u+1;
    }
    if(top->checker < ((row-1)*col) + 1) // add to up
    {
        random_num3[u] = top->checker + col;
        u = u+1;
    }
    if(top->checker > col) // add to down
    {
        random_num3[u] = top->checker -col;
        u = u+1;
    }
    
    int t= 0;
    for(int i=0; i<u; i++)
    {
        int p = random_num3[i];
        if(arr[p-1] != 0)
        {
            t = t+1;
        }
    }
    
    if(t == u)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <class T>
void stack<T>::show_walls()
{
    cout<<endl<<"Walls for every coordinates"<<endl;
    cout<<col<<" "<<row<<endl;
    int col2,row2;
    while(top->prev !=nullptr)
    {
        top = top->prev;
    }
    for(row2=0; row2<row; row2++)
    {
        for(col2=0; col2<col; col2++)
        {
            
            int order = (col2+1) + (row2*col);
            if(order == 1)
            {
                linkedlist* ex;
                cout<<"x=0 y=0 l=1";
                string w = top->value;
                if(w[4] == '|')
                {
                    cout<<" r=1";
                }
                else
                {
                    cout<<" r=0";
                }
                ex = top;
                for(int i=0; i< col; i++)
                {
                    ex= ex->next;
                }
                w = ex->value;
                if(w[2] == '_')
                {
                    cout<<" u=1";
                }
                else
                {
                    cout<<" u=0";
                }
                cout<<" d=1"<<endl;
                
                
            }
            else if(order == (row-1)*col +1)
            {
                
                cout<<"x="<<col2<<" y="<<row2<<" l=1";
                string w = top->value;
                if(w[4] == '|')
                {
                    cout<<" r=1";
                }
                else
                {
                    cout<<" r=0";
                }
                
                cout<<" u=1";
                
                if(w[2] == '_')
                {
                    cout<<" d=1";
                }
                else
                {
                    cout<<" d=0";
                }
                cout<<endl;
                
            }
            else if(order == row*col)
            {
                cout<<"x="<<col2<<" y="<<row2;
                string w= top->prev->value;
                if(w[3] == '|')
                {
                    cout<<" l=1";
                }
                else
                {
                    cout<<" l=0";
                }
                cout<<" r=1 u=1";
                w = top->value;
                if(w[1] == '_')
                {
                    cout<<" d=1";
                }
                else
                {
                    cout<<" d=0";
                }
                cout<<endl;
            }
            else if(order == col)
            {
                cout<<"x="<<col2<<" y="<<row2;
                string w= top->prev->value;
                if(w[3] == '|')
                {
                    cout<<" l=1";
                }
                else
                {
                    cout<<" l=0";
                }
                cout<<" r=1";
                linkedlist* ex;
                ex = top;
                for(int i=0; i< col; i++)
                {
                    ex= ex->next;
                }
                w = ex->value;
                if(w[2] == '_')
                {
                    cout<<" u=1";
                }
                else
                {
                    cout<<" u=0";
                }
                cout<<" d=1"<<endl;
                
            }
            else if(order % col == 0)
            {
                cout<<"x="<<col2<<" y="<<row2;
                string w= top->prev->value;
                if(w[3] == '|')
                {
                    cout<<" l=1";
                }
                else
                {
                    cout<<" l=0";
                }
                cout<<" r=1";
                linkedlist* ex;
                ex = top;
                for(int i=0; i< col; i++)
                {
                    ex= ex->next;
                }
                w = ex->value;
                if(w[2] == '_')
                {
                    cout<<" u=1";
                }
                else
                {
                    cout<<" u=0";
                }
                w = top->value;
                if(w[1] == '_')
                {
                    cout<<" d=1";
                }
                else
                {
                    cout<<" d=0";
                }
                cout<<endl;
            }
            
            else if(order % col == 1)
            {
                cout<<"x="<<col2<<" y="<<row2<<" l=1";
                string w = top->value;
                if(w[4] == '|')
                {
                    cout<<" r=1";
                }
                else
                {
                    cout<<" r=0";
                }
                linkedlist* ex;
                ex = top;
                for(int i=0; i< col; i++)
                {
                    ex= ex->next;
                }
                w = ex->value;
                if(w[2] == '_')
                {
                    cout<<" u=1";
                }
                else
                {
                    cout<<" u=0";
                }
                w = top->value;
                if(w[1] == '_')
                {
                    cout<<" d=1";
                }
                else
                {
                    cout<<" d=0";
                }
                cout<<endl;
                
                
            }
            else if(order < col)
            {
                cout<<"x="<<col2<<" y="<<row2;
                string w= top->prev->value;
                if(w[3] == '|' || w[4] == '|')
                {
                    cout<<" l=1";
                }
                else
                {
                    cout<<" l=0";
                }

                w = top->value;
                if(w[3] == '|')
                {
                    cout<<" r=1";
                }
                else
                {
                    cout<<" r=0";
                }
                linkedlist* ex;
                ex = top;
                for(int i=0; i< col; i++)
                {
                    ex= ex->next;
                }
                w = ex->value;
                if(w[2] == '_')
                {
                    cout<<" u=1";
                }
                else
                {
                    cout<<" u=0";
                }
                cout<<" d=1"<<endl;
                
            }
            else if(order > (row-1)*col)
            {
                cout<<"x="<<col2<<" y="<<row2;
                string w= top->prev->value;
                if(w[3] == '|' || w[4] == '|')
                {
                    cout<<" l=1";
                }
                else
                {
                    cout<<" l=0";
                }
                w = top->value;
                if(w[3] == '|')
                {
                    cout<<" r=1";
                }
                else
                {
                    cout<<" r=0";
                }
                cout<<" u=1";
                w = top->value;
                if(w[1] == '_')
                {
                    cout<<" d=1";
                }
                else
                {
                    cout<<" d=0";
                }
                cout<<endl;
                
            }
            else
            {
                cout<<"x="<<col2<<" y="<<row2;
                string w= top->prev->value;
                if(w[3] == '|' || w[4] == '|')
                {
                    cout<<" l=1";
                }
                else
                {
                    cout<<" l=0";
                }
                w = top->value;
                if(w[3] == '|')
                {
                    cout<<" r=1";
                }
                else
                {
                    cout<<" r=0";
                }
                linkedlist* ex;
                ex = top;
                for(int i=0; i< col; i++)
                {
                    ex= ex->next;
                }
                w = ex->value;
                if(w[2] == '_')
                {
                    cout<<" u=1";
                }
                else
                {
                    cout<<" u=0";
                }
                w = top->value;
                if(w[1] == '_')
                {
                    cout<<" d=1";
                }
                else
                {
                    cout<<" d=0";
                }
                cout<<endl;
                
            }
            top = top->next;
        }
    }
    
}

template <class T>
void stack<T>::maze()
{
    linkedlist * a = top;
    int col2 = col;
    
    while(a->next !=nullptr)
    {
        a = a->next;
    }
    
    cout<<"    ";
    for(int v =0; v<col; v++)
    {
        cout<<"____";
    }
    cout<<"_"<<endl;
    int i=0;
    while(i < row)
    {
        if(row-1-i>9)
        {
            cout<<row-1-i<<"  ";
        }
        else{
            cout<<row-1-i<<"   ";
        }
            
        
        if(i > 0)
        {
            col2 = col;
            col2 = col2 +1;
        }
        for(int q = 0; q <col2-1; q++)
        {
            a = a->prev;
        }
        int f =0;
        while(f<col)
        {
            if(a->checker % col == 0)
            {
                cout<< a->value<<endl;
            }
            else
            {
                cout<< a->value;
            }
            if( f != col-1)
            {
                a = a->next;

            }
            f++;
        }
        for(int q2 = 0; q2 <col-1; q2++)
        {
            a = a->prev;
        }
        i++;
        
    }
    
    cout<<"      ";
    for(int e=0; e<col; e++)
    {
        if(e<10)
        {
            cout<<e<<"   ";
        }
        else
        {
            cout<<e<<"  ";
        }
    }
    cout<<endl;
    
}

template <class T>
void stack<T>::maze_road(int enter_x, int enter_y, int exit_x, int exit_y)
{
    int enter = (enter_x+1) + (enter_y*col);
    int exit = (exit_x+1) + (exit_y*col);
    
        
    while(top2->checker != enter)
    {
        top2 = top2->prev;
    }
    
    
    cout<<endl<<"Maze path: "<<endl;
    if(top2->checker % col == 1)
    {
        string v2 = top2->value;
        v2[2] = 'E';
        top2->value = v2;
        int row_x = (top2->checker-1) / col;
        int col_y = (top2->checker-1) % col;
        cout<<col_y<<" "<<row_x<<endl;
        
            
    }
    else
    {
        string v2 = top2->value;
        v2[1] = 'E';
        top2->value = v2;
        int row_x = (top2->checker-1) / col;
        int col_y = (top2->checker-1) % col;
        cout<<col_y<<" "<<row_x<<endl;
            
    }
    if(enter < exit){top2 = top2->next;}
    else{top2 = top2->prev;}
    
    while(top2->checker != exit)
    {
        if(top2->checker % col == 1)
        {
            string v2 = top2->value;
            v2[2] = '*';
            top2->value = v2;
            int row_x = (top2->checker-1) / col;
            int col_y = (top2->checker-1) % col;
            cout<<col_y<<" "<<row_x<<endl;
                
        }
        else
        {
            string v2 = top2->value;
            v2[1] = '*';
            top2->value = v2;
            int row_x = (top2->checker-1) / col;
            int col_y = (top2->checker-1) % col;
            cout<<col_y<<" "<<row_x<<endl;
                
        }
        if(enter < exit){top2 = top2->next;}
        else{top2 = top2->prev;}
    }
    if(top2->checker % col == 1)
    {
        string v2 = top2->value;
        v2[2] = 'E';
        top2->value = v2;
        int row_x = (top2->checker-1) / col;
        int col_y = (top2->checker-1) % col;
        cout<<col_y<<" "<<row_x<<endl;
            
    }
    else
    {
        string v2 = top2->value;
        v2[1] = 'E';
        top2->value = v2;
        int row_x = (top2->checker-1) / col;
        int col_y = (top2->checker-1) % col;
        cout<<col_y<<" "<<row_x<<endl;
            
    }
        
        
    
    
    linkedlist * sort = nullptr;
    linkedlist * node;
    
    while(top2->next != nullptr)
    {
        top2 = top2->next;
    }
    linkedlist * a = top2;
    int r = 1;
    
    while(r < (row*col)+1)
        
    {
        
        while(a !=nullptr)
        {
            
            if(a->checker == r)
            {
                break;
            }
            a = a->prev;
        }
        
        if(sort == nullptr)
        {
            
            sort = new linkedlist(a->value,a->checker);
        }
        else
        {
            node = new linkedlist(a->value,a->checker,nullptr,sort);
            sort->next = node;
            sort = sort->next;
        }
        a = top2;
        r++;
    }
    top2 = sort;
    
    
    linkedlist * a2 = top2;
    int col2 = col;
    
    while(a2->next !=nullptr)
    {
        a2 = a2->next;
    }
    
    cout<<"    ";
    for(int v =0; v<col; v++)
    {
        cout<<"____";
    }
    cout<<"_"<<endl;
    int i=0;
    while(i < row)
    {
        if(row-1-i>9)
        {
            cout<<row-1-i<<"  ";
        }
        else{
            cout<<row-1-i<<"   ";
        }
        if(i > 0)
        {
            col2 = col;
            col2 = col2 +1;
        }
        for(int q = 0; q <col2-1; q++)
        {
            a2 = a2->prev;
        }
        int f =0;
        while(f<col)
        {
            if(a2->checker % col == 0)
            {
                cout<< a2->value<<endl;
            }
            else
            {
                cout<< a2->value;
            }
            if( f != col-1)
            {
                a2 = a2->next;

            }
            f++;
        }
        for(int q2 = 0; q2 <col-1; q2++)
        {
            a2 = a2->prev;
        }
        i++;
        
    }
    cout<<"      ";
    for(int e=0; e<col; e++)
    {
        if(e<10)
        {
            cout<<e<<"   ";
        }
        else
        {
            cout<<e<<"  ";
        }
    }
    cout<<endl;
    
}
 

template class stack<string>;
