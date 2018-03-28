#Average Records
SELECT eventId, CONCAT('[', personName, '](https://www.worldcubeassociation.org/persons/', personId, ')') person, average, CONCAT('[', name, '](https://www.worldcubeassociation.org/competitions/', competitionId, ')') comp, solves
FROM (
    SELECT r.eventId, personName, personId, average, c.name, competitionId, (numSolves - @dec) AS solves, 	
    	(@dec:= numSolves)
	FROM (SELECT @dec:= 0) dc, Results r
	INNER JOIN Competitions c ON r.competitionId = c.id
	INNER JOIN
   	    (SELECT eventId, start_date, (@runtot:= solves + @runtot) AS numSolves
		 FROM
		   (SELECT eventId, c.start_date, COUNT(value1>0 OR null) +
    		COUNT(value2>0 OR null) +
    		COUNT(value3>0 OR null) +
    		COUNT(value4>0 OR null) +
    		COUNT(value5>0 OR null) solves
		FROM Results r
		INNER JOIN Competitions c ON r.competitionId = c.id
		GROUP BY c.start_date, eventId
		) s, (SELECT @runtot:=0) rn
	) t ON c.start_date = t.start_date AND r.eventId = t.eventId
	WHERE regionalAverageRecord = 'WR'
	ORDER BY eventId, c.start_Date
)p;

#Single Records
SELECT eventId, CONCAT('[', personName, '](https://www.worldcubeassociation.org/persons/', personId, ')') person, average, CONCAT('[', name, '](https://www.worldcubeassociation.org/competitions/', competitionId, ')') comp, solves
FROM (
    SELECT r.eventId, personName, personId, best, c.name, competitionId, (numSolves - @dec) AS solves, 	
    	(@dec:= numSolves)
	FROM (SELECT @dec:= 0) dc, Results r
	INNER JOIN Competitions c ON r.competitionId = c.id
	INNER JOIN
   	    (SELECT eventId, start_date, (@runtot:= solves + @runtot) AS numSolves
		 FROM
		   (SELECT eventId, c.start_date, COUNT(value1>0 OR null) +
    		COUNT(value2>0 OR null) +
    		COUNT(value3>0 OR null) +
    		COUNT(value4>0 OR null) +
    		COUNT(value5>0 OR null) solves
		FROM Results r
		INNER JOIN Competitions c ON r.competitionId = c.id
		GROUP BY c.start_date, eventId
		) s, (SELECT @runtot:=0) rn
	) t ON c.start_date = t.start_date AND r.eventId = t.eventId
	WHERE regionalSingleRecord = 'WR'
	ORDER BY eventId, c.start_Date
)p
LIMIT 1000
