#include <stdio.h>
#include <ctype.h>
#define MAX_LEN 100
void PrintTable()
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
    
    printf("\n|--------------------------------------------------------------------------------------------------|\n");
    // print task[i] | print XXX for int month struct.start_month to struct.end_month ???

}

// function to turn the input into lowercase to make program less case sensitive
void toLower(char string[MAX_LEN])
{
    for (int i = 0; string[i] != '\0'; i++)
    {
        string[i] = tolower((unsigned char) string[i]);
    }
}
