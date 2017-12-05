#include <iostream>
using namespace std;


int main(int argc, char *argv[])
{
  int a, b;  // die ganzen Zahlen, deren ggT berechnet werden soll
  int ggt;   // Variable zum Speichern des ggT
  cout<<"a= 123"<<endl;
  cout<<"b= 1968"<<endl;
  a=123;
  b=1968;
  
  // Fuegen Sie hier Ihren Code fuer die Aufgabe ein.
  while(1){
	  if(a==0){
		  ggt=b;
		  break;
	  }
	  else if(b==0){
		  ggt=a;
		  break;
	  }
	  else if(a>b){
		  a=a-b;
	  }
	  else{
		  b=b-a;
	  }
  }
  cout << "Der groesste gemeinsame Teiler ist:  " << ggt << endl;
  
  return 0;
}
