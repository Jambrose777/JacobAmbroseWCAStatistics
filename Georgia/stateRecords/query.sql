SELECT 
    allStateRecords.Event, 
    allStateRecords.Type, 
    allStateRecords.Person, 
    allStateRecords.Time, 
    allStateRecords.Competition, 
    allStateRecords.WR, 
    allStateRecords.CR, 
    allStateRecords.NR
FROM(
    SELECT 
        Events.name AS Event, 
        'Average' AS Type, 
        CONCAT('[', Persons.name, '](https://www.worldcubeassociation.org/persons/', SRAverageHolders.personId, ')') As Person,
        IF (Events.id = '333fm', 
            CAST(SRAverageHolders.stateRecord/100 as decimal(4,2)), 
            IF (SRAverageHolders.stateRecord > 5999, 
                CONCAT(
                    FLOOR(SRAverageHolders.stateRecord/6000), 
                    ':', 
                    CAST((SRAverageHolders.stateRecord%6000)/100 as decimal(4,2))), 
                CAST(SRAverageHolders.stateRecord/100 as decimal(4,2))
        )) AS Time,
        CONCAT('[', Competitions.name, '](https://www.worldcubeassociation.org/competitions/', SRAverageHolders.competitionId, ')') AS Competition, 
        IF(RanksAverage.worldRank <= 100, CONCAT('**', RanksAverage.worldRank, '**'), RanksAverage.worldRank) AS WR,
        IF(RanksAverage.continentRank <= 10, CONCAT('**', RanksAverage.continentRank, '**'), RanksAverage.continentRank) AS CR,
        IF(RanksAverage.countryRank <= 10, CONCAT('**', RanksAverage.countryRank, '**'), RanksAverage.countryRank) AS NR,
        Events.rank,
        Competitions.start_date
    FROM (
        SELECT 
            Results.eventId, 
            Results.personId, 
            SRAverageTimes.stateRecord, 
            Results.competitionId
        FROM Results
        INNER JOIN (
            SELECT 
                MIN(Results.average) AS stateRecord, 
                Results.eventId
            FROM 
                Results
            WHERE 
                Results.average > 0 
                AND Results.personId IN ('2010AMBR01', '2010HULL01', '2014GOSL01', '2014STIN01', '2015DIZO02', '2015JOIN01', '2015SANC11') 
                AND Results.eventId NOT IN ('magic', 'mmagic')
            GROUP BY 
                Results.eventId
        ) SRAverageTimes ON 
            SRAverageTimes.stateRecord = Results.average 
            AND SRAverageTimes.eventId = Results.eventId
        WHERE 
            average > 0 
            AND personId IN ('2010AMBR01', '2010HULL01', '2014GOSL01', '2014STIN01', '2015DIZO02', '2015JOIN01', '2015SANC11') 
    ) SRAverageHolders
    LEFT JOIN RanksAverage ON 
        RanksAverage.personId = SRAverageHolders.personId
        AND RanksAverage.eventId = SRAverageHolders.eventId
    LEFT JOIN Events ON Events.id = SRAverageHolders.eventId
    LEFT JOIN Persons ON Persons.id = SRAverageHolders.personId
    LEFT JOIN Competitions ON Competitions.id = SRAverageHolders.competitionId

    UNION

    SELECT 
        Events.name AS Event, 
        'Single' AS Type, 
        CONCAT('[', Persons.name, '](https://www.worldcubeassociation.org/persons/', SRSingleHolders.personId, ')') As Person,
        IF (Events.id = '333mbf',
            CONCAT(
                99-FLOOR(SRSingleHolders.stateRecord/10000000)+SRSingleHolders.stateRecord%100, 
                '/', 
                99-FLOOR(SRSingleHolders.stateRecord/10000000)+2*SRSingleHolders.stateRecord%100, 
                ' ',
                FLOOR(((SRSingleHolders.stateRecord%10000000)/100)/60), 
                ':', 
                FLOOR(((SRSingleHolders.stateRecord%10000000)/100)%60)),
            IF (Events.id = '333fm', 
                SRSingleHolders.stateRecord, 
                IF (SRSingleHolders.stateRecord > 5999, 
                    CONCAT(
                        FLOOR(SRSingleHolders.stateRecord/6000), 
                        ':', 
                        CAST((SRSingleHolders.stateRecord%6000)/100 as decimal(4,2))), 
                    CAST(SRSingleHolders.stateRecord/100 as decimal(4,2))
        ))) AS Time,
        CONCAT('[', Competitions.name, '](https://www.worldcubeassociation.org/competitions/', SRSingleHolders.competitionId, ')') AS Competition, 
        IF(RanksSingle.worldRank <= 100, CONCAT('**', RanksSingle.worldRank, '**'), RanksSingle.worldRank) AS WR,
        IF(RanksSingle.continentRank <= 10, CONCAT('**', RanksSingle.continentRank, '**'), RanksSingle.continentRank) AS CR,
        IF(RanksSingle.countryRank <= 10, CONCAT('**', RanksSingle.countryRank, '**'), RanksSingle.countryRank) AS NR,
        Events.rank,
        Competitions.start_date
    FROM (
        SELECT 
            Results.eventId, 
            Results.personId, 
            SRSingleTimes.stateRecord, 
            Results.competitionId
        FROM Results
        INNER JOIN (
            SELECT 
                MIN(Results.best) AS stateRecord, 
                Results.eventId
            FROM 
                Results
            WHERE 
                Results.best > 0 
                AND Results.personId IN ('2010AMBR01', '2010HULL01', '2014GOSL01', '2014STIN01', '2015DIZO02', '2015JOIN01', '2015SANC11') 
                AND Results.eventId NOT IN ('magic', 'mmagic', '333mbfo')
            GROUP BY 
                Results.eventId
        ) SRSingleTimes ON 
            SRSingleTimes.stateRecord = Results.best 
            AND SRSingleTimes.eventId = Results.eventId
        WHERE 
            best > 0 
            AND personId IN ('2010AMBR01', '2010HULL01', '2014GOSL01', '2014STIN01', '2015DIZO02', '2015JOIN01', '2015SANC11') 
    ) SRSingleHolders
    LEFT JOIN RanksSingle ON 
        RanksSingle.personId = SRSingleHolders.personId
        AND RanksSingle.eventId = SRSingleHolders.eventId
    LEFT JOIN Events ON Events.id = SRSingleHolders.eventId
    LEFT JOIN Persons ON Persons.id = SRSingleHolders.personId
    LEFT JOIN Competitions ON Competitions.id = SRSingleHolders.competitionId
) allStateRecords
ORDER BY 
    allStateRecords.rank, 
    allStateRecords.Type DESC, 
    allStateRecords.start_date, person