SELECT m.MEMBER_NAME, r.REVIEW_TEXT, DATE_FORMAT(r.REVIEW_DATE, "%Y-%m-%d") as REVIEW_DATE
FROM MEMBER_PROFILE m
JOIN REST_REVIEW r ON m.MEMBER_ID = r.MEMBER_ID
WHERE m.MEMBER_ID in (SELECT m.MEMBER_ID
FROM MEMBER_PROFILE m
JOIN REST_REVIEW r ON m.MEMBER_ID = r.MEMBER_ID
GROUP BY r.MEMBER_ID
HAVING COUNT(r.MEMBER_ID) = (SELECT MAX(mmm)
                             FROM (SELECT r.MEMBER_ID, COUNT(*) as mmm
                                   FROM MEMBER_PROFILE mm
                                   JOIN REST_REVIEW rr ON mm.MEMBER_ID = rr.MEMBER_ID
                                   GROUP BY rr.MEMBER_ID
                                 ) as t
                            ))
ORDER BY r.REVIEW_DATE asc, r.REVIEW_TEXT asc
