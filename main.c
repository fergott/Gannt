#include <stdio.h>
#include <string.h>
#define MAX = 100;
int main(void)
{
    char test_value[MAX];
        printf("Welcome to the gantt generator");
        printf("Would you like to use the test example or create your on Gantt from scratch ? (yes or no)");
        scanf("&s", &test_value)


        if (strcmp("yes", test_value)){
            printf("yay");
        }

    /*
    to do:
    TEST gantt chart
    Initialize the struct
    get our inputs
    give the option to edit
    pick and check the circular dependicies 
    
    */
}