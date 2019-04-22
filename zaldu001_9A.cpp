#include <iostream>

#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string> 

using namespace std;

class person {
	
	private:
	
		string name;
		person* mom;
		person* dad;
	
	public:
		
		person(){ //contructor default
			name = "unknown";
			dad= NULL; //intiialize pointers to NULL
			mom= NULL; //initialize pointers to NULL
		}
		
		person(string myname){
			name = myname;
		}
		
		void setName(string myname){
			name= myname;
			if( mom == NULL) {
				mom = new person();
			}
			if( dad == NULL) {
				dad = new person();
			}
			
		}
		
		string getName(){
			return name;
		}
		
		person* retrieveMom() { //get pointer of mom
			//cout << "mom "<< endl;
			return mom;
		}
		
		person* retrieveDad() { //get pointer of dad
			return dad;
		}
		
		~person() { //deconstructor
			cout << "destructing!!";
			delete mom; 
			delete dad;
		}
		

		void printFamily(person * curr){
			cout << "You are currently at: " << name << endl;
			
		}
		
		friend ostream& operator<< (ostream& out, person*x);
};

ostream& operator<< (ostream& out, person*x){
	
	
	out << x -> name << endl;
	
	if(x -> retrieveMom() == NULL) {
		cout << "Your mom is: ??? "<< endl;
	}
	else {
		out << "Your mom is: "<< x ->retrieveMom()->name << endl;
	}
	if(x -> retrieveDad()== NULL) {	
		cout << "Your dad is: ???" << endl;
	}
	else {
		cout << "Your dad is: " << x ->retrieveDad()->name << endl;
	}
	
	return out;
	
}


person * processRequest(char c, person * x, person * y) {
	if( c == 'g') {
		string word;
		cout << "What name (single word)?";
		cin >> word;
		x -> setName(word);
		
	}
	if( c == 'm' ) 
	{
	    
		if( x -> retrieveMom() != NULL) 
		{
		    cout << "here" << endl << endl;
			x = x->retrieveMom();
		}
	}
	if( c == 'd') 
	{
		if( x -> retrieveDad() != NULL) 
		{
			x = x -> retrieveDad();
		}
	}
	if( c == 'b') {
		x = y;
	}
	
	return x;
}

int main() {


	person * start = new person();
	person * curr = start;

	char userRequest;
	
	do {
	cout << "You are currently at: " << curr;
	cout << "Do you want to (g)ive a name, goto the (m)om, goto"; 
	cout << " the (d)ada, (b)ack to starting person, or (q)uit?" << endl;
	cin >> userRequest;
	curr = processRequest(userRequest, curr, start);
	} 
	while(userRequest != 'q');
	
	delete start;
	curr -> ~person();
}

	
