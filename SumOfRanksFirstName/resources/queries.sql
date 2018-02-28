#All ranks for a first name
SELECT p.name, p.id, r.eventId, r.worldRank
FROM RanksSingle r
INNER JOIN Persons p ON r.personId = p.id
WHERE (IF(LOCATE(' ',p.name) = 0, p.name, LEFT(p.name, LOCATE(' ',p.name) - 1)), r.eventId, r.worldRank) IN (
	SELECT IF(LOCATE(' ',p.name) = 0, p.name, LEFT(p.name, LOCATE(' ',p.name) - 1)), r.eventId, MIN(r.worldRank) as rank
	FROM RanksSingle r
	INNER JOIN Persons p ON r.personId = p.id
WHERE IF(LOCATE(' ',p.name) = 0, p.name, LEFT(p.name, LOCATE(' ',p.name) - 1)) = 'Daniel'
	GROUP BY IF(LOCATE(' ',p.name) = 0, p.name, LEFT(p.name, LOCATE(' ',p.name) - 1)), r.eventId
    )
ORDER BY IF(LOCATE(' ',p.name) = 0, p.name, LEFT(p.name, LOCATE(' ',p.name) - 1)), r.eventId

#worst rankings
SELECT r.eventId, Max(r.worldRank) + 1
FROM RanksSingle r
GROUP BY r.eventId;
