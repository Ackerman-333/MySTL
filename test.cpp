#include<iostream>
template<typename T>
class MyArray
{
private:
    T *data;
    int size;
public:
    MyArray(int n)
    :data(new T[n]{}),size(n){}
    ~MyArray()
    {
        delete[] data;
    }
    MyArray(const MyArray& other)
    :data(new T[other.size]{}),size(other.size)
    {
        for(int i=0;i<size;i++)
        {
            data[i]=other.data[i];
        }
    }
    MyArray& operator=(const MyArray& other)
    {
        if(&other!=this)
        {
            delete[] data;
            data=new T[other.size]{};
            size=other.size;
            for(int i=0;i<size;i++)
            {
                data[i]=other.data[i];
            }
        }
        return *this;
    }
    MyArray(const MyArray&&other)noexcept
    :data(other.data),size(other.size)
    {
        other.data=nullptr;
        other.size=0;
    }
    MyArray& operator=(const MyArray&&other)noexcept
    {
        if(&other!=this)
        {
            delete[] data;
            data=other.data;
            size=other.data;
            other.data=nullptr;
            other.size=0;
        }
        return *this;
    }
    T& operator[](int index)
    {
        return data[index];
    }
    const T& operator[](int index)const
    {
        return data[index];
    }
};
int main()
{

}
