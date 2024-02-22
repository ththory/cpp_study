#include <iostream>

class A
{
    // const 함수 내에서 const가 아닌 작업을 할 수 있게 만들어 줌
    // ex) DB -> cache 저장
    mutable int data_;

public:
    A(int data) : data_(data) {}
    void DoSomething(int x) const
    {
        data_ = x;
    }
    void Print() const { std::cout << data_ << std::endl; }
};

int main()
{
    A a(10);
    a.DoSomething(7);
    a.Print();
}