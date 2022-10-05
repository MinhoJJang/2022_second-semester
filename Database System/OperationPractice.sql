# CREATE, INSERT ====================

CREATE TABLE TableA (
    No int(10) primary key,
    Id varchar(16) NOT NULL,
    Name varchar(16) NOT NULL
);

CREATE TABLE TableB (
    No int(10) primary key,
    Id varchar(16) NOT NULL,
    Name varchar(16) NOT NULL
);

INSERT INTO `TableA` VALUES (1, '100', 'value 100');
INSERT INTO `TableA` VALUES (2, '101', 'value 101');
INSERT INTO `TableA` VALUES (3, '102', 'value 102');
INSERT INTO `TableA` VALUES (4, '103', 'value 103');
INSERT INTO `TableA` VALUES (5, '104', 'value 104');
INSERT INTO `TableA` VALUES (6, '105', 'value 105');
INSERT INTO `TableA` VALUES (7, '106', 'value 106');
INSERT INTO `TableA` VALUES (8, '107', 'value 107');

INSERT INTO `TableB` VALUES (1, '101', 'value 101');
INSERT INTO `TableB` VALUES (2, '103', 'value 103');
INSERT INTO `TableB` VALUES (3, '106', 'value 106');
INSERT INTO `TableB` VALUES (4, '107', 'value 107');
INSERT INTO `TableB` VALUES (5, '110', 'value 110');

SELECT * FROM TableA;
SELECT * FROM TableB;

# Practice! 

# 1. 곱집합. Cartesian Product A * B 
# 기호로 x 이다. A x B 이렇게 쓴다. 
# A, B 요소들을 각각 1개씩, 모두 묶는다. 즉, 총 칼럼의 개수는 A의 총 칼럼 개수 * B의 총 칼럼 개수이다. 

SELECT TableA.Id, TableA.Name, TableB.Id, TableB.Name 
FROM TableA, TableB;

SELECT TableA.Id, TableA.Name, TableB.Id, TableB.Name
FROM TableA INNER JOIN TableB;


# 2. 합집합. Union Operation A U B
# 기호로 U 이다. 

SELECT TableA.Id AS Id, TableA.Name AS Name 
FROM TableA 
UNION 
SELECT TableB.Id AS Id, TableB.Name AS Name 
FROM TableB;


# 3. 교집합. InterSection Operation. U를 뒤집은 모양이다. 

SELECT TableA.Id, TableA.Name, TableB.Name
FROM TableA INNER JOIN TableB
ON TableA.Id = TableB.Id;

## LEFT JOIN : 왼쪽 테이블(TableA)를 기준으로, TableB가 해당 테이블에 매칭되면 value값을 적어주고, 매칭되지 않으면 Null을 적어준다. 반드시 왼쪽 테이블의 칼럼은 모두 적어주므로, 조건이 딱히 없으면 해당 join된 테이블의 칼럼 개수는 A의 칼럼 개수랑 같다. 
SELECT TableA.Id, TableA.Name, TableB.Name 
FROM TableA LEFT JOIN TableB 
ON TableA.Id = TableB.Id
WHERE TableB.Id IS NOT NULL;

SELECT TableA.Id, TableA.Name, TableB.Name 
FROM TableB LEFT JOIN TableA 
ON TableB.Id = TableA.Id
WHERE TableA.Id IS NOT NULL;


# 4. 차집합. Difference Operation. A-B

# LEFT JOIN 을 하고, IS NOT NULL을 걸면 합집합. IS NULL 을 걸면 차집합이다. 
SELECT TableA.Id, TableA.Name, TableB.Id
FROM TableA LEFT JOIN TableB 
ON TableA.Id = TableB.Id;
WHERE TableB.Id IS NULL;

SELECT TableA.Id, TableA.Name 
FROM TableA
WHERE NOT EXISTS (
    SELECT DISTINCT TableB.Id
    FROM TableB
    WHERE TableB.Id = TableA.Id
);

SELECT TableA.Id, TableA.Name 
FROM TableA 
WHERE TableA.Id NOT IN (
    SELECT DISTINCT TableB.Id 
    FROM TableB
); 

# B-A. 위 쿼리에서 테이블명만 서로 바꾸면 반대 차집합이 된다. 
SELECT TableB.Id, TableB.Name
FROM TableB
WHERE NOT EXISTS (
    SELECT DISTINCT TableA.Id 
    FROM TableA
    WHERE TableA.Id = TableB.Id
);


# 5. 대칭 차집합. 둘 중 하나에는 속하지만 둘 다에는 속하지 않는 범위
SELECT Id, Name FROM
(
    SELECT TableA.Id AS Id, TableA.Name AS Name 
    FROM TableA
    UNION ALL 
    SELECT TableB.Id AS Id, TableB.Name AS Name 
    FROM TableB
) AS Tbl
GROUP BY Id, Name
HAVING COUNT(*) = 1;

SELECT TableA.Id AS Id, TableA.Name AS Name 
    FROM TableA
    UNION ALL 
    SELECT TableB.Id AS Id, TableB.Name AS Name 
    FROM TableB;
   
# 6. 자연 조인. Natural Join. 자동으로 두 테이블의 공통접점을 모두 찾고, 그 공통 접점을 데이터로 갖는 다른 데이터들을 뽑아준다. 
   
SELECT * 
FROM TableB Join TableA ;


