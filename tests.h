#ifndef TESTS_H
#define TESTS_H

#include "ArrayList.h"
#include "LinkedList.h"

static void check(bool condition, const char* msg){
    if(!condition){
        cout << " [FAIL] " << msg << endl;
    }
}

static void runTestSuite(){
    cout << "--- Running Tests---" << endl;

    cout << "Creating empty, inserting at beginning, middle, end" << endl;
    ArrayList<int> al; 
    al.insert(0, 30); 
    al.insert(0, 10); 
    al.insert(1, 20); 
    al.insert(3, 40);
    check(al.getLength() == 4 && al.get(0) == 10 && al.get(2) == 30, "ArrayList Insertions/creation");
    
    cout << "ArrayList removals..." << endl;
    al.remove(1); 
    al.remove(0); 
    al.remove(1);
    check(al.getLength() == 1 && al.get(0) == 30, "ArrayList Removals");
    
    cout << "ArrayList invalid index boundaries..." << endl;
    check(al.get(-1) == 0 && al.get(2) == 0, "ArrayList Invalid Access");
    
    cout << "ArrayList clear and reuse..." <<endl;
    al.clear(); 
    al.insert(0, 99);
    check(al.getLength() == 1 && al.get(0) == 99, "ArrayList Clear & Reuse");

    cout << "ArrayList multiple expansions (resizing)..." << endl;
    ArrayList<int> alRes;
    for(int i=0; i<15; i++){
        alRes.insert(i, i);
    }
    check(alRes.getLength() == 15 && alRes.getCapacity() >= 15, "ArrayList Resizing");

    cout << "ArrayList copy constructor & isolation..." << endl;
    ArrayList<int> alOrig; 
    alOrig.insert(0, 5); 
    ArrayList<int> alCopy(alOrig);
    alOrig.set(0, 2); 
    alCopy.set(0, 7);
    check(alOrig.get(0) == 2 && alCopy.get(0) == 7, "ArrayList Copy Isolation");

    cout << "ArrayList assignment operator..." << endl;
    ArrayList<int> alAsg; 
    alAsg = alOrig; 
    alAsg = alAsg;
    check(alAsg.getLength() == 1 && alAsg.get(0) == 2, "ArrayList Assignment");

    cout << "LinkedList insertions..." << endl;
    LinkedList<int> ll; 
    ll.insert(0, 30); 
    ll.insert(0, 10); 
    ll.insert(1, 20); 
    ll.insert(3, 40);
    check(ll.getLength() == 4 && ll.get(0) == 10 && ll.get(3) == 40, "LinkedList Insertions");
    
    cout << "LinkedList removals..." << endl;
    ll.remove(1); 
    ll.remove(0); 
    ll.remove(1);
    check(ll.getLength() == 1 && ll.get(0) == 30, "LinkedList Removals");
    
    cout << "LinkedList invalid boundaries..." <<endl;
    check(ll.get(-1) == 0 && ll.get(2) == 0, "LinkedList Invalid Access");

    cout << "LinkedList clear and reuse..." <<endl;
    ll.clear(); 
    ll.add(5); 
    ll.clear(); 
    ll.add(85);
    check(ll.getLength() == 1 && ll.get(0) == 85, "LinkedList Clear & Reuse");

    cout << "LinkedList copy constructor..." << endl;
    LinkedList<int> llOrig; 
    llOrig.insert(0, 1); 
    LinkedList<int> llCopy(llOrig);
    
    cout << "LinkedList element modification & isolation..." << endl;
    llOrig.remove(0); 
    llOrig.insert(0, 9);
    check(llOrig.get(0) == 9 && llCopy.get(0) == 1, "LinkedList Copy Isolation");

    cout << "LinkedList assignment operator..." << endl;
    LinkedList<int> llAsg; 
    llAsg = llOrig; 
    llAsg = llAsg;
    check(llAsg.getLength() == 1 && llAsg.get(0) == 9, "LinkedList Assignment");
    
    cout << "Testing Finished Safely." << endl;
}
#endif