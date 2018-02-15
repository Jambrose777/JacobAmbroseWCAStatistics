SELECT CONCAT('[', p.name, '](https://www.worldcubeassociation.org/persons/', r.personId, ')') person, 
     RIGHT(r.competitionId, 4) as Year, 
     COUNT(DISTINCT r.competitionId) AS comps 
FROM Results r
INNER JOIN Persons p ON r.personId = p.id
GROUP BY r.personId, Year
ORDER BY comps DESC, Year
