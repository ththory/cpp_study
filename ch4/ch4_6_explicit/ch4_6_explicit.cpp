#include <iostream>

class MyString
{
    char *string_content; // 문자열 데이터를 가리키는 포인터
    int string_length;    // 문자열 길이

    int memory_capacity;

public:
    // capacity 만큼 미리 할당함.
    explicit MyString(int capacity);

    // 문자열로 부터 생성
    MyString(const char *str);

    // 복사 생성자
    MyString(const MyString &str);

    ~MyString();

    int length() const;
};

MyString::MyString(int capacity)
{
    string_content = new char[capacity];
    string_length = 0;
    memory_capacity = capacity;
    std::cout << "Capacity : " << capacity << std::endl;
}

MyString::MyString(const char *str)
{
    string_length = 0;
    while (str[string_length++])
    {
    }

    string_content = new char[string_length];
    memory_capacity = string_length;

    for (int i = 0; i != string_length; i++)
        string_content[i] = str[i];
}
MyString::MyString(const MyString &str)
{
    string_length = str.string_length;
    string_content = new char[string_length];

    for (int i = 0; i != string_length; i++)
        string_content[i] = str.string_content[i];
}
MyString::~MyString() { delete[] string_content; }
int MyString::length() const { return string_length; }

void DoSomethingWithString(MyString s)
{
    std::cout << "DoSomethingWithString!" << std::endl;
}

int main()
{
    // DoSomethingWithString(3);

    MyString s1 = "abc";
    std::cout << s1.length() << std::endl;

    // explicit 키워드로 되어있는 생성자는 명시적으로 선언되어 암시적 변환 불가
    // MyString s2 = 3;
    // std::cout << s2.length() << std::endl;
}