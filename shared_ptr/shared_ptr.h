#include <cstddef>
#include <memory>


struct ControlBlock
{
	size_t sharedCount;
	size_t weakCount;
	//void (*)(T*) deleter;
public:
	ControlBlock();
};

template <typename T>
class shared_ptr
{
public:
	shared_ptr();
	shared_ptr(T *rs);
	shared_ptr(const shared_ptr<T>& oth);
	template <typename Y>
	shared_ptr(const std::weak_ptr<Y>& oth);
	~shared_ptr();
public:
	shared_ptr& operator=(const shared_ptr<T>& oth);
	T& operator*();
	T* operator->();

private:
	T *m_data;
	ControlBlock *m_block;
};

#include "shared_ptr.tpp"

