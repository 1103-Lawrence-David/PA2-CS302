#include "LinkedList.h"
#include "ArrayList.h"
//Linked list test file: 

//void checkTest(bool condition, const char* testName);

// int test(){ 
//     LinkedList<Position> list; 
//     list.insert(0, Position(1,1)); 
//     list.insert(0, Position(1, 1)); 
//     checkTest(list.getHeadData() == Position(1, 1), "Test 2: Head placement match"); 
//     checkTest(list.getTailData() == Position(1, 1), "Test 2: Tail single alignment match"); 
//     // 3. Insert in the middle. 
//     list.insert(1, Position(3, 3)); 
//     list.insert(1, Position(2, 2)); 
//     checkTest(list.get(1) == Position(2, 2), "Test 3: Mid element splice matching"); 
//     // 4. Insert at the end. 
//     list.insert(3, Position(4, 4)); checkTest(list.getTailData() == Position(4, 4), "Test 4: Tail element assignment match"); 
//     // 5. Remove the first element. 
//     list.remove(0); 
//     checkTest(list.getHeadData() == Position(2, 2), "Test 5: Left side removal updates head"); 
//     // 6. Remove a middle element. 
//     list.remove(1); checkTest(list.get(1) == Position(4, 4), "Test 6: Middle slice deletion link repair"); 
//     // 7. Remove the last element. 
//     list.remove(1); 
//     checkTest(list.getTailData() == Position(2, 2), "Test 7: Tail drop updates final node references"); checkTest(list.getHeadData() == Position(2, 2), "Test 7: Head preservation holds"); 
//     // Re-populate for index queries
//      list.insert(1, Position(3, 3)); 
//      list.insert(2, Position(4, 4)); 
//      // 8. Access every valid index. 
//      checkTest(list.get(0) == Position(2, 2), "Test 8: Position 0 valid traversal"); 
//      checkTest(list.get(1) == Position(3, 3), "Test 8: Position 1 valid traversal"); 
//      checkTest(list.get(2) == Position(4, 4), "Test 8: Position 2 valid traversal"); 
//      // 9. Attempt to access an invalid index. 
//      checkTest(list.get(-1) == Position(0, 0), "Test 9: Lower bounds handling"); 
//      checkTest(list.get(5) == Position(0, 0), "Test 9: Higher bounds handling"); 
//      // 10. Clear an empty list. 
//      LinkedList<Position> emptyList; 
//      emptyList.clear(); 
//      // 11. Clear a nonempty list. 
//      list.clear(); 
//      checkTest(list.getHeadData() == Position(0, 0), "Test 11: Clearing removes head tracker elements"); 
//      // 12. Reuse a list after calling clear(). 
//      list.insert(0, Position(10, 10)); 
//      checkTest(list.getHeadData() == Position(10, 10), "Test 12: Clear-state recovery insertion");
//       // 13. Trigger multiple list growth sequences. 
//       for (int i = 1; i <= 50; ++i) { 
//         list.insert(i, Position(i, i)); 
//     } 
//     checkTest(list.get(50) == Position(50, 50), "Test 13: Large sequential insert sequence tracking"); 
//     // 14. Copy an empty list. 
//     LinkedList<Position> anotherEmptyList; 
//     LinkedList<Position> emptyCopy(anotherEmptyList); 
//     checkTest(emptyCopy.getHeadData() == Position(0, 0), "Test 14: Clear copy mapping structural matching"); 
//     // 15. Copy a nonempty list. 
//     LinkedList<Position> original; 
//     original.insert(0, Position(5, 5)); 
//     original.insert(1, Position(6, 6)); 
//     LinkedList<Position> copy(original); 
//     checkTest(copy.get(0) == Position(5, 5), "Test 15: Index 0 validation across deep duplication"); 
//     checkTest(copy.get(1) == Position(6, 6), "Test 15: Index 1 validation across deep duplication");
//      // 16. Modify the original after copying it. 
//      original.insert(2, Position(7, 7)); 
//      checkTest(copy.get(2) == Position(0, 0), "Test 16: Deep copies break tracking from structural origins"); 
//      // 17. Modify the copy without affecting the original. 
//      copy.insert(0, Position(9, 9)); 
//      checkTest(original.get(0) == Position(5, 5), "Test 17: Inbound copies isolate origin mutation actions");
//       // 18. Assign one list to another. 
//       LinkedList<Position> assignedList; 
//       assignedList = original; 
//       checkTest(assignedList.get(0) == Position(5, 5), "Test 18: Operator= replication verification sequence A"); 
//       checkTest(assignedList.get(1) == Position(6, 6), "Test 18: Operator= replication verification sequence B"); 
//       // 19. Destroy a nonempty list.
    
//     LinkedList<Position> scopeList; scopeList.insert(0, Position(1, 2)); 
    
//     std::cout << "[SUCCESS] -> All 19 tests with Position struct passed cleanly!" << std::endl; return 0;  

// }
// void checkTest(bool condition, const char* testName) {
//         if (!condition) {
//             std::cout << "[FAIL] -> " << testName << std::endl;
//             exit(1); 
//     }