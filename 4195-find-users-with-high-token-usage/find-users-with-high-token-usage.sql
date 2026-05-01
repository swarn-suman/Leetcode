# Write your MySQL query statement below
WITH temp AS(
    SELECT *, 
    COUNT(user_id) OVER(PARTITION BY user_id) AS prompt_count,
    ROUND(AVG(tokens) OVER(PARTITION BY user_id),2) AS avg_tokens
    FROM prompts
)

SELECT DISTINCT user_id, prompt_count, avg_tokens
FROM temp
WHERE prompt_count>=3 AND avg_tokens > tokens
ORDER BY avg_tokens DESC, user_id ASC