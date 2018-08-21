#include<iostream>
#include<cmath>
using namespace std;
int reverse(int x){
	cout<<x<<endl;
	if(x<-2147483648 | x>2147483647){
	   return 0;
	}
	int count=0;
	int sign=1;
	if(x<0)
	{
	   sign=-1;
	}
	x=abs(x);
    int cx=x;
    while(1){
	   cx=cx/10;
	   count=count+1;
	   if(cx==0) break;
    }
    int sign1[]={8,4,6,3,8,4,7,4,1,2};
    int sign2[]={7,4,6,3,8,4,7,4,1,2};
    //count=sign*count;
    int res=0;
    int flag=1;
    if(count==10){
    	flag=2;
    }
    while(count)
    {
    	int ml=pow(10,count-1);
    	int temp=x%10;
    	if(flag==2)
    	{
    		if(temp<sign2[count-1])
    		{
    			flag=1;
    		}
    		if(temp>sign2[count-1])
    		{
    			flag=0;
    			break;
    		}
    	}
    	res=res+(temp*ml);
    	x=x/10;
    	count=count-1;
    	cout<<ml<<"   "<<x<<"  "<<res<<endl;
    }
    if(flag==0) return 0;
    res=sign*res;
	
	return res;
}
int main()
{
   int input;
   cin>>input;
   cout<<reverse(input)<<endl;
   return 0;

}
