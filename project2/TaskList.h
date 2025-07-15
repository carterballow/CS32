#ifndef TASKLIST_H
#define TASKLIST_H

#include <string>

class TaskList {
private:
    struct Node {
        std::string m_task;
        Node* m_next;
        Node* m_prev;

        Node(const std::string& task) : m_task(task), m_next(nullptr), m_prev(nullptr) {}
    };

    Node* m_start;
    Node* m_end;
    int m_size;

    // Private helper functions
    void copyList(const TaskList& other);
    void freeList(); // Same as clear()
    Node* getNode(int pos) const;

public:
    // Constructor and Rule of Three
    TaskList();
    ~TaskList();
    TaskList(const TaskList& other);
    TaskList& operator=(const TaskList& rhs);

    // Member functions
    bool empty() const;
    int size() const;
    void addBack(const std::string& task);
    bool removeFront();
    bool get(int pos, std::string& task) const;
    int find(const std::string& task) const;
    void clear();
    void printAll() const;
};

#endif // TASKLIST_H