SELECT CONCAT('[', p.personName, '](https://www.worldcubeassociation.org/persons/', r.personId, ')') person, 
     RIGHT(competitionId, 4) as year, 
     COUNT(DISTINCT competitionId) AS comps 
FROM Results r
INNER JOIN Persons p ON r.personId = p.id
GROUP BY r.personId, year
ORDER BY comps DESC
