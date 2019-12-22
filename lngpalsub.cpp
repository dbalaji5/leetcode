#include<iostream>
#include<vector>
#include<string>
using namespace std;
string lps(string s){

	int n=s.length();
	vector<int> d1(n), d2(n);
	int max=0;
	int flag=0;
	int iter=0;
	for(int i=0;i<n;i++){

		d1[i]=1;
		while(i-d1[i]>=0 && i+d1[i]<n && s[i-d1[i]]==s[i+d1[i]])
		{
			d1[i]++;
		}
		d2[i]=0;
		while(i-d2[i]-1>=0 && i+d2[i]<n && s[i-d2[i]-1]==s[i+d2[i]]){

			d2[i]++;
		}
		if(d1[i]>1 && d1[i]>=max)
		{
			max=d1[i];
			flag=1;
			iter=i;
		}
		if(d2[i]>0 && d2[i]>=max){
			max=d2[i];
			flag=0;
			iter=i;
		}
	}
	return ((n==1)?s:((max==0)?s.substr(0,1):s.substr((iter-(max-flag)),((2*max)-flag))));
}

int main()
{

	string text;
	cin>>text;
	cout<<lps(text);
	return 0;
}