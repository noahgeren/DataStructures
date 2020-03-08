#ifndef ARRAYLIST_H_INCLUDED
#define ARRAYLIST_H_INCLUDED

#include <algorithm>
using namespace std;

template<typename T>
class ArrayList {
private:
    size_t length;
    size_t capacity;
    T* values;
public:
    ArrayList() {
        length = 0;
        capacity = 0;
        values = new T[capacity];
    }
    ~ArrayList() {
        delete values;
    }
    void operator+(T value) {
        add(value);
    }
    void add(T value) {
        if(length == capacity) {
            T* oldValues = values;
            capacity = (capacity * 3)/2 + 1;
            values = new T[capacity];
            copy(oldValues, oldValues + length, values);
            delete oldValues;
        }
        values[length++] = value;
    }
    T get(size_t n) {
        if(n < 0 || n > length - 1) {
            throw out_of_range("Out of range.");
        }
        return values[n];
    }
    size_t size() {
        return length;
    }
    void print() {
        for(size_t i = 0; i < length; i++) {
            cout << get(i) << endl;
        }
    }
};


#endif // ARRAYLIST_H_INCLUDED
