# Write your MySQL query statement below
select person_name from Queue as a where (select sum(weight) from Queue as b where b.turn<=a.turn)<=1000 order by turn desc limit 1