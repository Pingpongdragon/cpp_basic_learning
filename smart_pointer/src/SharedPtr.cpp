#include <atomic>
#include <memory>

using uint = unsigned int;
template<typename T>
class SharedPtr
{
public:
    SharedPtr() noexcept: ptr(nullptr),ref_count(new std::atomic<uint>(0)){}

    explicit SharedPtr(T* p) noexcept: ptr(p) , ref_count(new std::atomic<uint>(1)){}

    SharedPtr(const SharedPtr<T> & other) noexcept: ptr(other.get()),ref_count(other.ref_count)
    {
        add_ref();
    }

    template<typename U>
    SharedPtr(const SharedPtr<T> & other) noexcept: ptr(other.get()),ref_count(other.ref_count)
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

    SharedPtr<T> & operator=(const SharedPtr<T> & other) noexcept
    {
        release();
        ptr = other.get();
        ref_count = other.ref_count;
        add_ref();
        return *this;
    }

    template<typename U>
    SharedPtr<T> & operator=(const SharedPtr<U> & other) noexcept
    {
        release();
        ptr = other.get();
        ref_count = other.ref_count;
        add_ref();
        return *this;
    }

    T& operator*() const noexcept{
        return *ptr;
    }

    T* operator->() const noexcept{
        return ptr;
    }

    explicit operator bool() const noexcept{
        return ptr != nullptr;
    }

    bool operator==(const SharedPtr<T>& other) const noexcept{
        return ptr == other.ptr;
    }

    bool operator!=(const SharedPtr<T>& other) const noexcept{
        return !(*this == other);
    }

    bool unique() const noexcept{
        return ref_count->load() == 1;
    }

    T* get() const noexcept{
        return ptr;
    }

    std::size_t use_count() const noexcept{
        if (ref_count) {
        return ref_count->load();
        } else {
            return 0;
        }
    }

    void reset() noexcept{
        release();
        ptr = nullptr;
        ref_count = new std::atomic<uint>(0);
    }

    template<typename U>
    void reset(U* p) noexcept{
        release();
        ptr = p;
        ref_count = new std::atomic<uint>(1);
    }

    void swap(SharedPtr<T>& other) noexcept{
        std::swap(ptr, other.ptr);
        std::swap(ref_count, other.ref_count);
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

};
