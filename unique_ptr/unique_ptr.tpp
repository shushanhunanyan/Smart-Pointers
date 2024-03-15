template <typename T>
unique_ptr<T>::unique_ptr(T *ptr) 
	: m_ptr{ptr} 
{}


template <typename T>
unique_ptr<T>::~unique_ptr() 
{
	delete m_ptr;
	m_ptr = nullptr;
}


template <typename T>
unique_ptr<T>::unique_ptr(unique_ptr&& oth) 
	: m_ptr {oth.m_ptr} 
{
	oth.m_ptr = nullptr;
}


template <typename T>
unique_ptr<T>& unique_ptr<T>::operator=(unique_ptr&& oth) 
{
	if (this != &oth) {
		delete m_ptr;
		m_ptr = oth.m_ptr;
		oth.m_ptr = nullptr;
	}
	return *this;
}


template <typename T>
T& unique_ptr<T>::operator*() 
{ 
	return *m_ptr; 
}


template <typename T>
T* unique_ptr<T>::operator->()
{ 
	return m_ptr; 
}


template <typename T>
T* unique_ptr<T>::release() noexcept
{
	T *tmp = m_ptr;
	m_ptr = nullptr;
		 
        return tmp;
}


template <typename T>
template <typename U>
void unique_ptr<T>::reset(U *data) noexcept
{
	if (m_ptr != data) {
		delete m_ptr;
        	m_ptr = data;
	}
}


template <typename T>
void unique_ptr<T>::swap(unique_ptr& oth) noexcept
{
	T *tmp = m_ptr;
	m_ptr = oth.m_ptr;
	oth.m_ptr = tmp;
}


template <typename T>
T* unique_ptr<T>::get() const  noexcept
{
       return m_ptr; 
}





