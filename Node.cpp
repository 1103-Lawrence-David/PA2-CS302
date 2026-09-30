#include "Node.h"
        
    Node::Node(){
        data = -1;
        next = nullptr;
    }

    Node::Node(int d, Node* n){
        data = d;
        next = n; 
    }

    Node::Node(const Node& rhs){
        data = rhs.data;
        next = rhs.next;
    }

    int Node::getData(){
        return data;
    }

    void Node::setData(int d){
        data = d;
    }

    Node* Node::getNext(){
        return next;
    }

    void Node::setNode(Node* n){
        next = n;
    }    