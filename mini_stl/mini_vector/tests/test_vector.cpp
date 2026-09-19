#include"../include/mini_vector.hpp"
#include<iostream>
#include <algorithm>
int main()
{

MiniVector<int> v;

v.push_back(10);
v.push_back(20);

auto it = v.begin();
std::cout << static_cast<const void*>(it) << '\n';
std::cout<<it;
}