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



#include<stdio.h>
#include<string.h>

struct player
{
    char name[20];
    int age;
    char country[20];
    char category[20];
    int odi;
    int twenty_20;
    float avg_score;
    int wicket;
};

void swap(int i,int j,struct player a[])
{
    char name[20];  
    strcpy(name,a[i].name);
    strcpy(a[i].name,a[j].name);
    strcpy(a[j].name,name);

    int age = a[i].age;
    a[i].age = a[j].age;
    a[j].age = age;

    char country[20];
    strcpy(country,a[i].country);
    strcpy(a[i].country,a[j].country);
    strcpy(a[j].country,country);

    char category[20];
    strcpy(category,a[i].category);
    strcpy(a[i].category,a[j].category);
    strcpy(a[j].category,category);

    int odi = a[i].odi;
    a[i].odi = a[j].odi;
    a[j].odi = odi;

    int temp = a[i].twenty_20;
    a[i].twenty_20 = a[j].twenty_20;
    a[j].twenty_20 = temp;

    float score = a[i].avg_score;
    a[i].avg_score = a[j].avg_score;
    a[j].avg_score = score;

    int wicket = a[i].wicket;
    a[i].wicket = a[j].wicket;
    a[j].wicket = wicket;

}

int main()
{
    int n,ans;
    float temp1;
    int temp2;
    char search[20];
    char temp[20];
    printf("Enter number of players: ");
    scanf("%d",&n);

    struct player a[n];
    
    for(int i=0;i<n;i++)
    {
        printf("Enter name of player: ");
        scanf("%s",a[i].name);
        printf("Enter age of player: ");
        scanf("%d",&a[i].age);
        printf("Enter country of player:");
        scanf("%s",a[i].country);
        printf("Enter category of player: ");
        scanf("%s",a[i].category);
        printf("Enter number of ODI's palyed: ");
        scanf("%d",&a[i].odi);
        printf("Enter number of 20-20's played: ");
        scanf("%d",&a[i].twenty_20);
        printf("Enter average score: ");
        scanf("%f",&a[i].avg_score);
        printf("Enter number of wickets taken: ");
        scanf("%d",&a[i].wicket);
    }

    int choice;
    do
    {
        printf("______Menu______\n");
        printf("Select what you want to do: \n");
        printf("1. Display all players.\n");
        printf("2. Display number of batsman of particular country.\n");
        printf("3. Sort as per the average batting score\n");
        printf("4. Display batsman with highest average batting score.\n");
        printf("5. Display number of bowlers of particular country.\n");
        printf("6. Display bowlers with maximum wickets.\n");
        printf("7. Display details of particular player.\n");
        printf("8. Exit\n");

        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
            printf("____________________\n");
            printf("Name\tAge\tCountry\tCategory\tODI\t20-20\tAvgScore\tWickets\n");
            for(int i=0;i<n;i++)
            {
                printf("%s\t%d\t%s\t%s\t\t%d\t%d\t%f\t%d\n",a[i].name,a[i].age,a[i].country,a[i].category,a[i].odi,a[i].twenty_20,a[i].avg_score,a[i].wicket);
            }
            break;
            
            case 2:
            printf("____________________\n");
            ans=0;
            printf("Enter name of country: ");
            scanf("%s",temp);
            for(int i=0;i<n;i++)
            {
                if(strcmp(temp,a[i].country)==0 && strcmp(a[i].category,"batsman")==0)
                    ans++;
            }
            printf("Number of batsman of given country is %d\n",ans);
            break;
            
            case 3:
            printf("____________________\n");
            for(int i=0;i<n;i++)
            {
                for(int j=i+1;j<n;j++)
                {
                    if(a[j].avg_score > a[i].avg_score)
                        swap(i,j,a);
                }
            }
            printf("Name\tAge\tCountry\tCategory\tODI\t20-20\tAvgScore\tWickets\n");
            for(int i=0;i<n;i++)
            {
                printf("%s\t%d\t%s\t%s\t\t%d\t%d\t%f\t%d\n",a[i].name,a[i].age,a[i].country,a[i].category,a[i].odi,a[i].twenty_20,a[i].avg_score,a[i].wicket);
            }
            break;

            case 4:
            temp1 = a[0].avg_score;
            ans = 0;
            for(int i=1;i<n;i++)
            {
                if(a[i].avg_score>temp1)
                {
                    temp1=a[i].avg_score;
                    ans=i;
                }
            }
            printf("____________________\n\n");
            printf("Batsman with highest average score: %s\n",a[ans].name);
            break;

            case 5:
            printf("____________________\n");
            ans = 0;
            printf("Enter name of country: ");
            scanf("%s",temp);
            for(int i=0;i<n;i++)
            {
                if(strcmp(temp,a[i].country)==0 && strcmp(a[i].category,"bowler")==0)
                    ans++;
            }
            printf("Number of bowlers of given country is %d\n",ans);
            break;

            case 6:
            temp2 = a[0].wicket;
            ans = 0;
            for(int i=1;i<n;i++)
            {
                if(a[i].wicket>temp2)
                {
                    temp2 = a[i].wicket;
                    ans=i;
                }
            }
            printf("____________________\n\n");
            printf("Bowler with maximum number of wickets: %s\n",a[ans].name);
            break;

            case 7:
            printf("____________________\n");
            printf("Enter name of player: ");
            scanf("%s",search);
            for(int i=0;i<n;i++)
            {
                if(strcmp(a[i].name,search)==0)
                {
                    ans = i;
                    break;
                }
            }
            printf("\n");
            printf("Name of player: %s\n",a[ans].name);
            printf("Age of player: %d\n",a[ans].age);
            printf("Country of player: %s\n",a[ans].country);
            printf("Category of player: %s\n",a[ans].category);
            printf("Number of ODI's played: %d\n",a[ans].odi);
            printf("Number of 20-20's played: %d\n",a[ans].twenty_20);
            printf("Average score: %f\n",a[ans].avg_score);
            printf("Number of wickets taken: %d\n\n",a[ans].wicket);
            break;

            case 8:
            break;
                
            default:
            printf("Enter valid number.\n");
            break;
        }
    } while (choice!=8);

    return 0;
}
