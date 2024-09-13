SELECT stat_res.name, SUM(stat_res.count) AS total_count FROM

(SELECT pz.name, COUNT(po.menu_id)
FROM pizzeria AS pz
JOIN menu AS m
    ON m.pizzeria_id = pz.id
JOIN person_order AS po
    ON po.menu_id = m.id
GROUP BY pz.name

UNION ALL

SELECT pz.name, COUNT(pv.pizzeria_id)
FROM pizzeria AS pz
JOIN person_visits AS pv
    ON pv.pizzeria_id = pz.id
GROUP BY pz.name) AS stat_res

GROUP BY stat_res.name
ORDER BY 2 DESC, 1 ASC;