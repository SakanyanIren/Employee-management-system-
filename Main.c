#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

int main() {
    struct Employee* employees = NULL;
    int numEmployees = 0;
    int choice, empID;

    printf("Employee Management System\n");

    if (!authenticateUser()) {
        return 0;
    }
    /**
   * @brief Main function - Entry point of the program.
   *
   * This function loads existing employee data, if available, and provides a menu-driven
   * Employee Management System allowing users to perform various operations like inserting,
   * deleting, updating, searching, sorting employees, and saving to a file.
   *
   * @return Returns 0 upon successful execution.
   */

   // Load existing employee data from file if available
    if (loadFromFile(&employees, &numEmployees, "employee_data.txt")) {
        printf("Employee data loaded successfully.\n");
    }
    else {
        printf("No existing employee data found.\n");
    }

    // Menu-driven loop for Employee Management System operations
    do {
        printf("\n1. Insert New Employee\n");
        printf("2. Delete Employee\n");
        printf("3. Update Employee Details\n");
        printf("4. Search Employee\n");
        printf("5. Sort Employees by ID\n");
        printf("6. Search Employees by Criteria\n");
        printf("7. Save Employee Data to File\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            insertEmployee(employees, &numEmployees);
            break;
        case 2:
            printf("Enter Employee ID to delete: ");
            scanf("%d", &empID);
            deleteEmployee(employees, &numEmployees, empID);
            break;
        case 3:
            printf("Enter Employee ID to update details: ");
            scanf("%d", &empID);
            updateEmployee(employees, numEmployees, empID);
            break;
        case 4:
            printf("Enter Employee ID to search: ");
            scanf("%d", &empID);
            searchEmployeeByID(employees, numEmployees, empID);
            break;
        case 5:
            sortEmployeesByID(employees, numEmployees);
            printf("Employees sorted by ID successfully.\n");
            break;
        case 6:
            searchEmployeesByCriteria(employees, numEmployees);
            break;
        case 7:
            saveToFile(employees, numEmployees, "employee_data.txt");
            break;
        case 8:
            printf("Exiting the program.\n");
            break;
        default:
            printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 8);

    /**
 * @brief Function to free allocated memory for employees array.
 *
 * @param employees Pointer to the array of employees.
 */

    free(employees);

    return 0;
}
