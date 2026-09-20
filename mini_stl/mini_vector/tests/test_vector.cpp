#include"../include/mini_vector.hpp"
#include<iostream>
#include <algorithm>
int main()
{

MiniVector<int> v;

v.push_back(30);
v.push_back(10);
v.push_back(20);

std::sort(v.begin(), v.end());

for (const auto& x : v)
{
    std::cout << x << ' ';
}
}