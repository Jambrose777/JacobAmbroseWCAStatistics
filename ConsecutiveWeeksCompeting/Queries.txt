SELECT r.personId, r.personName, r.competitionId, c.start_date, c.end_date
FROM Results r
INNER JOIN Competitions c ON r.competitionId = c.id
GROUP BY r.personId, r.competitionId
ORDER BY r.personId, c.start_date, c.end_date
