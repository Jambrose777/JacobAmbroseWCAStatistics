#include <cstdlib>
#include <iostream>
#include <list>
#include <fstream>
#include <string>

using namespace std;

/*
 * Person's details
 */
struct Person{
	string name = "";
	list<Competition *> comps;
	list<int> streaks;
};//Person

/*
 * Competition's details
 */
struct Competition{
	string name = "";
	int Syear = 0;
	int Smonth = 0;
	int Sday = 0;
	int Eyear = 0;
	int Emonth = 0;
	int Eday = 0;
	Boolean hasSuccessor = false;
};//Competition

//TODO
/*
 * comparison rule for Scrambles
 */
bool comp(const Scramble * s1, const Scramble * s2){
	return s1->all > s2->all;
}//comp

//TOOD
/*
 * find pos after nth s in str
 */
int findnth(const string & str, int pos, const string & s, int nth){
	
	int found_pos = str.find(s, pos);
	if(0 == nth || string::npos == found_pos) return found_pos;
	return findnth(str, found_pos+1, s, nth-1);

}//findnth

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

	//read through file
	while(getline(file, line)){
		//creates new Person if needed
		if(persons.back()->name.compare("") == 0)
			persons.back()->name
{
			Scramble * s = new Scramble();
			s->start = findnth(line, 0, "|", 4) + 1;
			s->comp = line.substr(0, s->start);
			ScrambleList.push_back(s);
		}//if
		Scramble * s = ScrambleList.back();
	
		calcLuck(scramNum, line, s);	
		
		//output progress
		if(scramNum == 5){
			scramNum = 1;
			cout << s->comp << " " << s->all << endl;
		} else scramNum ++;
	}//while

	cout << "Calcing done" << endl;

	//output order and print average
	ofstream save;
	save.open("results/Results.md");
	int avg = 0, count = ScrambleList.size();
	ScrambleList.sort(comp);
	save << "# **Clock Luck in a Scramble Set**\n\n|Competition|Round|Group|1|Luck|\n|--------|--------|--------|--------|--------|" << endl;
	for(Scramble * s : ScrambleList){
		avg+=s->all;
		save << s->comp << s->all << "|" << endl;
	}//for

	cout << "Average: " << (avg+0.0)/count << endl;

	save.close();
	file.close();

}//main
