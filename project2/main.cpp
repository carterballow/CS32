#include "TaskList.h"
#include <iostream>
#include <cassert> // For using assert() to automatically check conditions
#include <string>
using namespace std;
// A helper function to print test results
void printTestResult(const string& testName, bool passed) {
    cerr << testName << ": " << (passed ? "PASSED ✅" : "FAILED ❌") << endl;
}

int main() {

    cerr << "\nconstruction" << endl;
    TaskList tasks;
    printTestResult("empty", tasks.empty());
    printTestResult("size", tasks.size() == 0);

    tasks.addBack("goon");
    tasks.addBack("eat hot pancake");
    tasks.addBack("rip ur favorite shirt");
    
    printTestResult("not empty", !tasks.empty());
    printTestResult("size should be 3", tasks.size() == 3);
    cerr << "Current List:" << endl;
    tasks.printAll();

    cerr << "----------------------------------------" << endl;

    cerr << "\nfind elements" << endl;
    string task;
    bool success = tasks.get(0, task);
    printTestResult("get() first element", success && task == "goon");
    
    success = tasks.get(2, task);
    printTestResult("get() last element", success && task == "rip ur favorite shirt");

    success = tasks.get(3, task); // Out of bounds
    printTestResult("get() out of bounds", !success);

    int pos = tasks.find("eat hot pancake");
    printTestResult("find() existing element", pos == 1);

    pos = tasks.find("non-existent task");
    printTestResult("find() non-existent element", pos == -1);

    cerr << "----------------------------------------" << endl;
    
    // --- Test 3: removeFront() ---
    cerr << "\n## Test 3: Removing Elements ##" << endl;
    success = tasks.removeFront(); // Removes "Reply to client emails"
    printTestResult("removeFront() on non-empty list", success && tasks.size() == 2);
    
    cerr << tasks.get(0, task) << endl;
    cerr << task << endl;
    printTestResult("Check new front element", task == "eat hot pancake");
    
    tasks.removeFront(); // Removes "Finish history essay"
    tasks.removeFront(); // Removes "Study for math quiz"
    printTestResult("List is empty after all removals", tasks.empty());

    success = tasks.removeFront(); // Try to remove from empty list
    printTestResult("removeFront() on empty list", !success);

    cerr << "----------------------------------------" << endl;

    // --- Test 4: Copy Constructor ---
    cerr << "\n## Test 4: Copy Constructor ##" << endl;
    TaskList original;
    original.addBack("Task A");
    original.addBack("Task B");

    TaskList copy = original; // Invokes copy constructor
    printTestResult("Copied list has correct size", copy.size() == 2);

    copy.removeFront(); // Modify the copy
    printTestResult("Original list is unaffected by modifying copy", original.size() == 2);
    printTestResult("Copy was modified correctly", copy.size() == 1);

    cerr << "----------------------------------------" << endl;

    // --- Test 5: Assignment Operator ---
    cerr << "\n## Test 5: Assignment Operator ##" << endl;
    TaskList another_list;
    another_list.addBack("Task C");

    another_list = original; // Invokes assignment operator
    printTestResult("Assigned list has correct size", another_list.size() == 2);
    another_list.get(1, task);
    printTestResult("Assigned list has correct content", task == "Task B");

    // Test self-assignment
    another_list = another_list;
    printTestResult("Self-assignment doesn't break list", another_list.size() == 2);

    cerr << "----------------------------------------" << endl;

    // --- Test 6: clear() ---
    cerr << "\n## Test 6: Clearing the List ##" << endl;
    TaskList list_to_clear;
    list_to_clear.addBack("A");
    list_to_clear.addBack("B");
    list_to_clear.clear();

    printTestResult("clear() results in size 0", list_to_clear.size() == 0);
    printTestResult("clear() results in empty() being true", list_to_clear.empty());

    cerr << "\n--- Test Suite Finished ---" << endl;

    return 0;
}