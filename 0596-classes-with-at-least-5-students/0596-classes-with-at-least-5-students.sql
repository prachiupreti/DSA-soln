# Write your MySQL query statement below
SELECT Class
FROM Courses
GROUP BY Class
HAVING COUNT(student)>=5 ;
