#include "STD.h"
#include "SDB.h"



int number_of_entries =-1  ; //To act indicator of stack
int number;





bool SDB_AddEntry(uint8 id, uint8 year, uint8* subjects, uint8* grades)
{
    uint32 i;

    student[number_of_entries]->student_ID = id;
    student[number_of_entries]->student_year = year;

    for (i = 0; i < 3; i++)
    {
        printf("enter ID of course %d :", i + 1);
        scanf("%d", subjects);
        subjects++;
    }
    for (i = 0; i < 3; i++)
    {
label1:
        printf("enter grade of course %d :", i + 1);
        scanf("%d", grades);
        if (!(grades[0] >= 0 && grades[0] <= 100))
        {
            printf("Please enter the grade between 0 and 100\n");
            goto label1;
        }
        else
        {
            grades++;
        }
    }
    if ((student[number_of_entries]->student_ID != 0) && (student[number_of_entries]->student_year != 0) &&
            (student[number_of_entries]->course_IDs[0] != 0) && (student[number_of_entries]->course_IDs[1] != 0) &&
            (student[number_of_entries]->course_IDs[2] != 0) && (student[number_of_entries]->course_grade[0] != 0) &&
            (student[number_of_entries]->course_grade[1] != 0) && (student[number_of_entries]->course_grade[2] != 0))
    {
        printf("\nThe new entry is successfully added\n\n");
        return 1;
    }
    else
    {
        printf("\nThe new entry is not successfully added\n\n");
        number_of_entries--;
        return 0;
    }
}
uint8 SDB_GetUsedSize()
{
    return (number_of_entries+1);
}

bool SDB_IsIdExist(uint8 id)
{
    uint32 i, flag = 0;

    for (i = 0; i <=number_of_entries; i++)
    {
        if (id == student[i]->student_ID)
        {
            flag++;
            number = i;
            break;
        }
    }
    if (flag == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}


bool SDB_ReadEntry(uint8 id, uint8* year, uint8* subjects, uint8* grades)
{
    int i,j;

    if(!(SDB_IsIdExist(id)))
    {
        printf("Error : there is not student with this id to read,please enter the correct id\n");
        return 0;
    }
    else
    {
        *year=student[number]->student_year;
        for(i=0; i<3; i++)
        {
            subjects[i]=student[number]->course_IDs[i];
            grades[i]=student[number]->course_grade[i];
        }

        printf("ID of the student = %d\n",id);
        printf("Year of the student = %d\n",*year);
        for(j=0; j<3; j++)
        {
            printf("The id of course %d = %d and the grade = %d\n",j+1,subjects[j],grades[j]);

        }
        return 1;
    }
}

void SDB_DeleteEntry(uint8 id)
{
    int i=0,delete_again;

    if (!(SDB_IsIdExist(id)))
    {
        printf("Error : there is not student with this id to delete,please enter the correct id\n");
        SDB_APP();
    }
    else
    {
        while (number + i + 1 <=number_of_entries)
        {
            student[number + i] = student[number + i + 1];
            i++;
        }

        printf("Deleted successfully\n");
        free(student[number_of_entries]);
        number_of_entries--;
    }
    printf("To return to the main menu or to delete another student press 0 : ");
    scanf("%d", &delete_again);
    if (delete_again == 0)
    {
        SDB_APP();
    }
}

bool SDB_IsFull(void)
{
    if (number_of_entries == MAX-1)//9 10 students
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


void SDB_GetIdList(uint8* count, uint8* list)
{
    int i,j;

    *count=SDB_GetUsedSize();

    printf("The number of entries currently exists in the database = %d\n",*count);

    for(i=0; i<=number_of_entries; i++)
    {
        list[i]=student[i]->student_ID;
    }
    for(j=number_of_entries; j>=0; j--)
    {
        printf("ID of the student %d = %d\n",j+1,list[j]);

    }
    SDB_APP();
}
