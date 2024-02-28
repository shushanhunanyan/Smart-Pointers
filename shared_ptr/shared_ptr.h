template <typename T>
class shared_ptr
{
public:
	~shared_ptr();
        shared_ptr();
        shared_ptr(T*);
        shared_ptr(const shared_ptr&);
        shared_ptr& operator=(const shared_ptr&);
        T& operator*();
        T* operator->();
	T& operator[](int);
private:
        int *m_count;
        int *m_res;
};

