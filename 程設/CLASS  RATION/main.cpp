#include "RationalCLass.h"
#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	RationalClass R4(52,-56);
	cout<<"R4= "<<R4<<endl;
	
	RationalClass R1, R2, R3;
	cout<<"Input three Rational (like -3/4): ";
	cin>>R1>>R2>>R3;
	cout<<"R1= "<<R1<<endl;
	cout<<"R2= "<<R2<<endl;
	cout<<"R3= "<<R3<<endl;
	
	cout<<R1<<" + "<<R2<<" = "<<R1+R2<<endl;
	cout<<R1<<" - "<<R2<<" = "<<R1-R2<<endl;
	cout<<R1<<" * "<<R2<<" = "<<R1*R2<<endl;
	cout<<R1<<" / "<<R2<<" = "<<R1/R2<<endl;
	
	R1+=R2;
	cout<<"R1+=R2 is "<<R1<<endl;
	R1-=R2;
	cout<<"R1-=R2 is "<<R1<<endl;
	R1*=R2;
	cout<<"R1*=R2 is "<<R1<<endl;
	R1/=R2;
	cout<<"R1/=R2 is "<<R1<<endl;
	
	cout<<R1<<" == "<<R2<<" is "
		<<( (R1==R2) ? "true" : "false" )<<endl;
	cout<<R1<<" != "<<R2<<" is "
		<<( (R1!=R2) ? "true" : "false" )<<endl;
	cout<<R1<<" > "<<R2<<" is "
		<<( (R1>R2) ? "true" : "false" )<<endl;
	cout<<R1<<" < "<<R2<<" is "
		<<( (R1<R2) ? "true" : "false" )<<endl;
	cout<<R1<<" >= "<<R2<<" is "
		<<( (R1>=R2) ? "true" : "false" )<<endl;
	cout<<R1<<" <= "<<R2<<" is "
		<<( (R1<=R2) ? "true" : "false" )<<endl;
		
	cout<<R1<<" == "<<R3<<" is "
		<<( (R1==R3) ? "true" : "false" )<<endl;
	cout<<R1<<" != "<<R3<<" is "
		<<( (R1!=R3) ? "true" : "false" )<<endl;
	cout<<R1<<" > "<<R3<<" is "
		<<( (R1>R3) ? "true" : "false" )<<endl;
	cout<<R1<<" < "<<R3<<" is "
		<<( (R1<R3) ? "true" : "false" )<<endl;
	cout<<R1<<" >= "<<R3<<" is "
		<<( (R1>=R3) ? "true" : "false" )<<endl;
	cout<<R1<<" <= "<<R3<<" is "
		<<( (R1<=R3) ? "true" : "false" )<<endl;
	
	system("pause");
	return 0;
}
