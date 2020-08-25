#include <stdio.h>

struct Product
{
    char name[30];
    int code;
    int price;
    int quantity;

};

struct Membership
{
    char member_name[30];
    int member_code;
    int member_password;
    int Total_expenditure;
    int member_point;
};

int Member_Registration(struct Membership member[], int member_num)
{
    // Means First time registration


    printf("Member name: \n");
    scanf("%s", member[member_num].member_name);


    printf("Membership code(Automated): %d\n", member_num+1);
    member[member_num].member_code = member_num+1;

    printf("Input pass: \n");
    scanf("%d", &member[member_num].member_password);
    member[member_num].Total_expenditure=0;
    member[member_num].member_point = 20;


    return member_num+1;
}

void Member_Display(struct Membership member[],int member_num)
{
    if(member_num==0)
    {
        printf("\n\n\n\n\nMember List is empty!!!!\n\n\n\n");
    }
    else
    {
        int i;
        printf("             ####  Member List #### \n");
        printf("------------------------------------------------------------------------------\n");
        printf("S.N.|    NAME           |   CODE    |   Total_Expenditure   |    Member_points \n");
        printf("------------------------------------------------------------------------------\n");
        for (i = 0; i < member_num; i++)
        {
            printf(" %d      %-15s      %-d             %-d                       %-d\n", i + 1, member[i].member_name, member[i].member_code, member[i].Total_expenditure, member[i].member_point );
        }
        printf("------------------------------------------------------------------------------\n");
    }
}

void Option(struct Product item[], int n, struct Membership member[], int member_num)
{
    int choice;
    while(1)
    {
        printf("Press 1 to register new products.\n");
        printf("Press 2 to register new Member.\n");
        printf("Press 3 to display existing products.\n");
        printf("Press 4 to display Member List.\n");
        printf("Press 5 to sell an products.\n");
        printf("Press 0 to exit.\n");

        printf("Please Enter your choice: ");
        scanf("%d", &choice);
        if(choice == 1)
        {
            n = Register_Product(item, n);
            printf("\n\n\nEntry complete!!!!! Thank You!!!!!!\n\n\n\n");
        }
        else if(choice==2)
        {
            member_num = Member_Registration(member, member_num);
            printf("\n\n\nEntry complete!!!!! Thank You %s !!!!!!\n\n\n\n", member[member_num-1].member_name);

        }
        else if(choice == 3)
        {
            Display_Product(item, n);

        }
        else if(choice == 4)
        {
            Member_Display(member, member_num);
        }
        else if(choice == 5)
        {
            Sell_Product(item, n, member, member_num);
        }
        else if(choice == 0)
        {
            break;
        }

    }
}
int Register_Product(struct Product item[],int n)
{
    int i , c, j, new_n;
    // Means First time registration

    printf("\n\nEnter number of items:");
    scanf("%d", &new_n);


    for (i = n; i < n+new_n; i++)
    {

        printf("Item name: \n");
        scanf("%s", item[i].name);

a:
        printf("Item code: \n");
        scanf("%d", &c);
        for(j=0; j<50; j++)
        {
            if(item[j].code==c)
            {
                printf("\n\n\nCode Already used. Please Use a different code\n\n\n");
                goto a;
            }
        }
        item[i].code = c;

        printf("Quantity: \n");
        scanf("%d", &item[i].quantity);

        printf("price: \n");
        scanf("%d",  &item[i].price);



    }
    return n+new_n;
}

void Display_Product(struct Product item[], int n)
{
    if(n==0)
    {
        printf("\n\n\n\n\nThe inventory is empty!!!!\n\n\n\n");
    }
    else
    {
        int i;
        printf("             ####  Product List #### \n");
        printf("------------------------------------------------------------------\n");
        printf("S.N.|    NAME           |   CODE   |  QUANTITY |  PRICE \n");
        printf("------------------------------------------------------------------\n");
        for (i = 0; i < n; i++)
        {
            printf("%d     %-15s        %-d          %-5d      %d\n", i + 1, item[i].name, item[i].code, item[i].quantity, item[i].price);
        }
        printf("------------------------------------------------------------------\n");
    }
}


void Sell_Product(struct Product item[], int n, struct Membership member[], int member_num)
{

    int card_code, x, i, M=-30, pass , flag=0;
    int selling_code,selling_quantity;
    int total_price=0;
    Display_Product(item, n );
    if(n==0)
    {
        printf("\n\n!!!!!!!!!!!No product in the inventory to sell!!!!!!!!!!!!!\n\n");
        return 0;
    }
    printf("!!!!!!!!!!If membership card exist, Please input 1, otherwise 0!!!!!!!!!!");
    printf("Input: ");
    scanf("%d", &x);
    if(x==1)
    {
        printf("Input membership code: ");

        scanf("%d", &card_code);
        for(i=0; i<member_num; i++)
        {
            if(card_code == member[i].member_code)
            {
                printf("Enter password: ");
                scanf("%d", &pass);
                if(member[i].member_password == pass)
                {
                    printf("\n\nThank You %s for shopping with us!!! You will have %d taka discount on any amount shopping.\n\n", member[i].member_name, member[i].member_point);
                    M= i;
                    flag=100;
                }
                else
                {
                    printf("\n\n!!!!!!!!!!!!!Password invalid!!!!!!!!!!!!!!!!!\n\n");
                    return 0;
                }
            }
            else
            {
                printf("\n\n!!!!!!!!!!!!!Invalid code!!!!!!!!!!!!!!!!!\n\n");
                return 0;
            }
        }

    }







    printf("    !!!!!!!!!!!!!!!!!Selling Platform!!!!!!!!!!!!!\n");
    printf("\n\nEnter Product Code For Selling: \n\n");
    scanf("%d", &selling_code);
    for(i=0; i<n; i++)
    {
        if(item[i].code==selling_code)
        {

            printf("Enter quantity of the order: \n");
            scanf("%d", &selling_quantity);
            if(selling_quantity > item[i].quantity)
            {
                printf("\nError!!! Not Enough Quantity in the inventory!!!!\n");
                return 0;
            }
            else
            {


                if(flag==100)
                {
                    total_price = (item[i].price*selling_quantity)-member[M].member_point;
                    member[M].Total_expenditure = total_price + member[M].Total_expenditure;
                    if(total_price>1000)
                    {
                        member[M].member_point = member[M].member_point +50;
                    }

                }
                else
                {
                    total_price = item[i].price*selling_quantity;
                }
                printf("\n\n!!!!Sold!!!!!\nTotal Price Paid: %d\n\n\n", total_price);
                item[i].quantity = item[i].quantity - selling_quantity;
                return 0;



            }

        }

    }



    if(i==n)
    {
        printf("Product Does Not Exist......\n\n");

    }

}



int main()
{
    struct Product item[500];
    struct Membership member[500];
    int n=0, i , j, choice, member_num = 0;

    for(i=0; i<500; i++)
    {
        item[i].code=0;
        member[i].member_code=0;

    }
    Option(item, n, member, member_num);


}


