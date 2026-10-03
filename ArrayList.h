#ifndef ARRAYLIST_H
#define ARRAYLIST_H
#include <iostream>
using namespace std;

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

    ArrayList(int c, int l){
        capacity = c;
        length = l;
        if(capacity > 0){
            data = new T[capacity];
        } 
        else{
            data = nullptr;
        }
    }

    ArrayList(const ArrayList& rhs){
        capacity = rhs.capacity;
        length = rhs.length;
        if(capacity > 0){
            data = new T[capacity];
            for(int i = 0; i < length; i++){
                data[i] = rhs.data[i];
            }
        } 
        else{
            data = nullptr;
        }
    }

    int getLength(){ 
        return length; 
    }
    int getCapacity(){ 
        return capacity;
    }
    bool isEmpty(){
        return length == 0; 
    }

    bool validIn(int i){
        if(i > length || i < 0){
            return false;
        }
        return true;
    }

    T get(int index){
        if(index < 0 || index >= length){
            return T();
        }
        return data[index];
    }

    void set(int index, T val){
        if(index >= 0 && index < length){
            data[index] = val;
        }
    }

    void insert(int target, T d){
        if(!validIn(target)) {
            return;
        }
        
        if(length >= capacity){
            resize();
        }
        
        
        for(int i = length; i > target; i--){
            data[i] = data[i - 1];
        }
        
        data[target] = d;
        length++;
    }

    void remove(int target){
        if(target < 0 || target >= length){ 
            return;
        }

        for(int i = target; i < length - 1; i++){
            data[i] = data[i + 1];
        }
        
        length--;
    }

    void clear(){
        delete[] data;
        data = nullptr;
        length = 0;
        capacity = 0;
    }

    void display(){
        for(int i = 0; i < length; i++){
            cout << data[i] << endl;
        }
    }

    void resize(){
        int newCapacity;
        if(capacity == 0){
            newCapacity = 5;
        }

        else{
            newCapacity = capacity * 2;
        }
        
        T* newData = new T[newCapacity];
        for(int i = 0; i < length; i++){
            newData[i] = data[i];
        }
        
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }

    ArrayList& operator=(const ArrayList& rhs){
        if(this == &rhs){
            return *this;
        }
        delete[] data;
        capacity = rhs.capacity;
        length = rhs.length;
        if(capacity > 0){
            data = new T[capacity];
            for(int i = 0; i < length; i++){
                data[i] = rhs.data[i];
            }
        }
        else{
            data = nullptr;
        }
        return *this;
    }
    
    ~ArrayList(){ 
        delete[] data; 
    }
};
#endif