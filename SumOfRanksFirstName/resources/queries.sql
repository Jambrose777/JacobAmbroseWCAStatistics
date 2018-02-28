SELECT p.name, p.id, r.eventId, MIN(r.worldRank)
FROM RanksSingle r
INNER JOIN Persons p ON r.personId = p.id
GROUP BY r.eventId, LEFT(p.name,LOCATE(' ',p.name) - 1)
ORDER BY LEFT(p.name,LOCATE(' ',p.name) - 1), r.eventId
