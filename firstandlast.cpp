#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
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
    vector<int> searchRange(vector<int>& nums, int target) {
        return binarySearch(nums,target,0,nums.size()-1);
    }
};
int main()
{
	Solution s;
	vector<int> nums={1};
	int t;
	cin>>t;

	vector<int> res=s.searchRange(nums,t);
	cout<<res[0]<<res[1]<<endl;
	return 0;
}