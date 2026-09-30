#include "Node.h"

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template <typename T>
class LinkedList {
    Node* head;
    int length;

    public:
        LinkedList(){
            head = nullptr;
            length = 0;
        }

        LinkedList(Node* h, int l){
            length = l;
            head = new T[length];
        }

        LinkedList(const LinkedList& rhs){
            length = rhs.length;
            head = new T[length];
            for(int i = 0; i < length; i++){
                head[i] = rhs.head[i];
            }
        }
        getLength(){

        }

        setLength(){

        }

        getNext(){

        }
        setNext(){

        }
        LinkedList& operator=(const LinkedList& rhs){
            length = rhs.length;
            head = new T[length];
            for(int i = 0; i < length; i++){
                head[i] = rhs.head[i];
            }
            return *this;
        }

        ~LinkedList(){
            delete[] head;
        }
};
#endif