#include <iostream>
#include <iomanip>

using namespace std; 

unsigned long fibonacci(unsigned long);
int main( ) {
	for(int counter=0;counter<=10;counter++)
	cout<<setw(10)<<counter<<setw(10)<<fibonacci(counter)<<endl;
	
	cout<<setw(10)<<"100000"<<setw(10)<<fibonacci(100000); 
}

unsigned long fibonacci(unsigned long number)
{
	unsigned long n1=0;
	unsigned long n2=1;
	unsigned long result=number;
	for(unsigned long i=2;i<=number;++i )
	{
		result=n1+n2;
		n1=n2;
		n2=result;
	}
	

	
	return result;
}
