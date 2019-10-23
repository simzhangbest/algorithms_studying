#include "Exception.h"
#include <cstring>
#include <cstdlib>
#include <stdio.h>
using namespace std;
namespace SimLib
{

	void Exception::init(const char* message, const char* file, int line)
	{
		m_message = _strdup(message);//�ַ������Ƶ��ѿռ�

		if (file != NULL)
		{
			char sl[16] = { 0 };
			sprintf_s(sl,"%d" , line);
			m_location = static_cast<char*> (malloc(strlen(file) + strlen(sl) + 2));

			if (m_location != NULL)
			{
				m_location = strcpy(m_location, file);
				m_location = strcat(m_location, ":");
				m_location = strcat(m_location, sl);
			}
			else
			{
				// �ѿռ��޷������ڴ�
				m_location = NULL;
			}

		}
		else
		{
			m_location = NULL;
		}
	}

	Exception::Exception(const char* message)
	{
		init(message, NULL, 0);
	}
	Exception::Exception(const char* file, int line)
	{
		init(NULL, file, line);
	}
	Exception::Exception(const char* message, const char* file, int line)
	{
		init(message, file, line);
	}


	Exception::Exception(const Exception& e)
	{
		m_message = _strdup(e.m_message);
		m_location = _strdup(e.m_location);
	}

	Exception& Exception::operator= (const Exception& e)
	{
		if (this != &e)
		{
			free(m_location);
			free(m_message);

			m_message = _strdup(e.m_message);
			m_location = _strdup(e.m_location);

		}
		return *this;
	}

	const char* Exception::message() const
	{
		return m_message;
	}
	const char* Exception::location() const
	{
		return m_location;
	}

	Exception::~Exception()
	{
		free(m_message);
		free(m_location);
	}

}