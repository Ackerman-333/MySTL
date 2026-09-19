#pragma once
#include<cstddef>
#include<utility>
#include <stdexcept>
template<typename T>
class MiniVector
{
private:
    T* data;
    std::size_t size_;
    std::size_t capacity_;
    void reallocate(std::size_t newCapacity)
    {
        T* newdata=new T[newCapacity];
        for(std::size_t i=0;i<size_;i++)
        {
            newdata[i]=std::move(data[i]);
        }
        delete[] data;
        data=newdata;
        capacity_=newCapacity;
    }
public:
    MiniVector():data(nullptr),size_(0),capacity_(0){}
    explicit MiniVector(std::size_t n)
        :data(new T[n]),size_(n),capacity_(n){}
    MiniVector(const MiniVector& other)
        :data(new T[other.capacity_]),size_(other.size_),capacity_(other.capacity_)
    {
        for(std::size_t i=0;i<size_;i++)
        {
            data[i]=other.data[i];
        }
    }
    MiniVector& operator=(const MiniVector&other)
    {
        if(this==&other)return *this;
        delete[] data;
        size_=other.size_;
        capacity_=other.capacity_;
        data=new T[capacity_];
        for(std::size_t i=0;i<size_;i++)
        {
            data[i]=other.data[i];
        }
        return *this;
    }
    MiniVector(MiniVector&& other)noexcept
        :data(other.data),size_(other.size_),capacity_(other.capacity_)
        {
            other.data=nullptr;
            other.size_=0;
            other.capacity_=0;
        }
    MiniVector& operator=(MiniVector &&other)noexcept
    {
        if(this==&other)return *this;
        delete[] data;
        data=other.data;
        size_=other.size_;
        capacity_=other.capacity_;
        other.data=nullptr;
        other.size_=0;
        other.capacity_=0;
        return *this;
    }
    void push_back(const T&value)
    {
        if(size_==capacity_)
        {
            std::size_t newCapacity=capacity_==0?1:capacity_*2;
            reallocate(newCapacity);
        }
        data[size_++]=value;
    }
    void reserve(std::size_t  newCapacity)
    {
        if(capacity_>=newCapacity)return ;
        reallocate(newCapacity);
    }
    void resize(std::size_t newSize)
    {
        if(newSize<=capacity_)
        {
            size_=newSize;
            return ;
        }
        reallocate(newSize);
        size_=newSize;
    }
    void pop_back()
    {
        if(size_==0)return;
        size_--;
    }
    T& at(std::size_t index)
    {
        if(index>=size_)throw std::out_of_range("MiniVector index out of range");
        else return data[index];
    }
    const T& at(std::size_t index) const
    {
        if(index>=size_)throw std::out_of_range("MiniVector index out of range");
        else return data[index];
    }
    T *begin()
    {
        return data;
    }
    T* end()
    {
        return data+size_;
    }
    const T* begin()const
    {
        return data;
    }
    const T* end()const
    {
        return data+size_;
    }
    T& operator[](const std::size_t index)
    {
        return data[index];
    }
    const T& operator[](const std::size_t index) const
    {
        return data[index];
    }
    ~MiniVector()
    {
        delete[] data;
    }
    std::size_t size() const
    {
        return size_;
    }
    std::size_t capacity()const
    {
        return capacity_;
    }
};