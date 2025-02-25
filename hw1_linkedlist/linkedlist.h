#pragma


#ifndef linkedlist_h
#define linkedlist_h

template <class T>
class iterator;

template <class T>
class stack;

template <class T>
class linkedlist
{
    linkedlist(const T & val = T( ), const int & check = int(), linkedlist* n = nullptr , linkedlist* p = nullptr)
    : value(val), checker(check), next(n), prev(p) {}
    
    T value;
    int checker;
    linkedlist *next;
    linkedlist *prev;
    
    friend class iterator<T>;
};

template<class T>
class iterator{
public:
    iterator(): currentCell(nullptr) {}
    bool checkEnd() const
    {
        return currentCell == nullptr;
    }
    void nextCell(){
        if(!checkEnd()) currentCell = currentCell->next;
    }
    
private:
    linkedlist<T>*currentCell;
    
    iterator(linkedlist<T> *node)
    : currentCell(node){}
    
    friend class stack<T>;
    
};

template<class T>
class stack
{
private:
    struct linkedlist
    {
        T value;
        int checker;
        linkedlist *next;
        linkedlist *prev;
        
        linkedlist(const T & val = T( ), const int & check = int(), linkedlist* n = nullptr, linkedlist* p = nullptr)
        : value(val), checker(check), next(n), prev(p) {}
    };
    linkedlist *top;
    linkedlist *top2;
    int col;
    int row;
    int *arr;
    linkedlist * arr2;
    
public:
    stack(int q, int w);
    void pop();
    void push(); // push every cell randomly
    void print();
    void cell_number();
    bool check(); // check if there is a unvisited cell
    bool pop_check(linkedlist * q);
    void maze();
    void sorted();
    void maze_road(int enter_x, int enter_y, int exit_x, int exit_y);
    void show_walls();
    void mazes(int q);
    void which_maze(int x);
};


#endif /* linkedlist_h */
