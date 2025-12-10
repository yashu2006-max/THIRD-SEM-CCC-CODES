#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student{int roll;char name[50];float marks;struct Student*next;};
struct Student*head=NULL;
struct Student*createStudent(int roll,const char name[],float marks){
    struct Student*ns=(struct Student*)malloc(sizeof(struct Student));
    if(!ns){fprintf(stderr,"Memory allocation failed\n");exit(EXIT_FAILURE);}
    ns->roll=roll;
    strncpy(ns->name,name,sizeof(ns->name)-1);
    ns->name[sizeof(ns->name)-1]='\0';
    ns->marks=marks;
    ns->next=NULL;
    return ns;
}

int rollExists(int roll){
    struct Student*tmp=head;
    while(tmp){if(tmp->roll==roll)return 1;tmp=tmp->next;}
    return 0;
}

void addStudent(){
    int roll;char name[50];float marks;
    printf("\nEnter Roll Number: ");
    if(scanf("%d",&roll)!=1){while(getchar()!='\n');printf("Invalid input.\n");return;}
    if(rollExists(roll)){printf("Roll number already exists. Use update instead.\n");return;}
    printf("Enter Name: ");
    while(getchar()!='\n');
    if(!fgets(name,sizeof(name),stdin)){printf("Input error.\n");return;}
    name[strcspn(name,"\n")]='\0';
    printf("Enter Marks: ");
    if(scanf("%f",&marks)!=1){while(getchar()!='\n');printf("Invalid marks.\n");return;}
    struct Student*ns=createStudent(roll,name,marks);
    if(head==NULL)head=ns;else{struct Student*t=head;while(t->next)t=t->next;t->next=ns;}
    printf("\nStudent Added Successfully!\n");
}

void displayStudents(){
    if(head==NULL){printf("\nNo Records Available!\n");return;}
    struct Student*t=head;printf("\n---- Student Records ----\n");
    while(t!=NULL){printf("Roll: %d | Name: %s | Marks: %.2f\n",t->roll,t->name,t->marks);t=t->next;}
}

void searchStudent(){
    int roll;printf("\nEnter Roll Number to Search: ");
    if(scanf("%d",&roll)!=1){while(getchar()!='\n');printf("Invalid input.\n");return;}
    struct Student*t=head;
    while(t!=NULL){if(t->roll==roll){printf("\nRecord Found:\nRoll: %d | Name: %s | Marks: %.2f\n",t->roll,t->name,t->marks);return;}t=t->next;}
    printf("\nStudent Not Found!\n");
}

void updateStudent(){
    int roll;printf("\nEnter Roll Number to Update: ");
    if(scanf("%d",&roll)!=1){while(getchar()!='\n');printf("Invalid input.\n");return;}
    struct Student*t=head;
    while(t!=NULL){
        if(t->roll==roll){
            char nn[50];float nm;
            printf("Enter New Name: ");
            while(getchar()!='\n');
            if(!fgets(nn,sizeof(nn),stdin)){printf("Input error.\n");return;}
            nn[strcspn(nn,"\n")]='\0';
            printf("Enter New Marks: ");
            if(scanf("%f",&nm)!=1){while(getchar()!='\n');printf("Invalid marks.\n");return;}
            strncpy(t->name,nn,sizeof(t->name)-1);t->name[sizeof(t->name)-1]='\0';t->marks=nm;
            printf("\nRecord Updated Successfully!\n");return;
        }
        t=t->next;
    }
    printf("\nStudent Not Found!\n");
}

void deleteStudent(){
    int roll;printf("\nEnter Roll Number to Delete: ");
    if(scanf("%d",&roll)!=1){while(getchar()!='\n');printf("Invalid input.\n");return;}
    struct Student*temp=head;struct Student*prev=NULL;
    if(temp!=NULL && temp->roll==roll){head=temp->next;free(temp);printf("\nRecord Deleted Successfully!\n");return;}
    while(temp!=NULL && temp->roll!=roll){prev=temp;temp=temp->next;}
    if(temp==NULL){printf("\nStudent Not Found!\n");return;}
    prev->next=temp->next;free(temp);printf("\nRecord Deleted Successfully!\n");
}

void freeAll(){struct Student*c=head;while(c){struct Student*n=c->next;free(c);c=n;}head=NULL;}
int main(){
    int choice;
    do{
        printf("\n STUDENT RECORD MANAGEMENT SYSTEM \n");
        printf("1.Add Student\n2.Display All Students\n3.Search Student\n4.Update Student\n5.Delete Student\n6.Exit\nEnter Your Choice: ");
        if(scanf("%d",&choice)!=1){while(getchar()!='\n');printf("Invalid input.\n");continue;}
        switch(choice){
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: updateStudent(); break;
            case 5: deleteStudent(); break;
            case 6: printf("\nExiting...\n"); break;
            default: printf("\nInvalid Choice!\n");
        }
    }while(choice!=6);
    freeAll();
    return 0;
}
