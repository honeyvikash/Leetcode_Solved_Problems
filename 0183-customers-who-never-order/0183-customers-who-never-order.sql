# Write your MySQL query statement below

# select c.name from Customers c 
# where not exists (select * from Orders o where o.customerId=c.id);
#upar wala accept hona chahie but usme headers name aara but isko chahie headers me Customers so aisa krna pda alias

select c.Name as Customers from Customers c
where not exists (select * from Orders o where o.customerId=c.id)