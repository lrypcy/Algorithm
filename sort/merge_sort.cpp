#include <vector>
#include <iostream>
using namespace std;
//typedef bool (*CMPF)() 
/*
template<typename VectorType>
ReturnType merge_sort(VectorType& input_vec)
{

}

template<typename VectorType, typename Type>
void merge(VectorType& input_vec, Type l, Type r)
{
    for (Type i=l; i<r;++i){
        if()
    }
}
*/
template <typename T>
vector<T> merge(const vector<T>& vec_1, const vector<T>& vec_2)
{
    vector<T> temp;
    int i=0,j=0;
    while(i<vec_1.size()&&j<vec_2.size()){
        if(vec_1[i]<vec_2[j]) {
            temp.push_back(vec_1[i]);
            ++i;
        }
        else{
            temp.push_back(vec_2[j]);
            ++j;
        }
    }
    while(i<vec_1.size()){
        temp.push_back(vec_1[i]);
        ++i;
    }
    while(j<vec_2.size()){
        temp.push_back(vec_2[j]);
        ++j;
    }
    return temp;
}

template <typename T>
vector<T> merge_sort(vector<T>& input_vec, int low, int high)
{
        vector<T> temp;
        if(low==high) {
            temp.push_back(input_vec[low]);
            return temp;
        }
        int mid=low+((high-low)>>1);
        auto temp1=merge_sort(input_vec, low, mid);
        auto temp2=merge_sort(input_vec, mid+1, high);
        temp=merge(temp1, temp2);
        return temp;
}


int main()
{
    vector<int> a={1,3,2,21,43,12,4};
    vector<int> res;
    res= merge_sort(a,0, a.size()-1);
    for (auto& e: res)
    std::cout<<e<<endl;
    return 0;
}









