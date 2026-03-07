//

//

#ifndef ASSIGNMENT2ELEYEHOR_TESTTABLE_H
#define ASSIGNMENT2ELEYEHOR_TESTTABLE_H
#define MAX_LEN 100
#define MAX_TASKS 10
typedef struct inputs
{
    int taskAmount;
    char taskName[10][MAX_LEN];
    int startMonth[MAX_TASKS];
    int endMonth[MAX_TASKS];
    int dependencies[MAX_TASKS][MAX_TASKS];
    int dependencyAmount[MAX_TASKS];
} inputs;

void PrintTable(inputs* CoolerInputs);
int depCheck(inputs *data, int task, int visited[], int stack[]);
void readInputs(inputs* CoolInputs);
int circDependency(inputs *data) ;
void toLower(char string[MAX_LEN]);


#endif //ASSIGNMENT2ELEYEHOR_TESTTABLE_H