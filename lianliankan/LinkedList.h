#pragma once
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <limits>
#include <stdexcept>

using namespace std;


template<typename T>
class Node
{
public:
	Node();
	Node(T e);
	Node(T e, Node<T>* p, Node<T>* n);
	~Node();
public:
	T item;
	Node<T> *prev;
	Node<T> *next;
};

template<typename T>
Node<T>::Node()
{
	prev = nullptr;
	next = nullptr;
}

template<typename T>
inline Node<T>::Node(T e)
{
	item = e;
	prev = nullptr;
	next = nullptr;
}

template<typename T>
Node<T>::Node(T d, Node<T> *p, Node<T> *n)
{
	item = d;
	prev = p;
	next = n;
}

template<typename T>
Node<T>::~Node()
{
}


template<typename T>
class LinkedList {

public:
	LinkedList();

	~LinkedList();

	void clear();

	bool isEmpty() const;

	int getSize() const;

	T getFirst();

	T getLast();

	T get(const int index);

	T set(const int index, T value);

	bool add(T e);

	void addFron(T e);

	void insert(const int index, T e);

	T remove(const int index);

	bool removeFirst();

	bool removeFirst(T &e);

	bool removeLast();

	bool removeLast(T &e);

private:

	int size;
	Node<T> *first;
	Node<T> *last;

private:

	void checkIndex(const int index);

	Node<T> *nodeAt(const int index);

	void linkToBefore(T e, Node<T> *before, Node<T> *next);

	void linkLast(T e);

	T unlink(Node<T> *x);

	Node<T> *getFirstNode();

	T removeElement(T e);

};


template<typename T>
LinkedList<T>::LinkedList() :size(0) {
	first = last = new Node<T>();
}

template<typename T>
LinkedList<T>::~LinkedList() {
	while (last != nullptr) {
		Node<T> *l = last;
		last = last->prev;
		delete l;
	}

	//delete this;
}

template<typename T>
inline void LinkedList<T>::clear()
{
	while (last != first) {
		Node<T> *l = last;
		last = last->prev;
		delete l;
		size--;
	}
}

template<typename T>
inline int LinkedList<T>::getSize() const {
	return size;
}

template<typename T>
inline T LinkedList<T>::getFirst() {
	return first->next->item;
}

template<typename T>
inline T LinkedList<T>::getLast()
{
	return last->item;
}

template<typename T>
inline T LinkedList<T>::get(const int index) {
	checkIndex(index);

	Node<T> *t = nodeAt(index);

	return t->item;
}

template<typename T>
inline T LinkedList<T>::set(const int index, T e) {
	checkIndex(index);

	Node<T> *t = nodeAt(index);

	T o = t->item;
	t->item = e;

	return o;
}

template<typename T>
inline bool LinkedList<T>::add(T e) {
	linkLast(e);

	if (last == nullptr) {
		return false;
	}

	return true;
}

template<typename T>
inline void LinkedList<T>::addFron(T e)
{
	if (size == 0) {
		linkLast(e);
	}
	else {
		linkToBefore(e, first, first->next)
	}
}

template<typename T>
inline void LinkedList<T>::insert(int index, T e) {
	checkIndex(index);

	Node<T> *t = nodeAt(index);
	linkToBefore(e, t->prev, t);
}

template<typename T>
inline T LinkedList<T>::remove(const int index) {
	checkIndex(index);

	return unlink(nodeAt(index));
}

template<typename T>
inline void LinkedList<T>::checkIndex(const int index)
{
	if (index >= size || index < 0) {
		throw out_of_range("");
	}
}

template<typename T>
inline Node<T>* LinkedList<T>::nodeAt(const int index)
{
	if (index > (size >> 1)) {
		Node<T> *x = last;
		for (int i = size - 1; i > index; i--) {
			x = x->prev;
		}
		return x;
	}
	else {
		Node<T>* x = first->next;
		for (int i = 0; i < index; i++) {
			x = x->next;
		}
		return x;
	}
}

template<typename T>
inline void LinkedList<T>::linkToBefore(T e, Node<T> *before, Node<T> *next)
{
	Node<T>* newNode = new Node<T>(e, before, next);
	before->next = newNode;
	next->prev = newNode;

	size++;
}

template<typename T>
inline void LinkedList<T>::linkLast(T e)
{
	last->next = new Node<T>(e, last, nullptr);
	last = last->next;

	size++;
}

template<typename T>
inline T LinkedList<T>::unlink(Node<T>* x)
{
	T e = x->item;

	x->prev->next = x->next;

	if (x->next != nullptr) {
		x->next->prev = x->prev;
	}
	else {
		last = x->prev;
	}

	delete x;
	size--;

	return e;
}

template<typename T>
inline bool LinkedList<T>::removeFirst()
{
	if (size == 0 || first == nullptr) {
		return false;
	}
	else {
		unlink(first);
		return true;
	}
}

template<typename T>
inline bool LinkedList<T>::removeFirst(T &e)
{
	if (size == 0 || first == nullptr) {
		return false;
	}
	else {
		e = unlink(first->next);
		return true;
	}
}

template<typename T>
inline bool LinkedList<T>::removeLast() {
	if (size == 0 || last == nullptr) {
		return false;
	}
	else {
		unlink(last);
		return true;
	}
}

template<typename T>
inline bool LinkedList<T>::removeLast(T &e)
{
	if (size == 0 || last == nullptr) {
		return false;
	}
	else {
		e = unlink(last);
		return true;
	}
}

template<typename T>
inline bool LinkedList<T>::isEmpty() const {
	return size <= 0;
}

template<typename T>
Node<T> *LinkedList<T>::getFirstNode() {
	return first->next;
}


template<typename T>
inline T LinkedList<T>::removeElement(T e) {
	for (Node<T> *x = first->next; x != nullptr; x = x->next) {
		if (x->item == e) {
			x->prev->next = x->next;

			if (x->next != nullptr) {
				x->next->prev = x->prev;
			}
			else {
				last = x->prev;
			}
			T r = x->item;

			delete x;
			size--;

			return r;
		}
	}
}


#endif