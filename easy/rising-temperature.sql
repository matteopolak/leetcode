SELECT t1.id FROM weather t1 INNER JOIN weather t2 ON t1.recordDate = t2.recordDate + INTERVAL '1 DAY' WHERE t1.temperature > t2.temperature;
