// #ifndef __STRING__
// #define __STRING__
#include<string.h>
#include<iostream>
#include<algorithm>

class String
{
 char *m_res;
 unsigned int m_length;
 
 public: //Default
        String() : m_res(nullptr),m_length(0){ std::cout<<"\r\nDefault\r\n";}
        //Parametirised
        String(const char *str){
            if(str==nullptr)
                return;
            m_length = strlen(str);
            m_res = new char[m_length +1];
            strcpy(m_res,str);
            std::cout<<"\r\nParametirised\r\n";
        }
        //Destructor
        ~String(){
            if(m_res){
                delete[] m_res;
            }
            m_res=nullptr;//NOTE this step
            std::cout<<"\r\n~String\r\n";
        }
        //Copy constructor
        String(const String& str){ //creating temp obj
            this->m_length = str.m_length;
            m_res = new char[str.m_length+1];
            strcpy(m_res,str.m_res);
            std::cout<<"\r\nCopy\r\n";
        }
        //Copy Assignment COPY-AND-SWAP Idiom
        String& operator=(String other) //NOTE pass-by-value to get deleted after swap, henre no const as we are swaping/modifying the value
        {
            std::cout<<"\r\noperator=\r\n";
            Swap(*this,other);//value pointed by *this will be swapped into other & then deleted by call
            return *this;
        }
        void Swap(String& str1,String& str2)//modifying the values hence no const
        {
            std::swap(str1.m_res,str2.m_res);
            std::swap(str1.m_length,str2.m_length);
            std::cout<<"\r\nswap\r\n";
        }
        //move constructor
        String(/*non-const*/ String&& other){
            std::cout<<"\r\nmove constructor\r\n";
            this->m_length = other.m_length;
            strcpy(this->m_res,other.m_res);
            other.m_res = nullptr;
            other.m_length=0;
        }
        //move assignment
        String& operator=(/*non-const*/ String&& other){
            std::cout<<"\r\nmove assignment\r\n";
            if(this != &other){
                if(this->m_res)
                    delete[] m_res;
                this->m_length = other.m_length;
                this->m_res = other.m_res;
                other.m_res = nullptr;
                other.m_length = 0;
            }
            return *this;
        }


};
int main()
{
    String obj;
    String obj1("hello");
    String obj2 = "Hey hi";
    obj2 = obj1;
    std::cout<<"\ncalling std::move() [Expected: move constructor]\n";
    String str3 = std::move(obj1);
    std::cout<<"\ncalling std::move() [Expected: move assignment]\n";
    //String str1,str2;
    //str1 = std::move(str2);

    return 0;
}
//#endif