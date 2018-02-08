#include <cstdlib>
#include <iostream>
#include <list>
#include <fstream>
#include <string>

using namespace std;

/*
 * Dates
 */
struct Date{

	int year = 0;
	int month = 0;
	int day = 0;
	int totDays = 0;

	static int month_days[];

	void setTotDays(){
		int leapyears = year / 4;
		if(year % 4 == 0 && month < 3) leapyears--;
		totDays = year*365 + month_days[month-1] + day + leapyears;
	}//setTotDays

};//date
int Date::month_days[] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};

/*
 * Competition's details
 */
struct Competition{
	string name = "";
	Date * start = new Date();
	Date * end = new Date();
	bool hasSuccessor = false;
};//Competition

/*
 * Person's details
 */
struct Person{
	string id = "";
	string name = "";
	list<Competition *> comps;
};//Person

//TODO
/*
 * comparison rule for Scrambles
 */
//bool comp(const Scramble * s1, const Scramble * s2){
//	return s1->all > s2->all;
//}//comp

/*
 * main
 */
int main(int argc, char * argv[]){

	//file specification
	if(argc != 2){
		cout << "Please specify a file to read the data from" << endl;
	}//if

	//open file
	ifstream file(argv[1]);

	list<Person *> persons;
	string line;

	persons.push_back(new Person());

	getline(file, line);
	cout << line << endl;
	
	//inserts data into objects	
	while(getline(file, line)){
		//parse line
		string id = line.substr(1, line.find("|", 1)-1);
		cout << id << endl;	
		line = line.substr(line.find("|", 1));
		string name = line.substr(1, line.find("|", 1)-1);
		cout << name << endl;
		line = line.substr(line.find("|", 1));
		string comp = line.substr(1, line.find("|", 1)-1);
		cout << comp << endl;
		line = line.substr(line.find("|", 1));
		string sdate = line.substr(1, line.find("|", 1)-1);
		cout << sdate << endl;
		string edate = line.substr(line.find("|", 1)+1);
		cout << edate << endl;
	
		//creates new person if needed
		if(persons.back()->id.compare("") == 0){
			persons.back()->id = id;
			persons.back()->name = name;
		}else if(persons.back()->id.compare(id) != 0){
			persons.push_back(new Person);
			persons.back()->id = id;
			persons.back()->name = name;
		}//if else
		Person * p = persons.back();

		p->comps.push_back(new Competition);
		Competition * c = p->comps.back();
		c->name = comp;
		c->start->year = stoi(sdate.substr(0, 4));
		c->start->month = stoi(sdate.substr(5, 2));
		c->start->day = stoi(sdate.substr(8, 2));
		c->start->setTotDays();
		c->end->year = stoi(edate.substr(0, 4));
		c->end->month = stoi(edate.substr(5, 2));
		c->end->day = stoi(edate.substr(8, 2));
		c->end->setTotDays();
		cout << c->start->totDays << endl;
	}//while

	//calculate streaks	
	for(Person * p : persons){
		
	}//for
	
	//save.close();
	file.close();

}//main
