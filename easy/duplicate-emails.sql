-- Write your PostgreSQL query statement below
SELECT DISTINCT(person.email) FROM person LEFT JOIN person p2 ON person.email = p2.email AND person.id != p2.id WHERE p2.id IS NOT NULL;
