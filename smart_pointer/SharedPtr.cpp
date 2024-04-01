#include <atomic>
#include <memory>

template<typename T>
class SharedPtr
{
public:
    SharedPtr() : ptr(nullptr),ref_count(new std::atomic<uint>(0)){}

    explicit SharedPtr(T* p) : ptr(p) , ref_count(new std::atomic<uint>(1)){}

    SharedPtr(const SharedPtr<T> & other) : ptr(other.get()),ref_count(other.ref_count)
    {
        add_ref();
    }

    template<typename U>
    SharedPtr(const SharedPtr<T> & other) : ptr(other.get()),ref_count(other.ref_count)
    {
        add_ref();
    }

    SharedPtr(SharedPtr<T> && other) noexcept : ptr(other.get()),ref_count(other.ref_count)
    {
        other.ptr = nullptr;
        other.ref_count = nullptr;
    }

    template<typename U>
    SharedPtr(SharedPtr<U> && other)  noexcept : ptr(other.get()),ref_count(other.ref_count)
    {
        other.ptr = nullptr;
        other.ref_count = nullptr;
    }

    ~SharedPtr()
    {
        release();
    }

    SharedPtr<T> & operator=(const SharedPtr<T> & other)
    {
        release();
        ptr = other.get();
        refCount = other.refCount;
        addRef();
        return *this;
    }

    template<typename U>
    SharedPtr<T> & operator=(const SharedPtr<U> & other)
    {
        release();
        ptr = other.get();
        refCount = other.refCount;
        addRef();
        return *this;
    }

    T& operator*() const{
        return *ptr;
    }

    T* operator->() const{
        return ptr;
    }

    explicit operator bool() const{
        return ptr != nullptr;
    }

    bool operator==(const SharedPtr<T>& other) const{
        return ptr == other.ptr;
    }

    bool operator!=(const SharedPtr<T>& other) const{
        return !(*this == other);
    }

    

private :
    T *ptr;
    std::atomic<uint> *ref_count;

    void add_ref()
    {
        if(ref_count)
        {
            ref_count->fetch_add(1);
        }
    }

    void release()
    {
        if(ref_count && ref_count->fetch_sub(1) == 1)
        {
            delete ptr;
            delete ref_count;
            ptr = nullptr;
            ref_count = nullptr;
        }
    }

    T* get() const{
        return ptr;
    }

};