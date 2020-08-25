#include<stdio.h>

struct login
{
    char name[30];
    char password[30];
    char cardnum[30];
};

regist()
{
    FILE*fp1;
    fp1=fopen("login.txt","w");

    struct login l;
    printf("Enter your Card number: ");
    scanf("%s",&l.cardnum);
    printf("Enter your username: ");
    scanf("%s",&l.name);
    printf("Enter your password: ");
    scanf("%s",&l.password);
    fwrite(&l,sizeof(l),1,fp1);
    fclose(fp1);

    printf("Successful!!");
    getch();
    system("CLS");
    login();
}

login()
{
    char u_name[30];
    char u_password[30];
    char u_cardnum[30];
    FILE*fp1;
    fp1=fopen("login.txt","r");
    struct login l;
    printf("Membership Card No: ");
    scanf("%s",&u_cardnum);
    printf("USERID: ");
    scanf("%s",&u_name);
    printf("PASSWORD: ");
    scanf("%s",&u_password);

    while(fread(&l,sizeof(l),1,fp1))
    {
        if(strcmp(u_name,l.name)==0 && strcmp(u_password,l.password)==0)
        {
            printf("Login successful!\n");
        } else
        {
            printf("Invalid name or password!\n");
        }
    }
    fclose(fp1);
}


int main()
{
    int choice;
    printf("Press 1 for register\n");
    printf("Press 2 for login\n");
    scanf("%d",&choice);
    switch(choice)
        {
        case 1:
            regist();
            break;
        case 2: login();
            break;
        }
            return 0;
    }


