SELECT personName, RIGHT(competitionId, 4) as year, COUNT(DISTINCT competitionId) AS comps 
FROM Results 
GROUP BY personName, year
ORDER BY comps DESC Limit 100
