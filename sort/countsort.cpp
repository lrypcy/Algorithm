#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstdio>

using namespace std;

// 关于计数排序的实现
vector<int> countSort(const vector<int>& vec)
{
    int sz_vec=vec.size();
    if(sz_vec==0) perror("The input vector should be larger than 0");
    if(sz_vec==1) return vec;
    int MAX,MIN;
    MIN=vec[0];
    MAX=vec[0];
    for(auto i=1; i<vec.size(); ++i){
        if(MAX<vec[i]) MAX=vec[i];
        if(MIN>vec[i]) MIN=vec[i];
    }
    vector<int> cnt(MAX-MIN+1,0);
    vector<int> res(sz_vec, 0);
    for (const auto & e : vec)
        ++cnt[e-MIN];
    for (int i=1; i<MAX-MIN+1; ++i)
        cnt[i]+=cnt[i-1];
    for (int i=sz_vec-1; i>=0; --i)
        res[--cnt[vec[i]-MIN]]=vec[i];//这里要注意，因为不是按照原来的vec中的元素来组织cnt的。
    return res;
}
inline void testCountSort()
{
    vector<int> vec={2,35,6,4,67,2};
    vector<int> a=countSort(vec);
    for (const auto & e: a)
        cout<<e<<endl;
    return ;
}

int main()
{
    testCountSort();
    return 0;
}
