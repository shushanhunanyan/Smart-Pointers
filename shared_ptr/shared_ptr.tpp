#include "shared_ptr.h"

#include <stdexcept>

//template <typename T>
ControlBlock::ControlBlock()
        : sharedCount{}
        , weakCount{}
{}


template <typename T>
shared_ptr<T>::shared_ptr() 
	: m_data{}
	, m_block{new ControlBlock()}
{}


template <typename T>
shared_ptr<T>::shared_ptr(T *rs)
        : m_data{}
        , m_block{new ControlBlock()}
{
	if (rs != nullptr) {
                m_data = rs;
                m_block->sharedCount++;
	}
}


template <typename T>
shared_ptr<T>::shared_ptr(const shared_ptr<T>& oth) 
	: m_block{oth.m_block}
	, m_data{}
{
	if (nullptr != oth.m_data) {
		m_data = oth.m_data;
		m_block->sharedCount++;
	}
}


template <typename T>
shared_ptr<T>& shared_ptr<T>::operator=(const shared_ptr<T>& oth)
{
       if (&oth != this) {
	       if (0 == m_block->sharedCount && 0 == --m_block->sharedCount) {
		       delete m_data;
		       delete m_block;
	       }

	       m_data = oth.m_data;
	       m_block = oth.m_block;
	       m_block->sharedCount++;
       }
       return *this;
}


template <typename T>
template <typename Y>
shared_ptr<T>::shared_ptr(const std::weak_ptr<Y>& oth)
        : m_block{oth.m_block}
        , m_data{}
{
        if (0 != oth.m_block->sharedCount) {
                m_data = oth.m_data;
                m_block->weakCount++;
        }
}


template <typename T>
shared_ptr<T>::~shared_ptr()
{
	if (0 == --m_block->sharedCount) {
		delete m_block;
		delete m_data;
	}
}


template <typename T>
T& shared_ptr<T>::operator*()
{
       if (m_data != nullptr) {	
	       return *m_data;
       } else {
	       throw std::runtime_error("dereferencing nullptr is runtime error!!!");
       }
}


template <typename T>
T* shared_ptr<T>::operator->()
{      
       if (m_data != nullptr) { 
               return m_data;
       } else {
               throw std::runtime_error("dereferencing nullptr is runtime error"); 
       }
}
