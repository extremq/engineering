#pragma once

typedef int Atom;

struct Element {
	Atom val;
	Element* next;
};

void insert_end(Element*& root, Atom value);
void insert_front(Element*& root, Atom value);
void insert_after(Element* root, int index, Atom value);
void insert_at(Element*& root, int index, Atom value);
void replace_at(Element* root, int index, Atom value);

void delete_end(Element*& root);
void delete_front(Element*& root);
void delete_at(Element*& root, int index);

void search_value(Element* root, Atom value);
void value_at(Element* root, int index);

void check_loop(Element* root);

void print_list(Element* root);