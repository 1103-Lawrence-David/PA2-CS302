#include <iostream>
using namespace std;

struct Position{
    int row;
    int column; 
    Position(){
        row = 0;
        column = 0;
    }

    Position(int r, int c){
        row = r;
        column = c;
    }

    Position(const Position& rhs){
        row = rhs.row;
        column = rhs.column;
    }

    bool operator ==(const Position& other) const{
        return row == other.row &&
            column == other.column;
    }
};