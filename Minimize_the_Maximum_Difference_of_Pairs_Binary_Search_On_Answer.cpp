#include<bits/stdc++.h>
using namespace std;
  bool isvalid(vector<int>& nums, int mid, int p); // we need to define it before as we are using this func in minimizeMax
    int minimizeMax(vector<int>& nums, int p) {
        //conditions:
        // no index appears more then one that means i,j,k = could be (i,j) not (k,j) , since j already arrived once 
        // take abosulute value |nums[i]-nums[j]| , so we can sort the array 

        // Input: nums = [10,1,2,7,1,3], p = 2 , pairs could be (1,1) (2,3)

        sort(nums.begin(), nums.end()); 
        // nums = [1,1,2,3,7,10] , ans = 0 , low = 0 high = 10-1 = 9 ; 
        // we are making a number line to apply binary search on answer
        // 0 1 2 3 4 5 6 7 8 9
        int ans=0;
        int low=0;
        int high=nums[nums.size()-1]-nums[0];

        while (low<=high){
            int mid = low + (high-low)/2; // 0+6/2 = 3 
            if(isvalid(nums,mid,p)==true){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans; 
    }

    bool isvalid(vector<int>&nums,int mid,int p){
        //conditions 1 1 2 3 7 10, p =2 , mid = 3 
        int in = 0; //  to keep the track if element has been already taken or not 
        int count = 0;  // to count how many possible pairs if count is greater then P we return true 
        // FFFFFTTTTTT   or TTTTTTFFFFF
        // we always needs to find first true ( T )


        for(int i = 1 ; i<nums.size();i++){
             if(in==1){
                 in = 0;
                 continue;
             }
             if(nums[i]-nums[i-1]<=mid){
                 in = 1;
                 count++;
             }
        }
      return count>=p;
    }


int main(){
    vector<int> nums = { 10,1,2,7,1,3 };
    int p=2;
    cout<<"minimized maximum difference  is : " << minimizeMax(nums,p) <<endl; 
}
