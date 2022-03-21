#include"filework.h"
#include<stdlib.h>

const char *filename = "sourceList";
const char *writeMode = "w";
const char *addMode = "a";
const char *readMode = "r";

void getBack()
{
    char c;
    printf("Enter any number to return to the main menu.\n");
    c = 1;
    while(c < 48 || c > 57)
    {
        scanf("%c", &c);
    }
}

int sort()
{
    char last, next;
    FILE *sourceList = fopen(filename, readMode);

    last = fgetc(sourceList);

    do
    {
        next = fgetc(sourceList);
    } while(next != '\n');
    next = fgetc(sourceList);

    if(last > next)
    {
        // next name is alphabetically 
    }
    printf("%c %c\n", last, next);
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
}

