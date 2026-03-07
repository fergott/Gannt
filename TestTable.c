#include <stdio.h>
#include <ctype.h>
#include "TestTable.h"
#define MAX_LEN 100
void PrintTable(inputs* CoolerInputs)
{

    char month[MAX_LEN][12]= {{"february"}, {"february"}, {"march"}, {"april"}, {"may"}, {"July"},
{"June"}, {"august"}, {"september"}, {"october"}, {"november"}, {"december"}};

    printf("|━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━|\n");
    printf("|--------------------------------------------------------------------------------------------------|\n");
    printf("|");
    for (int i = 0; i<12; i++)
    {
        printf("%s |", month[i]);
    }
    for (int i = 0; i<CoolerInputs->taskAmount; i++) {
        printf("| %s \n", CoolerInputs->taskName[i-1]);
       // if (i <= CoolerInputs->startMonth && i >= CoolerInputs->endMonth) {
         ////   printf("|XXX");
     //   }
       // else printf("|    |");
    }


    printf("\n|--------------------------------------------------------------------------------------------------|\n");
    // print task[i] | print XXX for int month struct.start_month to struct.end_month ???

}


//function to read the inputs into the struct
void readInputs(inputs* CoolInputs)
{

    printf("how many tasks would you like to add?(1-10)");
    scanf("%d", &CoolInputs->taskAmount);
    if (CoolInputs->taskAmount <= 0 || CoolInputs->taskAmount > 10) {
        printf("task Amount must be between 1 and 10) \n");
        printf("how many tasks would you like to add?(1-10) \n");
        scanf("%d", &CoolInputs->taskAmount);
    }
    for (int i = 0; i < CoolInputs->taskAmount; i++)
    {
        printf("Enter the task %d name \n", i+1);
        scanf("%s", CoolInputs->taskName[i]);
        printf("Enter the start month \n");
        scanf("%d", &CoolInputs->startMonth[i]);
        printf("Enter the end month \n");
        scanf("%d", &CoolInputs->endMonth[i]);
        printf("Enter how many dependancies does this task have\n");
        scanf("%d", &CoolInputs->dependencyAmount[i]);
        for (int j = 0; j < CoolInputs->dependencyAmount[i]; j++)
        {
            printf("Enter the dependancy %d for the task %d \n", i+1, i+1);
            scanf("%d", &CoolInputs->dependencies[i][j]);
        }
    }
}
// check for dependencies
int depCheck(inputs *data, int task, int visited[], int stack[])
{
    if (stack[task])
    {
        return 1;
    }
    if (visited[task])
    {
        return 0;
    }

    stack[task] = 1;
    visited[task] = 1;

    for (int i=0; i<data->dependencyAmount[task]; i++)
    {
        int dep = data->dependencies[task][i]-1;

        if (dep >= 0 && dep < data->taskAmount) {
            if (depCheck(data, dep, &task, stack)) {
                return 1;
            }
        }

    }
    stack[task] = 0;
    return 0;
}
//check for dependancies
int circDependency(inputs *data)
{
    int visited[MAX_TASKS]={0};
    int stack[MAX_TASKS]={0};

    for (int i=0;i < data->taskAmount; i++) {
        if (depCheck(data, i, visited, stack)) {
            return 1;
        }
    }
    return 0;
}



// function to turn the input into lowercase to make program less case sensitive
void toLower(char string[MAX_LEN])
{
    for (int i = 0; string[i] != '\0'; i++)
    {
        string[i] = tolower((unsigned char) string[i]);
    }
}
