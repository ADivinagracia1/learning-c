#include <stdio.h>

struct employee
{
    char *emplotee_name;
    int employee_id;
};

// Write a program in C to show a pointer to an array whose contents are pointers to structures
int main(int argc, char const *argv[])
{
	static struct employee emp1={"Jhon",1001},emp2={"Alex",1002},emp3={"Taylor",1003};
	struct employee(*arr[])={&emp1,&emp2,&emp3};
	struct employee(*(*pt)[3])=&arr;

	printf(" Exmployee Name : %s \n",(**(*pt+1)).emplotee_name);
	printf("---------------- Explanation --------------------\n");
	printf("(**(*pt+1)).empname\n");
	printf("= (**(*&arr+1)).empname   as pt=&arr\n");
	printf("= (**(arr+1)).empname     from rule *&pt = pt\n");
	printf("= (*arr[1]).empname       from rule *(pt+i) = pt[i]\n");
	printf("= (*&emp2).empname        as arr[1] = &emp2\n");
	printf("= emp2.empname = Alex       from rule *&pt = pt\n\n");
	printf(" Employee ID :  %d\n",(*(*pt+1))->employee_id);	
	printf("---------------- Explanation --------------------\n");
	printf("(*(*pt+1))-> empid\n");
	printf("= (**(*pt+1)).empid     from rule -> = (*).\n");
	printf("= emp2.empid = 1002\n");
	printf("\n\n");

    return 0;
}
