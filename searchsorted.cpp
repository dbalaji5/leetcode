#include<iostream>
#include<vector>
using namespace std;
class Solution {

public:
	int binarySearch(vector<int> nums,int t,int start,int end){

		if(start<=end){
			int mid=(start+end)/2;
			if(nums[mid]==t){
				return mid;
			}
			else if(nums[mid]<t){
				return binarySearch(nums,t,mid+1,end);
			}
			else{
				return binarySearch(nums,t,start,mid-1);
			}
		}
		return -1;
	}
	int binarySearchPivot(vector<int> nums,int t,int start,int end){
		if(start<=end){
			int mid=(start+end)/2;
			if(nums[mid]==t){
				return mid;
			}
			if(nums[start]<=nums[mid]){
				if(nums[start]<=t && nums[mid]>t){
					return binarySearchPivot(nums,t,start,mid-1);
				}
				return binarySearchPivot(nums,t,mid+1,end);
			}
			else{
				if(nums[end]>=t && nums[mid]<t){
					return binarySearchPivot(nums,t,mid+1,end);
				}
				return binarySearchPivot(nums,t,start,mid-1);
			}
		}
		return -1;
	}
	int binarySearchPivot2(vector<int> nums,int t,int start,int end){
        if(start<=end){
			int mid=(start+end)/2;
			if(nums[mid]==t){
				return mid;
			}
			else if(nums[mid]>t){
				if(nums[start]>t && nums[mid]>nums[end]){
					return binarySearchPivot2(nums,t,mid+1,end);
				}
				return binarySearchPivot2(nums,t,start,mid-1);
			}
			else{
				if(nums[end]<t && nums[mid]<nums[end]){
					return binarySearchPivot2(nums,t,start,mid-1);
				}
				return binarySearchPivot2(nums,t,mid+1,end);
			}
		}
		return -1;
	}
	int search(vector<int> &nums,int target){
		return binarySearchPivot(nums,target,0,nums.size()-1);
	}

};
int main()
{
	vector<int> in={5,6,7,8,9,1,3};

	Solution s;

	int t;

	cin>>t;

	cout<<s.search(in,t)<<endl;

	return 0;
}

