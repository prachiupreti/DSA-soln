# Write your MySQL query statement below
SELECT x , y , z , 
       CASE
        WHEN x >= y AND x >= z AND y + z > x THEN 'Yes'
        WHEN y >= x AND y >= z AND x + z > y THEN 'Yes'
        WHEN z >= x AND z >= y AND x + y > z THEN 'Yes'
        ELSE 'No'
    END AS triangle
FROM Triangle;