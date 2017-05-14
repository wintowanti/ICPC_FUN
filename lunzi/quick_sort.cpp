#include <cstdio>
#include <iostream>
using namespace std;
/***
 *poj 2388
 *1. use sort algorithm
 *2. use partition algorithm find k-th value
***/
void quick_sort(int [], int ,int);
int adjust_array(int [], int ,int);
int partition_k(int [], int, int ,  int );
void quick_sort(int array[], int l, int r){
    if(l < r){
        int split_idx = adjust_array(array, l, r);
        quick_sort(array, l, split_idx);
        quick_sort(array, split_idx+1, r);
    }
}
int partition_k(int array[], int l, int r, int k){
    if(l < r){
        int split_idx = adjust_array(array, l, r);
        if(split_idx == k) return array[split_idx];
        else if(split_idx > k){
            return partition_k(array, l, split_idx, k);
        }
        else{
            return partition_k(array, split_idx+1, r, k-(split_idx+1));
        }
    }
    return array[l];
}
int adjust_array(int array[], int l, int r){
    if(l < r){
        // use the first element as reference
        int temp = array[l];
        int i = l;
        int j = r;
        while(i < j){
            while(i < j && array[j] >= temp) j--;
            if(i < j) array[i++] = array[j];
            while(i < j && array[i] < temp) i++;
            if(i < j) array[j--] = array[i];
        }
        //i is split index of array 
        array[i] = temp;
        return i;
    }
    return -1;
}
const int MX = 100008;
int num[MX];
int main(){
    int n;
    while(cin>>n){
        for(int i = 0; i < n; i++){
            scanf("%d",&num[i]);
        }
        //quick_sort(num, 0, n-1);
        int ans = partition_k(num,0, n-1, n/2);
        cout<<ans<<endl;
    }
    return 0;
}
