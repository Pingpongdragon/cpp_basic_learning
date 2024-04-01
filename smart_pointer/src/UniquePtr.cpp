#include <algorithm>
template<typename T>
class UniquePtr
{
public:
    UniquePtr() noexcept :ptr(nullptr) {}
    explicit UniquePtr(T * p) noexcept : ptr(p) {}
    UniquePtr(UniquePtr && other) noexcept : ptr(other.ptr) {
        other.ptr = nullptr;
    }
    UniquePtr(const UniquePtr & other) = delete;

    ~UniquePtr() {delete ptr;}

    UniquePtr& operator=(UniquePtr &&other) noexcept {
        if(*this != other)
        {
            ptr = other.ptr;
            other.ptr = nullptr;
        }
        return * this;
    }
    UniquePtr& operator=(const UniquePtr& other) = delete;

    T& operator*() const noexcept{
        return *ptr;
    }

    T* operator->() const noexcept{
        return ptr;
    }

    bool operator==(const UniquePtr& other) const noexcept 
    { return ptr == other.ptr; }
    bool operator!=(const UniquePtr& other) const noexcept 
    { return ptr != other.ptr; }

    void swap(UniquePtr& other) noexcept { std::swap(ptr, other.ptr); }

    T* get() const noexcept { return ptr; }

    T* release() noexcept 
    {
        T* p = ptr;
        ptr = nullptr;
        return p;
    }
private:
    T *ptr;
};

