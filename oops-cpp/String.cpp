#include<iostream>
#include<string.h>
using namespace std;

class String
{
    public:
    String():res(nullptr),len(0)
    {
        cout<<"Default Constructor\n";
    }
    String(const char* ch)
    {
        cout<<"Parametirised Constructor\n";
        len=strlen(ch);
        cout<<"Parametirised Constructor=>1\n";
        res=new char[len+1];
        cout<<"Parametirised Constructor=>2\n";
        strcpy(res,ch);
        cout<<"Parametirised Constructor=>3\n";
    }
    String(const String& str)
    {
        cout<<"Copy Constructor\n";
        len=str.len;
        res=new char[len+1];
        strcpy(res,str.res);
    }

    String operator=(const String& str)
    {
        cout<<"Overloaded Assignment operator= \n";
        if(this!=&str)
        {
            delete[] res;
            len=str.len;
            res=new char[len+1];
            strcpy(res,str.res);
        }
        return *this;
    }

    private:
    unsigned int len;
    char * res;

};

int main()
{
    String str1="hello";
    std::cout<<"=======================1==========\n";
    str1 = "hello";//?? what will be called here pametirised constructor or copy assignment oprator
    std::cout<<"=======================2==========\n";
    return 0;
}