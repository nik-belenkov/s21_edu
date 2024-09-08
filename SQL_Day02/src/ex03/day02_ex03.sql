WITH cte1 AS (
    SELECT missing_date::date FROM
    generate_series('2022-01-01'::date, '2022-01-10'::date, '1 day')
    AS missing_date
)
SELECT missing_date FROM cte1
FULL JOIN (SELECT * FROM person_visits
    WHERE person_id = 1 OR person_id = 2) AS curr
    ON missing_date = curr.visit_date
    WHERE curr.person_id is NULL
ORDER BY missing_date ASC;