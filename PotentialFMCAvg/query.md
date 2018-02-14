~~~sql
SELECT personId, personName, competitionId, value1, value2, value3, average, (value1+value2)/2 AS potential
FROM Results
WHERE eventId = '333fm' AND value1 > 0 AND value2 > 0
ORDER BY potential
~~~
