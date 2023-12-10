#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void registerUser(char* name, char* password) 
{
    FILE* file = fopen("users.txt", "a");
    if (file == NULL) {
        printf("Unable to create/open the users base.\n");
        return;
    }
    fprintf(file, "%s %s\n", name, password);

    fclose(file);
    printf("User '%s' is successfully registered.\n", name);
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
int checkUser(char* name, char* password) 
{
    FILE* file = fopen("users.txt", "r");
    if (file == NULL) {
        printf("Unable to open the users database.\n");
        return 0;
    }

    // Simulated authentication, replace with your logic

    char currentName[20], currentPassword[20];
    while (fscanf(file, "%s %s", currentName, currentPassword) != EOF) {
        if (strcmp(currentName, name) == 0 && strcmp(currentPassword, password) == 0) {
            return 1;
        }
    }

    fclose(file);
    return 0;
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
    if (checkUser(username, password) == 1) {
        printf("Authentication successful.\n");
        return 1;
    }
    else {
        printf("Authentication failed.\n");
        printf("Do you want to register? 1-yes, 2-no.\n");
        int result = -1;
        scanf("%d", &result);
        if (result == 1) {
            registerUser(username, password);
            return 1;
        }
        return 0;
    }
}
