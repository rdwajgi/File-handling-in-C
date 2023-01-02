// File handling in C :date 2nd Jan 2023
#include<stdio.h>
#include<conio.h>
#define MAX 5
struct student
{
    int rollno;
    char name[10];
    float CGPA;

}st[MAX];

int main()
{

    FILE *fp, *fp1;
    int n,i,rno,ch,flag;
    char sname[10],res;
    float cgp;
    fp = fopen("stud.txt","w");
    if(fp == NULL)
    {
        printf("\n\t\tFile opening error");
        exit(0);
    }
    else
    {
        printf("\n\t\tEnter the number of record:\t");
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            printf("\n\t\t\tEnter roll no\t name \t CGPA\n\t\t");
            scanf("%d\n\t%s\n\t%f",&st[i].rollno,st[i].name,&st[i].CGPA);
            fprintf(fp,"%d\t%s\t%f\n", st[i].rollno,st[i].name,st[i].CGPA);
        }
        fclose(fp);
    }


    do
    {
        printf("\n1.Display\n2.Append\n3.Search\n4.Update");
        printf("\n\tEnter your choice:\t");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
                                fp = fopen("stud.txt","r");
                                if(fp == NULL)
                            {
                                    printf("\n\t\tFile opening error");
                                    exit(0);
                            }
                            else
                            {
                                i=0;
                                printf("\nRoll No\t\tName\t\tCGPA");
                                printf("\n----------------------------------------------------------------------------------------------------");
                                while(fscanf(fp, "%d\t%s\t%f",&st[i].rollno,st[i].name,&st[i].CGPA)!=EOF)
                                {
                                    printf("\n%d\t%s\t%f", st[i].rollno,st[i].name,st[i].CGPA);
                                    i++;
                                    getc(res);
                                }
                                fclose(fp);
                            }
            break;
        case 2:
                                      fp = fopen("stud.txt","a");
                                if(fp == NULL)
                            {
                                    printf("\n\t\tFile opening error");
                                    exit(0);
                            }
                            else
                            {
                                    printf("\n\t\t\tEnter roll no\t name \t CGPA\n\t\t");
                                    scanf("%d%s%f",&rno, &sname,&cgp);
                                    fprintf(fp,"%d\t%s\t%f", rno, sname,cgp);
                                    fclose(fp);

                            }
            break;
        case 3:
                           fp = fopen("stud.txt","r");
                                if(fp == NULL)
                            {
                                    printf("\n\t\tFile opening error");
                                    exit(0);
                            }
                            else
                            {
                                    printf("\n\t\t\tEnter roll no to be searched:\t");
                                    scanf("%d",&rno);
                                    i=0; flag =0;
                                    while(fscanf(fp, "%d\t%s\t%f",&st[i].rollno,st[i].name,&st[i].CGPA)!=EOF)
                                {
                                    if(st[i].rollno==rno)
                                    {
                                            printf("\nRecord details are");
                                           printf("\n\t%d\t%s\t%f", st[i].rollno,st[i].name,st[i].CGPA);
                                           flag =1;
                                           break;
                                    }

                                    i++;
                                }
                                if(flag==0)
                                    printf("\n\t\tRECORD not found");
                                fclose(fp);
                            }

            break;
        case 4:
                                 fp = fopen("stud.txt","r");
                                 fp1 = fopen("stud1.txt", "w"); //temporary file
                                if(fp == NULL && fp1 ==NULL)
                            {
                                    printf("\n\t\tFile opening error");
                                    exit(0);
                            }
                            else
                            {
                                      i=0; flag =0;
                                    printf("\n\t\t\tEnter roll no to be updated:\t");
                                    scanf("%d",&rno);
                                    while(fscanf(fp, "%d\t%s\t%f\n",&st[i].rollno,st[i].name,&st[i].CGPA)!=EOF)
                                {
                                    if(st[i].rollno==rno)
                                    {
                                         printf("\n\t\t\tEnter new CGPA\n");
                                         scanf("%f",&cgp);

                                         fprintf(fp1,"%d\t%s\t%f\n", st[i].rollno,st[i].name,cgp);

                                         printf("\n\nRecord updated");
                                         flag =1;
                                       // continue;
                                    }
                                    else
                                        fprintf(fp1,"%d\t%s\t%f\n", st[i].rollno,st[i].name,st[i].CGPA);
                                    i++;
                                }
                                     if(flag==0)
                                            printf("\n\t\tRECORD not found");
                                fclose(fp);
                                fclose (fp1);
                               fp = fopen("stud.txt","w");
                                 fp1 = fopen("stud1.txt", "r");
                                if(fp == NULL && fp1 ==NULL)
                            {
                                    printf("\n\t\tFile opening error");
                                    exit(0);
                            }
                            else
                            {
                                i=0;
                                  while(fscanf(fp1, "%d\t%s\t%f\n",&st[i].rollno,st[i].name,&st[i].CGPA)!=EOF)
                                  {
                                       fprintf(fp,"%d\t%s\t%f\n", st[i].rollno,st[i].name,st[i].CGPA);
                                       i++;
                                  }
                                fclose(fp);
                                fclose (fp1);
                            }
                            }
            break;
        }
    }while(ch<=4);
}
