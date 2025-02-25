
#include <iostream>
#include "linkedlist.h"

#include <string>
using namespace std;


int main() {
    
    int a,b,c;
    cout<<"Enter the number of mazes: ";
    cin>>c;
    cout<<"Enter the number of rows and columns (M and N): ";
    cin>>a>>b;
    stack<string> abc(a,b);
    int d =0;
    cout<<"All mazes are generated."<<endl;
    while(d <c)
    {
        abc.cell_number();
        abc.push();
        abc.sorted();
     
        abc.maze();
        d++;
    }
    int enter_x,enter_y,exit_x,exit_y,which_maze;
    cout<<"Enter a maze ID between 1 to "<<d<<" inclusive to find a path: ";
    cin>>which_maze;
    cout<<"Enter x and y coordinates of the entry points (x,y) or (column,row): ";
    cin>> enter_x >> enter_y;
    cout<<"Enter x and y coordinates of the exit points (x,y) or (column,row): ";
    cin >>exit_x>>exit_y;
    abc.show_walls();
    abc.maze_road(enter_x,enter_y,exit_x,exit_y);
    
    
    return 0;
}
