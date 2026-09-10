# Write your MySQL query statement below
select E2.employee_id, E2.name, count(E1.employee_id) as reports_count, round(AVG(E1.age)) as average_age
from Employees E1
right join Employees E2 on E2.employee_id = E1.reports_to
group by E2.employee_id, E2.name
having count(E1.employee_id) > 0
order by E2.employee_id;