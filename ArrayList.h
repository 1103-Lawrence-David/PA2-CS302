#include <iostream>
using namespace std;

#ifndef ARRAYLIST_H
#define ARRAYLIST_H


template<typename T>
class ArrayList{
    T* data;
    int length;
    int capacity;

    public:
        ArrayList(){
            capacity = 0;
            length = 0;
            data = nullptr;
        }
        ArrayList(int c){
            capacity = c;
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
            if(int i > length){
                return false;
            }
            else{
                return true;
            }
        }
        void insert(int index, T d){
            int i = 0;
            bool b = validIn(index);
            if(i < index && b == true){
                
            }
        }

        void remove(){

        }

        void resize(){
            if(length >= capacity){
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