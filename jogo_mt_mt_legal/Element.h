#pragma once
#include <iostream>
using namespace std;

template<class TYPE>
class Element
{
private:
	Element<TYPE>* pPrevious;
	Element<TYPE>* pNext;
	TYPE* pInfo;
public:
	Element();
	~Element();
	void setNext(Element<TYPE>* pN);
	Element<TYPE>* getNext() const;
	void setPrevious(Element<TYPE>* pP);
	Element<TYPE>* getPrevious() const;
	void setInfo(TYPE* pI);
	TYPE* getInfo() const;
};


template<class TYPE>
Element<TYPE>::Element() :
	pPrevious(NULL),
	pNext(NULL),
	pInfo(NULL)
{

}

template<class TYPE>
Element<TYPE>::~Element()
{
	pPrevious = NULL;
	pNext = NULL;
	pInfo = NULL;
}

template<class TYPE>
void Element<TYPE>::setNext(Element<TYPE>* pN)
{
	pNext = pN;
}

template<class TYPE>
Element<TYPE>* Element<TYPE>::getNext() const
{
	return pNext;
}

template<class TYPE>
void Element<TYPE>::setPrevious(Element<TYPE>* pP)
{
	pPrevious = pP;
}

template<class TYPE>
Element<TYPE>* Element<TYPE>::getPrevious() const
{
	return pPrevious;
}

template<class TYPE>
void Element<TYPE>::setInfo(TYPE* pI)
{
	pInfo = pI;
}

template<class TYPE>
TYPE* Element<TYPE>::getInfo() const
{
	return pInfo;
}

