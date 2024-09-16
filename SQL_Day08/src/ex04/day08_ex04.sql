-- Session 1
BEGIN TRANSACTION ISOLATION LEVEL SERIALIZABLE;

-- Session 2
BEGIN TRANSACTION ISOLATION LEVEL SERIALIZABLE;

-- Session 1
SELECT * FROM pizzeria WHERE name = 'Pizza Hut'; -- 3.6

-- Session 2
UPDATE pizzeria SET rating = 3.0 WHERE name = 'Pizza Hut';
COMMIT;

-- Session 1
SELECT * FROM pizzeria WHERE name = 'Pizza Hut'; -- 3.6
COMMIT;

-- Session 1
SELECT * FROM pizzeria WHERE name = 'Pizza Hut'; -- 3.0

-- Session 2
SELECT * FROM pizzeria WHERE name = 'Pizza Hut'; -- 3.0