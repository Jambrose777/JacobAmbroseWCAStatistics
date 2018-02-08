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
	//Date * end = new Date();
	int week = 0;	
};//Competition

/*
 * Person's details
 */
struct Person{
	string id = "";
	string name = "";
	list<Competition *> comps;
};//Person

/*
 * Streak
 */
struct Streak{
	Person * p;
	Competition * begin;
	Competition * end;
	int numComps = 0;
	int numWeeks = 0;
};//Streak

/*
 * comparison rule for Scrambles
 */
bool comparison(const Streak * s1, const Streak * s2){
	if(s1->numWeeks == s2->numWeeks) return s1->numComps > s2->numComps;
	else return s1->numWeeks > s2->numWeeks;
}//comp

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

	//inserts data into objects	
	cout << "Importing Data" << endl;
	while(getline(file, line)){
		//parse line
		string id = line.substr(1, line.find("|", 1)-1);
		//cout << id << endl;	
		line = line.substr(line.find("|", 1));
		string name = line.substr(1, line.find("|", 1)-1);
		//cout << name << endl;
		line = line.substr(line.find("|", 1));
		string comp = line.substr(1, line.find("|", 1)-1);
		//cout << comp << endl;
		line = line.substr(line.find("|", 1));
		string sdate = line.substr(1, line.find("|", 1)-1);
		//cout << sdate << endl;
		//string edate = line.substr(line.find("|", 1)+1);
		//cout << edate << endl;
	
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
		//c->end->year = stoi(edate.substr(0, 4));
		//c->end->month = stoi(edate.substr(5, 2));
		//c->end->day = stoi(edate.substr(8, 2));
		//c->end->setTotDays();
		c->week = (c->start->totDays + 2) / 7;
	}//while

	//calculate streaks	
	cout << "Calculating Streaks" << endl;
	list<Streak *> s;
	Streak * current;
	for(Person * p : persons){
		int week = 0;
		for(Competition * c : p->comps){
			if(c->week == week){
				current->numComps++;
				current->end = c;
			}else if(c->week == week + 1){
				current->numComps++;
				current->end = c;
				current->numWeeks++;
				week++;
			}else{				
				s.push_back(new Streak);
				current = s.back();
				current->p = p;
				week = c->week;
				current->begin = c;
				current->end = c;
				current->numComps++;
				current->numWeeks++;
			}
		}//for
	}//for
	
	//sort
	s.sort(comparison);

	//output to Results.md
	cout << "Exporting data" << endl;
	ofstream save;
	save.open("results/Results.md");
	save << "# **Most Consecutive Weeks Competing**\n\n|Rank|Person|NumWeeks|NumComps|StartComp|EndComp\n|--|--|--|--|--|--|" << endl;
	int rank = 0;
	for(Streak * ss : s){
		if(ss->numWeeks >= 5){
			rank++;
			save << "|" << rank << "|[" << ss->p->name << "](https://www.worldcubeassociation.org/person/" << ss->p->id << ")|" << ss->numWeeks << "|" << ss->numComps << "|" << ss->begin->name << "|" << ss->end->name << endl;
		}//if
	}//for

	save.close();
	file.close();

}//main
