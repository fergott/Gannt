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
#define MAX_TASKS 10
void toLower(char string[MAX_LEN]);
void readInputs(inputs* CoolInputs);



int main(void)
{
    inputs inputs;
    char test_value[MAX_LEN];
    char commands[MAX_LEN];

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

          readInputs(&inputs);
          }

PrintTable(&inputs);
    printf("\n If you wish to edit the Gantt please type 'edit' / If you wish to run a test, type 'test' or to exit,"
           " type 'quit' and then press enter to execute your option.\n");

    scanf("%s", commands);
    toLower(commands);
    if (strcmp(commands, "quit") == 0)
        {
            return 0;
        }
    else if (strcmp(commands, "edit") == 0)
        {
            // somehow edit values inside the table
        }
    else if (strcmp(commands, "test") == 0)
        {
            // call PrintTable with test values
        }

    return 0;
}




