#include<iostream>
#include<memory>
#include<vector>
#include<algorithm>
int main()
{
    std::vector<int>v{42,7,35,18,61,23};
    std::sort(v.begin(),v.end(),[](int a,int b){return a>b;});
    int threshold=30;
    auto it=std::find_if(v.begin(),v.end(),[threshold](int x){return x<threshold;});
    std::cout<<*it<<'\n';
    for(auto &a:v)
    {
        std::cout<<a<<'\n';
    }
}