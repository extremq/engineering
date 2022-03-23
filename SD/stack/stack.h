#pragma once
#include <stdexcept>

template <class Atom>
struct _stack_element {
	Atom data;
	_stack_element* prev = 0;
};

template <class Atom>
class stack {
private:
	_stack_element<Atom>* _top;
	size_t _size;
public:
	stack() {
		this->_top = 0;
		_size = 0;
	}

	bool empty() {
		return _top == 0;
	}

	size_t size() {
		return _size;
	}
	
	void push(Atom data) {
		// If the stack is empty, init a new top
		if (this->empty()) {
			this->_top = new _stack_element<Atom>;
			this->_top->data = data;
			this->_top->prev = 0;
		}
		else {
			// The stack isn't empty, just append to top
			_stack_element<Atom>* new_top = new _stack_element<Atom>;
			new_top->data = data;
			new_top->prev = this->_top;

			// And update the top
			this->_top = new_top;
		}

		this->_size++;
	}

	Atom top() {
		if (this->empty()) {
			throw std::out_of_range("The stack is empty.");
			exit(EXIT_FAILURE);
		}

		return this->_top->data;
	}

	Atom pop() {
		if (this->empty()) {
			throw std::out_of_range("The stack is empty.");
			exit(EXIT_FAILURE);
		}
		
		Atom ret_value = this->top();

		// Remember the address of the element we want to remove
		_stack_element<Atom>* to_remove = this->_top;

		// If this is the last element, set top as 0.
		if (this->size() > 1)
			this->_top = this->_top->prev;
		else
			this->_top = 0;

		delete to_remove;

		this->_size--;

		return ret_value;
	}
};