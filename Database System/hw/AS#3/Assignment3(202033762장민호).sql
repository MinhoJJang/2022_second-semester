# 202033762 장민호 Assignment 3

# 2-1 a. 
SELECT DISTINCT  ID, name 
FROM student s Natural Join takes t  
WHERE dept_name = 'Comp. Sci.';

# 2-1 b.
SELECT ID, name
from student s 
except
select ID, name 
from student s2 natural join takes
WHERE year <= 2017;

# 2-1 c. 
SELECT dept_name, max(salary) 
FROM instructor i 
group by dept_name ;

# 2-1 d.
SELECT min(maxi)
FROM (SELECT dept_name, max(salary) 
	   FROM instructor i 
	   GROUP BY dept_name) as max_salary(dept_name, maxi);


# 2-2
create table person
	(driver_id varchar(50),
	name varchar(50),
	address varchar(50),
	primary key (driver_id));
	
create table car
(license_plate varchar(50),
model varchar(50),
year integer,
primary key (license_plate));

create table accident
(report_number integer,
year integer,
location varchar(50),
primary key (report_number));

create table owns
(driver_id varchar(50),
license_plate varchar(50),
primary key (driver_id,license_plate),
foreign key (driver_id) references person(driver_id),
foreign key (license_plate) references car(license_plate));

create table participated
(report_number integer,
license_plate varchar(50),
driver_id varchar(50),
damage_amount integer,
primary key (report_number, license_plate) ,
foreign key (license_plate) references car(license_plate),
foreign key (report_number) references accident(report_number))	;

# 2-3 a.
select count *
from accident
where exists(
select * from participated, owns, person
where owns.driver_id = person.driver_id 
	and person.name = 'John Smith'
	and owns.license_plate = participated.license_plate
	and accident.report_number = participated.report_number);

select * 
from participated, owns, person
where owns.driver_id = person.driver_id 
	and person.name = "John Smith"
	and owns.license_plate = participated.license_plate
	and accident.report_number = participated.report_number;

# 2-3 b.
update participated 
set damage amount = 3000
where report_number = "AR2197" 
	and license_plate = "AABB2000";

# 2-4 a
select name, m.memb_no 
from member m, book b, borrowed r 
where m.memb_no = r.memb_no
	and r.isbn = b.isbn 
	and b.publisher = "McGrawHill" ;

# 2-4 b
select distinct m.name, m.memb_no 
from member m
where not exists(
	(select isbn
	from book b
	where publisher = "McGrawHill")
	except
	(select isbn 
	from borrowed l
	where l.memb_no = m.memb_no));
	
# 2-4 c
select publisher, name
from (select publisher, name, count(isbn)
	from member m, book b, borrowed l
	where m.memb_no = l.memb_no and l.isbn = b.isbn
	group by publisher, name) as bookSet(publisher, name, bookCount)
where bookCount > 5;

# 2-4 d
with memberCount as
	(select count(*)
	from member)
select count(*)/memberCount
from borrowed;

# 2-5
SELECT dept_name 
FROM department d 
WHERE d.budget > (SELECT budget 
				 FROM department d2
				 WHERE d2.dept_name = "Philosophy")
ORDER BY dept_name ;
				
# 2-6
SELECT course_id, ID
FROM takes t 
group by course_id, ID
HAVING COUNT(course_id) >= 2 and COUNT(ID) >= 2; 
	  
# 2-7					
WITH deptCount(depC, depN) as
	(SELECT count(dept_name), dept_name
	FROM instructor i
	group by dept_name)
SELECT ID, name
FROM deptCount join instructor
ON deptCount.depN = instructor.dept_name
WHERE depC = 1
ORDER BY name ;
								






