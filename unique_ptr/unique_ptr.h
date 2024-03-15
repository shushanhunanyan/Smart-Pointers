template <typename T>
class unique_ptr
{
public:
	unique_ptr() = default;
        unique_ptr(T *ptr);
        ~unique_ptr();
        unique_ptr(unique_ptr&& oth);
	unique_ptr(const unique&) = delete;
	unique_ptr& operator=(const unique_ptr&) = delete;
public:
        unique_ptr& operator=(unique_ptr&& oth);
        T& operator*();
        T* operator->();

public:
	T* get() const noexcept;
	T* release() noexcept;
	template <typename U>
	void reset(U*) noexcept;
	void swap(unique_ptr&) noexcept;

private:
        T *m_ptr;
};

//make_unique();


#include "unique_ptr.tpp"
