#include<bits/stdc++.h>
using namespace std;

int PeakElement(vector<int>& arr, int low, int high) {
    // 5 10 20 15 
    int size=high;// size = N-1;
    while(low<=high){
        int mid = low+(high-low)/2;
        // writing case for if peak is present in between
        if(mid>0 && mid < size)
        {
            if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]){
                return arr[mid];
            }else if(arr[mid]<arr[mid-1]){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }else if(mid==0){
            if (arr[0]>arr[1]) return arr[0];
            else return arr[1];
        }else{
            if(arr[size]>arr[size-1]) return arr[size];
            else return arr[size-1];
        }
    }
    
}


int main(){
    vector<int> arr = { 0,100,30,90 };
    int N = arr.size();
    cout<<"peak element is : " << PeakElement(arr,0,N-1) <<endl; 
}
