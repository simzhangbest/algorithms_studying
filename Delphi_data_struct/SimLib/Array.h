#ifndef ARRAY_H
#define ARRAY_H
#include "Exception.h"
namespace SimLib
{
	template<typename T>
	class Array
	{

	protected:
		T* m_array;
	public:

		virtual bool set(int i, const T& e)
		{
			bool ret = ((0 <= i) && (i < length()));
			if (ret)
			{
				m_array[i] = e;
			}
			return ret;
		}

		virtual bool get(int i, T& e)
		{
			bool ret = ((0 <= i) && (i < length()));
			if (ret)
			{
				e = m_array[i];
			}

			return ret;
		}


		// �Զ�������������Խ�磬�����׳��쳣����ֹ���󴫵�
		T& operator[] (int i)
		{
			bool ret = ((0 <= i) && (i < length()));
			if (ret)
			{
				return m_array[i];
			}
			else
			{
				THROW_EXCEPTION(IndexOutOfBoundsException, "Paramter i is invalid ...");
			}
		}

		T& operator[] (int i) const
		{
			return (const_cast<Array<T>&>(*this)[i]);
		}

		// ��֤���ǳ����࣬������Ϊ���� tips ����������˼� const ����Ҳ��� ��Ȼ����ͬһ�ຯ�����ᵼ�������޷�ʵ����
		virtual int length() const = 0;

	};

}
#endif // !ARRAY_H


