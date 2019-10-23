#ifndef STATICLIST_H
#define STATICLIST_H
#include "SeqList.h"
namespace SimLib
{
	template<typename T, int N>

	class StaticList : public SeqList<T>
	{
	protected:
		T m_space[N]; // ˳��洢�ռ䣬 N Ϊģ��ָ������
	public:
		StaticList()
		{
			this->m_array = m_space;
			this->m_length = 0;
		}
		int capacity() const
		{
			return N;
		}

	};
}



#endif

