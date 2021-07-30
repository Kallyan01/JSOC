#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
struct cricket
{
    char name[20], tname[20];
    float bavg;
} * player;
struct cricket num;
int main()
{
    FILE *ft;
    int arrs, i, j;
    char fname[20], mode[4], ch;
    printf("Enter the file name:");
    gets(fname); //FILE NAME WITH EXTENTION EG. FILE.JS
    printf("Enter the file mode (w,r,a,w+,r+,a+)");
    gets(mode);                                          //INPUT OF FILE OPENING MODE
    ft = fopen(fname, mode);                             //FILE OPENED USING FILE NAME AND ACCESS MODE
    printf("Number of Player Data You want to enter: "); // TAKING INPUT OF ARRAY SIZE
    scanf("%d", &arrs);
    player = malloc(arrs * sizeof(struct cricket)); // USED MALLOC FOR INDEPENDENTLY USE OF ARRAY SIZE

    //TAKING INPUT OF CRICKTER DATA USING LOOP INTO STRUCTER ==>

    for (i = 0; i < arrs; i++)
    {
        fflush(stdin);
        printf("Enter player name : ");
        gets(player[i].name);
        fflush(stdin);
        printf("Enter team name:");
        gets(player[i].tname);
        printf("Enter batting average:");
        scanf("%f", &player[i].bavg);
    }

    //SORTING JS OBJ FILE DTAT ACCORDING TO THE AVG VALUES GIVEN ==>

    for (i = 1; i <= arrs; i++)
    {
        for (j = 0; j < arrs - i; j++)
        {
            if (player[j].bavg < player[j + 1].bavg)
            {
                num = player[j];
                player[j] = player[j + 1];
                player[j + 1] = num;
            }
        }
    }

    //JS OBJECT CREATING PROCESS STARTS FROM HERE , FORMATING THE GIVEN DATA AS A OBJ.JS FILE ==>
    
    // int cmp = strcmp(mode, "r+");
    // if (cmp != 0)
        fprintf(ft, "let crdata = [");
    //  if (cmp == 0)
    // {
    //     while (1)
    //     {
    //         ch = fgetc(ft);
    //         if (ch == EOF)
    //             break;
    //     if(ch=="]")
    //     {
    //         printf("Done");
    //        fseek(ft,-1,SEEK_CUR);
    //             fprintf(ft, ",");
    //     } 
    //     }
    // }
    for (i = 0; i < arrs; i++)
    {
        fprintf(ft, "{ \n");
        fprintf(ft, "\tName : ");
        fprintf(ft, "\"%s\", \n", player[i].name);
        fprintf(ft, "\tTeam : ");
        fprintf(ft, "\"%s\", \n", player[i].tname);
        fprintf(ft, "\tAverage : ");
        fprintf(ft, "%.2f \n", player[i].bavg);
        fprintf(ft, "}, \n");
    }
    fprintf(ft, "]");

    fclose(ft);
    getch();
}

