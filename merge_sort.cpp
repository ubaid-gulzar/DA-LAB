#include<iostream>
#include<vector>
using namespace std;

void merge( int arr[],int si, int ei, int mid){
     vector<int> temp;
     int i=si;
     int j=mid+1;
     while(i<=mid && j<=ei){
        if(arr[i]<= arr[j]){
            temp.push_back(arr[i++]);
        }
        else{
            temp.push_back(arr[j++]);
        }
     }
     while (i<=mid)
     {
        temp.push_back(arr[i++]);
     }
     while (j<=ei)
     {
        temp.push_back(arr[j++]);
     }
     // coppy vactor elements to our original array
     for(int idx=si,x=0;idx<=ei;idx++){
        arr[idx]=temp[x++];
     }
}

void merge_sort(int arr[],int si, int ei){
    if(si>=ei){
        return;
    }
     int mid=si+(ei-si)/2;    // to calculate mid element
     merge_sort(arr, si,mid);   //left half
     merge_sort(arr, mid+1,ei);  //right half

     merge(arr, si, ei, mid);   //conquer
}

void printarr(int arr[],int n){
   for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
   }
}

int main(){
    int arr[6]={6,3,7,5,2,4};
    int n=sizeof(arr)/sizeof(arr[0]);
    merge_sort(arr , 0 , n-1);
    printarr(arr , n);
    return 0;
}
