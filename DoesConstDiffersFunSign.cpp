//HCL interview question

/*Question: Does the const'ness of function argument make it differ from other same function 
signature without const
Ans=> In case of non-pointer => not allowed, compiler error redefinintion
      In case of pointer => no error, it will differ
      In case of reference => no error, no output check it once again
*/

#include<iostream>
using namespace std;
 
//void fun(char *a)
void fun(char &a)
//void fun(int a) ////redefinition error for non-pointers
{
cout << "non-const fun() " << a;
}
 
//void fun(const char *a)
void fun(const char &a)
//void fun(const int a) //redefinition error for non-pointers
{
cout << "const fun() " << a;
}
 
int main()
{
const char *ptr = "GeeksforGeeks";
const int a=10;
const char d='A';
const char & ref = d;
fun(d);
//const int b;//compiler error
int c;
//fun(ptr);
/*fun(a);
cout<<"calling fun(b)\n";
fun(b);
cout<<"calling fun(b)\n";
fun(c);*/
return 0;
}