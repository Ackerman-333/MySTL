#include <iostream>
#include <utility>
#include<memory>
#include<string>
class Node
{
public:
    std::string name;
    std::shared_ptr<Node>next; 
    std::weak_ptr<Node>near;
    Node(std::string n)
        :name(std::move(n))
    {
        std::cout<<"consturct"<<name<<'\n';
    }
    ~Node()
    {
        std::cout<<"desturct"<<name<<'\n';
    }
};
int main()
{
    auto a=std::make_shared<Node>("A");
    auto b=std::make_shared<Node>("B");
    a->next=b;
    b->near=a;
    std::cout<<a.use_count()<<'\n';
    std::cout<<b.use_count();
}