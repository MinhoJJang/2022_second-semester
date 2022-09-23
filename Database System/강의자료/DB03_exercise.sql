show databases;
create database university22;
use university22;
show tables;
desc student;
desc department;
desc instructor;

drop table department;
create table department (
dept_name varchar(10) primary key, 
building varchar(10),
budget int );

create table instructor (
ID int, 
name varchar(20) not null,
dept_name varchar(10),
salary integer,
primary key(ID), 
foreign key(dept_name) references department(dept_name)
);

create table student(
ID int primary key, 
name varchar(10), 
dept_name varchar(10) references department(dept_name), 
tot_cred int );

show tables;
desc department;
desc instructor;
desc student;

alter table instructor add foreign key (dept_name) 
references department(dept_name);
alter table student add foreign key (dept_name) 
references department (dept_name);

create table course (
course_id varchar(10) primary key,
title varchar(50), 
dept_name varchar(10),
credits numeric(2, 1),
foreign key(dept_name) references department(dept_name));

drop table course;
desc instructor;

create table advisor (
s_id int primary key,
i_id int, 
foreign key (s_id) references student(ID),
foreign key (i_id) references instructor(ID)
);

desc advisor;
desc course;
create table prereq(
course_id varchar(10),
prereq_id varchar(10),
primary key (course_id, prereq_id),
foreign key(prereq_id) 
references course(course_id),
foreign key(course_id) 
references course(course_id)
);
desc prereq;

drop table classroom;
create table classroom(
building varchar(10), 
room_no varchar(10),
capacity int, 
primary key(building, room_no));

desc course;
create table section(
course_id varchar(10),
sec_id int, 
semester varchar(20),
year numeric (4,0),
building varchar(10),
room_no varchar(10),
time_slot_id varchar(4),
primary key(course_id, sec_id, semester, year),
foreign key (building, room_no) 
references classroom(building, room_no)
);
drop table section;
desc student;

create table takes(
ID int,
course_id varchar(10),
sec_id int, 
semester varchar(20),
year numeric (4,0),
grade numeric(2,1),
primary key (ID, course_id, sec_id, semester, year),
foreign key(ID) references student (ID),
foreign key (course_id, sec_id, semester, year) 
references section(course_id, sec_id, semester, year)
);
desc instructor;

create table teaches (
ID int,
course_id varchar(10),
sec_id int, 
semester varchar(20),
year numeric (4,0),
primary key(ID, course_id, sec_id, semester, year),
foreign key (ID) references instructor(ID),
foreign key (course_id, sec_id, semester, year) 
references section(course_id, sec_id, semester, year)
);

desc department;

insert into department values
("Comp. Sci", "Taylor", 100000);

insert into department values
('Elec. Eng.', 'Taylor', 85000),
('Finance', 'Painter', 120000),
('History', 'Painter', 50000),
('Music', 'Packard', 80000),
('Physics', 'Watson', 70000);

select * from department;

desc instructor;
insert into instructor values 
(10101, 'Srinivasan', 'Comp. Sci' , 65000);
select * from instructor;
insert into instructor values
(12121, 'Wu', 'Finance', 90000),
(15151, 'Mozart', 'Music', 40000),
(22222, 'Einstein',  'Physics', 95000),
(32343, 'El Said', 'History', 60000),
(33456, 'Gold', 'Physics', 87000),
(45565, 'Katz', 'Comp. Sci', 75000);

desc student;
insert into student values
(00128, 'Zhang', 'Comp. Sci', 102),
(12345, 'Choi', 'Comp. Sci', 32),
(19991, 'Brandt', 'History', 80),
(23121, 'Chavez', 'Finance', 110);
select * from student;

desc course;
insert into course values
('CS-101', 'Database', 'Comp. Sci', 4),
('CS-315', 'Robotics', 'Comp. Sci', 4),
('CS-347', 'Algorithm', 'Comp. Sci', 4),
('FIN-201', 'investment', 'Finance', 4),
('MU-199', 'Music video', 'Music', 4),
('PHY-101', 'Physics principles', 'Physics', 4);
select * from course;
desc classroom;
insert into classroom values
('IT', 412, 200),
('IT', 413, 100),
('IT', 415,500),
('FIN', 100, 500),
('MU', 122, 100),
('PHY', 123, 200);
desc section;
insert into section values
('CS-101', 1, 'Spring', 2021, 'IT', 412, 'E'),
('CS-101', 1, 'Spring', 2020, 'IT', 412, 'E'),
('CS-101', 1, 'Fall', 2021, 'IT', 412, 'E'),
('CS-315', 1, 'Spring', 2021, 'IT', 413, 'A'),
('CS-347', 2, 'Fall', 2021, 'IT', 415, 'B'),
('FIN-201', 1, 'Summer', 2021, 'FIN', 100, 'C'),
('MU-199', 1, 'Spring', 2021, 'MU', 122, 'C'),
('PHY-101', 2, 'Fall', 2020, 'PHY', 123, 'D');

