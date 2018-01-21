#include <iostream>
#include <string>
using namespace std;

class Room {
private:
	string name;
	int allowedEntries; //h)
public:
	//h)
	Room (string n) {
		name = n;
		North = this;
		South = this;
		East = this;
		West = this;
		if(n=="Schlafzimmer") allowedEntries=1;
		else{
			allowedEntries=0;
		}
	}

	Room *North, *South, *East, *West;
	//h)
	void increaseEntry(){
		this->allowedEntries++;
	}
	int getEntry()const{
		return allowedEntries;
	}
	//e)+f)
	void position(){
		if(this->name!="Ausgang"){
			cout << "Sie sind im " << this->name << ". Es gibt Wege nach";
			if (this->East!= this) cout << " O";
			if (this->West != this) cout << " W";
			if (this->North != this) cout << " N";
			if (this->South != this) cout << " S";
			cout << ". Wohin? (X:exit)" << endl;
		}
		else{
			cout << "Sie haben die Wohnung verlassen. Glückwunsch Sie haben gewonnen."<<endl;
		}

	}
};

int main() 
{
	//g)
	Room *r1=new Room("Bad");
	Room *r2=new Room("Schlafzimmer");
	Room *r3=new Room("Wohnzimmer");
	Room *r4=new Room("Esszimmer");
	Room *r5=new Room("Flur");
	Room *r6=new Room("Kueche");//d)
	Room *r7=new Room("Ausgang"); //f

	r1->North=r2;	r1->East=r5;
	r2->South=r1;	r2->East=r3;
	r3->West=r2;	r3->South=r5;	r3->East=r4;
	r4->West=r3;	r4->South=r6;									//d)
	r5->West=r1;	r5->North=r3;	r5->East=r6;	r5->South=r7;	//d) + f)
	r6->West=r5;	r6->North=r4;									//d)
	r7->North=r5;													//f)

	Room * here = r2; //c) Start im Schlafzimmer
	bool done = false;
	do {
		here->position();
		//(h)
		if(here->getEntry()<3){
			cout<<"Sie dürfen den Raum noch "<<2-here->getEntry()<<" mal besuchen!"<<endl;
		}
		else{
			cout<<"Sie haben den Raum zum dritten mal betreten. Leider haben sie das Spiel verloren."<<endl;
			done=true;
			break;
		}
		// f)
		if(here==r7) {
			done=true;
			break;
		}
		string in;
		cin >> in;
		switch (toupper(in[0])) {
			case 'N': 	here = here->North;
						here->increaseEntry();
						break;
			case 'S': 	here = here->South;
						here->increaseEntry();
						break;
			case 'O': 	here = here->East;
						here->increaseEntry();
						break;
			case 'W': 	here = here->West;
						here->increaseEntry();
						break;
			default: 	done = true;
						cout << "Tschuess!\n";
						break;
		}
	} while (!done);
}
