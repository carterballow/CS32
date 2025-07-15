#include "TaskList.h"
#include <iostream>
#include <cassert> // For using assert() to automatically check conditions
#include <string>
// A helper function to print test results
void printTestResult(const std::string& testName, bool passed) {
    std::cout << testName << ": " << (passed ? "PASSED ✅" : "FAILED ❌") << std::endl;
}

int main() {
    std::cout << "--- Starting TaskList Test Suite ---" << std::endl;

    // --- Test 1: Constructor, empty(), size(), and addBack() ---
    std::cout << "\n## Test 1: Basic Construction & Adding ##" << std::endl;
    TaskList tasks;
    printTestResult("Initial state (empty)", tasks.empty());
    printTestResult("Initial state (size)", tasks.size() == 0);

    tasks.addBack("Reply to client emails");
    tasks.addBack("Finish history essay");
    tasks.addBack("Study for math quiz");
    
    printTestResult("After adding (not empty)", !tasks.empty());
    printTestResult("After adding (size)", tasks.size() == 3);
    std::cout << "Current List:" << std::endl;
    tasks.printAll(); // Visually inspect the output

    std::cout << "----------------------------------------" << std::endl;

    // --- Test 2: get() and find() ---
    std::cout << "\n## Test 2: Accessing & Finding Elements ##" << std::endl;
    std::string task;
    bool success = tasks.get(0, task);
    printTestResult("get() first element", success && task == "Reply to client emails");
    
    success = tasks.get(2, task);
    printTestResult("get() last element", success && task == "Study for math quiz");

    success = tasks.get(3, task); // Out of bounds
    printTestResult("get() out of bounds", !success);

    int pos = tasks.find("Finish history essay");
    printTestResult("find() existing element", pos == 1);

    pos = tasks.find("Non-existent task");
    printTestResult("find() non-existent element", pos == -1);

    std::cout << "----------------------------------------" << std::endl;
    
    // --- Test 3: removeFront() ---
    std::cout << "\n## Test 3: Removing Elements ##" << std::endl;
    success = tasks.removeFront(); // Removes "Reply to client emails"
    printTestResult("removeFront() on non-empty list", success && tasks.size() == 2);
    
    tasks.get(0, task);
    printTestResult("Check new front element", task == "Finish history essay");
    
    tasks.removeFront(); // Removes "Finish history essay"
    tasks.removeFront(); // Removes "Study for math quiz"
    printTestResult("List is empty after all removals", tasks.empty());

    success = tasks.removeFront(); // Try to remove from empty list
    printTestResult("removeFront() on empty list", !success);

    std::cout << "----------------------------------------" << std::endl;

    // --- Test 4: Copy Constructor ---
    std::cout << "\n## Test 4: Copy Constructor ##" << std::endl;
    TaskList original;
    original.addBack("Task A");
    original.addBack("Task B");

    TaskList copy = original; // Invokes copy constructor
    printTestResult("Copied list has correct size", copy.size() == 2);

    copy.removeFront(); // Modify the copy
    printTestResult("Original list is unaffected by modifying copy", original.size() == 2);
    printTestResult("Copy was modified correctly", copy.size() == 1);

    std::cout << "----------------------------------------" << std::endl;

    // --- Test 5: Assignment Operator ---
    std::cout << "\n## Test 5: Assignment Operator ##" << std::endl;
    TaskList another_list;
    another_list.addBack("Task C");

    another_list = original; // Invokes assignment operator
    printTestResult("Assigned list has correct size", another_list.size() == 2);
    another_list.get(1, task);
    printTestResult("Assigned list has correct content", task == "Task B");

    // Test self-assignment
    another_list = another_list;
    printTestResult("Self-assignment doesn't break list", another_list.size() == 2);

    std::cout << "----------------------------------------" << std::endl;

    // --- Test 6: clear() ---
    std::cout << "\n## Test 6: Clearing the List ##" << std::endl;
    TaskList list_to_clear;
    list_to_clear.addBack("A");
    list_to_clear.addBack("B");
    list_to_clear.clear();

    printTestResult("clear() results in size 0", list_to_clear.size() == 0);
    printTestResult("clear() results in empty() being true", list_to_clear.empty());

    std::cout << "\n--- Test Suite Finished ---" << std::endl;

    return 0;
}