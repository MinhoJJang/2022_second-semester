# DBO3 part 2

# DML (Data Manipulation Language)

SELECT, INSERT, UPDATE, DELETE

## INSERT

반드시 테이블의 PK값은 넣어야 하고, not null로 설정된 칼럼도 데이터를 반드시 넣어야 한다.

```sql
create table dep (
    dept_name varchar (20),
    building varchar (15),
    budget numeric (12,2),
    primary key (dept_name));

INSERT into dep(dept_name, building) values
('Biology', 'abws');

INSERT into dep(dept_name) values
('avs');

INSERT into dep(dept_name, budget) values
('svs', 1234567890.12);

INSERT into dep(dept_name, budget) values
('svss', 123456790.12);

INSERT into dep(dept_name, budget) values
('svsss', 90.12);

```

## DELETE

```sql
delete from instructor;

delete from instructor
where dept_name= 'Finance';

delete from instructor
where dept_name in (select dept_name
                    from department
                    where building = 'Watson');
```

## UPDATE

update -> set -> where

```sql
UPDATE dep
set budget = budget * 3
where budget < 100;

UPDATE dep
set dept_name = 'svs12332' where dept_name = 'svss';

UPDATE dep
set dept_name = 'svs12332132' where dept_name like 'svs1233%';
```

## SELECT

```sql
중복허용
SELECT dept_name
FROM instructor i;

중복불허
SELECT DISTINCT dept_name
FROM instructor i;

중복삭제금지
SELECT dept_name
FROM instructor i;

SELECT 'bb';
SELECT 'Biology1' as deps;

SELECT ID, name, salary/12 as monthly_salary from instructor i ;
```

## SELECT - PLUS

```sql
select name
from instructor
where dept_name = 'Comp. Sci.' and salary > 80000;

select name from instructor where salary between 90000 and
100000;

select name, course_id
from instructor, teaches
where (instructor.ID, dept_name) = (teaches.ID, 'Biology');

# from instructor, teaches -> Cartesian product == Full Join

select distinct T.name from instructor as T, instructor as S
where T.salary > S.salary and S.dept_name = 'Comp. Sci.';



# String operations

select name from instructor where name like '%d%';

select name from instructor where name like '___d%';

Match the string "100%"
… like '100\%' escape '\';

select length("SQL Tutorial") AS LengthOfString;
select substring("MySql test", 1,5);
select UPPER('louder please');
select lower('AABB');


## order
기본적으로 asc해서 나옴

select distinct name from instructor order by name desc;

## UNION

(select course_id from section where semester  = 'Fall' and year
= 2017)
union
(select course_id from section where semester  = 'Spring' and
year = 2018);

## NULL

select name from instructor where salary is not null;

## aggregate Functions

select avg(salary) from instructor where dept_name = 'Comp. Sci.';

select count(distinct ID) from teaches
where semester = 'Spring' and year = 2018;

select count(*) from course;
-> course 의 전체 튜플 개수

## Group by

select dept_name, avg(salary) as avg_salary
from instructor group by dept_name;

## Having
이미 그룹화된 테이블에서 조건 달기

select dept_name, avg(salary) from instructor
group by dept_name having avg(salary) > 42000;

## NULL & aggregates

select sum(salary) from instructor;
이 경우 NULL값을 무시한다. count(*)를 제외하고 모든 연산은 null을 무시한다.
```
