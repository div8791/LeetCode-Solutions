# Write your MySQL query statement below
SELECT query_name,
ROUND(SUM(rating/position)/COUNT(*),2) as quality, 
ROUND(SUM(CASE WHEN rating < 3 then 1 else 0 end)/count(*)*100,2) as poor_query_percentage FROM Queries
GROUP BY query_name;
