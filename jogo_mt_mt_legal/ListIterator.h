#pragma once
#include "Element.h"

template<class TYPE>
class ListIterator
{
private:
	Element<TYPE>* pContent;
public:
	ListIterator();
	Element<TYPE>* getPContent() const;
	void setPContent(Element<TYPE>* pC);
	TYPE* operator*() const;
	const int operator++(const int a);
	const int operator--(const int a);
	void operator=(const ListIterator it);
	const bool operator==(const ListIterator& it) const;
	const bool operator!=(const ListIterator& it) const;
};

template<class TYPE>
ListIterator<TYPE>::ListIterator() : pContent(NULL) { }

template<class TYPE>
Element<TYPE>* ListIterator<TYPE>::getPContent() const { return pContent; }

template<class TYPE>
void ListIterator<TYPE>::setPContent(Element<TYPE>* pC) { pContent = pC; }

template<class TYPE>
TYPE* ListIterator<TYPE>::operator*() const { return (pContent->getInfo()); }

template<class TYPE>
const int ListIterator<TYPE>::operator++(const int a) { if (pContent != NULL) { pContent = pContent->getNext(); } return a; }

template<class TYPE>
const int ListIterator<TYPE>::operator--(const int a) { if (pContent != NULL) { pContent = pContent->getPrevious(); } return a; }

template<class TYPE>
void ListIterator<TYPE>::operator=(const ListIterator it) { pContent = it.getPContent(); }

//template<class TYPE>
//void ListIterator<TYPE>::operator=(const Element<TYPE>* el) { pContent = el; }

template<class TYPE>
const bool ListIterator<TYPE>::operator==(const ListIterator& it) const { return (it.getPContent() == pContent); }

template<class TYPE>
const bool ListIterator<TYPE>::operator!=(const ListIterator& it) const { return (it.getPContent() != pContent); }