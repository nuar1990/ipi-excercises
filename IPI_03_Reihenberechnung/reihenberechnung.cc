#include <iostream>
using namespace std;


int main(int argc, char *argv[])
{
  double summeTeilA, summeTeilB; // Variablen zum Speichern
  int i=1;                       // Laufvariable
  
  // Fuegen Sie hier Ihren Code fuer Aufgabenteil a ein.

  double summand; //Rechenschritt
  while(1){

	  summand= (1.0/(i*i));

	  //Abbruchbedingung: Für die Reihe gilt Sie bewegt sich zwischen 1 und 2, mit einem cast auf ein integer wird,
	  //der double Wert auf eine 1 gekuerzt(floor!), falls das nicht der Fall ist befindet sich der Wert nicht mehr in der Range
	  //des double.
	  if((int)(summeTeilA+summand)!=1){
		  break;
	  }
	  summeTeilA +=summand	;
	  i++;
  }
  i=1;
  summand=0;
  cout << "Die Summe aus Teil a ergibt:  " << summeTeilA << endl;
  
  // Fuegen Sie hier Ihren Code fuer Aufgabenteil b ein.
  while(1){
	  //i modulo 2 ==0 gerade, i modulo 2 ==1 ungerade
	  if(i%2==0){
		  summand= (1.0/(i*i));
	  }
	  else{
		  summand=-(1.0/(i*i));
	  }
	  //Reihe zwischen ]0, -1]
	  if((int)(summeTeilB+summand)!=0 && (int)(summeTeilB+summand)!=-1){
		  break;
	  }
	  summeTeilB +=summand;
	  i++;
  }
  cout << "Die Summe aus Teil b ergibt:  " << summeTeilB << endl;
  
  return 0;
}

