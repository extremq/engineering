#pragma once
#include <iostream>

template <class T>
struct node {
	T data;
	node* l, * r;
};

template <class T>
class BST {
public:
	node<T> *root;
	int _size;
public: 
	BST() {
		this->root = 0;
		this->_size = 0;
	}

	void insert(T data) {
		node<T>* iter = this->root;

		if (iter == 0) {
			this->root = alloc_node(data);
		}
		else
		{
			node<T>* parent_iter = iter;
			bool is_left = 0;
			while (iter != 0) {
				parent_iter = iter;
				if (data > iter->data) {
					iter = iter->r;
					is_left = 0;
				}
				else if (data < iter->data) {
					iter = iter->l;
					is_left = 1;
				}
				else {
					return;
				}
			}
			
			iter = alloc_node(data);
			if (is_left)
				parent_iter->l = iter;
			else
				parent_iter->r = iter;
		}

		this->_size++;
	}
	bool search(T data) {
		node<T>* iter = this->root;

		if (iter == 0) {
			return false;
		}

		while (iter != 0) {
			if (data > iter->data) {
				iter = iter->r;
			}
			else if (data < iter->data) {
				iter = iter->l;
			}
			else {
				return true;
			}
		}

		return false;
	}
	void print(node<T>* root) {
		if (root == 0) return;

		print(root->l);
		std::cout << root->data << ' ';
		print(root->r);
	}
	T max() {
		if (this->root == 0) {
			// empty 
			return 0;
		}

		node<T>* iter = this->root;

		// ONLY FOR INTS
		T max_value;

		while (iter != 0) {
			max_value = iter->data;
			iter = iter->r;
		}

		return max_value;
	}
	T min() {
		if (this->root == 0) {
			// empty 
			return 0;
		}

		node<T>* iter = this->root;

		// ONLY FOR INTS
		T min_value;

		while (iter != 0) {
			min_value = iter->data;
			iter = iter->l;
		}

		return min_value;
	}
private:
	node<T>* alloc_node(T data) {
		node<T>* new_node = new node<T>;
		new_node->data = data;
		new_node->l = new_node->r = 0;

		return new_node;
	}
};
