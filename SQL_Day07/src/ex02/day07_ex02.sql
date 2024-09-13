(SELECT pz.name, COUNT(po.menu_id), 'order' AS action_type
FROM pizzeria AS pz
JOIN menu AS m
    ON m.pizzeria_id = pz.id
JOIN person_order AS po
    ON po.menu_id = m.id
GROUP BY pz.name
ORDER BY 2 DESC
LIMIT 3)

UNION

(SELECT pz.name, COUNT(pv.pizzeria_id), 'visit' AS action_type
FROM pizzeria AS pz
JOIN person_visits AS pv
    ON pv.pizzeria_id = pz.id
GROUP BY pz.name
LIMIT 3)
ORDER BY 3 ASC, 2 DESC;