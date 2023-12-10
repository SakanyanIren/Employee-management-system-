#include "Main.h"

void deleteEmployee(struct Employee*, int*, int);
void insertEmployee(struct Employee*, int*);
void searchEmployeeByID(struct Employee*, int, int);
void updateEmployee(struct Employee*, int, int);
void saveToFile(struct Employee*, int, const char*);
void registerUser(char*, char*);
int loadFromFile(struct Employee**, int*, const char*);
int checkUser(char*, char*);
void sortEmployeesByID(struct Employee*, int);
void searchEmployeesByCriteria(struct Employee*, int);
authenticateUser();
