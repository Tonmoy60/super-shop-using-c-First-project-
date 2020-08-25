#include<stdio.h>


struct Product
{
    int id;
    char name[15];
    double price;
};

struct Product inputProduct()
{
    struct Product pt;
    printf("Insert product name: ");
    gets(pt.name);
    printf("Insert product ID: ");
    gets(pt.id);
    printf("Insert product price: ");
    scanf("%lf",&pt.price);
    //printf("Insert quantity of the product: ");
    //scanf("%d",&pt.qnty);
    return pt;
};

void printProduct(struct Product pt)
{
    printf("Name: ");
    puts(pt.name);
    printf("ID: ");
    puts(pt.id);
    printf("price: %lf",pt.price);
}
void writeProduct(struct Product pt)
{
    FILE *fp2;
    fp2=fopen(pt.id,"w");
    fputs(pt.name,fp2);
    fputs("\n",fp2);
    fputs(pt.id,fp2);
    fputs("\n",fp2);
    fprintf(fp2, "%lf",pt.price);
    fputs("\n",fp2);
    fclose(fp2);
}
struct Product readProduct(char id[100])
{
    FILE *fp;
    fp=fopen(id,"r");
    struct Product p;
    fgets(p.name,99,fp);
    fgets(p.id,99,fp);
    fscanf(fp,"%lf",&p.price );
    fclose(fp);
    return p;

}
int main()
{
    while(1)
    {
        printf("Press 1 to Insert product \n");
        printf("Press 2 to print product \n");
        printf("Press 0 to exit the program\n");

        int choice;
        char str[2];
        scanf("%d",&choice);
        gets(str);

        if(choice==0)
        {
            break;

        }
        else if(choice==1)
        {
            struct Product pt;
            pt=inputProduct();
            writeProduct(pt);
        }
        else if(choice==2)
        {
            char product_id[100];
            gets(product_id);
            struct Product pr;
            pr=readProduct(product_id);
            printProduct(pr);
        }
    }
    return 0;

}
