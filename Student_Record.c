#include<stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10;

struct Student
{
    char Name[15];
    char roll[12];
    float CGPA;
    struct Student* next;
};

struct Student* newNode(char* name,char* roll,float CGPA)
{
    struct Student* node = (struct Student*)malloc(sizeof(struct Student));
    strncpy(node->Name, name, 15);
    strncpy(node->roll, roll, 12);
    node->CGPA = CGPA;
    node->next = NULL;
    return node;
}

struct Student* head;
struct Student* curr;
int num_stud=0;

void addRecord(){
    printf("\nAdd new record\n\n");
    char str[15];
    char rollno[12];
    float cgpa;
    printf("Student Name :- ");
    scanf("%s",str);
    printf("Student Roll No. :- ");
    scanf("%s", rollno);
    printf("Student CGPA :- ");
    scanf("%f",&cgpa);
    printf("\n\n");
    if(num_stud==0){
        head = newNode(str,rollno,cgpa);
        curr = head;
        num_stud++;
    }
    else{
        struct Student* temp=curr;
        temp->next = newNode(str,rollno,cgpa);
        curr=temp->next;
    }
}

void displayRecord(){
    printf("\nDisplay record\n\n");
    struct Student* temp=head;
    while(temp!=NULL){
        printf("*) Student name :- %s",temp->Name);
        printf("\n  Student Roll No. :- %s",temp->roll);
        printf("\n  Student CGPA :- %f",temp->CGPA);
        printf("\n\n");
        temp=temp->next;
    }
}

void searchRecord(){
    printf("\nSearch record\n\n");
    char search[15];
    printf("Student name :- ");
    scanf("%s",search);
    struct Student* temp=head;
    while(temp!=NULL){
        if(strcmp(temp->Name,search)==0){
            printf("Student Found!!\n");
            printf("Student Name :- %s\n",temp->Name);
            printf("Student Roll No. :- %s\n",temp->roll);
            printf("Student CGPA:- %f\n",temp->CGPA);
            printf("\n\n");
            return;
        }
        temp=temp->next;
    }
    printf("Student Not Found!!\n\n\n");
}



int main(){

    printf("\n\n********   Student Records  ********\n\n");
    printf("1. Add new record\n");
    printf("2. Display Record\n");
    printf("3. Search record\n");
    printf("4. Exit\n\n");

    while(1){
        printf("Enter your choice :- ");
        int code;
        scanf("%d",&code);
        switch(code)
        {
            case 1:
                addRecord();
                break;

            case 2:
                displayRecord();
                break;

            case 3:
                searchRecord();
                break;

            case 4:
                exit(0);
                break;

            default:
                printf("Not a valid choice");
        }
    }


}