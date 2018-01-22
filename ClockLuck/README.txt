#ClockLuck

Last Updated 1/22/2018

#Description 
This program takes the results from an sql query on the WCA database to select
all scrambles for clock. Since properties of the clock puzzle can be calculated 
from the scramble, it is possible to quantify the round into luck.  It then 
calculates how many Lucky Cases that scramble has. Finally it adds the luck 
factor per scramble to have a total calulation for the group.

#Definitions
#Lucky Case
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

Cases considered to be Skill Lukcy Cases, these can be forced and depend on the method of solving:
 - a corner skip
 - a 12 o'clock skip

#Results
#Best
|LatvianOpen2016|f|A|1|14
|NacionalesSpeedCubing2017|c|C|1|14
|ClassicCityShhhhh2017|f|B|1|13
|Generalforsamlingen2015|d|B|1|13
|IutopiaOpen2014|f|B|1|13
|MPEIOpen2016|c|A|1|13
|ShanghaiWinter2018|f|A|1|13
#Worst
|ChinaChampionship2017|d|B|1|0
|DvinaOHEdition2014|c|B|1|0
|MiraVe2017|d|B|1|0
|PolishChampionship2016|f|A|1|0
|UrdanetaCity2015|f|A|1|0
#Average
6.0991
