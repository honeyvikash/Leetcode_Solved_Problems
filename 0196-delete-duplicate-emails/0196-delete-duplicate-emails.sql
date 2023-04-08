# Please write a DELETE statement and DO NOT write a SELECT statement.
# Write your MySQL query statement below

delete b 
from Person a, Person b
where a.Email = b.Email and b.Id > a.Id