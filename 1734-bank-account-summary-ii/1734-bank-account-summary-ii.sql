# Write your MySQL query statement below
SELECT U.name, SUM(amount) as balance
FROM Transactions as T LEFT JOIN Users as U
ON T.account = U.account
GROUP BY T.account
HAVING balance>10000;