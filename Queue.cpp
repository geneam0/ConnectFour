#ifndef __QUEUE_MERI_CPP__
#define __QUEUE_MERI_CPP__

#include "Queue.h"

template <class Item>
Queue<Item>::Queue() {
	capacity = 30;
	used = 0;
	first = 0;
	last = -1;
	data = new Item[capacity];
}

template <class Item>
Queue<Item>::Queue(const Queue<Item>& source) {
	used = source.used;
	first = source.first;
	last = source.last;
	capacity = source.capacity;
	data = new Item[capacity];
	for (int i = first; i <= last; i++) {		
		data[i] = source.data[i];
	}
}

template <class Item>
Queue<Item>::~Queue() {
	delete[] data;
}

template <class Item>
void Queue<Item>::push(const Item& entry) {
	assert(used < capacity);
	data[nextIndex(last)] = entry;
	used++;
	last = nextIndex(last);
}

template <class Item>
void Queue<Item>::pop() {
	if(empty()) { return; }
	first = nextIndex(first);
	used--;
}	

template <class Item>
void Queue<Item>::operator=(const Queue<Item>& source) {
	delete[] data;
	used = source.used;
	first = source.first;
	last = source.last;
	data = new Item[capacity];
	for(int i = 0; i < used; i++) {
		data[i] = source.data[i];
	}
}

template <class Item>
size_t Queue<Item>::size() const {
	return used;
}

template <class Item>
bool Queue<Item>::empty() const {
	return (size() == 0);
}

template <class Item>
Item Queue<Item>::front() const {
	assert(!empty());
	return(data[first]);
}


#endif
