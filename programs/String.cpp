int main()
{
    String str1;//default
    String str2="hello";//parametirised
    String str3=str2;//copy constructor
    String str5(str2);//copy constructor
    str3=str2;//copy assignment
    str3="Hey Hi";//what will be called here is => overloaded assignment as str3 already been created
    int len=str2.length();
    std::cout<<str2<<str3<<str1;//overloading <<
    cin>>str1;//overloading >>
    String str6=std::move(str3); //will it call move assignment? , what is r-value?

}