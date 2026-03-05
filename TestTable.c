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
        if (i < CoolerInputs->startMonth && i <= CoolerInputs->endMonth) {
            printf("|XXX");
        }
        else printf("|    |");
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
    }
/*
    for (int i = 0; i < CoolInputs->taskAmount; i++) {
        printf("%s", CoolInputs->taskName[i]);
        printf("start month: %d \n", CoolInputs->startMonth[i]);
        printf("end month: %d \n", CoolInputs->endMonth[i]);
        //       printf("dependencies: %d", inputs.dependencies);
    }
*/
}


// function to turn the input into lowercase to make program less case sensitive
void toLower(char string[MAX_LEN])
{
    for (int i = 0; string[i] != '\0'; i++)
    {
        string[i] = tolower((unsigned char) string[i]);
    }
}
