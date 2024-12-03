#include <iostream>
#include "LinkedList.hpp"

int main(){
    LinkedList list;
    init(&list);
    add(&list, 1);
    add(&list, 2);
    add(&list, 3);
    add(&list, 4);
    add(&list, 5);

    print(&list);

    delete_last(&list);
    delete_last(&list);

    print(&list);

    delete_some_value(&list, 2);

    print(&list);

    return 0;
}