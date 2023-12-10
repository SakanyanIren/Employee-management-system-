#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Structure representing an Employee.
 */
struct Employee {
    char name[50];          /**< Name of the employee */
    int employeeID;         /**< Employee ID */
    char designation[50];   /**< Designation of the employee */
    int experience;         /**< Experience in years */
    int age;                /**< Age of the employee */
};

/**
 * @brief Function to insert a new employee entry.
 *
 * @param employees Pointer to the array of employees.
 * @param numEmployees Pointer to the number of employees.
 */
void insertEmployee(struct Employee* employees, int* numEmployees)
// Implementation of insertEmployee function
{
    printf("\nEnter employee details:\n");
    printf("Name: ");
    scanf("%s", employees[*numEmployees].name);
    printf("Employee ID: ");
    scanf("%d", &employees[*numEmployees].employeeID);
    printf("Designation: ");
    scanf("%s", employees[*numEmployees].designation);
    printf("Experience: ");
    scanf("%d", &employees[*numEmployees].experience);
    printf("Age: ");
    scanf("%d", &employees[*numEmployees].age);

    (*numEmployees)++;
    printf("Employee added successfully!\n");
}

/**
 * @brief Function to delete an employee entry by ID.
 *
 * @param employees Pointer to the array of employees.
 * @param numEmployees Pointer to the number of employees.
 * @param empID ID of the employee to be deleted.
 */
void deleteEmployee(struct Employee* employees, int* numEmployees, int empID)
// Implementation of deleteEmployee function
{
    int i, found = 0;
    for (i = 0; i < *numEmployees; i++) {
        if (employees[i].employeeID == empID) {
            found = 1;
            // Remove the entry by shifting elements
            for (int j = i; j < *numEmployees - 1; j++) {
                employees[j] = employees[j + 1];
            }
            (*numEmployees)--;
            printf("Employee deleted successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Employee not found!\n");
    }
}

/**
 * @brief Function to search for an employee record by ID.
 *
 * @param employees Pointer to the array of employees.
 * @param numEmployees The number of employees.
 * @param empID ID of the employee to search for.
 */
void searchEmployeeByID(struct Employee* employees, int numEmployees, int empID)
// Implementation of searchEmployeeByID function
{
    int i, found = 0;
    for (i = 0; i < numEmployees; i++) {
        if (employees[i].employeeID == empID) {
            found = 1;
            printf("\nEmployee Details:\n");
            printf("Name: %s\n", employees[i].name);
            printf("Employee ID: %d\n", employees[i].employeeID);
            printf("Designation: %s\n", employees[i].designation);
            printf("Experience: %d years\n", employees[i].experience);
            printf("Age: %d\n", employees[i].age);
            break;
        }
    }

    if (!found) {
        printf("Employee not found!\n");
    }
}

/**
 * @brief Function to update employee details by ID.
 *
 * @param employees Pointer to the array of employees.
 * @param numEmployees The number of employees.
 * @param empID ID of the employee to update.
 */
void updateEmployee(struct Employee* employees, int numEmployees, int empID)
// Implementation of updateEmployee function
{
    int i, found = 0;
    for (i = 0; i < numEmployees; i++) {
        if (employees[i].employeeID == empID) {
            found = 1;
            printf("Enter updated employee details:\n");
            printf("Name: ");
            scanf("%s", employees[i].name);
            printf("Designation: ");
            scanf("%s", employees[i].designation);
            printf("Experience: ");
            scanf("%d", &employees[i].experience);
            printf("Age: ");
            scanf("%d", &employees[i].age);
            printf("Employee details updated successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Employee not found!\n");
    }
}

/**
 * @brief Function to save employee data to a file.
 *
 * @param employees Pointer to the array of employees.
 * @param numEmployees The number of employees.
 * @param filename The name of the file to save data.
 */
void saveToFile(struct Employee* employees, int numEmployees, const char* filename)
// Implementation of saveToFile function
{
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Unable to create/open the file.\n");
        return;
    }

    for (int i = 0; i < numEmployees; i++) {
        fprintf(file, "%s %d %s %d %d\n", employees[i].name, employees[i].employeeID,
            employees[i].designation, employees[i].experience, employees[i].age);
    }

    fclose(file);
    printf("Employee data saved to file '%s' successfully.\n", filename);
}

/**
 * @brief Function to load employee data from a file.
 *
 * @param employees Pointer to the array of employees.
 * @param numEmployees Pointer to the number of employees.
 * @param filename The name of the file to load data.
 * @return Returns 1 if successful, otherwise 0.
 */
int loadFromFile(struct Employee** employees, int* numEmployees, const char* filename)
// Implementation of loadFromFile function
{
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Unable to open the file.\n");
        return 0;
    }

    *employees = (struct Employee*)malloc(sizeof(struct Employee));
    if (*employees == NULL) {
        fclose(file);
        printf("Memory allocation failed.\n");
        return 0;
    }

    while (fscanf(file, "%s %d %s %d %d", (*employees)[*numEmployees].name, &(*employees)[*numEmployees].employeeID,
        (*employees)[*numEmployees].designation, &(*employees)[*numEmployees].experience, &(*employees)[*numEmployees].age) != EOF) {
        (*numEmployees)++;
        *employees = (struct Employee*)realloc(*employees, (*numEmployees + 1) * sizeof(struct Employee));
        if (*employees == NULL) {
            fclose(file);
            printf("Memory reallocation failed.\n");
            return 0;
        }
    }

    fclose(file);
    return 1;
}

/**
 * @brief Function to sort employees by employee ID (ascending order).
 *
 * @param employees Pointer to the array of employees.
 * @param numEmployees The number of employees.
 */
void sortEmployeesByID(struct Employee* employees, int numEmployees)
// Implementation of sortEmployeesByID function
{
    struct Employee temp;
    for (int i = 0; i < numEmployees - 1; i++) {
        for (int j = 0; j < numEmployees - i - 1; j++) {
            if (employees[j].employeeID > employees[j + 1].employeeID) {
                temp = employees[j];
                employees[j] = employees[j + 1];
                employees[j + 1] = temp;
            }
        }
    }
}

/**
 * @brief Function to search employees by multiple criteria (e.g., name, designation).
 *
 * @param employees Pointer to the array of employees.
 * @param numEmployees The number of employees.
 */
void searchEmployeesByCriteria(struct Employee* employees, int numEmployees)
// Implementation of searchEmployeesByCriteria function
{
    int choice;
    printf("1. Search by Name\n");
    printf("2. Search by Designation\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1: {
        char searchName[50];
        printf("Enter Name to search: ");
        scanf("%s", searchName);
        printf("\nEmployees with Name '%s':\n", searchName);
        int found = 0;
        for (int i = 0; i < numEmployees; i++) {
            if (strcmp(employees[i].name, searchName) == 0) {
                printf("Employee ID: %d, Name: %s, Designation: %s, Experience: %d, Age: %d\n", employees[i].employeeID,
                    employees[i].name, employees[i].designation, employees[i].experience, employees[i].age);
                found = 1;
            }
        }
        if (!found) {
            printf("No employee found with Name  '%s'\n", searchName);
        }
        break;
    }
    case 2: {
        char searchDesignation[50];
        printf("Enter Designation to search: ");
        scanf("%s", searchDesignation);
        printf("\nEmployees with Designation '%s':\n", searchDesignation);
        int found = 0;
        for (int i = 0; i < numEmployees; i++) {
            if (strcmp(employees[i].designation, searchDesignation) == 0) {
                printf("Employee ID: %d, Name: %s, Designation: %s, Experience: %d, Age: %d\n", employees[i].employeeID,
                    employees[i].name, employees[i].designation, employees[i].experience, employees[i].age);
                found = 1;
            }
        }
        if (!found) {
            printf("No employee found with Designation '%s'\n", searchDesignation);
        }
        break;
    }
    default:
        printf("Invalid choice.\n");
        break;
    }
}

/**
 * @brief Function to handle user authentication.
 *
 * @return Returns 1 if authentication is successful, otherwise 0.
 */
int authenticateUser()
// Implementation of authenticateUser function
{
    char username[20], password[20];
    printf("Username: ");
    scanf("%s", username);
    printf("Password: ");
    scanf("%s", password);

    // Simulated authentication, replace with your logic
    if (strcmp(username, "admin") == 0 && strcmp(password, "admin123") == 0) {
        printf("Authentication successful.\n");
        return 1;
    }
    else {
        printf("Authentication failed.\n");
        return 0;
    }
}

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
