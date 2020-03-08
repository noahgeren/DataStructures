#include <iostream>

#include "DoublyLinkedList.h"

using namespace std;

int main()
{
    DoublyLinkedList<int> linkedList;
    linkedList.add(0);
    linkedList.add(1);
    linkedList.add(2);
    linkedList.add(3);
    linkedList.add(4);
    linkedList + 5;
    linkedList + 6;
    for(linkedList.begin(); !linkedList.end(); linkedList++){
        cout << *linkedList << endl;
    }
    return 0;
}
