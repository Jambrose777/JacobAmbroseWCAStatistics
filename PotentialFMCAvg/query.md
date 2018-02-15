~~~sql
SELECT CONCAT('[', personName, '](https://www.worldcubeassociation.org/persons/', personId, ')') person, CONCAT('[', competitionId, '](https://www.worldcubeassociation.org/competitions/', competitionId, ')'), value1, value2, value3, IF(average < 8100, average, IF(average = 8100, 'N/A', 'DNF')), (value1+value2)/2 AS potential
FROM 
  (SELECT personName, personId, competitionId, value1, value2, value3, IF(average > 0, average, IF(average = 0, 8100, 8200)) as average
  FROM Results
  WHERE eventId = '333fm' AND value1 > 0 AND value2 > 0
  ) temp
ORDER BY potential, average
~~~
