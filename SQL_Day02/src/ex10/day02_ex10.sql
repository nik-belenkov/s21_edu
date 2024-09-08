SELECT person.name AS person_name1,
p2.name AS person_name2,
person.address AS common_address
FROM person
JOIN person p2
    ON person.address = p2.address
    AND p2.id < person.id
ORDER BY 1, 2, 3;