SELECT  CONCAT('[', personName, '](https://www.worldcubeassociation.org/persons/', personId, ')') person,
	RIGHT(competitionId, 4) AS year,
	COUNT(value1>0 OR null) +
    COUNT(value2>0 OR null) +
    COUNT(value3>0 OR null) +
    COUNT(value4>0 OR null) +
    COUNT(value5>0 OR null) solves,
    COUNT(value1 AND value1<>-2 OR null)+
    COUNT(value2 AND value2<>-2 OR null)+
    COUNT(value3 AND value3<>-2 OR null)+
    COUNT(value4 AND value4<>-2 OR null)+
    COUNT(value5 AND value5<>-2 OR null)attempts
FROM Results
WHERE eventId = '333'
GROUP BY personId, year
ORDER BY solves DESC, attempts LIMIT 10;

SELECT  CONCAT('[', personName, '](https://www.worldcubeassociation.org/persons/', personId, ')') person,
	RIGHT(competitionId, 4) AS year,
	COUNT(value1>0 OR null) +
    COUNT(value2>0 OR null) +
    COUNT(value3>0 OR null) +
    COUNT(value4>0 OR null) +
    COUNT(value5>0 OR null) solves,
    COUNT(value1 AND value1<>-2 OR null)+
    COUNT(value2 AND value2<>-2 OR null)+
    COUNT(value3 AND value3<>-2 OR null)+
    COUNT(value4 AND value4<>-2 OR null)+
    COUNT(value5 AND value5<>-2 OR null)attempts
FROM Results
WHERE eventId = '222'
GROUP BY personId, year
ORDER BY solves DESC, attempts LIMIT 10;

SELECT  CONCAT('[', personName, '](https://www.worldcubeassociation.org/persons/', personId, ')') person,
	RIGHT(competitionId, 4) AS year,
	COUNT(value1>0 OR null) +
    COUNT(value2>0 OR null) +
    COUNT(value3>0 OR null) +
    COUNT(value4>0 OR null) +
    COUNT(value5>0 OR null) solves,
    COUNT(value1 AND value1<>-2 OR null)+
    COUNT(value2 AND value2<>-2 OR null)+
    COUNT(value3 AND value3<>-2 OR null)+
    COUNT(value4 AND value4<>-2 OR null)+
    COUNT(value5 AND value5<>-2 OR null)attempts
FROM Results
WHERE eventId = '444'
GROUP BY personId, year
ORDER BY solves DESC, attempts LIMIT 10;

SELECT  CONCAT('[', personName, '](https://www.worldcubeassociation.org/persons/', personId, ')') person,
	RIGHT(competitionId, 4) AS year,
	COUNT(value1>0 OR null) +
    COUNT(value2>0 OR null) +
    COUNT(value3>0 OR null) +
    COUNT(value4>0 OR null) +
    COUNT(value5>0 OR null) solves,
    COUNT(value1 AND value1<>-2 OR null)+
    COUNT(value2 AND value2<>-2 OR null)+
    COUNT(value3 AND value3<>-2 OR null)+
    COUNT(value4 AND value4<>-2 OR null)+
    COUNT(value5 AND value5<>-2 OR null)attempts
FROM Results
WHERE eventId = '555'
GROUP BY personId, year
ORDER BY solves DESC, attempts LIMIT 10;

SELECT  CONCAT('[', personName, '](https://www.worldcubeassociation.org/persons/', personId, ')') person,
	RIGHT(competitionId, 4) AS year,
	COUNT(value1>0 OR null) +
    COUNT(value2>0 OR null) +
    COUNT(value3>0 OR null) +
    COUNT(value4>0 OR null) +
    COUNT(value5>0 OR null) solves,
    COUNT(value1 AND value1<>-2 OR null)+
    COUNT(value2 AND value2<>-2 OR null)+
    COUNT(value3 AND value3<>-2 OR null)+
    COUNT(value4 AND value4<>-2 OR null)+
    COUNT(value5 AND value5<>-2 OR null)attempts
FROM Results
WHERE eventId = '666'
GROUP BY personId, year
ORDER BY solves DESC, attempts LIMIT 10;

SELECT  CONCAT('[', personName, '](https://www.worldcubeassociation.org/persons/', personId, ')') person,
	RIGHT(competitionId, 4) AS year,
	COUNT(value1>0 OR null) +
    COUNT(value2>0 OR null) +
    COUNT(value3>0 OR null) +
    COUNT(value4>0 OR null) +
    COUNT(value5>0 OR null) solves,
    COUNT(value1 AND value1<>-2 OR null)+
    COUNT(value2 AND value2<>-2 OR null)+
    COUNT(value3 AND value3<>-2 OR null)+
    COUNT(value4 AND value4<>-2 OR null)+
    COUNT(value5 AND value5<>-2 OR null)attempts
FROM Results
WHERE eventId = '777'
GROUP BY personId, year
ORDER BY solves DESC, attempts LIMIT 10;

SELECT  CONCAT('[', personName, '](https://www.worldcubeassociation.org/persons/', personId, ')') person,
	RIGHT(competitionId, 4) AS year,
	COUNT(value1>0 OR null) +
    COUNT(value2>0 OR null) +
    COUNT(value3>0 OR null) +
    COUNT(value4>0 OR null) +
    COUNT(value5>0 OR null) solves,
    COUNT(value1 AND value1<>-2 OR null)+
    COUNT(value2 AND value2<>-2 OR null)+
    COUNT(value3 AND value3<>-2 OR null)+
    COUNT(value4 AND value4<>-2 OR null)+
    COUNT(value5 AND value5<>-2 OR null)attempts
FROM Results
WHERE eventId = '333bf'
GROUP BY personId, year
ORDER BY solves DESC, attempts LIMIT 10;

SELECT  CONCAT('[', personName, '](https://www.worldcubeassociation.org/persons/', personId, ')') person,
	RIGHT(competitionId, 4) AS year,
	COUNT(value1>0 OR null) +
    COUNT(value2>0 OR null) +
    COUNT(value3>0 OR null) +
    COUNT(value4>0 OR null) +
    COUNT(value5>0 OR null) solves,
    COUNT(value1 AND value1<>-2 OR null)+
    COUNT(value2 AND value2<>-2 OR null)+
    COUNT(value3 AND value3<>-2 OR null)+
    COUNT(value4 AND value4<>-2 OR null)+
    COUNT(value5 AND value5<>-2 OR null)attempts
FROM Results
WHERE eventId = '333fm'
GROUP BY personId, year
ORDER BY solves DESC, attempts LIMIT 10;

SELECT  CONCAT('[', personName, '](https://www.worldcubeassociation.org/persons/', personId, ')') person,
	RIGHT(competitionId, 4) AS year,
	COUNT(value1>0 OR null) +
    COUNT(value2>0 OR null) +
    COUNT(value3>0 OR null) +
    COUNT(value4>0 OR null) +
    COUNT(value5>0 OR null) solves,
    COUNT(value1 AND value1<>-2 OR null)+
    COUNT(value2 AND value2<>-2 OR null)+
    COUNT(value3 AND value3<>-2 OR null)+
    COUNT(value4 AND value4<>-2 OR null)+
    COUNT(value5 AND value5<>-2 OR null)attempts
FROM Results
WHERE eventId = '333oh'
GROUP BY personId, year
ORDER BY solves DESC, attempts LIMIT 10;

SELECT  CONCAT('[', personName, '](https://www.worldcubeassociation.org/persons/', personId, ')') person,
	RIGHT(competitionId, 4) AS year,
	COUNT(value1>0 OR null) +
    COUNT(value2>0 OR null) +
    COUNT(value3>0 OR null) +
    COUNT(value4>0 OR null) +
    COUNT(value5>0 OR null) solves,
    COUNT(value1 AND value1<>-2 OR null)+
    COUNT(value2 AND value2<>-2 OR null)+
    COUNT(value3 AND value3<>-2 OR null)+
    COUNT(value4 AND value4<>-2 OR null)+
    COUNT(value5 AND value5<>-2 OR null)attempts
FROM Results
WHERE eventId = '333ft'
GROUP BY personId, year
ORDER BY solves DESC, attempts LIMIT 10;

SELECT  CONCAT('[', personName, '](https://www.worldcubeassociation.org/persons/', personId, ')') person,
	RIGHT(competitionId, 4) AS year,
	COUNT(value1>0 OR null) +
    COUNT(value2>0 OR null) +
    COUNT(value3>0 OR null) +
    COUNT(value4>0 OR null) +
    COUNT(value5>0 OR null) solves,
    COUNT(value1 AND value1<>-2 OR null)+
    COUNT(value2 AND value2<>-2 OR null)+
    COUNT(value3 AND value3<>-2 OR null)+
    COUNT(value4 AND value4<>-2 OR null)+
    COUNT(value5 AND value5<>-2 OR null)attempts
FROM Results
WHERE eventId = 'clock'
GROUP BY personId, year
ORDER BY solves DESC, attempts LIMIT 10;

SELECT  CONCAT('[', personName, '](https://www.worldcubeassociation.org/persons/', personId, ')') person,
	RIGHT(competitionId, 4) AS year,
	COUNT(value1>0 OR null) +
    COUNT(value2>0 OR null) +
    COUNT(value3>0 OR null) +
    COUNT(value4>0 OR null) +
    COUNT(value5>0 OR null) solves,
    COUNT(value1 AND value1<>-2 OR null)+
    COUNT(value2 AND value2<>-2 OR null)+
    COUNT(value3 AND value3<>-2 OR null)+
    COUNT(value4 AND value4<>-2 OR null)+
    COUNT(value5 AND value5<>-2 OR null)attempts
FROM Results
WHERE eventId = 'minx'
GROUP BY personId, year
ORDER BY solves DESC, attempts LIMIT 10;

SELECT  CONCAT('[', personName, '](https://www.worldcubeassociation.org/persons/', personId, ')') person,
	RIGHT(competitionId, 4) AS year,
	COUNT(value1>0 OR null) +
    COUNT(value2>0 OR null) +
    COUNT(value3>0 OR null) +
    COUNT(value4>0 OR null) +
    COUNT(value5>0 OR null) solves,
    COUNT(value1 AND value1<>-2 OR null)+
    COUNT(value2 AND value2<>-2 OR null)+
    COUNT(value3 AND value3<>-2 OR null)+
    COUNT(value4 AND value4<>-2 OR null)+
    COUNT(value5 AND value5<>-2 OR null)attempts
FROM Results
WHERE eventId = 'pyram'
GROUP BY personId, year
ORDER BY solves DESC, attempts LIMIT 10;

SELECT  CONCAT('[', personName, '](https://www.worldcubeassociation.org/persons/', personId, ')') person,
	RIGHT(competitionId, 4) AS year,
	COUNT(value1>0 OR null) +
    COUNT(value2>0 OR null) +
    COUNT(value3>0 OR null) +
    COUNT(value4>0 OR null) +
    COUNT(value5>0 OR null) solves,
    COUNT(value1 AND value1<>-2 OR null)+
    COUNT(value2 AND value2<>-2 OR null)+
    COUNT(value3 AND value3<>-2 OR null)+
    COUNT(value4 AND value4<>-2 OR null)+
    COUNT(value5 AND value5<>-2 OR null)attempts
FROM Results
WHERE eventId = 'skewb'
GROUP BY personId, year
ORDER BY solves DESC, attempts LIMIT 10;

SELECT  CONCAT('[', personName, '](https://www.worldcubeassociation.org/persons/', personId, ')') person,
	RIGHT(competitionId, 4) AS year,
	COUNT(value1>0 OR null) +
    COUNT(value2>0 OR null) +
    COUNT(value3>0 OR null) +
    COUNT(value4>0 OR null) +
    COUNT(value5>0 OR null) solves,
    COUNT(value1 AND value1<>-2 OR null)+
    COUNT(value2 AND value2<>-2 OR null)+
    COUNT(value3 AND value3<>-2 OR null)+
    COUNT(value4 AND value4<>-2 OR null)+
    COUNT(value5 AND value5<>-2 OR null)attempts
FROM Results
WHERE eventId = 'sq1'
GROUP BY personId, year
ORDER BY solves DESC, attempts LIMIT 10;

SELECT  CONCAT('[', personName, '](https://www.worldcubeassociation.org/persons/', personId, ')') person,
	RIGHT(competitionId, 4) AS year,
	COUNT(value1>0 OR null) +
    COUNT(value2>0 OR null) +
    COUNT(value3>0 OR null) +
    COUNT(value4>0 OR null) +
    COUNT(value5>0 OR null) solves,
    COUNT(value1 AND value1<>-2 OR null)+
    COUNT(value2 AND value2<>-2 OR null)+
    COUNT(value3 AND value3<>-2 OR null)+
    COUNT(value4 AND value4<>-2 OR null)+
    COUNT(value5 AND value5<>-2 OR null)attempts
FROM Results
WHERE eventId = '444bf'
GROUP BY personId, year
ORDER BY solves DESC, attempts LIMIT 10;

SELECT  CONCAT('[', personName, '](https://www.worldcubeassociation.org/persons/', personId, ')') person,
	RIGHT(competitionId, 4) AS year,
	COUNT(value1>0 OR null) +
    COUNT(value2>0 OR null) +
    COUNT(value3>0 OR null) +
    COUNT(value4>0 OR null) +
    COUNT(value5>0 OR null) solves,
    COUNT(value1 AND value1<>-2 OR null)+
    COUNT(value2 AND value2<>-2 OR null)+
    COUNT(value3 AND value3<>-2 OR null)+
    COUNT(value4 AND value4<>-2 OR null)+
    COUNT(value5 AND value5<>-2 OR null)attempts
FROM Results
WHERE eventId = '555bf'
GROUP BY personId, year
ORDER BY solves DESC, attempts LIMIT 10;

SELECT  CONCAT('[', personName, '](https://www.worldcubeassociation.org/persons/', personId, ')') person,
	RIGHT(competitionId, 4) AS year,
	COUNT(value1>0 OR null) +
    COUNT(value2>0 OR null) +
    COUNT(value3>0 OR null) +
    COUNT(value4>0 OR null) +
    COUNT(value5>0 OR null) solves,
    COUNT(value1 AND value1<>-2 OR null)+
    COUNT(value2 AND value2<>-2 OR null)+
    COUNT(value3 AND value3<>-2 OR null)+
    COUNT(value4 AND value4<>-2 OR null)+
    COUNT(value5 AND value5<>-2 OR null)attempts
FROM Results
WHERE eventId = '333mbf'
GROUP BY personId, year
ORDER BY solves DESC, attempts LIMIT 10;
