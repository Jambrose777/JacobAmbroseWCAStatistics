
SELECT result, COUNT(*) AS count
FROM 
	(SELECT value1 AS result
     FROM Results
     WHERE eventId = '333fm'
     UNION ALL 
     SELECT value2 AS result
     FROM Results
     WHERE eventId = '333fm'
     UNION ALL
     SELECT value3 AS result
     FROM Results
     WHERE eventId = '333fm'
    ) allSingles
GROUP BY result 
ORDER BY count DESC

