# Write your MySQL query statement below
SELECT id, "Root" as type 
FROM Tree
WHERE p_id IS NULL
UNION
SELECT A.id, "Inner" as type 
FROM Tree as A
JOIN Tree as B
ON A.id = B.p_id
WHERE A.p_id is NOT NULL
UNION
SELECT A.id, "Leaf" as type 
FROM Tree as A
LEFT JOIN Tree as B
ON A.id = B.p_id
WHERE B.id is NULL AND A.p_id is NOT NULL; 
