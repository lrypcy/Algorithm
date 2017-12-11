/*************************************************************************
	> File Name: quicksort.cpp
	> Author:cpei
	> Mail: p_c_yuan@163.com 
	> Created Time: Mon 11 Dec 2017 09:35:25 AM EST
 ************************************************************************/
template<typename ArrayType>
int partition(ArrayType arr[],int p,int r)
{
	ArrayType temp;
	ArrayType pivot=arr[r];
	int i = p-1;
	int j=p;
	for(;j<r;j++){
		if( arr[j]<=pivot){
		i=i+1;
		temp=arr[j];arr[j]=arr[i];arr[i]=temp;
		}
		}
	temp=arr[i+1];arr[i+1]=arr[r];arr[r]=temp;
return i+1;
}

template<typename ArrayType>
void quicksort(ArrayType arr[],int p,int r){
	if(p<r)
	{ int q=partition<ArrayType>(arr,p,r);
	quicksort<ArrayType>(arr,p,q-1);
	quicksort<ArrayType>(arr,q+1,r);
    }
}
