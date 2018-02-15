SELECT CONCAT('[', p.name, '](https://www.worldcubeassociation.org/persons/', r.personId, ')') person, 
     RIGHT(r.competitionId, 4) as year, 
     COUNT(DISTINCT r.competitionId) AS comps 
FROM Results r
INNER JOIN Persons p ON r.personId = p.id
GROUP BY r.personId, RIGHT(r.competitionId, 4)
ORDER BY comps DESC
