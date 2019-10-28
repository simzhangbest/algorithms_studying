#ifndef LINKLIST_H
#define LINKLIST_H

#include "List.h"
#include "Exception.h"
namespace SimLib
{
	template<typename T>
	class LinkList : public List<T>
	{

	protected:
		class Node : public Object
		{
			T value;
			Node* next;
		};

		Node m_header;
		int m_length;

	public:
		LinkList()
		{
			m_header.next = nullptr;
			m_length = 0;
		}
		~LinkList();
		virtual bool  insert(const T& e) = 0; //Œ≤≤ø≤Â»Î
		virtual bool insert(int i, const T& e)
		{
			bool ret = ((0 <= i) && (i <= m_length));
			
			if (ret)
			{
				Node* node = new Node();

				if (node != Null)
				{
					Node* current = &m_header;

					for (size_t p = 0; p < i; p++)
					{
						current = current->next;
					}

					node->value = e;
					node->next = current->next;
					current->next = node;

					m_length++;
				}
				else
				{
					
				}
			}

			return ret;
		}
		virtual bool remove(int i) = 0;
		virtual bool set(int i, const T& e) = 0;
		virtual bool get(int i, T& e) const = 0;
		virtual int length() const = 0;
		virtual void clear() = 0;

	};


}
#endif // !LINKLIST_H



