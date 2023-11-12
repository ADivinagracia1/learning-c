#include <stdio.h>

struct employeeAddress
{
    char* employee_name;
    char street_name[20];
    int lock_code;
};

int main(int argc, char const *argv[])
{
    struct employeeAddress employee = {"Jason Kim", "3500 Deer Creek Rd", 1234};
    struct employeeAddress *pt = &employee;

    printf("%s works at %s\n",
                        pt->employee_name,
                        (*pt).street_name);    
    
    printf("%s works at %s\n",
                        employee.employee_name,
                        employee.street_name);


    return 0;
}
