#pragma once
#include <stdexcept>

template <class Atom>
struct _queue_element {
	Atom data;
	_queue_element* next = 0;
};

template <class Atom>
class Queue {
private:
	_queue_element<Atom>* _front, * _back;
	size_t _size;
public:
	Queue() {
		this->_front = 0;
		this->_back  = 0;
		this->_size  = 0;
	}

	size_t size() {
		return this->_size;
	}

	bool empty() {
		return this->_back == 0;
	}

	Atom& front() {
		this->throw_if_empty();

		return this->_front->data;
	}

	Atom& back() {
		this->throw_if_empty();

		return this->_back->data;
	}

	void push(Atom data) {
		if (this->empty()) {
			this->_front = new _queue_element<Atom>;
			this->_front->data = data;
			this->_front->next = 0;
			this->_back = this->_front;
		}
		else {
			_queue_element<Atom>* new_element = new _queue_element<Atom>;
			new_element->data = data;
			new_element->next = 0;

			this->_back->next = new_element;
			this->_back = new_element;
		}

		this->_size++;
	}

	Atom pop() {
		this->throw_if_empty();

		_queue_element<Atom>* deleted_element = this->_front;
		if (this->size() == 1) {
			this->_back = this->_front = 0;
		}
		else {
			this->_front = this->_front->next;
		}
		
		Atom return_value = deleted_element->data;
		delete deleted_element;

		this->_size--;
		
		return return_value;
	}

private:
	void throw_if_empty() {
		if (this->empty()) {
			throw std::out_of_range("The queue is empty.");
		}
	}
};
