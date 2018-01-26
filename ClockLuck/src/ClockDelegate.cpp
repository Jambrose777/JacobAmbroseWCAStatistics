#include <cstdlib>
#include <iostream>
#include <list>
#include <fstream>
#include <string>

using namespace std;

/*
 * Scramble holds the comp ID and each scramble's luck
 */
struct Scramble{
	string comp = "";
	int all=0, s1=0, s2=0, s3=0, s4=0, s5=0, start=0;
};//ScrambleSet

/*
 * All scrambles that a delegate has ever held
 */
struct Delegate{
	string name = "";
	double avg = 0;
	list<Scramble *> s;
};//Delegate

/*
 * comparison rule for Scrambles
 */
bool comp(const Scramble * s1, const Scramble * s2){
	return s1->all > s2->all;
}//comp

/*
 * comparison rule for delegates
 */
bool comp2(const Delegate * d1, const Delegate * d2){
	return d1->avg > d2 ->avg;
}//comp2

/*
 * find pos after nth s in str
 */
int findnth(const string & str, int pos, const string & s, int nth){
	
	int found_pos = str.find(s, pos);
	if(0 == nth || string::npos == found_pos) return found_pos;
	return findnth(str, found_pos+1, s, nth-1);

}//findnth

/*
 * Calculate luck for a scramble
 */
void calcLuck(int scramNum, string line, Scramble * s){

	//gets scramble from line
	string scram = line.substr(s->start);
	int luck = 0;

	//initial values for all turns (does not include all)
	int ur = (int)scram.at(2) - 48;
	if((int)scram.at(3) == '-') ur = -1*ur + 12;
	int dr = (int)scram.at(7) - 48;
	if((int)scram.at(8) == '-') dr = -1*dr + 12;
	int dl = (int)scram.at(12) - 48;
	if((int)scram.at(13) == '-') dl = -1*dl + 12;
	int ul = (int)scram.at(17) - 48;
	if((int)scram.at(18) == '-') ul = -1*ul + 12;
	int u1 = (int)scram.at(21) - 48;
	if((int)scram.at(22) == '-') u1 = -1*u1 + 12;
	int r1 = (int)scram.at(25) - 48;
	if((int)scram.at(26) == '-') r1 = -1*r1 + 12;
	int d1 = (int)scram.at(29) - 48;
	if((int)scram.at(30) == '-') d1 = -1*d1 + 12;
	int l1 = (int)scram.at(33) - 48;
	if((int)scram.at(34) == '-') l1 = -1*l1 + 12;
	int u2 = (int)scram.at(46) - 48;
	if((int)scram.at(47) == '-') u2 = -1*u2 + 12;
	int r2 = (int)scram.at(50) - 48;
	if((int)scram.at(51) == '-') r2 = -1*r2 + 12;
	int d2 = (int)scram.at(54) - 48;
	if((int)scram.at(55) == '-') d2 = -1*d2 + 12;
	int l2 = (int)scram.at(58) - 48;
	if((int)scram.at(59) == '-') l2 = -1*l2 + 12;
	
	//adds luck for side 2
	if(u2 == 0) luck++;
	else if(u2 == r2) luck++;
	if(r2 == 0) luck++;
	else if (r2 == d2) luck++;
	if(d2 == 0) luck++;
	else if (d2 == l2) luck++;
	if(l2 == 0) luck++;
	else if (l2 == u2) luck++;

	//subs luck of bad cases for side 2
	if(u2 != 0 && u2 == r2 && r2 == d2 && d2 == l2) luck -= 2;
	else if(u2 != 0 && u2 == r2 && r2 == d2) luck--;
	else if(r2 != 0 && r2 == d2 && d2 == l2) luck--;
	else if(d2 != 0 && d2 == l2 && l2 == u2) luck--;
	else if(l2 != 0 && l2 == u2 && u2 == r2) luck--;

	//adds luck for side 1
	if((dr + dl + d1)%12 == 0) luck ++;
	else if((dr + d1)%12 == (ul + l1)%12) luck++;
	if((ul + dl + l1)%12 == 0) luck ++;
	else if((dl + l1)%12 == (ur + u1)%12) luck++;
	if((ur + ul + u1)%12 == 0) luck ++;
	else if((ul + u1)%12 == (dr + r1)%12) luck++;
	if((ur + dr + r1)%12 == 0) luck ++;
	else if((ur + r1)%12 == (dl + d1)%12) luck++;

	//subs luck of bad cases for side 1
	if(((dr + dl + d1)%12 != 0) 
		&& ((ur + ul + u1 + r1 + l1)%12 == (ur + dr + r1 + d1 + u1)%12)
		&& ((ur + dr + r1 + d1 + u1)%12 == (dr + dl + d1 + l1 + r1)%12)
		&& ((dr + dl + d1 + l1 + r1)%12 == (dl + ul + l1 + u1 + d1)%12))
		luck -= 2; 
	else if ((dr + dl + d1)%12 != 0 
		&& ((ur + ul + u1 + r1 + l1)%12 == (ur + dr + r1 + d1 + u1)%12)
		&& ((ur + dr + r1 + d1 + u1)%12 == (dr + dl + d1 + l1 + r1)%12))
		luck--;
	else if ((ul + dl + l1)%12 != 0
		&& ((ur + dr + r1 + d1 + u1)%12 == (dr + dl + d1 + l1 + r1)%12)
		&& ((dr + dl + d1 + l1 + r1)%12 == (dl + ul + l1 + u1 + d1)%12))
		luck--;
	else if ((ur + ul + u1)%12 != 0
		&& ((dr + dl + d1 + l1 + r1)%12 == (dl + ul + l1 + u1 + d1)%12)
		&& ((dl + ul + l1 + u1 + d1)%12 == (ur + ul + u1 + r1 + l1)%12))
		luck--;
	else if ((ur + dr + r1)%12 != 0
		&& ((dl + ul + l1 + u1 + d1)%12 == (ur + ul + u1 + r1 + l1)%12)
		&& ((ur + ul + u1 + r1 + l1)%12 == (ur + dr + r1 + d1 + u1)%12))
		luck--;	

	//increase luck for scramble
	if(scramNum == 1) s->s1 = luck;
	else if(scramNum == 2) s->s2 = luck;
	else if(scramNum == 3) s->s3 = luck;
	else if(scramNum == 4) s->s4 = luck;
	else if(scramNum == 5) s->s5 = luck;
	s->all += luck;

}//calcLuck

int main(int argc, char * argv[]){

	//file specification
	if(argc != 2){
		cout << "Please specify a file to read scrambles from" << endl;
	}//if

	//open file
	ifstream file(argv[1]);

	//creates delegates
	list<Delegate *> delegates;
	string line;
	int scramNum = 1;

	delegates.push_back(new Delegate());

	//read through file
	while(getline(file, line)){
		//creates new Delegate if needed
		if(delegates.back()->name.compare("") == 0)
			delegates.back()->name = 
				line.substr(0, findnth(line, 0, "|", 1) + 1);
		else if(delegates.back()->name.compare(
			line.substr(0, findnth(line, 0, "|", 1) + 1)) != 0){
			for(Scramble * s: delegates.back()->s) 
				delegates.back()->avg += s->all;
			delegates.back()->avg /= (double)delegates.back()->s.size();
			delegates.push_back(new Delegate);
			delegates.back()->name = 
				line.substr(0, findnth(line, 0, "|", 1) + 1);
		}//if else
		Delegate * d = delegates.back();

		//creates scramble if needed
		if(scramNum == 1){
			Scramble * s = new Scramble();
			s->start = findnth(line, 0, "|", 5) + 1;
			s->comp = line.substr(0, s->start);
			d->s.push_back(s);
		}//if
		Scramble * s = d->s.back();
	
		calcLuck(scramNum, line, s);	
		
		//output progress
		if(scramNum == 5){
			scramNum = 1;
			cout << s->comp << " " << s->all << endl;
		} else scramNum ++;
	}//while
	for(Scramble * s: delegates.back()->s) 
		delegates.back()->avg += s->all;
	delegates.back()->avg /= (double)delegates.back()->s.size();

	cout << "Calcing done" << endl;

	//output order and print average by delegate then by scramble
	ofstream save;
	save.open("results/ResultsDelegates.txt");
	
	delegates.sort(comp2);
	for(Delegate * d : delegates){
		save << d->name << " Avg: " << d->avg << endl;
		d->s.sort(comp);
		for(Scramble * s: d->s)
			save << s->comp << s->all << endl;
	}//for

	save.close();
	file.close();

}//main
