-- session - 1
BEGIN;

-- session - 1
UPDATE pizzeria 
SET rating = 5 
WHERE name = 'Pizza Hut';

-- session - 2
SELECT * 
FROM pizzeria 
WHERE name = 'Pizza Hut';

-- session - 2
COMMIT;

-- session - 1
SELECT * 
FROM pizzeria 
WHERE name = 'Pizza Hut';