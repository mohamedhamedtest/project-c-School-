#include "STD.h"
#include "SDB.h"
void Exit(void)
{
    exit(0);

}
extern int number_of_entries  ; //To act indicator of stack
extern int number;

uint32 choice, id, year, add_again,i,check=0;
uint8 *count,*list,*id_year,*id_subjects,*id_grades,id_read,id_deleted;

void SDB_APP(void)
{
    printf("////////////////////////////////////////////////\n");
    printf("Please chose one of below choices\n\n");
    printf("1) Add new entry\n"
           "2) Read entries\n"
           "3) Get list of entries IDs\n"
           "4) Delete entry\n"
           "5) Exit\n");
    printf("////////////////////////////////////////////////\n");

    scanf("%d", &choice);
    SDB_action(choice);
}


void SDB_action (uint8 choice)
{
    switch (choice)
    {
    case 1:
        if (SDB_IsFull())
        {
            printf("The database is full \n\n");
            SDB_APP();
        }
        else
        {
            number_of_entries++;
            student[number_of_entries] = (Database*)malloc(sizeof(Database));
label2:
            printf("enter ID of the student %d : ", number_of_entries + 1);
            scanf("%d", &id);
            for(i=0; i<number_of_entries; i++)
            {
                if(id==student[i]->student_ID)
                {
                    check++;
                }
            }
            if(check !=0)
            {
                printf("Error:there is a student with this id .\n");
                check=0;
                goto label2;
            }
            printf("enter year of the student %d : ", number_of_entries + 1);
            scanf("%d", &year);
            SDB_AddEntry(id, year, &student[number_of_entries]->course_IDs, &student[number_of_entries]->course_grade);
        }
        printf("To return to the main menu or to add another student press 0 : ");
        scanf("%d", &add_again);
        if (add_again == 0)
        {
            SDB_APP();
        }
        break;
    case 2:
        if (number_of_entries == -1)
        {
            printf("There is not any ID to read\n");
            SDB_APP();
        }
        else
        {
            printf("Please enter the id of the student to read his data : ");
            scanf("%d", &id_read);
            id_year=(uint8*)malloc(sizeof(uint8));
            id_subjects=(uint8*)malloc(3*sizeof(uint8));
            id_grades=(uint8*)malloc(3*sizeof(uint8));
            SDB_ReadEntry(id_read,id_year,id_subjects,id_grades);
            free(id_year);
            free(id_subjects);
            free(id_grades);
        }
        break;
    case 3:
        count=(uint8*)malloc(sizeof(uint8));
        list=(uint8*)malloc((number_of_entries+1)*sizeof(uint8));
        SDB_GetIdList(count,list);
        free(count);
        free(list);
        break;
    case 4:
        if (number_of_entries == -1)
        {
            printf("There is not any student to delete\n");
            SDB_APP();
        }
        else
        {
            printf("Please enter the id of the student to delete:");
            scanf("%d", &id_deleted);
            SDB_DeleteEntry(id_deleted);
        }
        break;
    case 5:
        Exit();
        break;
    default:
        printf("try again\n");
        SDB_APP();
        break;
    }
}

