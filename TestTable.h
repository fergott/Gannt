
#ifndef ASSIGNMENT2ELEYEHOR_TESTTABLE_H
#define ASSIGNMENT2ELEYEHOR_TESTTABLE_H
#define MAX_LEN 100
#define MAX_TASKS 10
#define MAX_DEPS 10

//the struct is defined here so that it is universally the same
typedef struct
{
    int taskAmount;
    char taskName[MAX_TASKS][MAX_LEN];
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
void loadTestData(inputs *data);
void editTask(inputs *data);
void clearScreen(void);


#endif //ASSIGNMENT2ELEYEHOR_TESTTABLE_H