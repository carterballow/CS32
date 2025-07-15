#include "TaskList.h"
#include <iostream>

// TODO: Implement all member functions

TaskList::TaskList() {
    // TODO: Initialize members
}

TaskList::~TaskList() {
    // TODO: Free all allocated memory
}

TaskList::TaskList(const TaskList& other) {
    // TODO: Copy constructor logic
}

TaskList& TaskList::operator=(const TaskList& rhs) {
    // TODO: Assignment operator logic
    return *this;
}

bool TaskList::empty() const {
    return false; // TODO: Return true if list is empty
}

int TaskList::size() const {
    return 0; // TODO: Return actual size
}

void TaskList::addBack(const std::string& task) {
    // TODO: Add new node to back
}

bool TaskList::removeFront() {
    return false; // TODO: Remove first node
}

bool TaskList::get(int pos, std::string& task) const {
    return false; // TODO: Retrieve task at pos
}

int TaskList::find(const std::string& task) const {
    return -1; // TODO: Return index of task or -1
}

void TaskList::clear() {
    // TODO: Clear the list
}

void TaskList::printAll() const {
    // TODO: Print all tasks to cerr
}

void TaskList::copyList(const TaskList& other) {
    // TODO: Deep copy all nodes from other
}

void TaskList::freeList() {
    // TODO: Free all nodes
}

TaskList::Node* TaskList::getNode(int pos) const {
    return nullptr; // TODO: Return pointer to node at pos
}
