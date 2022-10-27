mhj@mhj-IdeaPad:~$ sudo mysql
[sudo] mhj 암호:
Welcome to the MySQL monitor. Commands end with ; or \g.
Your MySQL connection id is 12
Server version: 8.0.30-0ubuntu0.20.04.2 (Ubuntu)

Copyright (c) 2000, 2022, Oracle and/or its affiliates.

Oracle is a registered trademark of Oracle Corporation and/or its
affiliates. Other names may be trademarks of their respective
owners.

Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

mysql> CREATE DATABASE nstagram;
Query OK, 1 row affected (0.03 sec)

mysql> SHOW DATABASES;
+--------------------+
| Database |
+--------------------+
| dbs |
| information_schema |
| mhj |
| mysql |
| nstagram |
| performance_schema |
| sys |
| testdb |
+--------------------+
8 rows in set (0.00 sec)

mysql> CREATE USER 'E1I3'@'localhost' IDENTIFIED BY '0000';
Query OK, 0 rows affected (0.04 sec)

mysql> FLUSH PRIVILEGES;
Query OK, 0 rows affected (0.01 sec)

mysql> GRANT ALL PRIVILEGES ON nstagram.\* to E1I3@localhost;
Query OK, 0 rows affected (0.03 sec)

mysql> FLUSH PRIVILEGES;
Query OK, 0 rows affected (0.02 sec)

mysql> SHOW GRANTS FOR 'E1I3'@'localhost';
+------------------------------------------------------------+
| Grants for E1I3@localhost |
+------------------------------------------------------------+
| GRANT USAGE ON _._ TO `E1I3`@`localhost` |
| GRANT ALL PRIVILEGES ON `nstagram`.\* TO `E1I3`@`localhost` |
+------------------------------------------------------------+
2 rows in set (0.00 sec)

mysql> CREATE DATABASE jsp;
Query OK, 1 row affected (0.03 sec)

mysql> SHOW DATABASES;
+--------------------+
| Database |
+--------------------+
| dbs |
| information_schema |
| jsp |
| mhj |
| mysql |
| nstagram |
| performance_schema |
| sys |
| testdb |
+--------------------+
9 rows in set (0.01 sec)
