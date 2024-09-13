SELECT p.name, COUNT(pv.person_id) AS count_of_visits
FROM person AS p
JOIN person_visits AS pv
    ON pv.person_id = p.id
GROUP BY p.name
HAVING COUNT(pv.person_id) > 3;