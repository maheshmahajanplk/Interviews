//FlexTrade interview question
#include<iostream>

class MyClass
{
    int m;
    float n;
public:
    MyClass() {
        std::cout << "MyClass();\n";
            m = 0;
            n = 0.0f;
    }
    
    MyClass(int a,float b) {
        m = a;
        n = b;
        std::cout << "MyClass(int,float);\n";
    }
};

int main()
{
    MyClass arrMyClass[10];
    MyClass arr[5] = {
        {1,1.1f},
        {2,2.2f},
        {3,3.3f},
        {4,4.4f},
        {5,5.5f}
   };
}