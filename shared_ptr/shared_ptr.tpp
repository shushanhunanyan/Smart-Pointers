#include "shared_ptr.h"


#include <iostream>

template <typename T>
shared_ptr<T>::shared_ptr() 
	: m_res{}
	, m_count{new size_t(0)}
{}

template <typename T>
shared_ptr<T>::~shared_ptr()
{
	--(*m_count);
	if (*m_count == 0) {
		delete m_res;
		delete m_count;
	}

}

template <typename T>
shared_ptr<T>::shared_ptr(T* rs)
{
	if (rs.m_res != nullptr) {
		m_res = rs->m_res;
		m_count = rs->m_count;
		++(*m_count);

	} else {
		m_res = nullptr;
		m_count = new size_t(0);
	}
	
}

template <typename T>
shared_ptr<T>::shared_ptr(const shared_ptr<T>& oth)
{
	if (oth->m_res != nullptr) {
		m_res = oth.m_res;
		m_count = oth.m_count;
		++(*m_count);
	}
	m_res = nullptr;
	m_count = new size_t(0);
}

template <typename T>
shared_ptr<T>& shared_ptr<T>::operator=(const shared_ptr<T>& oth)
{
	if (this != &oth) {
		if (m_count && --(*m_count) == 0) {
			delete m_res;
			delete m_count;
        	}

        	m_count = oth->m_count;

        	if (oth->m_count == 0) {
                	m_res = nullptr;

        	} else {
                	m_res = oth.m_res;
                	++(*m_count);
        	}
	}
	return *this;
}


template <typename T>
T& shared_ptr<T>::operator*()
{
	if (m_res) {
		return *m_res;
	} else {
		std::cerr << "nullptr dereference = runtime error." << std::endl;
	}
}

template <typename T>
T* shared_ptr<T>::operator->()
{
	if (m_res) {
		return m_res;
	} else {
		std::cerr << "Do you wanna see runtime error?" << std::endl;
	}
}

template <typename T>
T& shared_ptr<T>::operator[](int index)
{
	return m_res[index];
}


