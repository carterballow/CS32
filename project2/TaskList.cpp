#include "TaskList.h"
#include <iostream>

// 0/3
TaskList::TaskList() {
    m_start = nullptr;
    m_end = nullptr;
    m_size = 0;
}

// 1/3
TaskList::~TaskList() {
    clear();
}

// 2/3
TaskList::TaskList(const TaskList& other) {
  
    m_start = nullptr;
    m_end = nullptr;
    m_size = 0;
    // Copy all nodes from the other list
    copyList(other);
}

// 3/3
TaskList& TaskList::operator=(const TaskList& rhs) {
    if (this != &rhs) { // this is the check for self assignment
        clear();       
        copyList(rhs);   
    }
    return *this;
}

//is the list empty
bool TaskList::empty() const {
    return m_size == 0;
}

// Gives the user the size which is a member function so that it doesnt get altered on accident
int TaskList::size() const {
    return m_size;
}

// Adds tasks to the end, this is how you essentially create it
void TaskList::addBack(const std::string& task) {
    Node *newNode = new Node(task);
    if(m_start == nullptr){
        m_start = newNode;
        m_end = newNode;
    }
    else{
        m_end->m_next = newNode;
        newNode->m_prev = m_end;
        newNode->m_next = nullptr;
        m_end = newNode;
    }
    newNode = nullptr;
    m_size++;
}

// Removes tasks from the beginning of the list, has to make a temp in order to correctly index it. 
bool TaskList::removeFront() {
    if (empty()) {
        return false;
    }

    Node* temp = m_start;
    if (m_size == 1) { 
        m_start = nullptr;
        m_end = nullptr;
    } else { 
        m_start = m_start->m_next;
        m_start->m_prev = nullptr;
    }

    delete temp;
    m_size--;
    return true;
}

bool TaskList::get(int pos, std::string& task) const {
    if (pos < 0 || pos >= m_size) {
        return false;
    }
    Node* targetNode = getNode(pos);
    task = targetNode->m_task;
    return true;
}

// Finds a task and returns its 0-based position
int TaskList::find(const std::string& task) const {
    Node* current = m_start;
    int position = 0;
    while (current != nullptr) {
        if (current->m_task == task) {
            return position;
        }
        current = current->m_next;
        position++;
    }
    return -1; // Not found
}

// Deletes all nodes and resets the list
void TaskList::clear() {
    Node* current = m_start;
    while (current != nullptr) {
        Node* nextNode = current->m_next;
        delete current;
        current = nextNode;
    }
    m_start = nullptr;
    m_end = nullptr;
    m_size = 0;
}

// Prints all tasks to the console (using cerr as specified)
void TaskList::printAll() const {
    Node* current = m_start;
    while (current != nullptr) {
        std::cerr << current->m_task << std::endl;
        current = current->m_next;
    }
}

// Private helper to copy a list
void TaskList::copyList(const TaskList& other) {
    Node *current = other.m_start;
    while(current != nullptr){
        addBack(current->m_task);
        current = current->m_next;
    }
}

// Private helper to free memory (same as clear)
void TaskList::freeList() {
    clear();
}

// Private helper to get a node at a 0-based position
TaskList::Node* TaskList::getNode(int pos) const {
    // This helper assumes 'pos' is valid.
    Node* current = m_start;
    for (int i = 0; i < pos; i++) {
        current = current->m_next;
    }
    return current;
}