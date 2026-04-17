# Write your MySQL query statement below
select score ,dense_Rank() over (order by score desc) as `rank` from Scores;