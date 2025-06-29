#include <iostream>
#include <vector>
#include <algorithm> // for swap
using namespace std;
class Solution {
public:
    void heapify(vector<int> &nums, int ind, int val) {
            if(val<nums[ind]){
                nums[ind]=val;
                heapifyUp(nums,ind);
            }
            else{
                nums[ind]=val;
                heapifyDown(nums,ind);
            }
    }
private:    
    void heapifyUp(vector<int>&nums,int i){
          int parent=(i-1)/2;
          if(parent>=0 && nums[i]<nums[parent]){
               swap(nums[i],nums[parent]);
               heapifyUp(nums,parent);
          }
    }
    void heapifyDown(vector<int>& nums,int i){
        int smallest=i;
        int left=2*i+1;
        int right=2*i+2;
        int n=nums.size();
        if(left<n && nums[smallest]>nums[left]){
            smallest=left;
        }
        if(right<n && nums[smallest]>nums[right]){
            smallest=right;
        }
        if(smallest!=i){
            swap(nums[smallest],nums[i]);
            heapifyDown(nums,smallest);
        }
    }
};
 int main(){
     vector<int> nums = {1, 4, 5, 5, 7, 6};
    int ind = 5, val = 2;
     Solution sol;
     sol.heapify(nums,ind,val);

     for(auto it:nums){
        cout<<it<<",";
     }
    
    return 0;
 }   