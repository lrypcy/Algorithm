/*************************************************************************
	> File Name: testquick.cpp
	> Author:cpei 
	> Mail:p_c_yuan@163.com 
	> Created Time: Mon 11 Dec 2017 11:24:24 AM EST
 ************************************************************************/

#include<iostream>
#include "quicksort.cpp"
using namespace std;
int main(void){
	double arr[]={1.2,3.4,6,7.8,8,5,3.5,7.6,8.2,8.6,2.2,2.2,4.5,6.6};
	for(int i=0;i<=13;i++){
	cout<<arr[i]<<' ';
	}
	cout<<endl;
	quicksort<double>(arr,0,13);
	for(int i=0;i<=13;i++){
		cout<<arr[i]<<' ';
	}
	cout<<endl;
	return 0;
}
