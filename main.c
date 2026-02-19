#include <stdio.h>
#include <string.h>
#define MAX = 100;
int main(void)
{
    char test_value[MAX];
        printf("Welcome to the gantt generator");
        printf("Would you like to use the test example or create your on Gantt from scratch ? (yes or no)");
        scanf("&s", &test_value);

        toLower(test_value);

        if (strcmp("yes", test_value)){
            printf("yay");
        }
        else 
        {
            printf("BOoo you lame");
        }

}




void toLower(char string[MAX_LEN])
{
    for (int i = 0; string[i] != '\0'; i++) 
    {
        string[i] = tolower((unsigned char) string[i]);
    }
}
    /*
    to do:
    TEST gantt chart
    Initialize the struct Ele
    get our inputs  Yehor

    give the option to edit
    pick and check the circular dependicies 
    
    */
