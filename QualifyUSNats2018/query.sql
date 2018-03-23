SELECT competitionId, COUNT(*) AS numQualify
FROM 
 (SELECT competitionId, personId, eventId, countryId
  FROM
   (SELECT competitionId, personId, eventId, Competitions.countryId
    FROM Results
    INNER JOIN Competitions ON Results.competitionId = Competitions.id
    WHERE eventId = '333' AND average <= 3000 AND average > 0
    UNION
    SELECT competitionId, personId, eventId, Competitions.countryId
    FROM Results
    INNER JOIN Competitions ON Results.competitionId = Competitions.id
    WHERE eventId = '222' AND average <= 1200 AND average > 0
    ORDER BY Competitions.start_date
    ) b
  GROUP BY personId, eventId
  ) a
WHERE competitionId LIKE '%2018' AND countryId = 'USA'
GROUP BY competitionId;
