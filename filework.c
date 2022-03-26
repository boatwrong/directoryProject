#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *filename = "sourceList.txt";
const char *writeMode = "w";
const char *addMode = "a";
const char *readMode = "r";
static int idCount = 1;

typedef struct person {
    int id;
    char lastName[50], firstName[50];
} person;

person list[10];

void trim(char *str)
{
    for(int i=0; i < strlen(str); i++)
    {
        if(str[i] == '\n' || str[i] == ',' || str[i] == ' ')
        {
            str[i] = '\0';
            return;
        }
    }
}

int startup() {
    int idx = 0;
    FILE *file = fopen(filename, readMode);
    char *last = malloc(10 * sizeof(char));
    char *first = malloc(10 * sizeof(char));

    //TODO make source file have more than ten names to test realloc!
    while(idx < 9)
    {
        if(fscanf(file, "%s", last) ==  EOF)
        {
            break;
        }
        trim(last);
        fscanf(file, "%s", first);
        trim(first);

        strcat(list[idx].firstName, first);
        strcat(list[idx].lastName, last);
        list[idx].id = idCount;
        idx++;
    }
    //TODO realloc and think of logic to continue adding to array
    // // maybe a recursive function with the above while loop...

    
    return 0;
}

void getBack()
{
    char c;
    printf("Enter any number to return to the main menu.\n");
    c = 1;
    while(c < 32)
    {
        scanf("%c", &c);
    }
}

int sort()
{
    char next;
    FILE *sourceList = fopen(filename, readMode);

    do
    {
        next = fgetc(sourceList);
        printf("%c \n", next);
    } while(next != '\n');

    return 0;
}

int checkfile()
{
    if(fopen(filename, addMode) == NULL)
    {
        printf("FILE NOT FOUND\n");
        return 1;
    }
    return 0;
}

int addSource(char *sourceName)
{
    FILE *sourceList = fopen(filename, addMode);
    fputs(sourceName, sourceList);
    fclose(sourceList);
    //sort();
    return 0;
}

void addName(char *first, char *last)
{
    FILE *sourceList = fopen(filename, addMode);
    fputs(first, sourceList);
    fputs(" ", sourceList);
    fputs(last, sourceList);
    fputs("\n", sourceList);
    fclose(sourceList);

    //sort();
}

void readList()
{
    system("clear");
    char c;
    FILE *sourceList = fopen(filename, readMode);

    c = fgetc(sourceList);
    while(c != EOF)
    {
        printf("%c", c);
        c = fgetc(sourceList);
    }
    fclose(sourceList);
    getBack();

}

void clearList()
{
    FILE *sourceList = fopen(filename, writeMode);
    fclose(sourceList);
    getBack();
}

