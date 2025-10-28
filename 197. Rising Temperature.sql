SELECT Id
FROM (
    SELECT Id, Temperature,
           LAG(Temperature) OVER (ORDER BY RecordDate) AS prev_temp
    FROM Weather
) AS t
WHERE Temperature > prev_temp;
