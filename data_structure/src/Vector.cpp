#include <cstddef>
#include <utility>
template<typename T>
class Vector{
public:
    Vector() noexcept : m_data(nullptr), m_capacity(0), m_size(0){ReAllocate(2);}

    size_t Size() const{
        return m_size;
    }

    void PushBack(const T& value) 
    {
        if(m_size >= m_capacity)
            ReAllocate(m_size * 2);
        m_data[m_size++] = value;
    }

    void PushBack(T && value)
    {
        if(m_size >= m_capacity)
            ReAllocate(m_size * 2);
        m_data[m_size++] = std::move(value);
    }

    void PopBack(){
        if(m_size > 0){
            m_size--;
            m_data[m_size].~T();
        }
    }

    //forward
    template<typename ... Args>
    T& EmplaceBack(Args&&... args){
        if(m_size >= m_capacity){
            ReAllocate(m_size * 2);
        }
        new (&m_data[m_size]) T(std::forward<Args>(args)...);
        return m_data[m_size++];
    }

    T& operator[](size_t index){
        return m_data[index];
    }

    const T& operator[](size_t index) const{
        return m_data[index];
    }

    void Clear(){
        for(size_t i = 0;i < m_size;i++)
            m_data[i].~T();
        m_size = 0;
    }

    ~Vector(){
        Clear();
        ::operator delete(m_data,m_capacity * sizeof(T));
    }

private:
    T* m_data;
    size_t m_capacity;
    size_t m_size;

    //shrink or enlarge
    void ReAllocate(size_t new_capacity)
    {
        //global new
        T * new_block = (T *)::operator new(new_capacity * sizeof(T));

        if(new_capacity < m_size)
            m_size = new_capacity;

        for(size_t i = 0;i < m_size;i++)
        {
            new(&new_block[i]) T(std::move(m_data[i]));
        }

        Clear();
        ::operator delete(m_data,m_capacity * sizeof(T));
        m_data = new_block;
        m_capacity = new_capacity;
    }
};
