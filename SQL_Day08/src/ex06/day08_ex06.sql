-- Session 1
BEGIN TRANSACTION ISOLATION LEVEL REPEATABLE READ;

-- Session 2
BEGIN TRANSACTION ISOLATION LEVEL REPEATABLE READ;

-- Session 1
SELECT SUM(rating) FROM pizzeria; -- 26.9

-- Session 2
INSERT INTO pizzeria
VALUES(
    11,
    'Kazan Pizza 2',
    4.0
);
COMMIT;

-- Session 1
SELECT SUM(rating) FROM pizzeria; -- 26.9
COMMIT;

-- Session 1
SELECT SUM(rating) FROM pizzeria; -- 30.9

-- Session 2
SELECT SUM(rating) FROM pizzeria; -- 30.9