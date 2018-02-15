~~~sql
SELECT CONCAT('[', personName, '](https://www.worldcubeassociation.org/persons/', personId, ')') person, CONCAT('[', competitionId, '](https://www.worldcubeassociation.org/competitions/', competitionId, ')'), value1, value2, value3, IF(average < 81, average, IF(average = 81, 'N/A', 'DNF')), (value1+value2)/2 AS potential
FROM 
  (SELECT personName, personId, competitionId, value1, value2, value3, IF(average > 0, average, IF(average = 0, 81, 82)) as average
  FROM Results
  ) temp
WHERE eventId = '333fm' AND value1 > 0 AND value2 > 0
ORDER BY potential, average
~~~
