#include<iostream>
#include<algorithm>
#include<vector>
int main()
{
    auto add=[](auto a,auto b){return a+b;};
    std::cout<<add(10,20)<<'\n';
    std::vector<int>v{43,7,25,32,61,18};
    std::sort(v.begin(),v.end(),[](int a,int b){return a>b;});
    for(auto x:v)
    {
        std::cout<<x<<'\n';
    }
    int threshold=30;
    auto it=std::find_if(v.begin(),v.end(),[threshold](int x){return x<threshold;});
    std::cout<<*it<<'\n';
    int x = 10;

    auto f1 = [x]() {
    std::cout << x << '\n';
    };
    auto f2 = [&x]() {
    std::cout << x << '\n';
    };
    x = 100;
    f1();
    f2();
}