#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
template<typename T>
class Vector
{
private:
    T* data;
    std::size_t size;
    std::size_t capacity;
public:
    Vector():data(nullptr),size(0),capacity(0){}
    ~Vector()
    {
        delete[] data;
    }
    void reserve(std::size_t newCapacity)
    {
        if(capacity>=newCapacity)return;
        T* newdata=new T[newCapacity];
        for(size_t i=0;i<size;i++)
        {
            newdata[i]=std::move(data[i]);
        }
        delete[] data;
        data=newdata;
        capacity=newCapacity;
    }
    void push_back(const T& value)
    {
        if(capacity==size)
        {
            std::size_t newCapacity=capacity==0?1:capacity*2;
            reserve(newCapacity);
        }
        data[size++]=value;
    }
    T& operator[](std::size_t index)
    {
        return data[index];
    }
    const T& operator[](std::size_t index)const
    {
        return data[index];
    }
    std::size_t getSize()const
    {
        return size;
    }
    std::size_t getCapacity() const
    {
        return capacity;
    }
    T* begin()
    {
        return data;
    }
    T* end()
    {
        return data+size;
    }
    const T* begin() const
    {
        return data;
    }
    const T* end() const
    {
        return data+size;
    }
    T* find(T* first,T* last,const T& value)
    {
        while(first!=last&&(*first)!=value)first++;
        return first;
    }
};
int main()
{

}
