#include <iostream>
#include <vector>

using namespace std;
//继续考虑是否可以继续优化，以及是否存在其他可能的未发现的问题！！！
template<typename T>
void adjustHeap(vector<T>& vec, int len, int idx)
{
    if(idx<len-1){
        if(2*idx+1<=len-1 && vec[idx]<vec[2*idx+1]){
            swap(vec[idx], vec[2*idx+1]);
            adjustHeap(vec, len, 2*idx+1);    
        }
        if(2*idx+2<=len-1 && vec[idx]<vec[2*idx+2]){
            swap(vec[idx], vec[2*idx+2]);
            adjustHeap(vec, len, 2*idx+2);
        }
    } 
}

template<typename T>
void makeHeap(vector<T>& vec, int len)
{
    for(int i=(len-1)>>1;i>=0;--i){
        if(2*i+1<=len-1 && vec[i]<vec[2*i+1]){
            swap(vec[i], vec[2*i+1]);
            adjustHeap(vec, len, 2*i+1);
        }
        if(2*i+2<=len-1 && vec[i]<vec[2*i+2]){
            swap(vec[i], vec[2*i+2]);
            adjustHeap(vec, len, 2*i+2);    
        }
    }
    return;
}

template<typename T>
void heapSort(vector<T>& vec)
{
    int len=vec.size();
    while(len>0){
        makeHeap(vec, len);
        swap(vec[0], vec[len-1]);
        --len;
    }
    return ;

}

void testHeapSort()
{
    //将这里的固定的写法改为输入输出的写法。
    vector<float> a={1.0f, 2.03f,8.7f,8.8f,9.3f,6.7f,10101.3f};
    heapSort(a);
    for(const auto & e: a)
        std::cout<<e<<endl;
}

int main(int argc, char** argv)
{
    testHeapSort();
    return 0;
}
