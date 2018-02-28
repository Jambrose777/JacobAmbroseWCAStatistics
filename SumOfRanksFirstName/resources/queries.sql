SELECT p.name, p.id, r.eventId, MIN(r.worldRank)
FROM RanksSingle r
INNER JOIN Persons p ON r.personId = p.id
GROUP BY IF(LOCATE(' ',p.name) = 0, p.name, LEFT(p.name, LOCATE(' ',p.name) - 1)), r.eventId
ORDER BY IF(LOCATE(' ',p.name) = 0, p.name, LEFT(p.name, LOCATE(' ',p.name) - 1)), r.eventId
