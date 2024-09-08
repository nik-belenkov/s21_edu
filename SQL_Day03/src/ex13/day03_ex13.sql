DELETE FROM person_order
WHERE menu_id = (SELECT id FROM menu WHERE pizza_name = 'greek pizza');

DELETE FROM menu
WHERE pizza_name = 'greek pizza';