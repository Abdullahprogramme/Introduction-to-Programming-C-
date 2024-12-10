#include <iostream>
#include "LinkedList.hpp"

int main(){
    LinkedList list;
    init(&list);

    add(&list, 5);
    add(&list, 3);
    add(&list, 8);
    add(&list, 1);
    print(&list);

    add_first(&list, 0);
    print(&list);

    add_last(&list, 10);
    print(&list);

    delete_first(&list);
    print(&list);

    delete_last(&list);
    print(&list);

    delete_some_value(&list, 3);
    print(&list);

    return 0;
}
