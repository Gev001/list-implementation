#pragma once

#include<iostream>
#include"node.h"



template<class T>
class list
{
public:
	list();//def ctor
	list(const list<T>&);
	list(list<T>&&);
	list<T> operator=(list<T>&);
	list<T> operator=(list<T>&&);
	bool empty();
	void push_back(T);
	void pop_back();
	void push_front(const T&);
	void pop_front();//?
	void print();
	void insert(const int& ,const T&);
	const int size();

private:
	Node<T>* Head;
};
