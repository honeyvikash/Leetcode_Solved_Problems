# Write your MySQL query statement below
select if(id%2=0,id-1,if(id=(select max(id) from Seat),id,id+1)) as id,student from Seat order by id;