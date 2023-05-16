# Write your MySQL query statement below
SELECT Users.name, SUM(Transactions.amount) AS 'balance' 
FROM Users, Transactions
WHERE Users.account = Transactions.account
GROUP BY Users.name
HAVING SUM(Transactions.amount) > 10000;