#pragma once

#include <memory>

template<typename T>
class Singleton
{
public:
	using Ptr = std::shared_ptr<T>;

public:
	static Ptr get()
	{
		if (!m_instance)
		{
			m_instance = Ptr(new T());
		}

		return m_instance;
	}

private:
	static Ptr m_instance;
};

template<typename T>
typename Singleton<T>::Ptr Singleton<T>::m_instance;