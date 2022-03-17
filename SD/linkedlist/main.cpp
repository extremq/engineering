#include <iostream>

#include "Lista.h"

int main() {
    Element* root = 0; 

    insert_at(root, 0, 100);
    insert_front(root, -5);
    insert_end(root, -6);
    print_list(root);

    insert_at(root, 1, 6);
    print_list(root);

    replace_at(root, 1, -19);
    print_list(root);

    insert_after(root, 1, -20);
    print_list(root);

    delete_end(root);
    delete_end(root);
    delete_end(root);
    delete_end(root);
    delete_end(root);
    print_list(root);

    insert_end(root, 1);
    insert_end(root, 2);
    insert_end(root, 3);
    print_list(root);

    delete_front(root);
    print_list(root);

    delete_end(root);
    print_list(root);

    insert_end(root, -5);
    insert_end(root, -8);
    insert_end(root, 6);
    insert_end(root, 7);
    insert_end(root, 2);
    insert_end(root, 1);
    delete_at(root, 0);
    print_list(root);

    search_value(root, 7);
    value_at(root, 3);

    Element* root2 = 0;
    insert_end(root2, 1);
    insert_end(root2, 2);
    insert_end(root2, 3);
    insert_end(root2, 4);
    // [1, 2, 3, 4] as a list, we now link 4 to 2
    root2->next->next->next->next = root2->next;

    // infinite loop
    //print_list(root2);
    check_loop(root2);
    check_loop(root);

    Element* root3 = 0;
    insert_end(root3, 1);
    check_loop(root3);
    insert_end(root3, 2);
    root3->next = root3;
    check_loop(root3);
}
