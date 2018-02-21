# ConsecutiveWeeksCompeting

Last Computed 2/20/2018

# Description 
This program takes calculates the number of consecutive weeks that a competitor has competed in. A week is defined by Wednesday - Tuesday. A competitor has competed in a week if they attended a competition that starts within the weeks period. Ordering is based off of number of weeks in a row and if that is tied then the number of competitions competed in during those weeks.

 - Name = of competitor
 - NumWeeks = Number of consecutive weeks competed in
 - NumComps = Number of comeptitions competed in during those weeks
 - StartComp = Competition of start of streak
 - EndComp = Competition at end of streak

# Files

 - [results/Results.md](https://github.com/Jambrose777/JacobAmbroseWCAStatistics/blob/master/ConsecutiveWeeksCompeting/results/Results.md)
	Results of ConsecutiveWeeksCompeting.cpp
 - [Makefile](https://github.com/Jambrose777/JacobAmbroseWCAStatistics/blob/master/ConsecutiveWeeksCompeting/Makefile)
	$make
		compiles code
	$make run 
		compiles and runs the all the files
	$make clean
		cleans the code
 - [src/ConsecutiveWeeksCompeting.cpp](https://github.com/Jambrose777/JacobAmbroseWCAStatistics/blob/master/ConsecutiveWeeksCompeting/src/ConsecutiveWeeksCompeting.cpp)
	source code for calculating the number of weeks someone has comepted in.
 - [resources/query.sql](https://github.com/Jambrose777/JacobAmbroseWCAStatistics/blob/master/ConsecutiveWeeksCompeting/resources/query.sql)
	Queries used to obtain the other resources files
 - [resources/data.txt](https://github.com/Jambrose777/JacobAmbroseWCAStatistics/blob/master/ConsecutiveWeeksCompeting/resources/data.txt)
	data extracted from query
 - [bin/* ](https://github.com/Jambrose777/JacobAmbroseWCAStatistics/tree/master/ConsecutiveWeeksCompeting/bin)
	compiled code

