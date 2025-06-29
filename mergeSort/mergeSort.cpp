#include<bits/stdc++.h>
#include<vector>
using namespace std;

class Solution {
    public:
        void merge(int l,int mid,int h,vector<int>&nums){
            vector<int> temp;
            int left=l;
            int right=mid+1;
            while(left<=mid && right<=h){
    
                if(nums[left]<=nums[right]){
                    temp.push_back(nums[left]);
                    left++;
                }
                else{
                    temp.push_back(nums[right]);
                    right++;
                }
            }
            while(left<=mid) {
                temp.push_back(nums[left]);
                left++;
            }
            while(right<=h){
                temp.push_back(nums[right]);
                right++;
            }
            for(int i=l;i<=h;i++){
                nums[i]=temp[i-l];
            }
        }
        void sort(int l,int h,vector<int>&nums){
           if(l>=h) return;
           int mid=l+(h-l)/2;
           sort(l,mid,nums);
           sort(mid+1,h,nums);
           merge(l,mid,h,nums);
        }
        vector<int> mergeSort(vector<int>& nums) {
            int n=nums.size();
          sort(0,n-1,nums);
          return nums;
        }
    };
int main(){
  Solution mg;
//   int n;
//   cin>>n;
   vector<int> In={5,6,7,1,7,8};
//   for(int i=0;i<n;i++){
//     int el;
//     cin>>el;
//     In.push_back(el);
//   }
  mg.mergeSort(In);
  for(int i=0;i<In.size();i++){
    cout<<In[i]<<" ";
  }

}