#pragma once
#include "ListIterator.h"
#include <iostream>
using namespace std;

template<class TYPE>
class List
{
private:
	Element<TYPE>* pFirstElement;
	Element<TYPE>* pLastElement;
	int listSize;
	void updateSize();
public:
	List();
	~List();
	void clear();
	const int size() const;
	ListIterator<TYPE> begin() const;
	//Element<TYPE>* begin() const;
	ListIterator<TYPE> end() const;
	void push_back(TYPE* pointer);
	void remove(TYPE* pointer);
};

template<class TYPE>
void List<TYPE>::updateSize()
{
	ListIterator<TYPE> it = begin();
	int cont = 0;
	while (it != end())
	{
		cont++;
		it++;
	}
	listSize = cont;
}

template<class TYPE>
List<TYPE>::List() :
	pFirstElement(),
	pLastElement(),
	listSize(0)
{
	pFirstElement = new Element<TYPE>;
	pLastElement = pFirstElement;
}

template<class TYPE>
List<TYPE>::~List()
{
	clear();
}

template<class TYPE>
void List<TYPE>::clear()
{
	if (listSize > 0)
	{
		ListIterator<TYPE> it;
		it = begin();
		ListIterator<TYPE> itNext = it;
		itNext++;
		while (itNext != end())
		{
			Element<TYPE>* removed = it.getPContent();
			delete removed;
			it = itNext;
			itNext++;
		}
		Element<TYPE>* removed = it.getPContent();
		delete removed;
		listSize = 0;
	}
}

template<class TYPE>
const int List<TYPE>::size() const
{
	return listSize;
}

template<class TYPE>
ListIterator<TYPE> List<TYPE>::begin() const
{
	ListIterator<TYPE> it;
	it.setPContent(pFirstElement);
	return it;
}

/*template<class TYPE>
Element<TYPE>* List<TYPE>::begin() const
{
	return pFirstElement;
}*/

template<class TYPE>
ListIterator<TYPE> List<TYPE>::end() const
{
	ListIterator<TYPE> it;
	it.setPContent(pLastElement);
	return it;
}

template<class TYPE>
void List<TYPE>::push_back(TYPE* pointer)
{
	if (pointer == NULL) { return; }
	Element<TYPE>* vessel = new Element<TYPE>;
	vessel->setInfo(pointer);
	vessel->setNext(pLastElement);
	Element<TYPE>* lastBut1 = pLastElement->getPrevious();
	pLastElement->setPrevious(vessel);
	if (pLastElement == pFirstElement) { pFirstElement = vessel; }
	if (lastBut1 != NULL) { lastBut1->setNext(vessel); }
	vessel->setPrevious(lastBut1);
	updateSize();
}

template<class TYPE>
void List<TYPE>::remove(TYPE* pointer)
{
	if (pointer == NULL) { return; }
	if (listSize > 0)
	{
		ListIterator<TYPE> it;
		bool found = 0;
		it = begin();
		ListIterator<TYPE> itNext = it;
		itNext++;
		while (itNext != end())
		{
			if ((*it) == pointer)
			{
				Element<TYPE>* removed = it.getPContent();
				Element<TYPE>* before = removed->getPrevious();
				Element<TYPE>* after = removed->getNext();
				if (before != NULL)
					before->setNext(after);
				else
					pFirstElement = after;
				if (after != NULL)
					after->setPrevious(before);
				delete removed;
				found = 1;
			}
			it = itNext;
			itNext++;
		}

		if ((*it) == pointer)
		{
			Element<TYPE>* removed = it.getPContent();
			Element<TYPE>* before = removed->getPrevious();
			Element<TYPE>* after = removed->getNext();
			if (before != NULL)
				before->setNext(after);
			else
				pFirstElement = after;
			if (after != NULL)
				after->setPrevious(before);
			delete removed;
			found = 1;
		}

		if (found)
			updateSize();
	}
}