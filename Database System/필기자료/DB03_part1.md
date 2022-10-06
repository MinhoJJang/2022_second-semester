# DBO3 part 1

# DDL (Data Definition Language)

## Domain types

```sql
char(n) : fixed length string
varchar(n) : not-fixed length string
int : integer
tinyint: 1byte integer
numeric(p,d) ex_numeric(3,1) 32.4 O / 3.21 X
float(n)
...
```

## DDL commands

```sql
CREATE
DROP
ALTER
TRUNCATE
COMMENT
RENAME
```

## CREATE

```SQL
create table dep (
    dept_name varchar (20),
    building varchar (15),
    budget numeric (12,2),
    primary key (dept_name));

create table ins (
    ID varchar (5),
    name varchar (20) not null,
    dept_name varchar (20),
    salary numeric (8,2),
    primary key (ID),
    foreign key (dept_name)
    references dep (dept_name));
```

primary key -> automatically not null

## ALTER

```sql
SHOW CREATE TABLE ins;
/*
 * CREATE TABLE `ins` (
  `ID` varchar(5) NOT NULL,
  `name` varchar(20) NOT NULL,
  `dept_name` varchar(20) DEFAULT NULL,
  `avgSalary` decimal(8,2) DEFAULT NULL,
  PRIMARY KEY (`ID`),
  KEY `dept_name` (`dept_name`),
  CONSTRAINT `ins_ibfk_1` FOREIGN KEY (`dept_name`) REFERENCES `dep` (`dept_name`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci
 */
 /*
 foreign key = ins_ibfk_1
 fk를 드랍시킬 때에는, SHOW CREATE TABLE ins; 를 통해서 테이블 내 FK의 이름을 보고 그 이름을 드랍해주어야 한다.
 */
ALTER TABLE ins DROP foreign key ins_ibfk_1;

# dept_name을 fk로 지정
ALTER TABLE ins add foreign key (dept_name) references dep(dept_name);

# 칼럼의 이름 바꾸기
ALTER TABLE ins RENAME COLUMN salary TO avgSalary;
ALTER TABLE ins RENAME COLUMN avgSalary TO salary ;

# 칼럼 일부만 드랍시키기
ALTER TABLE ins DROP COLUMN salary, DROP COLUMN name;

# 테이블에 일부 칼럼 추가시키기
ALTER TABLE ins ADD COLUMN salary numeric(8,2), ADD COLUMN name varchar(20) not null;

# 칼럼의 정보 변경하기 (데이터타입, NULL 여부)
# MODIFY, CHANGE 모두 동일한 작업을 한다. MODIFY의 경우, 원래 존재하던 칼럼의 정보만 변경하지만 CHANGE는 칼럼의 이름도 같이 변경해야 한다.
ALTER TABLE ins MODIFY COLUMN name varchar(10) NULL;
ALTER TABLE ins MODIFY COLUMN name varchar(10) NOT NULL;

ALTER TABLE ins CHANGE name na BIGINT NOT NULL;
ALTER TABLE ins CHANGE na name varchar(10) NOT NULL;

desc ins;
```
