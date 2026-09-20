#include<iostream>
template<typename T>
T Max(const T& a,const T& b)
{
    return a>b?a:b;
}
int main()
{
std::cout << Max(10, 20) << '\n';
std::cout << Max(3.14, 2.71) << '\n';

std::string a = "abc";
std::string b = "xyz";

std::cout << Max(a, b) << '\n';
}