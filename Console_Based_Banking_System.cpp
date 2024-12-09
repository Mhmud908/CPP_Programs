#include<iostream>
#include<math.h>

using namespace std;
int mean(int a, int b, int c)
{
	int am;
	am = (a+b+c)/3;
	return am;
}

int main()
{
	int x,y,z,r;
	cout<<"enter a Number  ";
	cin>>x>>y>>z;
	r = mean(x,y,z);
	cout<<"Arithmetic mean of \'"<<x<<"\' \'"<<y<<"\' \'"<<z<<"\' is "<<endl;
	
	cout<<r;
	
	return 0;
	
}
