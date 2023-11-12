#include <stdio.h>

union employeeAddress
{
    char* employee_name;
    char* street_name;
    //char street_name[20]; // not assignable
    int lock_code;
};

int main(int argc, char const *argv[])
{
    union employeeAddress employee, *pt;

    employee.employee_name = "Jason Kim";
    //employee.street_name = "3500 Deer Creek Rd"; // OVERRIDES EMPLOYEE POINTER

    pt = &employee;


    printf("%s works at %s\n",
                        pt->employee_name,
                        (*pt).street_name);    
    
    printf("%s works at %s\n",
                        employee.employee_name,
                        employee.street_name);


    return 0;
}
