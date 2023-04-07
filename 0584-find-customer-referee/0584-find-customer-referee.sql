# Write your MySQL query statement below
select name from Customer where Customer.referee_id is NULL or Customer.referee_id!=2;