SELECT pizzeria.name FROM pizzeria
JOIN person_visits
    ON pizzeria.id = person_visits.pizzeria_id
JOIN person
    ON person_visits.person_id = person.id
JOIN menu
    ON menu.pizzeria_id = pizzeria.id
    WHERE person_visits.visit_date = '2022-01-08'
    AND person.name = 'Dmitriy' AND menu.price < 800;