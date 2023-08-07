# Write your MySQL query statement below
SELECT a.project_id , ROUND(SUM(b.experience_years)/COUNT(b.experience_years),2) as average_years
FROM Project as a
JOIN Employee as b
ON a.employee_id = b.employee_id
GROUP BY project_id;