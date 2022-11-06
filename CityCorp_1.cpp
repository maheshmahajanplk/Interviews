//Question-1: Syntax for passing array by reference to lambda with a float by value
//Question-2: Write/solve consumer-producer problem/Queue using multithreading
#include<iostream>
#include<thread>
#include<array>
#include<vector>
#include<array>


int arr1[] = {1,2,3,4,5,6};
std::array<int,6> arr2 = {11,22,33,44,55,66};
std::vector<int> vec{21,22,23,24,25,26,27,28,29,30};
//Ans-1: Syntax for passing array by reference to lambda with a float by value
auto pass_check_array_c = [](int(&)[6], float b){
    for(int i=0;i<sizeof(arr1);i++)
        std::cout << arr1[i] << '\n';
};

auto pass_check_std_array = [](int(&)[6], float b){
    for(int i=0;i<sizeof(arr2);i++)
        std::cout << arr2[i] << '\n';
};

auto pass_check_vector = [vec](float b){
    for(int i=0;i<vec.size();i++)
        std::cout << vec[i] << '\n';
};

int main()
{
    float b=0.011f;
    pass_check_array_c(arr1,b);
    pass_check_std_array(arr2,b);
    pass_check_vector(vec,b);
    return 0;
}