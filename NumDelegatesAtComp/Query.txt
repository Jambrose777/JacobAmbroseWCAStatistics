SELECT competitionId, COUNT(DISTINCT personId) as delegates
FROM Results
WHERE personId IN (SELECT wca_id FROM `users` WHERE delegate_status IS NOT NULL)
GROUP BY CompetitionId
ORDER BY delegates DESC
LIMIT 100
