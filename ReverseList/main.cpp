#include <iostream>
#include <reverselist.h>


int main(){

    SingleLinkedList ll;

    ll.push(20);
    ll.push(4);
    ll.push(15);
    ll.push(85);

    std::cout << "Given linked list\n";
    ll.print();

    ll.reverse();

    std::cout << "\nReversed Linked list \n";
    ll.print();

    return 0;
}
