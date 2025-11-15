# Write your MySQL query statement below
SELECT id, visit_date, people
FROM stadium s
WHERE people >= 100
  AND (
        (SELECT COUNT(*) FROM stadium s2
         WHERE s2.people >= 100
           AND s2.id BETWEEN s.id - 2 AND s.id
        ) = 3
        OR
        (SELECT COUNT(*) FROM stadium s2
         WHERE s2.people >= 100
           AND s2.id BETWEEN s.id - 1 AND s.id + 1
        ) = 3
        OR
        (SELECT COUNT(*) FROM stadium s2
         WHERE s2.people >= 100
           AND s2.id BETWEEN s.id AND s.id + 2
        ) = 3
      )
ORDER BY visit_date;
