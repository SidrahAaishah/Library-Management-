#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#define max 100
#define max_borrowed_book 5
struct book
{
    char title[max];
    char author[max];
    int ISBN;
    int pub_year;
    char genre[max];
    int quantity;
    char availability[max];
    struct book *next;
}*head_book;
struct user
{
    char name[max];
    char id[max];
    long int mobile;
    char member_status[max];
    struct borrowed_book *head_borrowed_book;
    int num_borrowed_book;
    struct user *next;
}*head_user=NULL;
// struct user *users[max];
int num_user=0;
// int top=-1, top_borr_book[max];
struct date
{
    int day;
    int month;
    int year;
};
struct borrowed_book
{
    char title[max];
    int ISBN;
    struct date borrowed_date;
    struct date return_date;
    struct borrowed_book *next;
};
void add_book()
{
    struct book *new = (struct book *)malloc(sizeof(struct book));
    struct book *temp;
    printf("Title of book: ");
    scanf("%s",new->title);
    printf("Author: ");
    scanf("%s",new->author);
    printf("ISBN no. : ");
    scanf("%d",&new->ISBN);
    printf("Publication year: ");
    scanf("%d",&new->pub_year);
    printf("Genre: ");
    scanf("%s",new->genre);
    printf("Quantity: ");
    scanf("%d",&new->quantity);
    printf("Avalaibilty status: ");
    scanf("%s",new->availability);
    if(head_book==NULL)
    {
        head_book=new;
        new->next=NULL;
    }
    else
    {
        temp=head_book;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=new;
        new->next=NULL;
    }
}
void update_book()
{
    char title[max];
    printf("Enter book title to update: ");
    scanf("%s",title);
    struct book *temp=head_book;
    int flag=0;
    while(temp!=NULL)
    {
        if(temp->title==title)
        {
            flag=1;
            break;
        }
    }
    if(flag==1)
    {
        int n=0;
        while(n!=8)
        {
            printf("1.Title\n2.Author\n3.ISBN No.\n4.Publication year\n5.Genre\n6.Quantity\n7.Availability\n8.Exit");
            printf("Choose what to update: ");
            scanf("%d",&n);
            switch(n)
            {
                case 1:
                    printf("Enter new title of book: ");
                    scanf("%s",temp->title);
                    break;
                case 2:
                    printf("Enter new author: ");
                    scanf("%s",temp->author);
                    break;
                case 3:
                    printf("Enter new ISBN No. : ");
                    scanf("%d",&temp->ISBN);
                    break;
                case 4:
                    printf("Enter new Publication year: ");
                    scanf("%d",&temp->pub_year);
                    break;  
                case 5:
                    printf("Enter new genre: ");
                    scanf("%s",temp->genre);
                    break;
                case 6:
                    printf("Enter new quantity: ");
                    scanf("%d",&temp->quantity);
                    break;
                case 7:
                    printf("Enter  availability status: ");
                    scanf("%s",temp->availability);
                    break;
                case 8:
                    exit(1);
                default :
                    printf("Choose valid option\n");
            }
        }
    }
}
void add_user()
{
    if(num_user==max)
    {
        printf("Library is full\n");
    }
    else
    {
        num_user++;
        struct user *new_user = (struct user *)malloc(sizeof(struct user));
        printf("Enter name: ");
        scanf("%s",new_user->name);
        printf("Enter id: ");
        scanf("%s",new_user->id);
        printf("Enter mobile No. : ");
        scanf("%ld",&new_user->mobile);
        printf("1.Platinum(3 Year plan)\n2.Gold(2 Year plan)\n3.Silver(1 Year plan)\n");
        int n=0;
        while(n<1 || n>3)
        {
            printf("Choose plan: ");
            scanf("%d",&n);
            switch(n)
            {
                case 1:
                    strcpy(new_user->member_status, "Platinum user");
                    break;
                case 2:
                    strcpy(new_user->member_status, "Gold user");
                    break;
                case 3:
                    strcpy(new_user->member_status, "Silver user");
                    break;
                default:
                    printf("Choose valid plan\n");
            }
        }
        new_user->head_borrowed_book=NULL;
        new_user->num_borrowed_book=0;
        if(head_user==NULL)
        {
            new_user->next=NULL;
            head_user=new_user;
        }
        else
        {
            new_user->next=head_user;
            head_user=new_user;
        }
    }
}
void update_user()
{

}
void borrowBook()
{
    char id[max];
    int flag=0;
    struct user *ptr=head_user;
    while(flag!=1)
    {
        printf("Enter user id: ");
        scanf("%s",id);
        
        while(ptr!=NULL)
        {
            if(ptr->id==id)
            {
                flag=1;
                break;
            }
            ptr=ptr->next;
        }
        if(flag==1)
        {
            if(ptr->num_borrowed_book==max_borrowed_book)
            {
                printf("You have reached the limit of borrowing book\n");
                exit(1);
            }
            else
            {
                struct borrowed_book *new_borr_book = malloc(sizeof(struct borrowed_book));
                char title[max];
                printf("Enter title of book: ");
                scanf("%s",title);
                struct book *temp=head_book;
                int f=0;
                while(temp!=NULL)
                {
                    if(temp->title==title)
                    {
                        f=1;
                        temp->quantity--;
                        strcpy(new_borr_book->title , temp->title);
                        new_borr_book->ISBN = temp->ISBN;
                        struct date d1;
                        printf("Enter date\n");
                        printf("Day: ");
                        scanf("%d",new_borr_book->borrowed_date.day);
                        printf("Month: ");
                        scanf("%d",new_borr_book->borrowed_date.month);
                        printf("Year: ");
                        scanf("%d",new_borr_book->borrowed_date.year);
                        if(ptr->head_borrowed_book==NULL)
                        {
                            new_borr_book->next = NULL;
                            ptr->head_borrowed_book = new_borr_book;
                        }
                        else
                        {
                            new_borr_book->next = ptr->head_borrowed_book;
                            ptr->head_borrowed_book = new_borr_book;
                        }
                        ptr->num_borrowed_book++;
                        break;
                    }
                    temp=temp->next;
                }
                if(f==0)
                printf("Enter valid book title\n");
            }
            
        }
        else
        {
            printf("Enter valid user id\n");
        }
    }  
}
void returnBook()
{
    char id[max];
    int flag=0;
    struct user *ptr=head_user;
    while(flag!=1)
    {
        printf("Enter user id : ");
        scanf("%s",id);
        while(ptr!=NULL)
        {
            if(ptr->id==id)
            {
                flag=1;
                break;
            }
            ptr=ptr->next;
        }
        if(flag==1)
        {
            if(ptr->num_borrowed_book==0)
            {
                printf("There is book you have borrowed\n");
                exit(1);
            }
            else
            {
                char title[max];
                printf("Enter title of book: ");
                scanf("%s",title);
                struct book *temp=head_book;
                int f=0;
                while(temp!=NULL)   
                {
                    if(temp->title==title)
                    {
                        f=1;
                        struct borrowed_book *temp_head = ptr->head_borrowed_book;
                        while(temp_head!=NULL)
                        {
                            if(temp_head->title == title)
                            {
                                printf("Enter date\n");
                                printf("Day: ");
                                scanf("%d",temp_head->return_date.day);
                                printf("Month: ");
                                scanf("%d",temp_head->return_date.month);
                                printf("Year: ");
                                scanf("%d",temp_head->return_date.year);
                                break;
                            }
                        }
                        temp->quantity++;
                        ptr->num_borrowed_book--;
                        break;
                    }
                    temp=temp->next;
                }
                

            }
        }
        else
        {
            printf("Enter valid user id\n");
        }

    }
}
void main()
{
    int t=2;
    while(t--)
    {
        add_user();
    }
    printf("\n");
    struct user *temp = head_user;
    while(temp!=NULL)
    {
        printf("Name: %s\n",temp->name);
        printf("Id: %s\n",temp->id);
        printf("Mobile: %ld\n",temp->mobile);
        printf("Member status: %s\n",temp->member_status);
        printf("Number of books borrowed: %d\n",temp->num_borrowed_book);
        temp=temp->next;
    }
}
