template<class T>
struct Node {
	Node<T>* prew;
	T val;
	Node<T>* next;
	Node(Node<T>* prew, T val, Node<T>* next)
	{
		this->prew = prew;
		this->val = val;
		this->next = next;
	};
};
#pragma once#pragma once
