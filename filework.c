#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdlib.h>

#define MAX_NAME_SIZE 20
#define LIST_START_SIZE 10

const char *filename = "sourceList.txt";
const char *writeMode = "w";
const char *addMode = "a";
const char *readMode = "r";
static int idCount = 1;

typedef struct {
    int id;
//    char lastName[50], firstName[50];
    char *lastName; // = malloc(MAX_NAME_SIZE * sizeof(char));
    char *firstName; //  = malloc(MAX_NAME_SIZE * sizeof(char));
} person;

// trim {{{
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
// }}}

void readPerson(FILE *file, person *list, int idx, int maxIndex)
{
    char *last = malloc(MAX_NAME_SIZE * sizeof(char));
    char *first = malloc(MAX_NAME_SIZE * sizeof(char));

    //TODO make source file have more than ten names to test realloc!
    while(idx < maxIndex)
    {
        if(fscanf(file, "%s", last) ==  EOF)
        {
            break;
        }

        list[idx].firstName = malloc(MAX_NAME_SIZE * sizeof(char));
        list[idx].lastName = malloc(MAX_NAME_SIZE * sizeof(char));

        trim(last);
        fscanf(file, "%s", first);
        trim(first);

        strcat(list[idx].firstName, first);
        strcat(list[idx].lastName, last);
        list[idx].id = idCount;
        printf("%d: %s %s\n", list[idx].id, list[idx].firstName, list[idx].lastName);
        idCount++;
        idx++;
    }

    list = realloc(list, 2 * maxIndex);

    if(idx == maxIndex)
    {
        readPerson(file, list, idx, 2 * maxIndex);
    }

}

void startup() {
    person *list = calloc(LIST_START_SIZE, sizeof(*list));

    int idx = 0;
    FILE *file = fopen(filename, readMode);

    readPerson(file, list, idx, LIST_START_SIZE);
    
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

void readList(person[] list)
{
    system("clear");
    char c;
    // FILE *sourceList = fopen(filename, readMode);

   //  c = fgetc(sourceList);
    // while(c != EOF)
 //     {
       // pri ntf("%c", c);
        // c = fgetc(sourceList);
    // }
    // fclose(sourceList);
    //

    for(int i=0; i < sizeof(list); i++)
    {
        printf("%s", list[i].name)
    }

    getBack();

}

void clearList()
{
    FILE *sourceList = fopen(filename, writeMode);
    fclose(sourceList);
    getBack();
}

