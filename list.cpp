#include"list.h"



template<class T>
inline list<T>::list()
{
	Head = nullptr;
}

template<class T>
list<T>::list(const list<T>&other)
{
	if (other.Head == nullptr) { Head = nullptr; }
	else
	{
		Node<T>* crrobj = other.Head;
		
		Head = new Node<T>(nullptr,crrobj->val,crrobj->next);
        Node<T>* ptr = Head;
		while (crrobj->next != nullptr)
		{
			crrobj = crrobj->next;
			ptr->next = new Node<T>(ptr, crrobj->val, crrobj->next);
			ptr = ptr->next;
		}
	}
	std::cout << "copy ctor \n";
}

template<class T>
list<T>::list(list<T>&&other) //move
{
		if (other.Head == nullptr) { Head = nullptr; }
		else
		{
			Node<T>* crrobj = other.Head;
			Head = new Node<T>(nullptr, crrobj->val, crrobj->next);
			Node<T>* ptr = Head;
			while (crrobj->next != nullptr)
			{
				crrobj = crrobj->next;
				ptr->next = new Node<T>(ptr, crrobj->val, crrobj->next);
				ptr = ptr->next;
		}
		std::cout << "move ctor \n";
	}
}

template<class T>
list<T> list<T>::operator=(list<T>&other)
{
	if (this == &other) { throw std::exception("same adress \n");  }

	else if (other.Head == nullptr) { Head = nullptr; }
	else
	{
		Node<T>* crrobj = other.Head;

		Head = new Node<T>(nullptr, crrobj->val, crrobj->next);
		Node<T>* ptr = Head;
		while (crrobj->next != nullptr)
		{
			crrobj = crrobj->next;
			ptr->next = new Node<T>(ptr, crrobj->val, crrobj->next);
			ptr = ptr->next;
		}
		return *this;
	}
	std::cout << "assigment operator overload \n";
}

template<class T>
list<T> list<T>::operator=(list<T>&& other)
{
	if (this == &other) { throw std::exception("same adress \n"); }

	else if (other.Head == nullptr) { Head = nullptr; }
	else
	{
		Node<T>* crrobj = other.Head;
		Head = new Node<T>(nullptr, crrobj->val, crrobj->next);
		Node<T>* ptr = Head;
		while (crrobj->next != nullptr)
		{
			crrobj = crrobj->next;
			ptr->next = new Node<T>(ptr, crrobj->val, crrobj->next);
			ptr = ptr->next;
		}
		std::cout << "move assigment overload \n";
		return *this;
	}
	
}
template<class T>
bool list<T>::empty()
{
	return Head == nullptr;
}

template<class T>
void list<T>::push_back(T val)
{
	if (empty()) { Head = new Node<T>(nullptr, val, nullptr); }
	else
	{
		Node<T>* crr = Head;
		while (crr->next != nullptr)
		{
			crr = crr->next;
		}
		crr->next = new Node<T>(crr, val, nullptr);
	}

}

template<class T>
void list<T>::pop_back()
{
	if (empty()) { throw std::exception("Satck underflow: \n"); }
	else if (Head->next == nullptr) { delete Head; Head = nullptr; }
	else
	{
		Node<T>* ptr = Head;
		while (ptr->next->next != nullptr)
		{
			ptr = ptr->next;
		}
		delete ptr->next;
		ptr->next = nullptr;

	}
}

template<class T>
void list<T>::push_front(const T& val)
{
	if (empty()) { Head = new Node<T>(nullptr, val, nullptr); }
	else
	{
		Head = new Node<T>(nullptr, val, Head);
	}

}

template<class T>
void list<T>::pop_front()
{
	Node<T>* ptr = Head;
	Head = Head->next;
	delete ptr;
	Head->prew = nullptr;
}



template<class T>
void list<T>::print()

{
	if (empty()) { throw std::exception("undrfolw: \n"); }
	else
	{
		Node<T>* ptr = Head;
		while (ptr != nullptr)
		{
			std::cout << ptr->val << " ";
			ptr = ptr->next;
		}
	}
}


template<class T>
void list<T>::insert(const int& n,const  T& val1)
{
	if (n == 0){
	Node<T>*ptr= new Node<T>(nullptr, val1, Head);
	
	}
	else
	{
		Node<T>* ptr = Head;
		int c = 0;
		while (c != n)
		{
			ptr = ptr->next;
			++c;
		}
		
		ptr = new Node<T>(nullptr, val1, nullptr);
		ptr->next->prew = ptr;
		ptr->prew->next = ptr;
	}
}

template<class T>
const int list<T>::size()
{
	if (empty()) { std::cout << "dont have element: \n"; return -1; }
	else
	{
		int c = 0;
		Node<T>* ptr = Head;
		while (ptr != nullptr)
		{
			ptr = ptr->next;
			++c;
		}
	return c;
	}
}
