// ey.gellis@gmail.com
#include <iostream>
#include <stdexcept>
#include "data_strct.hpp"
using namespace data;
#include "graph.hpp"

template class data::list<int>;
template class data::list_item<int>;
template class data::list<bool>;
template class data::list_item<bool>;
template class data::list<graph::edge>;
template class data::list_item<graph::edge>;
template class data::list<graph::vertex>;
template class data::list_item<graph::vertex>;

template<class K>
K list_item<K>::get() {
	if(empty) throw std::invalid_argument("Item is empty.");
	return this->value;
}
template<class K>
void list_item<K>::set(K value) {
	this->value = value;
	this->empty = false;
}
template<class K>
bool list_item<K>::isEmpty() {
	return this->empty;
}
template<class K>
void list_item<K>::erase() {
	this->empty= true;
}
template<class T>
int list<T>::getSize() {
	return this->size;
}
template<class T>
int list<T>::getCount() {
	return this->count;
}
template<class T>
T list<T>::get(int index) {
	if(index > this->size || index < 0)
		throw std::out_of_range("Index is out of range.");
	return this->arr[index].get();
}
template<class T>
T list<T>::getLast() {
	int i = 0;
	while(i < this->size && !this->arr[i].isEmpty())
		i++;
	return this->arr[i-1].get();
}
template<class T>
void list<T>::set(int index, T value) {
	if(index > this->size || index < 0)
		throw std::out_of_range("Index is out of range.");
	if(this->arr[index].isEmpty()) this->count++;
	this->arr[index].set(value);
}

template<class T>
void list<T>::push(T value) {
	int i = 0;
	while(i < this->size && !this->arr[i].isEmpty())
		i++;
	if(i == this->size) {
		list_item<T>* new_arr = new list_item<T>[2*this->size];
		for (int j = 0; j < this->size; j++) {
			new_arr[j] = this->arr[j];
		}
		this->arr = new_arr;
		this->size *= 2;
	}
	this->arr[i].set(value);
	this->count++;
	std::cout << "count: " << this->getCount() << "\n";
}

template<class T>
void list<T>::pop() {
	if (this->empty()) throw std::out_of_range("No elements to pop.");

	int i = 0;
	while(!this->arr[i].isEmpty() && i < this->size-1)
		i++;
	this->arr[i-1].erase();
	if(this->size > 1 && i + 1 <= this->size/2) {
		list_item<T>* new_arr = new list_item<T>[this->size/2];
		for (int j = 0; j < this->size/2; j++) {
			new_arr[j] = this->arr[j];
		}
		this->arr = new_arr;
		this->size /= 2;
	}
	this->count--;
}

template<class T>
void list<T>::remove(int index) {
	if(index > this->size || index < 0)
		throw std::out_of_range("Index is out of range.");
	for (int i = index; i < this->size-1; i++) {
		arr[i].set(arr[i+1].get());
	}
	this->count--;
}

template<class T>
bool list<T>::empty() {
	return count == 0;
}
