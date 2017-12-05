#include <iostream>
#include <math.h>
using namespace std;

int detWidth(int number);

int main(int argc, char *argv[])
{
	//c+d
	const int N=10;
	int k=detWidth(N);
	//b)-d)
	for(int i=1;i<=N;i++){
		for (int j=1;j<=N;j++){
			cout.width(k+1);
			cout<<i*j;
		}
		cout<<endl;
	}
	cout<<endl<<endl;
	//e)
	for(int i=N;i>0;i--){
		for (int j=1;j<=N;j++){
			cout.width(k+1);
			cout<<i*j;
		}
		cout<<endl;
	}

	return 0;
}
//zu c+d)
int detWidth(int number){
	float check=number;
	int checkSum=0;

	while(check>=0.1){
		check=check/10;
		checkSum++;
	}
	return checkSum;
}

