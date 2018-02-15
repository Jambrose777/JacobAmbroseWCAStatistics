SELECT COUNT(*) AS numStates, CONCAT('[', personName, '](https://www.worldcubeassociation.org/persons/', personId, ')') person, GROUP_CONCAT(state) AS States
FROM 
(	SELECT SUBSTR(c.cityName, LOCATE(',', c.cityName)+1) AS state, personId, personName
 	FROM Results r
 	INNER JOIN Competitions c ON r.competitionId = c.id
 	WHERE c.countryId = 'USA' 
 	GROUP BY state, personId
) s
WHERE state != 'Multiple Cities'
GROUP BY personId
ORDER BY numStates DESC
