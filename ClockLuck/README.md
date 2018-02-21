# ClockLuck

Last Updated 1/29/2018
- TODO Next Update, added competition Names and Links 

# Description 
This program takes the results from an sql query on the WCA database to select
all scrambles for clock. Since properties of the clock puzzle can be calculated 
from the scramble, it is possible to quantify the round into luck.  It then 
calculates how many Lucky Cases that scramble has. Finally it adds the luck 
factor per scramble to have a total calulation for the group.

# Lucky Case Definition
On Clock, A Lucky case is often defined as pieces already being solved relative
to one another. I've separated out cases that are dependent on the scramble vs.
cases that are dependent on skill. Here a Scramble's Lucky Case is defined as:
 + 1 Point if a center is solved to an edge (can happen 4 times per side)
 + 1 Point if 2 adjacent edges are solved (can happen 4 times per side)
 - 1 Point if 2 adjacent edges and a center are solved (overlap)
 - 1 Point if 3 adjacent edges are sovled and a the center is not relative to them
     (overlap, takes same amount of moves as if 2 adjacent edges are solved)
 - 2 Points if 4 adjacent edges are solved and the center is not relative to them
     (overlap, takes 2 moves to solve, not 0) 

Cases considered to be Skill Lucky Cases, these can be forced and depend on the method of solving:
 - a corner skip
 - a 12 o'clock skip

# Result Files
 - [results/Results.md](https://github.com/Jambrose777/JacobAmbroseWCAStatistics/blob/master/ClockLuck/results/Results.md)
	Results of ClockLuck per scramble set
 - [results/ResultsDelegates.md](https://github.com/Jambrose777/JacobAmbroseWCAStatistics/blob/master/ClockLuck/results/ResultsDelegates.md)
	Results of ClockLuck on average for a delegate
 - [results/ResultsSingle.md](https://github.com/Jambrose777/JacobAmbroseWCAStatistics/blob/master/ClockLuck/results/ResultsSingle.md)
	Results of ClockLuck by Single scrambles

# Other Files
 - [Makefile](https://github.com/Jambrose777/JacobAmbroseWCAStatistics/blob/master/ClockLuck/Makefile)
	$make
		compiles code
	$make run 
		compiles and runs the all the files
	$make clean
		cleans the code
 - [src/ClockDelegate.cpp](https://github.com/Jambrose777/JacobAmbroseWCAStatistics/blob/master/ClockLuck/src/ClockDelegate.cpp)
	source code for calculating the scramble luck ordered by who generated them.
 - [src/ClockLuck.cpp](https://github.com/Jambrose777/JacobAmbroseWCAStatistics/blob/master/ClockLuck/src/ClockLuck.cpp)
	inital problem. Calculates the luck for a scramble set and orders them
 - [src/ClockLuckSingle.cpp](https://github.com/Jambrose777/JacobAmbroseWCAStatistics/blob/master/ClockLuck/src/ClockLuckSingle.cpp)
	calculates the clock luck for a single (not scramble set) scramble.
 - [resources/queries.sql](https://github.com/Jambrose777/JacobAmbroseWCAStatistics/blob/master/ClockLuck/resources/Queries.txt)
	Queries used to obtain the other resources files
 - [resources/RanksAverage.txt](https://github.com/Jambrose777/JacobAmbroseWCAStatistics/blob/master/ClockLuck/resources/RanksAverage.txt)
	NOT USED IN PROJECT
 - [resources/all.txt](https://github.com/Jambrose777/JacobAmbroseWCAStatistics/blob/master/ClockLuck/resources/all.txt)
	all scramble sets in the database
 - [resources/competition_delegates.txt](https://github.com/Jambrose777/JacobAmbroseWCAStatistics/blob/master/ClockLuck/resources/competition_delegates.txt)
	all scramble sets in the database preceeded by the delegate
 - [bin/* ](https://github.com/Jambrose777/JacobAmbroseWCAStatistics/tree/master/ClockLuck/bin)
	compiled code

