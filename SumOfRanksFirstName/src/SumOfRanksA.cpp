#include <cstdlib>
#include <iostream>
#include <list>
#include <fstream>
#include <string>

using namespace std;

int w222;
int w333;
int w333bf;
int w333fm;
int w333ft;
int w333oh;
int w444;
int w555;
int w666;
int w777;
int wclock;
int wminx;
int wpyram;
int wskewb;
int wsq1;

/*
 * Person's details
 */
struct Person{
	string fname = "";
	int e222 = w222;
	string lname222;
	string lid222;
	int e333 = w333;
	string lname333;
	string lid333;
	int e333bf = w333bf;
	string lname333bf;
	string lid333bf;
	int e333fm = w333fm;
	string lname333fm;
	string lid333fm;
	int e333ft = w333ft;
	string lname333ft;
	string lid333ft;
	int e333oh = w333oh;
	string lname333oh;
	string lid333oh;
	int e444 = w444;
	string lname444;
	string lid444;
	int e555 = w555;
	string lname555;
	string lid555;
	int e666 = w666;
	string lname666;
	string lid666;
	int e777 = w777;
	string lname777;
	string lid777;
	int eclock = wclock;
	string lnameclock;
	string lidclock;
	int eminx = wminx;
	string lnameminx;
	string lidminx;
	int epyram = wpyram;
	string lnamepyram;
	string lidpyram;
	int eskewb = wskewb;
	string lnameskewb;
	string lidskewb;
	int esq1 = wsq1;
	string lnamesq1;
	string lidsq1;
	int sor = 0;
};//Person

/*
 * comparison rule for Scrambles
 */
bool comparison(const Person * p1, const Person * p2){
	return p1->sor < p2->sor;
}//comp

/*
 * main
 */
int main(int argc, char * argv[]){

	//file specification
	if(argc != 3){
		cout << "Please specify a file for wrost ranks, then a file for personsRanks" << endl;
		exit(0);
	}//if

	//Set Worst Ranks
	cout << "Importing Worst Ranks" << endl;
	//open Worst Ranks file
	ifstream file(argv[1]);

	string line;

	getline(file, line);
	w222 = stoi(line.substr(5));
	getline(file, line);
	w333 = stoi(line.substr(5));
	getline(file, line);
	w333bf = stoi(line.substr(7));
	getline(file, line);
	w333fm = stoi(line.substr(7));
	getline(file, line);
	w333ft = stoi(line.substr(7));
	getline(file, line);
	w333oh = stoi(line.substr(7));
	getline(file, line);
	w444 = stoi(line.substr(5));
	getline(file, line);
	w555 = stoi(line.substr(5));
	getline(file, line);
	w666 = stoi(line.substr(5));
	getline(file, line);
	w777 = stoi(line.substr(5));
	getline(file, line);
	wclock = stoi(line.substr(7));
	getline(file, line);
	wminx = stoi(line.substr(6));
	getline(file, line);
	wpyram = stoi(line.substr(7));
	getline(file, line);
	wskewb = stoi(line.substr(7));
	getline(file, line);
	wsq1 = stoi(line.substr(5));
	getline(file, line);

	file.close();

	//create each person

	file.open(argv[2]);

	list<Person *> persons; 
	persons.push_back(new Person());

	//inserts data into objects	
	cout << "Importing Data" << endl;
	while(getline(file, line)){
		//parse line
		string name = line.substr(1, line.find("|", 1)-1);
		line = line.substr(line.find("|", 1));
		string id = line.substr(1, line.find("|", 1)-1);
		line = line.substr(line.find("|", 1));
		string event = line.substr(1, line.find("|", 1)-1);
		line = line.substr(line.find("|", 1));
		string rank = line.substr(1, line.find("|", 1)-1);
		string fname, lname;
		//check if no last name
		if(name.find(" ", 0) == -1){
			fname = name;
			lname = "";
		}else{
			fname = name.substr(0, name.find(" ", 0));
			lname = name.substr(name.find(" ", 0) + 1);
		}//if else 
		
		//creates new person if needed
		if(persons.back()->fname.compare("") == 0){
			persons.back()->fname = fname;
		}else if(persons.back()->fname.compare(fname) != 0){
			persons.back()->sor = 
				persons.back()->e222 +
				persons.back()->e333 +
				persons.back()->e444 +
				persons.back()->e555 +
				persons.back()->e666 +
				persons.back()->e777 +
				persons.back()->e333bf +
				persons.back()->e333fm +
				persons.back()->e333oh +
				persons.back()->e333ft +
				persons.back()->eclock +
				persons.back()->eminx +
				persons.back()->epyram +
				persons.back()->eskewb +
				persons.back()->esq1; 
			persons.push_back(new Person);
			persons.back()->fname = fname;
		}//if else
		Person * p = persons.back();

		//adds event rank
		if(event.compare("333")  == 0){
			p->e333 = stoi(rank);
			p->lname333 = lname;
			p->lid333 = id;
		}else if (event.compare("222") == 0){
			p->e222 = stoi(rank);
			p->lname222 = lname;
			p->lid222 = id;
		}else if (event.compare("444") == 0){
			p->e444 = stoi(rank);
			p->lname444 = lname;
			p->lid444 = id;
		}else if (event.compare("555") == 0){
			p->e555 = stoi(rank);
			p->lname555 = lname;
			p->lid555 = id;
		}else if (event.compare("666") == 0){
			p->e666 = stoi(rank);
			p->lname666 = lname;
			p->lid666 = id;
		}else if (event.compare("777") == 0){
			p->e777 = stoi(rank);
			p->lname777 = lname;
			p->lid777 = id;
		}else if (event.compare("333bf") == 0){
			p->e333bf = stoi(rank);
			p->lname333bf = lname;
			p->lid333bf = id;
		}else if (event.compare("333fm") == 0){
			p->e333fm = stoi(rank);
			p->lname333fm = lname;
			p->lid333fm = id;
		}else if (event.compare("333oh") == 0){
			p->e333oh = stoi(rank);
			p->lname333oh = lname;
			p->lid333oh = id;
		}else if (event.compare("333ft") == 0){
			p->e333ft = stoi(rank);
			p->lname333ft = lname;
			p->lid333ft = id;
		}else if (event.compare("clock") == 0){
			p->eclock = stoi(rank);
			p->lnameclock = lname;
			p->lidclock = id;
		}else if (event.compare("minx") == 0){
			p->eminx = stoi(rank);
			p->lnameminx = lname;
			p->lidminx = id;
		}else if (event.compare("pyram") == 0){
			p->epyram = stoi(rank);
			p->lnamepyram = lname;
			p->lidpyram = id;
		}else if (event.compare("skewb") == 0){
			p->eskewb = stoi(rank);
			p->lnameskewb = lname;
			p->lidskewb = id;
		}else if (event.compare("sq1") == 0){
			p->esq1 = stoi(rank);
			p->lnamesq1 = lname;
			p->lidsq1 = id;
		} // if else

	}//while
	persons.back()->sor = 
		persons.back()->e222 +
		persons.back()->e333 +
		persons.back()->e444 +
		persons.back()->e555 +
		persons.back()->e666 +
		persons.back()->e777 +
		persons.back()->e333bf +
		persons.back()->e333fm +
		persons.back()->e333oh +
		persons.back()->e333ft +
		persons.back()->eclock +
		persons.back()->eminx +
		persons.back()->epyram +
		persons.back()->eskewb +
		persons.back()->esq1; 
	
	//sort
	persons.sort(comparison);

	//output to Results.md
	cout << "Exporting data" << endl;
	ofstream save;
	save.open("results/Results.md");
	save << "# **Sum Of Ranks Per Each First Name**" << endl << endl
		<< "|Rank|First Name / sor|333|222|444|555|666|777|333bf|333fm|333oh|333ft|clock|minx|pyram|skewb|sq1|\n|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|" << endl;
	int rank = 0;
	int count = 0;
	Person * prev = new Person();
	for(Person * pp : persons){
		if(prev->sor == pp->sor){
			count++;
		} else {
			rank=rank+count+1;
			count = 0;	
		}//if else
		
		if(rank <= 100)
			save << "|" << rank
				<< "|" << pp->fname
				<< "|[" << pp->lname333 << "](https://worldcubeassociation.org/persons/" << pp->lid333
				<< ")|[" << pp->lname222 << "](https://worldcubeassociation.org/persons/" << pp->lid222
				<< ")|[" << pp->lname444 << "](https://worldcubeassociation.org/persons/" << pp->lid444
				<< ")|[" << pp->lname555 << "](https://worldcubeassociation.org/persons/" << pp->lid555
				<< ")|[" << pp->lname666 << "](https://worldcubeassociation.org/persons/" << pp->lid666
				<< ")|[" << pp->lname777 << "](https://worldcubeassociation.org/persons/" << pp->lid777
				<< ")|[" << pp->lname333bf << "](https://worldcubeassociation.org/persons/" << pp->lid333bf
				<< ")|[" << pp->lname333fm << "](https://worldcubeassociation.org/persons/" << pp->lid333fm
				<< ")|[" << pp->lname333oh << "](https://worldcubeassociation.org/persons/" << pp->lid333oh
				<< ")|[" << pp->lname333ft << "](https://worldcubeassociation.org/persons/" << pp->lid333ft
				<< ")|[" << pp->lnameclock << "](https://worldcubeassociation.org/persons/" << pp->lidclock
				<< ")|[" << pp->lnameminx << "](https://worldcubeassociation.org/persons/" << pp->lidminx
				<< ")|[" << pp->lnamepyram << "](https://worldcubeassociation.org/persons/" << pp->lidpyram
				<< ")|[" << pp->lnameskewb << "](https://worldcubeassociation.org/persons/" << pp->lidskewb
				<< ")|[" << pp->lnamesq1 << "](https://worldcubeassociation.org/persons/" << pp->lidsq1
				<< ")" << endl
				<< "||" << pp->sor 
				<< "|" << pp->e333
				<< "|" << pp->e222
				<< "|" << pp->e444
				<< "|" << pp->e555
				<< "|" << pp->e666
				<< "|" << pp->e777
				<< "|" << pp->e333bf
				<< "|" << pp->e333fm
				<< "|" << pp->e333oh
				<< "|" << pp->e333ft
				<< "|" << pp->eclock
				<< "|" << pp->eminx
				<< "|" << pp->epyram
				<< "|" << pp->eskewb
				<< "|" << pp->esq1
				<< endl;
		prev = pp;
	}//for

	save.close();
	file.close();

}//main
