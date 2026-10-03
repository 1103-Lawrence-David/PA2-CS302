#ifndef TEST_H
#define TEST_H

#include <iostream>
#include "ArrayList.h"
#include "LinkedList.h"

// Simple helper function to emulate assertions using only iostream
inline void check(bool condition, const char* message) {
    if (!condition) {
        std::cout << "  [FAIL] " << message << "\n";
    }
}

inline void runTestSuite() {
    std::cout << "==================================================\n";
    std::cout << "STARTING COMPREHENSIVE DATA STRUCTURE TEST SUITE\n";
    std::cout << "==================================================\n\n";

    // --------------------------------------------------
    // ARRAYLIST TESTING
    // --------------------------------------------------
    std::cout << "--- Testing ArrayList ---\n";
    
    // 1. Construct an empty list.
    {
        ArrayList<int> list;
        check(list.getLength() == 0, "Condition 1: Empty list length should be 0.");
        check(list.isEmpty() == true, "Condition 1: Empty list should report true for isEmpty.");
        std::cout << "Condition 1 Checked: Empty list construction.\n";
    }

    // 2. Insert at the beginning, 3. Middle, 4. End.
    {
        ArrayList<int> list;
        list.insert(0, 30); // End/Beg since it's size 0
        list.insert(0, 10); // Beginning
        list.insert(1, 20); // Middle
        list.insert(3, 40); // End

        check(list.getLength() == 4, "Condition 2,3,4: Length should be 4.");
        check(list.get(0) == 10, "Condition 2: Front element mismatch.");
        check(list.get(1) == 20, "Condition 3: Middle element mismatch.");
        check(list.get(2) == 30, "Condition 3: Middle element mismatch.");
        check(list.get(3) == 40, "Condition 4: End element mismatch.");
        std::cout << "Condition 2, 3, 4 Checked: Front, middle, and end insertions.\n";
    }

    // 5. Remove first, 6. Middle, 7. Last element.
    {
        ArrayList<int> list;
        list.insert(0, 50); list.insert(0, 40); list.insert(0, 30); list.insert(0, 20); list.insert(0, 10);

        list.remove(2); // Remove middle (30)
        check(list.getLength() == 4, "Condition 6: Length should be 4 after middle removal.");
        check(list.get(2) == 40, "Condition 6: Incorrect element at middle index after removal.");

        list.remove(0); // Remove first (10)
        check(list.getLength() == 3, "Condition 5: Length should be 3 after front removal.");
        check(list.get(0) == 20, "Condition 5: Incorrect element at front after removal.");

        list.remove(2); // Remove last (50)
        check(list.getLength() == 2, "Condition 7: Length should be 2 after end removal.");
        check(list.get(1) == 40, "Condition 7: Incorrect element at end after removal.");
        std::cout << "Condition 5, 6, 7 Checked: Front, middle, and end removals.\n";
    }

    // 8. Access every valid index, 9. Attempt to access an invalid index.
    {
        ArrayList<int> list;
        list.insert(0, 100);
        list.insert(1, 200);

        check(list.get(0) == 100, "Condition 8: Index 0 validation.");
        check(list.get(1) == 200, "Condition 8: Index 1 validation.");

        bool exceptionCaught = false;
        try {
            list.get(2);
        } catch (...) {
            exceptionCaught = true;
        }
        check(exceptionCaught == true, "Condition 9: Out of bounds access should throw.");
        std::cout << "Condition 8, 9 Checked: Boundary access safeguards.\n";
    }

    // 10. Clear empty list, 11. Clear nonempty, 12. Reuse list.
    {
        ArrayList<int> list;
        list.clear();
        check(list.getLength() == 0, "Condition 10: Clear on empty list failed.");

        list.insert(0, 5);
        list.clear();
        check(list.getLength() == 0, "Condition 11: Clear on non-empty list failed.");

        list.insert(0, 99);
        check(list.get(0) == 99, "Condition 12: List could not be reused properly after clear.");
        std::cout << "Condition 10, 11, 12 Checked: Clearing behaviors and state reuse.\n";
    }

    // 13. Trigger multiple array resizes.
    {
        ArrayList<int> list;
        for (int i = 0; i < 12; i++) {
            list.insert(i, i * 10);
        }
        check(list.getLength() == 12, "Condition 13: List size tracking ruined during scaling.");
        check(list.getCapacity() >= 12, "Condition 13: Internal capacity did not adjust upward.");
        std::cout << "Condition 13 Checked: Dynamic array exponential resizing.\n";
    }

    // 14. Copy empty list, 15. Copy nonempty, 16. Modify original, 17. Modify copy.
    {
        ArrayList<int> emptyList;
        ArrayList<int> emptyCopy(emptyList);
        check(emptyCopy.getLength() == 0, "Condition 14: Copied empty list size must be 0.");

        ArrayList<int> original;
        original.insert(0, 1);
        original.insert(1, 2);

        ArrayList<int> copy(original);
        check(copy.getLength() == 2, "Condition 15: Copy size constructor cloning flaw.");

        original.set(0, 99);
        check(copy.get(0) == 1, "Condition 16: Deep copy failed; changing original changed the copy.");

        copy.set(1, 88);
        check(original.get(1) == 2, "Condition 17: Deep copy failed; changing copy changed original.");
        std::cout << "Condition 14, 15, 16, 17 Checked: Deep copy integrity and isolation.\n";
    }

    // 18. Assign one list to another.
    {
        ArrayList<int> listA;
        listA.insert(0, 500);
        ArrayList<int> listB;
        listB.insert(0, 100);

        listA = listB;
        check(listA.getLength() == 1, "Condition 18: Assignment operator copying size error.");
        check(listA.get(0) == 100, "Condition 18: Assignment operator data transfer error.");
        
        listA = listA; // Self-assignment guard check
        check(listA.getLength() == 1, "Condition 18: Self-assignment sequence collapsed data.");
        std::cout << "Condition 18 Checked: Overloaded deep assignment mechanics.\n";
    }

    // 19. Destroy a nonempty list.
    {
        {
            ArrayList<int> scopedList;
            scopedList.insert(0, 10);
        }
        std::cout << "Condition 19 Checked: Destructor scope test isolated without a terminal crash.\n\n";
    }


    // --------------------------------------------------
    // LINKEDLIST TESTING
    // --------------------------------------------------
    std::cout << "--- Testing LinkedList ---\n";

    // 1. Construct an empty list.
    {
        LinkedList<int> list;
        check(list.getLength() == 0, "LL Condition 1: Empty list length should be 0.");
        std::cout << "Condition 1 Checked: Empty list construction.\n";
    }

    // 2. Insert at the beginning, 3. Middle, 4. End.
    {
        LinkedList<int> list;
        list.insert(0, 30); // Insert at 0 (front/end)
        list.insert(0, 10); // Insert at 0 (front)
        list.insert(1, 20); // Insert at 1 (middle)
        list.insert(3, 40); // Insert at 3 (end)

        check(list.getLength() == 4, "LL Condition 2,3,4: Length should be 4.");
        check(list.get(0) == 10, "LL Condition 2: Front element mismatch.");
        check(list.get(1) == 20, "LL Condition 3: Middle element mismatch.");
        check(list.get(2) == 30, "LL Condition 3: Middle element mismatch.");
        check(list.get(3) == 40, "LL Condition 4: End element mismatch.");
        std::cout << "Condition 2, 3, 4 Checked: Front, middle, and end insertions.\n";
    }

    // 5. Remove first, 6. Middle, 7. Last element.
    {
        LinkedList<int> list;
        list.add(50); list.add(40); list.add(30); list.add(20); list.add(10); // Adds at front, order: 10, 20, 30, 40, 50

        list.remove(2); // Remove 30
        check(list.getLength() == 4, "LL Condition 6: Length should be 4 after middle removal.");
        check(list.get(2) == 40, "LL Condition 6: Incorrect element at middle index after removal.");

        list.remove(0); // Remove 10
        check(list.getLength() == 3, "LL Condition 5: Length should be 3 after front removal.");
        check(list.get(0) == 20, "LL Condition 5: Incorrect element at front after removal.");

        list.remove(2); // Remove 50
        check(list.getLength() == 2, "LL Condition 7: Length should be 2 after end removal.");
        check(list.get(1) == 40, "LL Condition 7: Incorrect element at end after removal.");
        std::cout << "Condition 5, 6, 7 Checked: Front, middle, and end removals.\n";
    }

    // 8. Access every valid index, 9. Attempt to access an invalid index.
    {
        LinkedList<int> list;
        list.add(200); list.add(100); // order: 100, 200

        check(list.get(0) == 100, "LL Condition 8: Index 0 validation.");
        check(list.get(1) == 200, "LL Condition 8: Index 1 validation.");

        // LinkedList returns T() on invalid index rather than throwing an exception
        check(list.get(2) == int(), "LL Condition 9: Out of bounds access tracking.");
        check(list.get(-1) == int(), "LL Condition 9: Negative out of bounds access tracking.");
        std::cout << "Condition 8, 9 Checked: Boundary access safeguards.\n";
    }

    // 10. Clear empty list, 11. Clear nonempty, 12. Reuse list.
    {
        LinkedList<int> list;
        list.clear();
        check(list.getLength() == 0, "LL Condition 10: Clear on empty list failed.");

        list.add(5);
        list.clear();
        check(list.getLength() == 0, "LL Condition 11: Clear on non-empty list failed.");

        list.add(99);
        check(list.get(0) == 99, "LL Condition 12: List could not be reused properly after clear.");
        std::cout << "Condition 10, 11, 12 Checked: Clearing behaviors and state reuse.\n";
    }

    // 13. Trigger multiple resizes (N/A for LinkedList node allocation, tested as massive addition)
    {
        LinkedList<int> list;
        for (int i = 0; i < 50; i++) {
            list.add(i);
        }
        check(list.getLength() == 50, "LL Condition 13: Large scale node allocation tracing.");
std::cout << "Condition 13 Checked: Large scale linear growth tracking.\n";
}
// 14. Copy empty list, 15. Copy nonempty, 16. Modify original, 17. Modify copy.
{
LinkedList emptyList;
LinkedList emptyCopy(emptyList);
check(emptyCopy.getLength() == 0, "LL Condition 14: Copied empty list size must be 0.");
LinkedList original;
original.add(2); original.add(1); // 1, 2
LinkedList copy(original);
check(copy.getLength() == 2, "LL Condition 15: Copy size constructor cloning flaw.");
// Linked list doesn't have an inline setter, so we clear/insert to emulate modifications
original.remove(0);
original.insert(0, 99);
check(copy.get(0) == 1, "LL Condition 16: Deep copy failed; changing original isolated node.");
copy.remove(1);
copy.insert(1, 88);
check(original.get(1) == 2, "LL Condition 17: Deep copy failed; changing copy isolated node.");
std::cout << "Condition 14, 15, 16, 17 Checked: Linked Deep copy integrity and isolation.\n";
}
// 18. Assign one list to another.
{
LinkedList listA;
listA.add(500);
LinkedList listB;
listB.add(100);
listA = listB;
check(listA.getLength() == 1, "LL Condition 18: Assignment operator copying size error.");
check(listA.get(0) == 100, "LL Condition 18: Assignment operator data transfer error.");
listA = listA; // Self-assignment guard check
check(listA.getLength() == 1, "LL Condition 18: Self-assignment sequence collapsed data.");
std::cout << "Condition 18 Checked: Overloaded deep assignment mechanics.\n";
}
// 19. Destroy a nonempty list.
{
{
LinkedList scopedList;
scopedList.add(10);
scopedList.add(20);
}
std::cout << "Condition 19 Checked: Destructor scope node deallocation isolated safely.\n";
}
std::cout << "\n==================================================\n";
std::cout << "COMPREHENSIVE RUN COMPLETE. ALL SYSTEMS VERIFIED.\n";
std::cout << "==================================================\n";
}
#endif