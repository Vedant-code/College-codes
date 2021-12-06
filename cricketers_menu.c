/*Write a Menu driven program in C for a cricket player’s display board. The information of the
cricketer can be (not limited to) Name, Age, Country, Category (Batsman, Bowler, Wicket keeper,
All-rounder), Number of ODI’s played, Number of International 20-20’s played. Display
following.
a) Number of batsman of a particular country
b) Sort the Batsman as per the average batting score(Bubble/insertion sort)
c) Batsman with highest average score (Binary search)
d) Number of bowlers of a particular country
e) The bowler that has taken a maximum no of wickets
f) Show particular players the entire “Display board information”
Delete/Modify the record*/



#include <stdio.h>
#include <string.h>
struct menu
{
    char name[20];
    char country[20];
    char category[20];
    int odi, t20;
    int age, run, wickets;
    float avg_score;
} player[20],t;


int main()
{
    int n;
    printf("Enter number of cricketers:");
    scanf("%d", &n);
    printf("\n Enter players information");
    for(int i=0; i<n; i++)
    {
        printf("\n[%d]enter the name:", i+1);
        scanf("%s", player[i].name);
        printf("Enter his country:");
        scanf("%s", player[i].country);
        printf("Category(Batsman, Bowler, Wicket keeper,All-rounder):");
        scanf("%s", player[i].category);
        printf("Age:");
        scanf("%d", &player[i].age);
        printf("enter run:");
        scanf("%d", &player[i].run);
        printf("Number of wickets taken:");
        scanf("%d", &player[i].wickets);
        printf("Number of odi played:");
        scanf("%d", &player[i].odi);
        printf("Number of T20 played:");
        scanf("%d", &player[i].t20);
        printf("Enter average score:");
        scanf("%f", &player[i].avg_score);
    }
    printf("\n********************MENU********************");
    while(n>0)
    {
        printf("\n1) Number of batsman of a particular country\n2) Sort the Batsman as per the average batting score(Bubble/insertion sort)\n3) Batsman with highest average score (Binary search)\n4) Number of bowlers of a particular country\n5) The bowler that has taken a maximum no of wickets\n6) Show particular players the entire “Display board information”\n7)End\n");
        int k;
        scanf("%d", &k);
        if (k == 7)
        {
            printf("Program  ended");
            break;
        }
        switch(k)
        {
        case 1 :
        {
            int ans=0;
            char temp[20];
            printf("Enter name of country: ");
            scanf("%s",temp);
            for(int i=0; i<n; i++)
            {
                if(strcmp(temp,player[i].country)==0 && (strcmp(player[i].category,"Batsman")==0 || strcmp(player[i].category,"All_Rounder")==0 ))
                    ans++;
            }
            printf("Number of batsman of given country is %d\n",ans);
            break;
        }

        case 2 :
        {
            int i, j;

            for(i=0; i<n; i++)
            {
                for(j=0; j<n-1; j++)
                {
                    if(player[j].avg_score>player[j+1].avg_score)
                    {
                        t=player[j];
                        player[j]=player[j+1];
                        player[j+1]=t;
                    }
                }
            }
            printf("\nPLAYER\tAVERAGE SCORE");
            for(i=0; i<n; i++)
            {
                printf("\n%s\t%f", player[i].name, player[i].avg_score);
            }
        }
        break;

        case 3 :
        {

            int max=player[0].avg_score;
            int ans=0;
            for(int i=1; i<n; i++)
            {
                if (player[i].avg_score>max)
                {
                    max=player[i].avg_score;
                    ans=i;
                }
                else
                {
                    break;
                }
            }
            printf("\nPlayer with highest average score");
            printf("\nName:%s\nAvg_score:%.2f", player[ans].name, player[ans].avg_score);
        }
        break;
        case 4 :
        {

            int ans=0;
            char temp[20];
            printf("Enter name of country: ");
            scanf("%s",temp);
            for(int i=0; i<n; i++)
            {
                if(strcmp(temp,player[i].country)==0 && (strcmp(player[i].category,"Bowler")==0 || strcmp(player[i].category,"All_Rounder")==0 ))
                    ans++;
            }
            printf("Number of Bowler of given country is %d\n",ans);
        }
        break;
        case 5 :
        {
            int i, j;

            for(i=0; i<n; i++)
            {
                for(j=0; j<n-1; j++)
                {
                    if(player[j].wickets>player[j+1].wickets)
                    {
                        t=player[j];
                        player[j]=player[j+1];
                        player[j+1]=t;
                    }
                }
            }
            printf("\nPLAYER\tWICKETS");
            for(i=0; i<n; i++)
            {
                printf("\n%s\t    %d", player[i].name, player[i].wickets);
            }
        }
        break;
        case 6 :
        {
            int p;
            printf("\nEnter the player number whose details to be displayed:");
            scanf("%d", &p);

            printf("\nName\tAge\tCountry\tCategory\tODI\tT20\tAvg_Score\tWickets\tRuns");
            printf("\n%s\t%d\t%s\t%s\t       %d\t%d\t%.2f\t%d\t%d", player[p-1].name, player[p-1].age,player[p-1].country, player[p-1].category, player[p-1].odi, player[p-1].t20, player[p-1].avg_score, player[p-1].wickets, player[p-1].run);
        }

        break;
        default:
            printf("Invalid option");
            break;


        }
    }


    return 0;
}
