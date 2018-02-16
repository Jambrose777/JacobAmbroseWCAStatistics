SELECT CONCAT('[', p.name, '](https://www.worldcubeassociation.org/persons/', r.personId, ')') person, 
     RIGHT(r.competitionId, 4) as InYear, 
     COUNT(DISTINCT r.competitionId) AS comps 
FROM Results r
INNER JOIN 
    (SELECT id, name
     FROM Persons
     WHERE subId = 1
    )p ON r.personId = p.id
GROUP BY r.personId, InYear
ORDER BY comps DESC, InYear
