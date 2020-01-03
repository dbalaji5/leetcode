#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	//Version 1
	vector<int> binarySearch(vector<int> nums,int t,int start,int end){

		if(start<=end){
			int mid=(start+end)/2;
			if(nums[mid]==t && mid==start && mid+1<=end){
				int l=mid;
				int r=(nums[mid+1]!=t)?mid:binarySearch(nums,t,mid+1,end)[1];
				return {l,r};
			}
			if(nums[mid]==t && mid-1>=start && mid+1<=end && (nums[mid-1]==t || nums[mid+1]==t)){
				int l=(nums[mid-1]!=t)?mid:binarySearch(nums,t,start,mid-1)[0];
				int r=(nums[mid+1]!=t)?mid:binarySearch(nums,t,mid+1,end)[1];
				return {l,r};
			}
			else if(nums[mid]==t)
			{
				return {mid,mid};
			}
			else if(nums[mid]<t){
				return binarySearch(nums,t,mid+1,end);
			}
			else{
				return binarySearch(nums,t,start,mid-1);
			}
		}
		return {-1,-1};
	}
	//Version 2 Logic
	int binarySearchLeft(vector<int> nums,int t,int start,int end){

		if(start<=end){
			int mid=(start+end)/2;
			if(nums[mid]==t && mid==start && mid+1<=end){
				//int r=(nums[mid+1]!=t)?mid:binarySearch(nums,t,mid+1,end)[1];
				return mid;
			}
			if(nums[mid]==t && mid-1>=start && nums[mid-1]==t){
				//int l=binarySearch(nums,t,start,mid-1);
				//int r=(nums[mid+1]!=t)?mid:binarySearch(nums,t,mid+1,end)[1];
				return binarySearchLeft(nums,t,start,mid-1);
			}
			else if(nums[mid]==t)
			{
				return mid;
			}
			else if(nums[mid]<t){
				return binarySearchLeft(nums,t,mid+1,end);
			}
			else{
				return binarySearchLeft(nums,t,start,mid-1);
			}
		}
		return -1;

	}
	int binarySearchRight(vector<int> nums,int t,int start,int end){

		if(start<=end){
			int mid=(start+end)/2;
			if(nums[mid]==t && mid+1<=end && nums[mid+1]==t){
				//int l=(nums[mid-1]!=t)?mid:binarySearch(nums,t,start,mid-1)[0];
				return binarySearchRight(nums,t,mid+1,end);
			}
			else if(nums[mid]==t)
			{
				return mid;
			}
			else if(nums[mid]<t){
				return binarySearchRight(nums,t,mid+1,end);
			}
			else{
				return binarySearchRight(nums,t,start,mid-1);
			}
		}
		return -1;

	}
    vector<int> searchRange(vector<int>& nums, int target) {
        int l=binarySearchLeft(nums,target,0,nums.size()-1);
        if(l==-1){
        	return {-1,-1};
        }
        int r=binarySearchRight(nums,target,0,nums.size()-1);
        return {l,r};
    }
};
int main()
{
	Solution s;
	vector<int> nums={3,3};
	int t;
	cin>>t;

	vector<int> res=s.searchRange(nums,t);
	cout<<res[0]<<res[1]<<endl;
	return 0;
}