
Employee Management System
Overview
This repository contains a simple Employee Management System implemented in C. The system allows users to perform various operations on employee records, including insertion, deletion, updating, searching, sorting, and saving to a file. Additionally, the program incorporates user authentication and registration functionalities.

Features
User Authentication and Registration:

Users are required to authenticate with a username and password.
If authentication fails, users have the option to register a new account.
Employee Operations:

Insert New Employee
Delete Employee by ID
Update Employee Details by ID
Search Employee by ID
Sort Employees by ID
Search Employees by Name or Designation
File I/O:

Load existing employee data from a file on program startup.
Save employee data to a file before program exit

File Descriptions
main.c: Contains the main program logic, user interface, and menu-driven operations.
functions.h: Header file declaring functions used in main.c.
users.txt: File storing registered user accounts (username and password).
employee_data.txt: File storing employee records.
Additional Notes
User authentication is simulated for demonstration purposes and can be replaced with a more robust authentication system.
The program dynamically allocates memory for the array of employees and ensures proper memory management.
