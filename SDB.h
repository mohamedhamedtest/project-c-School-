#include <stdbool.h>
#ifndef  _SDB_H
#define  _SDB_H
#define MAX 10


typedef struct SimpleDB
{
    uint8 student_ID;
    uint8 student_year;
    uint8 course_IDs[3];
    uint8 course_grade[3];
} Database;

Database * student[MAX];

void SDB_APP(void);
bool SDB_IsFull(void);
uint8 SDB_GetUsedSize(void);
bool SDB_AddEntry(uint8 id, uint8 year, uint8* subjects, uint8* grades);
void SDB_DeleteEntry(uint8 id);
bool SDB_ReadEntry(uint8 id, uint8* year, uint8* subjects, uint8* grades);
void SDB_GetIdList(uint8* count, uint8* list);
bool SDB_IsIdExist(uint8 ID);
void SDB_action (uint8 choice);



#endif // _SDB_H






