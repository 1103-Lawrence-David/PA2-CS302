#include <iostream>
using namespace std;

struct Position{
    int row;
    int column; 
    
    bool operator ==(const Position& other) const{
        return row == other.row &&
            column == other.column;
    }
};