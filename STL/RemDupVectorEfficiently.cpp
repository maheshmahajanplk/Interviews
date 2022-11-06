//Remove duplicates from a vector in O(n) complexity
#include<iostream>
#include<vector>
#include<algorithm>

void removeAllMatchingElements_Efficient(std::vector<int> & vec, int elem) //O(n) complexity where n is data-size
{
    vec.erase(std::remove(vec.begin(), vec.end(), elem), vec.end());                            
}

int main()
{
    std::vector<int> vec = {1, 4, 9, 2, 3, 4, 4, 8,8,7,6, 5, 99,8,};
    //removeAllMatchingElements_Efficient(vec,8);
    sort(vec.begin(),vec.end());
    vec.erase(unique(vec.begin(),vec.end()),vec.end());
    for(auto itr:vec){
        std::cout<<" "<<itr<<" ";
    }
    return 0;
}
    
    
