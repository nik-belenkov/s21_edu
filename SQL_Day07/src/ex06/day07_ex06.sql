SELECT pz.name, COUNT(po.menu_id) AS count_of_orders,
ROUND(AVG(m.price), 2) AS average_price,
MAX(m.price) AS max_price, MIN(m.price) AS min_price
FROM pizzeria AS pz
JOIN menu AS m
    ON m.pizzeria_id = pz.id
JOIN person_order AS po
    ON po.menu_id = m.id
GROUP BY pz.name
ORDER BY 1;