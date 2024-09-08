CREATE TABLE nodes(
	id SERIAL PRIMARY KEY,
	point1 VARCHAR(50) NOT NULL,
	point2 VARCHAR(50) NOT NULL,
	cost INTEGER NOT NULL
);

INSERT INTO nodes(point1, point2, cost)
VALUES
('A', 'D', 20),
('D', 'A', 20),
('B', 'D', 25),
('D', 'B', 25),
('C', 'D', 30),
('D', 'C', 30),
('A', 'B', 10),
('B', 'A', 10),
('B', 'C', 35),
('C', 'B', 35),
('A', 'C', 15),
('C', 'A', 15);

CREATE VIEW team00_ex00 AS (
WITH RECURSIVE all_routes AS (
	SELECT n1.id,
	n1.point1,
	n1.point2,
	n1.cost,
	ARRAY [n1.point1, n1.point2]::varchar[] AS tour
	FROM nodes n1
	WHERE n1.point1 = 'A'

	UNION ALL

	SELECT n2.id,
	n2.point1,
	n2.point2,
	all_routes.cost + n2.cost,
	all_routes.tour || n2.point2
	FROM nodes n2
	JOIN all_routes ON all_routes.point2 = n2.point1
	WHERE CASE
		WHEN (array_length(tour, 1) = 4) THEN n2.point2 = 'A'
		ELSE NOT (n2.point2 = ANY (all_routes.tour))
	END
)

	SELECT cost AS total_cost, tour
	FROM all_routes
	WHERE array_length(tour, 1) = (
		SELECT MAX(array_length(tour, 1))
		FROM all_routes
	) AND
		cost = (SELECT MIN(cost) FROM all_routes
			WHERE array_length(tour, 1) = (
				SELECT MAX(array_length(tour, 1))
			FROM all_routes
			)
		)
);

SELECT * FROM team00_ex00
ORDER BY 1, 2;