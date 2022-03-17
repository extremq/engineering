#include <iostream>

#include "Lista.h"

void search_value(Element* root, Atom value) {
    if (root == 0) {
        std::cout << "ERROR search_value: List is empty.\n";
        return;
    }

    Element* iter = root;
    int counter = 0;

    while (iter->next) {
        if (iter->val == value) {
            std::cout << "Value " << value << " found at position " << counter << "!\n";
        }
        iter = iter->next;
        counter++;
    }
    if (iter->val == value) {
        std::cout << "Value " << value << " found at position " << counter << "!\n";
    }
}

void value_at(Element* root, int index) {
    if (root == 0) {
        std::cout << "ERROR value_at: List is empty.\n";
        return;
    }

    Element* iter = root;
    int counter = 0;

    while (iter->next && index > counter) {
        iter = iter->next;
        counter++;
    }

    if (index != counter) {
        std::cout << "ERROR value_at: Index " << index << " not in list.\n";
        return;
    }

    std::cout << "Value at index " << index << " is " << iter->val << ".\n";
}

void check_loop(Element* root) {
    if (root == 0) {
        std::cout << "ERROR check_loop: List is empty.\n";
        return;
    }

    Element* iter = root;
    Element* checker = root;
    int counter = 0, check_count = 0;

    while (iter->next) {
        iter = iter->next;
        counter++;

        checker = root;
        check_count = 0;
        while (checker->next && counter > check_count) {
            checker = checker->next;
            check_count++;

            if (checker == iter && check_count != counter) {
                std::cout << "Loop found at index " << counter << ".\n";
                return;
            }
        }
    }

    std::cout << "No loop found.\n";
}

void print_list(Element* root) {
    std::cout << "\nBegin printing list:\n";
    if (root == 0) {
        std::cout << "None.\n";
        return;
    }

    Element* iter = root;
    int counter = 0;

    while (iter->next) {
        std::cout << "List[" << counter++ << "]: " << iter->val << '\n';
        iter = iter->next;
    }
    std::cout << "List[" << counter++ << "]: " << iter->val << '\n'; // last element
}

void insert_end(Element*& root, Atom value) {
    if (root == 0) {
        insert_front(root, value);

        return;
    }

    Element* iter = root;

    while (iter->next) {
        iter = iter->next;
    }

    Element* new_end = new Element;
    new_end->val = value;
    new_end->next = 0;

    iter->next = new_end;
}

void insert_front(Element*& root, Atom value) {
    if (root == 0) // empty list case
    {
        root = new Element;

        root->val = value;
        root->next = 0;

        return;
    }

    Element* old_front = new Element;
    old_front->val = root->val;
    old_front->next = root->next;

    root->val = value;
    root->next = old_front;
}

void insert_after(Element* root, int index, Atom value) {
    Element* iter = root;
    int counter = 0;
    if (index < 0) {
        std::cout << "ERROR insert_after: Index must be >= 0.\n";
        return;
    }

    while (iter->next && index > counter) {
        iter = iter->next;
        counter++;
    }

    if (counter != index) {
        std::cout << "ERROR insert_after: Index " << index << " not in list.\n";
        return;
    }

    Element* new_element = new Element;
    new_element->val = value;
    new_element->next = iter->next;

    iter->next = new_element;
}

void insert_at(Element*& root, int index, Atom value) {
    Element* iter = root;
    int counter = 0;

    if (index == 0) {
        insert_front(root, value);
        return;
    }

    while (iter->next && index - 1 > counter) {
        iter = iter->next;
        counter++;
    }

    if (counter != index - 1) {
        std::cout << "ERROR insert_at: Index " << index << " not in list.\n";
        return;
    }

    Element* new_element = new Element;
    new_element->val = value;
    new_element->next = iter->next;

    iter->next = new_element;
}

void replace_at(Element* root, int index, Atom value) {
    Element* iter = root;
    int counter = 0;

    while (iter->next && index > counter) {
        iter = iter->next;
        counter++;
    }

    if (counter != index) {
        std::cout << "ERROR replace_at: Index " << index << " not in list.\n";
        return;
    }

    iter->val = value;
}

void delete_end(Element*& root) {
    if (root == 0) {
        std::cout << "ERROR delete_end: Empty list.\n";
        return;
    }

    Element* iter = root;
    Element* previter = iter;

    while (iter->next) {
        previter = iter;
        iter = iter->next;
    }

    previter->next = 0;
    if (previter == iter) {
        // If there is one single element, delete the root
        root = 0;
    }
    delete iter;

}

void delete_front(Element*& root) {
    if (root == 0) {
        std::cout << "ERROR delete_front: Empty list.\n";
        return;
    }

    if (root->next == 0) {
        // If there is one single element, delete the root
        root = 0;
        delete root;

        return;
    }

    Element* next_elem = root->next;
    root->val = next_elem->val;
    root->next = next_elem->next;
    delete next_elem;
}

void delete_at(Element*& root, int index) {
    if (root == 0) {
        std::cout << "ERROR delete_at: Empty list.\n";
        return;
    }

    if (index == 0) {
        delete_front(root);
        return;
    }

    Element* iter = root;
    Element* previter = iter;
    int counter = 0;

    while (iter->next && index > counter) {
        previter = iter;
        iter = iter->next;
        counter++;
    }

    if (counter != index) {
        std::cout << "ERROR delete_at: Index " << index << " not in list.\n";
        return;
    }

    previter->next = iter->next;
    delete iter;
}