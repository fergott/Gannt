 /*
to do:
   TEST gantt chart
   Initialize the struct Ele
   get the inputs  Yehor

   give the option to edit
   pick and check the circular dependencies

   */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "TestTable.h"
#define MAX_LEN 100

void toLower(char string[MAX_LEN]);

int main(void)
{
    char test_value[MAX_LEN];
    char input[MAX_LEN];

        printf("Welcome to the gantt generator");
        printf("Would you like to use the test example or create your on Gantt from scratch ? (yes or no) \n");
        scanf("%s", test_value);

        toLower(test_value);

      if (strcmp(test_value, "yes") == 0)
         {
        PrintTable();
          //to do print out the test table

         }
      else
        {
             printf("BOoo you lame");
        }


    printf("\n If you wish to edit the Gantt please type 'edit' / If you wish to run a test, type 'test' or to exit,"
           " type 'quit' and then press enter to execute your option.\n");

    scanf("%s", input);
    toLower(input);
    if (strcmp(input, "quit") == 0)
        {
            return 0;
        }
    else if (strcmp(input, "edit") == 0)
        {
            // somehow edit values inside the table
        }
    else if (strcmp(input, "test") == 0)
        {
            // call PrintTable with test values
        }

    return 0;
}




