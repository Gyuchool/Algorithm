SELECT (PRICE div 10000)*10000 as PRICE_GROUP, COUNT(*) AS PRODUCTS
FROM PRODUCT
GROUP BY PRICE div 10000
ORDER BY PRICE div 10000
