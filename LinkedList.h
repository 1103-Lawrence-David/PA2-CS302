#include "Node.h"

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template <typename T>
class LinkedList {
    Node<T>* head;
    Node<T>* tail;
    int length;

    public:
        LinkedList(){
            head = nullptr;
            tail = nullptr;
            length = 0;
        }

        LinkedList(Node<T>* h, Node<T>* t, int l){
            length = l;
            tail = t;
            head = h;
        }

        LinkedList(const LinkedList& rhs){
            head = nullptr;
            tail = nullptr;
            length = 0;

            if(rhs.head == nullptr){
                return ;
            }

            Node<T>* currentRhs = rhs.head;

            while(currentRhs != nullptr){
                Node<T>* newNode = new Node<T>(currentRhs->getData(), nullptr);
                
                if (head == nullptr){
                    head = newNode;
                    tail = newNode;
                }
                else{
                    tail->setNext(newNode);
                    tail = newNode;
                }

                length++;
                currentRhs = currentRhs->getNext();
            }
        }

        LinkedList& operator=(const LinkedList& rhs){
            if(this == &rhs){
                return *this;
            }

            clear();
            
            if(rhs.head == nullptr){
                return *this;
            }

            Node<T>* currentRhs = rhs.head;

            while(currentRhs != nullptr){
                Node<T>* newNode = new Node<T>(currentRhs->getData(), nullptr);
                
                if (head == nullptr){
                    head = newNode;
                    tail = newNode;
                }
                else{
                    tail->setNext(newNode);
                    tail = newNode;
                }
                
                length++;
                currentRhs = currentRhs->getNext();
            }

            return *this;
        }
        
        T getHeadData(){
            if (head != nullptr){
                return head->getData();
            }
            return T();
        }

        T getTailData(){
            if (tail != nullptr){
                return tail->getData();
            }
            return T();
        }

        int getLength(){
            return length;
        }
        
        T get(int index){
            if(index < 0 || index >= length || head == nullptr){
                return T();
            }
            
            Node<T>* current = head;
            
            for(int i = 0; i < index; i++){
                current = current->getNext();
            }

            return current->getData();
        }

        void add(T val){
            Node<T>* newNode = new Node<T>(val, nullptr);
            newNode->setNext(head);
            head = newNode;

            if(tail == nullptr){
                tail = newNode;
            }

            length++;
        }

        void insert(int index, T val){
            if (index < 0 || index > length){
                return;
            }

            if (index == 0){
                add(val);
                return;
            }

            Node<T>* current = head;
            for (int i = 0; i < index - 1; ++i) {
                current = current->getNext();
            }

            Node<T>* newNode = new Node<T>(val, nullptr);
            newNode->setNext(current->getNext());
            current->setNext(newNode);

            if (newNode->getNext() == nullptr) {
                tail = newNode;
            }

            length++;
        }

        void remove(int index) {
            if (index < 0 || index >= length || head == nullptr) {
                return;
            }

            if (index == 0){
                Node<T>* temp = head;
                head = head->getNext();
                delete temp;
                
                if (head == nullptr) {
                    tail = nullptr;
                }

                length--;
                
                return;
            }

            Node<T>* current = head;

            for(int i = 0; i < index-1; i++){
                current = current->getNext();
            }

            Node<T>* temp = current->getNext();
            current->setNext(temp->getNext());

            if(temp == tail){
                tail = current;
            }

            delete temp;
            length --;
            return;
        }

        void clear(){
            Node<T>* current = head;
            
            while(current != nullptr){
                Node<T>* nextNode = current->getNext();
                delete current;
                current = nextNode;
            }
            
            head = nullptr;
            length = 0;
            tail = nullptr;
        }

        ~LinkedList(){
            clear();
        }
    
};
#endif