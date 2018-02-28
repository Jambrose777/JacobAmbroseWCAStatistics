#All ranks for a first name
SELECT p.name, p.id, RanksSingle.eventId, RanksSingle.worldRank
FROM RanksSingle
INNER JOIN Persons p ON RanksSingle.personId = p.id
WHERE (IF(LOCATE(' ',p.name) = 0, p.name, LEFT(p.name, LOCATE(' ',p.name) - 1)), RanksSingle.eventId, RanksSingle.worldRank) IN (
	SELECT IF(LOCATE(' ',p.name) = 0, p.name, LEFT(p.name, LOCATE(' ',p.name) - 1)), r.eventId, MIN(r.worldRank) as rank
	FROM RanksSingle r
	INNER JOIN Persons p ON r.personId = p.id
	GROUP BY IF(LOCATE(' ',p.name) = 0, p.name, LEFT(p.name, LOCATE(' ',p.name) - 1)), r.eventId
    )
ORDER BY IF(LOCATE(' ',p.name) = 0, p.name, LEFT(p.name, LOCATE(' ',p.name) - 1)), RanksSingle.eventId;

#worst rankings
SELECT r.eventId, Max(r.worldRank) + 1
FROM RanksSingle r
GROUP BY r.eventId;
