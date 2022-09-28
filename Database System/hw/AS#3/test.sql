show tables;

desc advisor ;
desc classroom ;
desc course; 
desc department ;
desc instructor ;
desc prereq ;
desc section ;
desc student ;
desc takes ;
desc teaches ;

drop table takes ;
drop table classroom ;
drop table department ;
drop table instructor ;
drop table student ;
drop table course ;
drop table teaches ;
drop table advisor ; 
drop table prereq ;
drop table section ;

# advisor , prereq , teaches 데이터 넣어야함

SELECT * FROM advisor a ;
SELECT *FROM classroom c ;
SELECT *FROM course c ;
SELECT *FROM department d ;
SELECT *FROM instructor i ;
SELECT *FROM prereq p ;
SELECT *FROM `section` s ;
SELECT *FROM student s ;
SELECT *FROM takes t ;
SELECT *FROM teaches t ;









