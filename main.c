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

struct InputsStr
{
    int taskAmount;
    char taskName[10][MAX_LEN];
    int startMonth;
    int endMonth;
    int dependencies;
};


int main(void)
{
    struct InputsStr inputs;
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
          printf("how many tasks would you like to add?(1-10");
             scanf("%d", &inputs.taskAmount);
            if (inputs.taskAmount <= 0 || inputs.taskAmount > 10)
            {
                printf("task Amount must be between 1 and 10 \n");
                printf("how many tasks would you like to add?(1-10");
                scanf("%d", &inputs.taskAmount);

                for (int i = 0; i < inputs.taskAmount; i++)
                {
                    printf("Enter the task %d name \n", i+1);
                    scanf("%s", inputs.taskName[i]);
                    printf("Enter the start month \n");
                    scanf("%d", &inputs.startMonth);
                    printf("Enter the end month \n");
                    scanf("%d", &inputs.endMonth);
                }
            }

        }


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




