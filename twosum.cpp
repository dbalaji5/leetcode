#include<stdio.h>
#include<iostream>
#include<vector>
#include<map>
using namespace std;
vector<int> twosum(vector<int>& nums,int target)
{
	vector<int> res;
	map<int,int> dict;
	for(int i=0;i<nums.size();i++)
	{
		cout<<nums[i]<<endl;
		dict[nums[i]]=i;
	}
	for(int i=0;i<nums.size();i++)
	{
	   int temp=target-nums[i];
	   if(dict.count(temp)!=0){
		if(dict[temp]!=i){
			//cout<<i<<"  "<<dict[temp]<<"  "<<endl;
			res.push_back(i);
			res.push_back(dict[temp]);
			break;
		}
	   }
		
	}
	return res;
}
int main()
{
	int l[4]={3,7,11,15};
	vector<int> a;
	a.push_back(3);
	a.push_back(2);
	a.push_back(4);
	//a.push_back(15);
	//cout<<a;
	
	vector<int> result=twosum(a,6);
	for(int j=0;j<result.size();j++)
	{
		cout<<result[j]<<endl;
	}
	//cout<<a.size()<<a[0]<<endl;	
	return 0;
}
