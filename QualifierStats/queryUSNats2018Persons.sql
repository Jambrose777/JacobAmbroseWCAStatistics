
SELECT CONCAT("[", personName, "](https://www.worldcubeassociation.org/persons/", personid, ")"), COUNT(*) AS numQualify
  FROM 
   (SELECT competitionId, personId, eventId, countryId, personName, start_date
    FROM
     (SELECT r.competitionId, r.personId, r.eventId, r.countryId, c.start_date, r.personName
      FROM Results r
      INNER JOIN Competitions c ON r.competitionId = c.id
      WHERE r.eventId = '333' AND r.average <= 3000 AND r.average > 0
      UNION
      SELECT r.competitionId, r.personId, r.eventId, r.countryId, c.start_date, r.personName
      FROM Results r
      INNER JOIN Competitions c ON r.competitionId = c.id
      WHERE r.eventId = '222' AND r.average <= 1200 AND r.average > 0
      UNION
      SELECT r.competitionId, r.personId, r.eventId, r.countryId, c.start_date, r.personName
      FROM Results r
      INNER JOIN Competitions c ON r.competitionId = c.id
      WHERE r.eventId = '444' AND r.average <= 70000 AND r.average > 0
      UNION
      SELECT r.competitionId, r.personId, r.eventId, r.countryId, c.start_date, r.personName
      FROM Results r
      INNER JOIN Competitions c ON r.competitionId = c.id
      WHERE r.eventId = '555' AND r.average <= 11000 AND r.average > 0
      UNION
      SELECT r.competitionId, r.personId, r.eventId, r.countryId, c.start_date, r.personName
      FROM Results r
      INNER JOIN Competitions c ON r.competitionId = c.id
      WHERE r.eventId = '666' AND r.average <= 21000 AND r.average > 0
      UNION
      SELECT r.competitionId, r.personId, r.eventId, r.countryId, c.start_date, r.personName
      FROM Results r
      INNER JOIN Competitions c ON r.competitionId = c.id
      WHERE r.eventId = '777' AND r.average <= 28500 AND r.average > 0
      UNION
      SELECT r.competitionId, r.personId, r.eventId, r.countryId, c.start_date, r.personName
      FROM Results r
      INNER JOIN Competitions c ON r.competitionId = c.id
      WHERE r.eventId = '333bf' AND r.best <= 24000 AND r.best > 0
      UNION
      SELECT r.competitionId, r.personId, r.eventId, r.countryId, c.start_date, r.personName
      FROM Results r
      INNER JOIN Competitions c ON r.competitionId = c.id
      WHERE r.eventId = '333fm' AND r.average <= 4500 AND r.average > 0
      UNION
      SELECT r.competitionId, r.personId, r.eventId, r.countryId, c.start_date, r.personName
      FROM Results r
      INNER JOIN Competitions c ON r.competitionId = c.id
      WHERE r.eventId = '333oh' AND r.average <= 3500 AND r.average > 0
      UNION
      SELECT r.competitionId, r.personId, r.eventId, r.countryId, c.start_date, r.personName
      FROM Results r
      INNER JOIN Competitions c ON r.competitionId = c.id
      WHERE r.eventId = '333ft' AND r.average <= 7500 AND r.average > 0
      UNION
      SELECT r.competitionId, r.personId, r.eventId, r.countryId, c.start_date, r.personName
      FROM Results r
      INNER JOIN Competitions c ON r.competitionId = c.id
      WHERE r.eventId = 'clock' AND r.average <= 1500 AND r.average > 0
      UNION
      SELECT r.competitionId, r.personId, r.eventId, r.countryId, c.start_date, r.personName
      FROM Results r
      INNER JOIN Competitions c ON r.competitionId = c.id
      WHERE r.eventId = 'minx' AND r.average <= 10500 AND r.average > 0
      UNION
      SELECT r.competitionId, r.personId, r.eventId, r.countryId, c.start_date, r.personName
      FROM Results r
      INNER JOIN Competitions c ON r.competitionId = c.id
      WHERE r.eventId = 'pyram' AND r.average <= 1200 AND r.average > 0
      UNION
      SELECT r.competitionId, r.personId, r.eventId, r.countryId, c.start_date, r.personName
      FROM Results r
      INNER JOIN Competitions c ON r.competitionId = c.id
      WHERE r.eventId = 'skewb' AND r.average <= 1200 AND r.average > 0
      UNION
      SELECT r.competitionId, r.personId, r.eventId, r.countryId, c.start_date, r.personName
      FROM Results r
      INNER JOIN Competitions c ON r.competitionId = c.id
      WHERE r.eventId = 'sq1' AND r.average <= 3500 AND r.average > 0
      UNION
      SELECT r.competitionId, r.personId, r.eventId, r.countryId, c.start_date, r.personName
      FROM Results r
      INNER JOIN Competitions c ON r.competitionId = c.id
      WHERE r.eventId = '444bf' AND r.best <= 60000 AND r.best > 0
      UNION
      SELECT r.competitionId, r.personId, r.eventId, r.countryId, c.start_date, r.personName
      FROM Results r
      INNER JOIN Competitions c ON r.competitionId = c.id
      WHERE r.eventId = '555bf' AND r.best <= 120000 AND r.best > 0
      UNION
      SELECT r.competitionId, r.personId, r.eventId, r.countryId, c.start_date, r.personName
      FROM Results r
      INNER JOIN Competitions c ON r.competitionId = c.id
      WHERE r.eventId = '333mbf' AND r.best <= '939999999' AND r.best > 0
      ORDER BY start_date
      ) b
    GROUP BY personId, eventId
    ) a
  WHERE countryId = 'USA' AND start_date > '2017-12-22' AND start_date < '2018-06-18'
  GROUP BY personId
  ORDER BY numQualify DESC, personName
