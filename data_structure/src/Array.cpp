#include <cstddef>
#include <algorithm>
//Gonna implement iterators later
template<typename T,size_t N>
class Array{
public : 
    Array() noexcept{}

    Array(const Array<T,N> & other) noexcept{
        std::copy(other.m_data, other.m_data + N,m_data);
    }

    Array(Array<T,N> && other) noexcept{
        std::move(other.m_data, other.m_data + N,m_data);
    }

    Array& operator=(const Array<T,N> & other) noexcept{
        if(*this != other)
        {
            std::copy(other.m_data, other.m_data + N,m_data);
        }
        return *this;
    }

    Array& operator=(Array<T,N> && other) noexcept{
        if(*this != other)
        {
            std::move(other.m_data, other.m_data + N,m_data);
        }
        return *this;
    }

    constexpr size_t size() const noexcept{
        return N;
    }
    T& operator[](size_t index){
        return m_data[index];
    }
    const T& operator[](size_t index) const{
        return m_data[index];
    }
    T* data(){
        return m_data;
    }
    const T * data() const{
        return m_data;
    }
private:
    T m_data[N];
}; 