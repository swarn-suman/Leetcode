# Write your MySQL query statement below
SELECT *,
CASE WHEN dna_sequence like 'ATG%' THEN 1 ELSE 0 END AS has_start,
CASE WHEN dna_sequence like '%TAA' OR dna_sequence like '%TAG' OR dna_sequence like '%TGA' THEN 1 ELSE 0 END AS has_stop,
CASE WHEN dna_sequence like '%ATAT%' THEN 1 ELSE 0 END AS has_atat,
CASE WHEN dna_sequence like '%GGG%' THEN 1 ELSE 0 END AS has_ggg
FROM Samples
