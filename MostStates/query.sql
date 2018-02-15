SELECT 
     COUNT(*) AS totStates, 
     CONCAT('[', name, '](https://www.worldcubeassociation.org/persons/', s.personId, ')') person, 
     comps,
     GROUP_CONCAT(state) AS listStates
FROM 
    (SELECT CONCAT(SUBSTR(c.cityName, LOCATE(',', c.cityName)+1), ' (', COUNT(*), ')') AS state, r.personId, p.name
 	   FROM 
         (SELECT personId, competitionId
          FROM Results 
          GROUP BY personId, competitionId
         )r
     INNER JOIN Competitions c ON r.competitionId = c.id
     INNER JOIN Persons p ON r.personId = p.id
 	   WHERE c.countryId = 'USA' AND SUBSTR(c.cityName, LOCATE(',', c.cityName)+1) != 'Multiple Cities'
    	GROUP BY SUBSTR(c.cityName, LOCATE(',', c.cityName)+1), r.personId
    )s
INNER JOIN 
    (SELECT personId, COUNT(DISTINCT competitionId) AS comps 
     FROM Results 
     GROUP BY personId
    )t ON s.personId = t.personId
GROUP BY s.personId
ORDER BY totStates DESC, comps
