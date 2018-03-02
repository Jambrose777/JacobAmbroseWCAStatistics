#All Single ranks for a first letter
SELECT p.name, p.id, RanksSingle.eventId, RanksSingle.worldRank
FROM RanksSingle
INNER JOIN Persons p ON RanksSingle.personId = p.id
WHERE LEFT(p.name, 1), RanksSingle.eventId, RanksSingle.worldRank) IN (
	SELECT LEFT(p.name, 1), r.eventId, MIN(r.worldRank) as rank
	FROM RanksSingle r
	INNER JOIN Persons p ON r.personId = p.id
	GROUP BY LEFT(p.name, 1), r.eventId
    )
ORDER BY LEFT(p.name, 1), RanksSingle.eventId;

#worst Single rankings
SELECT r.eventId, Max(r.worldRank) + 1
FROM RanksSingle r
GROUP BY r.eventId;

#All Average ranks for a first letter
SELECT p.name, p.id, RanksAverage.eventId, RanksAverage.worldRank
FROM RanksAverage
INNER JOIN Persons p ON RanksAverage.personId = p.id
WHERE LEFT(p.name, 1), RanksAverage.eventId, RanksAverage.worldRank) IN (
	SELECT LEFT(p.name, 1), r.eventId, MIN(r.worldRank) as rank
	FROM RanksAverage r
	INNER JOIN Persons p ON r.personId = p.id
	GROUP BY LEFT(p.name, 1), r.eventId
    )
ORDER BY LEFT(p.name, 1), RanksAverage.eventId;

#worst Average rankings
SELECT r.eventId, Max(r.worldRank) + 1
FROM RanksAverage r
GROUP BY r.eventId;
