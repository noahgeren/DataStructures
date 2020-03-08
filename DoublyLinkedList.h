#ifndef DOUBLYLINKEDLIST_H_INCLUDED
#define DOUBLYLINKEDLIST_H_INCLUDED
#include <stdio.h>

using namespace std;

template<typename T>
class DoublyLinkedList {
private:
    struct Node {
        Node* next;
        Node* prev;
        T value;
        Node(T value){
            this->value = value;
            next = nullptr;
            prev = nullptr;
        }
    };
    Node* head;
    Node* tail;
    size_t length;
    Node* _current;
public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
        length = 0;
        _current = nullptr;
    }
    ~DoublyLinkedList() {
        Node* current = head;
        while(current != nullptr){
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
    void add(T value){
        Node* newNode = new Node(value);
        if(tail != nullptr){
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        } else {
            head = newNode;
            tail = newNode;
        }
        length++;
    }
    void operator+(T value) {
        add(value);
    }
    void begin() {
        _current = head;
    }
    bool end() {
        return _current == nullptr;
    }
    void operator++(int n) {
        _current = _current->next;
    }
    T operator*() {
        if(!end()) {
            return _current->value;
        }
        throw out_of_range("Out of range.");
    }
    size_t size() {
        return length;
    }
    T get(size_t n){
        int inc = 1;
        Node* current = head;
        size_t i = 0;
        if(length - n < n) {
            inc = -1;
            current = tail;
            i = length - 1;
        }
        while(i != n) {
            i += inc;
            if(inc > 0){
                current = current->next;
            } else {
                current = current->prev;
            }
        }
        return current->value;
    }
    void print() {
        Node* current = head;
        while(current != nullptr){
            cout << current->value << endl;
            current = current->next;
        }
    }
};


#endif // DOUBLYLINKEDLIST_H_INCLUDED
