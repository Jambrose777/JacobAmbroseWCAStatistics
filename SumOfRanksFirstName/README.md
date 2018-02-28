# Sum Of Ranks By First Name

Last Computed 2/28/2018

# Description 
This program calculates the sum of ranks by first name for all single and average events.
Example: for Daniel, in each event the rank is taken from the best ranked Daniel and added up to compare to other names. 

 - every result is on 2 rows of the table
 - Rank = ranking in list
 - First Name / sor = First name on the first row, sum of ranks on the second row
 - each event = last name of competitor w/ link to WCA Profile, competitor's World Rank in the event.

# Files

 - [results/ResultsS.md](https://github.com/Jambrose777/JacobAmbroseWCAStatistics/blob/master/SumOfRanksFirstName/results/ResultsS.md)
	Results of Single SORs
   - [results/ResultsA.md](https://github.com/Jambrose777/JacobAmbroseWCAStatistics/blob/master/SumOfRanksFirstName/results/ResultsA.md)
	Results of Average SORs
 - [Makefile](https://github.com/Jambrose777/JacobAmbroseWCAStatistics/blob/master/SumOfRanksFirstName/Makefile)
	$make
		compiles code
	$make run 
		compiles and runs the all the files
	$make clean
		cleans the code
 - [src/SumOfRanksS.cpp](https://github.com/Jambrose777/JacobAmbroseWCAStatistics/blob/master/SumOfRanksFirstName/src/SumOfRanksS.cpp)
	source code for calculating the Single sor per person.
- [src/SumOfRanksA.cpp](https://github.com/Jambrose777/JacobAmbroseWCAStatistics/blob/master/SumOfRanksFirstName/src/SumOfRanksA.cpp)
	source code for calculating the Average sor per person.
 - [resources/queries.sql](https://github.com/Jambrose777/JacobAmbroseWCAStatistics/blob/master/SumOfRanksFirstName/resources/queries.sql)
	Queries used to obtain the other resources files
 - [resources/RanksS.txt](https://github.com/Jambrose777/JacobAmbroseWCAStatistics/blob/master/SumOfRanksFirstName/resources/RanksS.txt)
	data extracted from query 1
- [resources/WorstRanksS.txt](https://github.com/Jambrose777/JacobAmbroseWCAStatistics/blob/master/SumOfRanksFirstName/resources/WorstRanksS.txt)
	data extracted from query 2
- [resources/RanksA.txt](https://github.com/Jambrose777/JacobAmbroseWCAStatistics/blob/master/SumOfRanksFirstName/resources/RanksA.txt)
	data extracted from query 3
- [resources/WorstRanksA.txt](https://github.com/Jambrose777/JacobAmbroseWCAStatistics/blob/master/SumOfRanksFirstName/resources/WorstRanksA.txt)
	data extracted from query 4
 - [bin/* ](https://github.com/Jambrose777/JacobAmbroseWCAStatistics/tree/master/SumOfRanksFirstName/bin)
	compiled code


