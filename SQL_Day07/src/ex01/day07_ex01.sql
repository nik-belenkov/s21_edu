SELECT person.name, COUNT(person_id) AS count_of_visits
FROM person_visits
JOIN person ON person.id = person_visits.person_id
GROUP BY person.name, person_id
ORDER BY 2 DESC, 1 ASC
LIMIT 4;