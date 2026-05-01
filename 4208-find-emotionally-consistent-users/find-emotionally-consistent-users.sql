# Write your MySQL query statement below
WITH temp AS(
    SELECT *,
    COUNT(user_id) OVER(PARTITION BY user_id) AS cnt,
    COUNT(user_id) OVER(PARTITION BY user_id,reaction) AS reaction_cnt
    FROM reactions
)

SELECT user_id, 
       reaction AS dominant_reaction,
       ROUND(reaction_cnt/cnt,2) AS reaction_ratio
       FROM (
    SELECT *,
    ROW_NUMBER() OVER(PARTITION BY user_id ORDER BY reaction_cnt DESC) AS rn
    FROM temp
) t
WHERE rn = 1 AND cnt >= 5 AND reaction_cnt * 1.0 / cnt >= 0.6
ORDER BY reaction_ratio DESC, user_id;
