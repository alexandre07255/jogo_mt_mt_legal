#pragma once
#include "Element.h"
#include <iostream>
using namespace std;

namespace Lists
{
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
		class Iterator
		{
		private:
			Element<TYPE>* pContent;
		public:
			Iterator(Element<TYPE>* content = NULL) : pContent(content) { }
			~Iterator() { pContent = NULL; }
			Element<TYPE>* getPContent() const { return pContent; }
			void setPContent(Element<TYPE>* pC) { pContent = pC; }
			TYPE* operator*() const { return (pContent->getInfo()); }
			const int operator++(const int a) { if (pContent != NULL) { pContent = pContent->getNext(); } return a; }
			const int operator--(const int a) { if (pContent != NULL) { pContent = pContent->getPrevious(); } return a; }
			void operator=(const Iterator it) { pContent = it.getPContent(); }
			const bool operator==(const Iterator& it) const { return (it.getPContent() == pContent); }
			const bool operator!=(const Iterator& it) const { return (it.getPContent() != pContent); }
		};

		Iterator begin() const
		{
			Iterator it(pFirstElement);
			return it;
		}
		//Element<TYPE>* begin() const;
		Iterator end() const
		{
			Iterator it(pLastElement);
			return it;
		}
		void push_back(TYPE* pointer);
		void remove(TYPE* pointer);
	};

	template<class TYPE>
	void List<TYPE>::updateSize()
	{
		List<TYPE>::Iterator it = begin();
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
			List<TYPE>::Iterator it;
			it = begin();
			List<TYPE>::Iterator itNext = it;
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

			pFirstElement = pLastElement;
			pLastElement->setPrevious(NULL);
			pLastElement->setNext(NULL);
			listSize = 0;
		}
	}

	template<class TYPE>
	const int List<TYPE>::size() const
	{
		return listSize;
	}

	/*template<class TYPE>
	Element<TYPE>* List<TYPE>::begin() const
	{
		return pFirstElement;
	}*/


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
			List<TYPE>::Iterator it;
			bool found = 0;
			it = begin();
			List<TYPE>::Iterator itNext = it;
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
}
