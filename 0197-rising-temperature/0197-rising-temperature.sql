# Write your MySQL query statement below
SELECT DISTINCT A.id 
FROM Weather A
JOIN Weather B
ON DATEDIFF(A.recordDate, B.recordDate) = 1
   AND A.temperature > B.temperature ;