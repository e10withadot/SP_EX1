#include <stdexcept>
#include "data_strct.hpp"
using namespace data;
template<class T>
T list<T>::get(int index) {
	if(index > this->size || index < 0)
		throw std::out_of_range("Index is out of range.");
	return this->arr[index];
}

template<class T>
void list<T>::set(int index, T value) {
	if(index > this->size || index < 0)
		throw std::out_of_range("Index is out of range.");
	this->arr[index] = value;
}

template<class T>
void list<T>::push(T value) {
	int i = 0;
	while(this->arr[i] != nullptr || i < this->size)
		i++;
	if(i == this->size) {
		T* new_arr = new T[2*this->size];
		for (int j = 0; j < this->size; j++) {
			new_arr[j] = this->arr[j];
		}
		delete [] arr;
		this->arr = new_arr;
		this->size *= 2;
	}
	this->arr[i] = value;
}

template<class T>
T list<T>::pop() {
	int i = 0;
	while(this->arr[i] != nullptr || i < this->size-1)
		i++;
	T res = this->arr[i];
	this->arr[i] = nullptr;
	if(i*2 == this->size) {
		T* new_arr = new T[this->size/2];
		for (int j = 0; j < this->size/2; j++) {
			new_arr[j] = this->arr[j];
		}
		delete [] arr;
		this->arr = new_arr;
		this->size /= 2;
	}
	return res;
}

template<class T>
void list<T>::remove(int index) {
	if(index > this->size || index < 0)
		throw std::out_of_range("Index is out of range.");
	for (int i = index; i < this->size-1; i++) {
		arr[i] = arr[i+1];
	}
}

template<class T>
bool list<T>::empty() {
	int i = 0;
	while(this->arr[i] == nullptr) {
		if(i == this->size)
			return true;
		i++;
	}
	return false;
}
