#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "TestTable.h"

#include <stdlib.h>

void clearScreen(void) {
    // this function uses system commands to clear the screen as outlined in brief
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void PrintTable(inputs *data)
{
    const char *months[12] = {
        "Jeb", "Feb", "March", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
    };

    printf("\n%-20s", "Task"); //the "%-20" allows for there to be buffer room so the table is uniform
    for (int i = 0; i < 12; i++) // for loop that prints the headers/titles
    {
        printf("| %3s ", months[i]);
    }
    printf("| Dep\n");

    for (int i = 0; i < 100; i++) {
        printf("-"); //formatting
    }
    printf("\n");

    for (int i = 0; i < data->taskAmount; i++) {
        printf("%-20s", data->taskName[i]); // the "%-20" is most useful here where the length of task names is diferent

        for (int month = 1; month <= 12; month++) {
            if (month >= data->startMonth[i] && month <= data->endMonth[i]) {
                printf("| %-3s ", "XXX");
            } else {
                printf("| %-3s ", "");
            }
        }

        printf("| ");

        if (data->depCount[i] == 0) {
            printf("None");
        } else {
            for (int j = 0; j < data->depCount[i]; j++) {
                printf("%d", data->dependencies[i][j]);
                if (j < data->depCount[i] - 1) {
                    printf(" ");
                }
            }
        }

        printf("\n");
    }

    printf("\n");
}


//function to read the inputs into the struct
void readInputs(inputs *data)
{

    printf("how many tasks would you like to add?(1-10)");
    scanf("%d", &data->taskAmount);

    while (data->taskAmount < 1 || data->taskAmount > MAX_TASKS) {
        printf("Task amount must be between 1 and 10\n");
        printf("How many tasks would you like to add?: ");
        scanf("%d", &data->taskAmount);
    }

    for (int i = 0; i < data->taskAmount; i++) {
        printf("Task %d name (UNDERSCORES!!): ", i+1); //using underscores allows us to use the scanf function rather than fgets or something
        scanf("%99s", data->taskName[i]);

        printf("Start month(1-12): ");
        scanf("%d", &data->startMonth[i]);
        while (data->startMonth[i] < 1 || data->startMonth[i] > 12) {
            printf("Month must be between 1 and 12: ");
            scanf("%d", &data->startMonth[i]);
        }

        printf("End month(1-12)");
        scanf("%d", &data->endMonth[i]);
        while (data->endMonth[i] < data->startMonth[i] || data->endMonth[i] > 12) {
            printf("invalid month. Try again: ");
            scanf("%d", &data->endMonth[i]);
        }

        printf("how many dependencies for this task?: ");
        scanf("%d", &data->depCount[i]);

        if (data->depCount[i] < 0) data->depCount[i] = 0; //cant have negative dependencies
        if (data->depCount[i] > MAX_DEPS) data->depCount[i] = MAX_DEPS; // cant have more dependencies than tasks

        for (int j=0; j < data->depCount[i]; j++) {
            printf("Enter dependecy %d(Task number): ", j+1);
            scanf("%d", &data->dependencies[i][j]);
        }
    }
/*   not in use anymore
    for (int i = 0; i < data->taskAmount; i++) {
        printf("%s", data->taskName[i]);
        printf("start month: %d \n", data->startMonth[i]);
        printf("end month: %d \n", data->endMonth[i]);
        //       printf("dependencies: %d", inputs.dependencies);
    }
*/
}


// function to turn the input into lowercase to make program less case sensitive
void toLower(char string[MAX_LEN])
{
    for (int i = 0; string[i] != '\0'; i++)
    {
        string[i] = (char)tolower((unsigned char) string[i]);
    }
}

// this allows us to print the test gantt chart with preloaded data
void loadTestData(inputs *data) {
    data->taskAmount = 10;

    strcpy(data->taskName[0], "Book_Venue");
    data->startMonth[0] = 1;
    data->endMonth[0] = 2;
    data->depCount[0] = 0;

    strcpy(data->taskName[1], "Hire_Performers");
    data->startMonth[1] = 2;
    data->endMonth[1] = 5;
    data->depCount[1] = 1;
    data->dependencies[1][0] = 1;

    strcpy(data->taskName[2], "Order_sound_lighting");
    data->startMonth[2] = 3;
    data->endMonth[2] = 5;
    data->depCount[2] = 1;
    data->dependencies[2][0] = 1;

    strcpy(data->taskName[3], "Marketing");
    data->startMonth[3] = 5;
    data->endMonth[3] = 8;
    data->depCount[3] = 2;
    data->dependencies[3][0] = 1;
    data->dependencies[3][1] = 2;

    strcpy(data->taskName[4], "Ticket_sales");
    data->startMonth[4] = 8;
    data->endMonth[4] = 9;
    data->depCount[4] = 1;
    data->dependencies[4][0] = 4;

    strcpy(data->taskName[5], "Hire_security");
    data->startMonth[5] = 10;
    data->endMonth[5] = 11;
    data->depCount[5] = 1;
    data->dependencies[5][0] = 5;

    strcpy(data->taskName[6], "Equipment_delivery");
    data->startMonth[6] = 8;
    data->endMonth[6] = 10;
    data->depCount[6] = 1;
    data->dependencies[6][0] = 3;

    strcpy(data->taskName[7], "Setup_stage");
    data->startMonth[7] = 9;
    data->endMonth[7] = 10;
    data->depCount[7] = 1;
    data->dependencies[7][0] = 7;

    strcpy(data->taskName[8], "Rehearsal");
    data->startMonth[8] = 11;
    data->endMonth[8] = 11;
    data->depCount[8] = 2;
    data->dependencies[8][0] = 2;
    data->dependencies[8][1] = 7;

    strcpy(data->taskName[9], "Event_day");
    data->startMonth[9] = 12;
    data->endMonth[9] = 12;
    data->depCount[9] = 2;
    data->dependencies[9][0] = 9;
    data->dependencies[9][1] = 6;
}


//allows user to edit tasks already added to the struct
void editTask(inputs *data) {
    char target[MAX_LEN];
    int found = 0;// binary value to see if the task the user wants to change is actually in the struct already

    printf("Enter the task name you want to edit exactly: ");
    scanf("%99s", target);

    for (int i = 0;i < data->taskAmount; i++) {
        if (strcmp(target, data->taskName[i]) == 0) {
            found = 1;

            printf("Enter new task name (or same one): ");
            scanf("%99s", data->taskName[i]);

            printf("New start month (1 -12): ");
            scanf("%d", &data->startMonth[i]);
            while (data->startMonth[i] < 1 || data->startMonth[i] > 12) {
                printf("Invalid month. Month must be between 1 and 12: ");
                scanf("%d", &data->startMonth[i]);
            }

            printf("New end month (1 -12): ");
            scanf("%d", &data->endMonth[i]);
            while (data->endMonth[i] < data->startMonth[i] || data->endMonth[i] > 12) {
                printf("Invalid month. Month must be between 1 and 12: ");
                scanf("%d", &data->endMonth[i]);
            }

            printf("How many dependencies does this task have?: ");
            scanf("%d", &data->depCount[i]);

            if (data->depCount[i] < 0) data->depCount[i] = 0; //can't be negative
            if (data->depCount[i] > MAX_DEPS) data->depCount[i] = MAX_DEPS; // cant be greater than number of tasks

            for (int j = 0; j < data->depCount[i]; j++) {
                printf("Enter dependency %d(Task number): ", j+1);
                scanf("%d", &data->dependencies[i][j]);
            }
            printf("Task updated successfully");
            return;
        }
    }

    if (!found) {
        printf("Task does not exist.\n");
    }
}
