#include <iostream>
#include <algorithm>
using namespace std;

void printarray(int arr[], int n) {
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}


int partition(int arr[], int si, int ei){
    int i=si-1;
    int pivot = arr[ei];
    for(int j=si; j<ei; j++){
        if(arr[j] <= pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    i++;
    swap(arr[i],arr[ei]);
    return i;
}
void quick_sort(int arr[],int si,int ei){
     if(si>=ei){
        return;
     }
     int pi = partition( arr, si, ei);
     quick_sort(arr,si, pi-1);   //left half
     quick_sort(arr, pi+1,ei);   //right half 
}
int main() {
    int arr[] = {6,3,7,5,2,4,11,8,10,45,23};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "original array is: ";
    printarray(arr, n);
    quick_sort(arr,0,n-1);
    cout << "Sorted array is: ";
    printarray(arr, n);
    return 0;
}