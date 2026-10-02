//#include "Position.h"
#include <iostream>
using namespace std;
#ifndef ARRAYLIST_H
#define ARRAYLIST_H


template<typename T>
class ArrayList{ //mostly feature complete, god i hope it works. 
    T* data;
    int length;
    int capacity;

    public:
        ArrayList(){
            capacity = 0;
            length = 0;
            data = nullptr;
        }
        ArrayList(int c, int l){
            capacity = c;
            length = l;
            data = new T[capacity];
        }
        ArrayList(const ArrayList& rhs){
            capacity = rhs.capacity;
            length = rhs.length;
            data = new T[capacity];
            for(int i = 0; i < length; i++){
                data[i] = rhs.data[i];
            }
        }

        int getLength(){
            return length;
        }

        int getCapacity(){
            return capacity;
        }

        bool isEmpty(){
            if(length == 0){
                return true;
            }
            else{
                return false;
            }
        }

        bool validIn(int i){
            if(i > length || i < 0){
                return false;
            }
            else{
                return true;
            }
        }

        void insert(int target, T d){ //works
            bool b = validIn(target);
            if(b == false){
                return;
            }
            length++;
            if(length >= capacity){
                resize();
            }
            
            T* da = new T[capacity];
            
            
            for(int i = 0; i < target; i++){
                da[i] = data[i];
            }
            da[target] = d;
            for(int i = target+1; i < length; i++){
                da[i] = data[i-1];
            }
            
            delete [] data;
            data = da;
        }

        void remove(int target){ //works
            bool b = validIn(target);
            if(b == false){
                return;
            }
            T* da = new T[capacity];
            for(int i = 0; i < target; i++){
                da[i] = data[i];
            }
            for(int i = target+1; i < length; i++){
                da[i-1] = data[i];
            }
            
            delete [] data;
            data = da;
            length--;

        }

        void display(){ //debugging
            for(int i = 0; i < length; i++){
                cout << data[i] << endl;
            }
        }

        void resize(){
            if(length >= capacity){
                if(capacity == 0){
                    capacity += 5;
                }
                int newCapacity = capacity *2;
                T* newData = new T[newCapacity];
                for(int i = 0; i < length; i++){
                    newData[i] = data[i];
                }
                delete [] data;
                data = newData;
                capacity = newCapacity;
            }
        }

        ArrayList& operator=(const ArrayList& rhs){
            capacity = rhs.capacity;
            length = rhs.length;
            data = new T[capacity];
            for(int i = 0; i < length; i++){
                data[i] = rhs.data[i];
            }
            return *this;
        }
        
        ~ArrayList(){
            delete [] data;
        }
};
#endif