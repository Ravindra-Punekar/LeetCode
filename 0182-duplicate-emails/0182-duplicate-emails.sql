# Write your MySQL query statement below
    SELECT email as Email
    FROM Person
    GROUP BY email
    Having COUNT(email)>1;