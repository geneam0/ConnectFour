#ifndef __PRIORITYQUEUE_CPP__
#define __PRIORITYQUEUE_CPP__

#include "priorityQueue.h"

template <class Item> 
PriorityQueue<Item>::PriorityQueue() {
	first = 0;
	last = -1;
	used = 0;
	capacity = 30;
	data = new Item[capacity];
}

// copy constructor
template <class Item> 
PriorityQueue<Item>::PriorityQueue(const PriorityQueue<Item>& source) {
	first = source.first;
	last = source.last;
	used = source.used;
	capacity = source.capacity;
	data = new Item[capacity];
	int i = 0;
	size_t current = first;
	while(i <= used) {
		data[current] = source.data[current];
		current = nextIndex(current);
		i++;	
	}
}

template <class Item>
PriorityQueue<Item>::~PriorityQueue() {
	delete[] data;
}

// member functions

template <class Item> 
void PriorityQueue<Item>::push(const Item& entry) {
	if(used == 0) {
		data[nextIndex(last)] = entry;
		used++;
		last = nextIndex(last);
	} else {
		if(entry < data[last]) {
			size_t current = last;
			int count = 0;
			while(entry <= data[current]) {
				if (current == first) {
					count++;
					break;
				}
				current = prevIndex(current);
				count++;
			}
			Item tempData = data[current];
			Item tempDataNext;
			data[current] = entry;
			for(int i = 0; i < count; i++) {
				tempDataNext = data[nextIndex(current)];
				data[nextIndex(current)] = tempData;
				tempData = tempDataNext;
				current = nextIndex(current);
			}
			last = nextIndex(last);		
			used++;

		} else { 
		data[nextIndex(last)] = entry;
		used++;
		last = nextIndex(last);
		} 
	}		
}

template <class Item> 
void PriorityQueue<Item>::pop() {
	if(empty()) { return; }
	first = nextIndex(first);
	used--;
}

template <class Item> 
void PriorityQueue<Item>::operator=(const PriorityQueue<Item>& source) {
	delete[] data;
	used = source.used;
	first = source.first;
	last = source.last;
	data = new Item[capacity];
	int i = 0;
	size_t current = first;
	while(i <= used) {
		data[current] = source.data[current];
		current = nextIndex(current);
		i++;	
	}
}

template <class Item> 
size_t PriorityQueue<Item>::size() const {
	return used;
}

template <class Item>
bool PriorityQueue<Item>::empty() const {
	return (size() == 0);
}

template <class Item>
Item PriorityQueue<Item>::front() const {
	assert(!empty());
	return (data[first]);
}

template <class Item>
size_t PriorityQueue<Item>::prevIndex(size_t i) const {
	return (i - 1 + capacity)%capacity;
}	

template <class Item>
void PriorityQueue<Item>::resize(PriorityQueue<Item> queue, size_t newSize) {
	first = queue.first;
	last = queue.last;
	used = queue.used;
	capacity = newSize;
	delete[] data;
	data = new Item[newSize];
	int i = 0;
	size_t current = first;
	while(i <= used) {
		data[current] = queue.data[current];
		current = nextIndex(current);
		i++;	
	}
}	

#endif
