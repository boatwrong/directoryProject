// Notes
//
// Need to utilize file as storage of contacts for long running memory

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include"filework.h"

#define MAX_NAME_SIZE 15

// take name input {{{
void takeName(char *name)
{
            fflush(stdin);
            fgets(name, MAX_NAME_SIZE,stdin);
            trim(name);
}
// }}}

// main menu {{{
int menuQuerry()
{
    int x;
    char first[MAX_NAME_SIZE];
    char last[MAX_NAME_SIZE];

    scanf("%d", &x);

    switch(x) {
        // Add Contact
        case(1): 
            printf("Enter the new contact's first name: \n");
            takeName(first);
            printf("Enter the new contact's last name: \n");
            takeName(last);
            addSource(last);
            addSource(", ");
            addSource(first);
            addSource("\n");
            return 1;

        // print list
        case(2):
            readList();
            return 1;

        // Exit
        case(3): 
            return 0;

        // Clear
        case(4):
            clearList();
            return 1;

    }
    printf("That is not a valid input, please try again.\n");
    sleep(1);
    return -1;
}

void printMain()
{
    system("clear");
    printf("1: add contact\n2: print list\n3: Exit\n4: Clear\n");
}
// }}}

int main()
{
    if(checkfile())
    {
        return 1;
    }

   
//    This creates array of people, need to combine functionality of this with
 //   lower operations
   
   
   
    startup();




/********************************************************************************************/



    
    //
    // this displays main menu and gives options to add to list
    //
    //
    int x = 1;

    while(x != 0)
    {
        printMain();
       x = menuQuerry();
    }

   return 0;

}
