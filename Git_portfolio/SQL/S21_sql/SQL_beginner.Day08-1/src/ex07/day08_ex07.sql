-- session 1
BEGIN;

-- session 2
BEGIN;

-- session 1
SET TRANSACTION ISOLATION LEVEL REPEATABLE READ;

-- session 2
SET TRANSACTION ISOLATION LEVEL REPEATABLE READ;

-- session 1
UPDATE pizzeria 
SET rating = 4 
WHERE id = 1;

-- session 2
UPDATE pizzeria 
SET rating = 5 
WHERE id = 2;

-- session 1
UPDATE pizzeria 
SET rating = 4 
WHERE id = 2;

-- session 2
UPDATE pizzeria 
SET rating = 4 
WHERE id = 1;

-- session 1
COMMIT;

-- session 2
COMMIT;