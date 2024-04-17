#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 100
#define max_borrowed_book 5
#define max_num_book 1000
#define shelf_size 5
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
} *head_book;
struct user
{
    char name[max];
    char id[max];
    long int mobile;
    char member_status[max];
    struct borrowed_book *head_borrowed_book;
    int num_borrowed_book;
    struct user *next;
} *head_user = NULL;
// struct user *users[max];
int num_user = 0;
int num_book = 0;
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
struct shelf
{
    struct book *a[shelf_size][shelf_size];//a 2d array like any library shelf
    int col;//the row and column number of the last book added
    int row;
} s1, s2;//two shelf
void addbooktoshelf(struct book *book)
{
    if (s2.col > 4 && s2.row > 4)
    {
        printf("THE SHELVES ARE FULL PLEASE ADD NEW SHELVES \n");
        return;
    }
    num_book++;
    struct book *new = (struct book *)malloc(sizeof(struct book));
    struct book *temp;
    printf("Title of book: ");
    scanf(" %[^\n]s", new->title);
    printf("Author: ");
    scanf(" %[^\n]s", new->author);
    printf("ISBN no. : ");
    scanf("%d", &new->ISBN);
    printf("Publication year: ");
    scanf("%d", &new->pub_year);
    printf("Genre: ");
    scanf(" %[^\n]s", new->genre);
    printf("Quantity: ");
    scanf("%d", &new->quantity);
    printf("Avalaibilty status: ");
    scanf(" %[^\n]s", new->availability);
    if (head_book == NULL)
    {
        head_book = new;
        new->next = NULL;
    }
    else
    {
        temp = head_book;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new;
        new->next = NULL;
    }
    if (s1.col < shelf_size-1 || s1.row < shelf_size-1)
    {
        if (s1.col < shelf_size-1)
        {
            s1.col++;
            s1.a[s1.row][s1.col] = new;
        }
        else
        {
            s1.row++;
            s1.col = 0;
            s1.a[s1.row][s1.col] = new;
        }
    }
    else
    {
        if (s2.col < shelf_size-1)
        {
            s2.col++;
            s2.a[s2.row][s2.col] = new;
        }
        else
        {
            s2.row++;
            s2.col = 0;
            s2.a[s2.row][s2.col] = new;
        }
    }
}
void add_book()
{
    if (num_book == max_num_book)
    {
        printf("Library has reached it's books limit\n");
    }
    else
    {
        num_book++;
        struct book *new = (struct book *)malloc(sizeof(struct book));
        struct book *temp;
        printf("Title of book: ");
        scanf(" %[^\n]s", new->title);
        printf("Author: ");
        scanf(" %[^\n]s", new->author);
        printf("ISBN no. : ");
        scanf("%d", &new->ISBN);
        printf("Publication year: ");
        scanf("%d", &new->pub_year);
        printf("Genre: ");
        scanf(" %[^\n]s", new->genre);
        printf("Quantity: ");
        scanf("%d", &new->quantity);
        printf("Avalaibilty status: ");
        scanf(" %[^\n]s", new->availability);
        if (head_book == NULL)
        {
            head_book = new;
            new->next = NULL;
        }
        else
        {
            temp = head_book;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = new;
            new->next = NULL;
        }
    }
}
void update_book()
{
    char title[max];
    printf("Enter book title to update: ");
    scanf(" %[^\n]s", title);
    struct book *temp = head_book;
    int flag = 0;
    while (temp != NULL)
    {
        if (strcmp(temp->title, title) == 0)
        {
            flag = 1;
            break;
        }
    }
    if (flag == 1)
    {
        int n = 0;
        while (n != 8)
        {
            printf("1.Title\n2.Author\n3.ISBN No.\n4.Publication year\n5.Genre\n6.Quantity\n7.Availability\n8.Exit");
            printf("Choose what to update: ");
            scanf("%d", &n);
            switch (n)
            {
            case 1:
                printf("Enter new title of book: ");
                scanf(" %[^\n]s", temp->title);
                break;
            case 2:
                printf("Enter new author: ");
                scanf(" %[^\n]s", temp->author);
                break;
            case 3:
                printf("Enter new ISBN No. : ");
                scanf("%d", &temp->ISBN);
                break;
            case 4:
                printf("Enter new Publication year: ");
                scanf("%d", &temp->pub_year);
                break;
            case 5:
                printf("Enter new genre: ");
                scanf(" %[^\n]s", temp->genre);
                break;
            case 6:
                printf("Enter new quantity: ");
                scanf("%d", &temp->quantity);
                break;
            case 7:
                printf("Enter  availability status: ");
                scanf(" %[^\n]s", temp->availability);
                break;
            case 8:
                exit(1);
            default:
                printf("Choose valid option\n");
            }
        }
    }
}
void add_user()
{
    if (num_user == max)
    {
        printf("Library is full\n");
    }
    else
    {
        num_user++;
        struct user *new_user = (struct user *)malloc(sizeof(struct user));
        printf("Enter name: ");
        scanf(" %[^\n]s", new_user->name);
        printf("Enter id: ");
        scanf(" %[^\n]s", new_user->id);
        printf("Enter mobile No. : ");
        scanf("%ld", &new_user->mobile);
        printf("1.Platinum(3 Year plan)\n2.Gold(2 Year plan)\n3.Silver(1 Year plan)\n");
        int n = 0;
        while (n < 1 || n > 3)
        {
            printf("Choose plan: ");
            scanf("%d", &n);
            switch (n)
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
        new_user->head_borrowed_book = NULL;
        new_user->num_borrowed_book = 0;
        if (head_user == NULL)
        {
            new_user->next = NULL;
            head_user = new_user;
        }
        else
        {
            new_user->next = head_user;
            head_user = new_user;
        }
    }
}
void update_user()
{
    char id[max];
    int flag = 0, ch = 0;
    struct user *ptr = head_user;
    while (flag != 1)
    {
        printf("Enter user id: ");
        scanf(" %[^\n]s", id);
        while (ptr != NULL)
        {
            if (strcmp(ptr->id, id) == 0)
            {
                flag = 1;
                break;
            }
            ptr = ptr->next;
        }
        if (flag == 1)
        {
            while (ch != 5)
            {
                printf("1.Name\n2.ID\n3.Mobile\n4.Membership Status\n5.Exit\n");
                printf("Choose what to update: ");
                scanf("%d", &ch);
                switch (ch)
                {
                case 1:
                    printf("Enter new name: ");
                    scanf(" %[^\n]s", ptr->name);
                    break;
                case 2:
                    printf("Enter new id: ");
                    scanf(" %[^\n]s", ptr->id);
                    break;
                case 3:
                    printf("Enter new mobile: ");
                    scanf("%ld", &ptr->mobile);
                    break;
                case 4:
                    printf("Enter new Membership Status: ");
                    scanf(" %[^\n]s", ptr->member_status);
                    break;
                case 5:
                    exit(1);
                default:
                    printf("Choose valid option\n");
                }
            }
        }
        else
        {
            printf("Please enter valid user id\n");
        }
    }
}

void borrowBook()
{
    char id[max];
    int flag = 0;
    struct user *ptr = head_user;
    while (flag != 1)
    {
        printf("Enter user id: ");
        scanf(" %[^\n]s", id);

        while (ptr != NULL)
        {
            if (strcmp(ptr->id, id) == 0)
            {
                flag = 1;
                break;
            }
            ptr = ptr->next;
        }
        if (flag == 1)
        {
            if (ptr->num_borrowed_book == max_borrowed_book)
            {
                printf("You have reached the limit of borrowing book\n");
                exit(1);
            }
            else
            {
                struct borrowed_book *new_borr_book = malloc(sizeof(struct borrowed_book));
                char title[max];
                printf("Enter title of book: ");
                scanf(" %[^\n]s", title);
                struct book *temp = head_book;
                int f = 0;
                while (temp != NULL)
                {
                    if (strcmp(temp->title, title) == 0)
                    {
                        f = 1;
                        temp->quantity--;
                        strcpy(new_borr_book->title, temp->title);
                        new_borr_book->ISBN = temp->ISBN;
                        struct date d1;
                        printf("Enter date\n");
                        printf("Day: ");
                        scanf("%d", &new_borr_book->borrowed_date.day);
                        printf("Month: ");
                        scanf("%d", &new_borr_book->borrowed_date.month);
                        printf("Year: ");
                        scanf("%d", &new_borr_book->borrowed_date.year);
                        new_borr_book->return_date.day = 0;
                        new_borr_book->return_date.month = 0;
                        new_borr_book->return_date.year = 0;
                        if (ptr->head_borrowed_book == NULL)
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
                    temp = temp->next;
                }
                if (f == 0)
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
    int flag = 0;
    struct user *ptr = head_user;
    while (flag != 1)
    {
        printf("Enter user id : ");
        scanf(" %[^\n]s", id);
        while (ptr != NULL)
        {
            if (strcmp(ptr->id, id) == 0)
            {
                flag = 1;
                break;
            }
            ptr = ptr->next;
        }
        if (flag == 1)
        {
            if (ptr->num_borrowed_book == 0)
            {
                printf("There is no book you have borrowed\n");
                exit(1);
            }
            else
            {
                char title[max];
                printf("Enter title of book: ");
                scanf(" %[^\n]s", title);
                struct book *temp = ptr->head_borrowed_book;
                int f = 0;
                while (temp != NULL)
                {
                    if (strcmp(temp->title, title) == 0)
                    {
                        f = 1;
                        struct borrowed_book *temp_head = ptr->head_borrowed_book;
                        while (temp_head != NULL)
                        {
                            if (strcmp(temp_head->title, title) == 0)
                            {
                                printf("Enter date\n");
                                printf("Day: ");
                                scanf("%d", &temp_head->return_date.day);
                                printf("Month: ");
                                scanf("%d", &temp_head->return_date.month);
                                printf("Year: ");
                                scanf("%d", &temp_head->return_date.year);
                                break;
                            }
                        }
                        temp->quantity++;
                        ptr->num_borrowed_book--;
                        break;
                    }
                    temp = temp->next;
                }
            }
        }
        else
        {
            printf("Enter valid user id\n");
        }
    }
}
void show_borrow_history()
{
    char id[max];
    int flag = 0;
    struct user *ptr = head_user;
    struct borrowed_book *temp;
    int n = 1;
    while (flag != 1)
    {
        printf("Enter user id: ");
        scanf(" %[^\n]s", id);
        while (ptr != NULL)
        {
            if (strcmp(ptr->id, id) == 0)
            {
                flag = 1;
                break;
            }
            ptr = ptr->next;
        }
        if (flag == 1)
        {
            temp = ptr->head_borrowed_book;
            while (temp != NULL)
            {
                printf("Book %d\n", n);
                printf("Title:  %[^\n]s\n", temp->title);
                printf("ISBN: %d\n", temp->ISBN);
                printf("Borrowed date: %d - %d - %d\n", temp->borrowed_date.day, temp->borrowed_date.month, temp->borrowed_date.year);
                if (temp->return_date.day == 0)
                {
                    printf("Return date: Book is not returned yet\n");
                }
                else
                {
                    printf("Return date:  %d - %d - %d\n\n", temp->return_date.day, temp->return_date.month, temp->return_date.year);
                }
                n++;
                temp = temp->next;
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
    int ch = 0, n, m;
    while (ch != 3)
    {
        printf("Welcome to Central Library\n\n");
        printf("1.User\n2.Librarian\n3.Exit\n\n");
        printf("Choose your type: ");
        scanf("%d", &ch);
        printf("\n");
        switch (ch)
        {
        case 1:
            n = 0;
            while (n != 5)
            {
                printf("1.New user registration\n2.Update user info\n3.Borrow book\n4.Return book\n5.Show History\n6.Exit\n\n");
                printf("Choose option: ");
                scanf("%d", &n);
                switch (n)
                {
                case 1:
                    add_user();
                    printf("\n");
                    break;
                case 2:
                    update_user();
                    printf("\n");
                    break;
                case 3:
                    borrowBook();
                    printf("\n");
                    break;
                case 4:
                    returnBook();
                    printf("\n");
                    break;
                case 5:
                    show_borrow_history();
                    printf("\n");
                    break;
                case 6:
                    printf("\n");
                    break;
                default:
                    printf("Choose valid option\n\n");
                }
            }
            break;
        case 2:
            m = 0;
            while (m != 3)
            {
                printf("1.Add new book\n2.Update a book\n3.Exit\n\n");
                printf("Choose option: ");
                scanf("%d", &m);
                switch (m)
                {
                case 1:
                    add_book();
                    printf("\n");
                    break;
                case 2:
                    update_book();
                    printf("\n");
                    break;
                case 3:
                    printf("\n");
                    break;
                default:
                    printf("Choose valid option\n\n");
                }
            }
            break;
        case 3:
            exit(1);
            break;
        default:
            printf("Choose valid option\n\n");
        }
    }
    // int t=2;
    // while(t--)
    // {
    //     add_user();
    // }
    // printf("\n");
    // struct user *temp = head_user;
    // while(temp!=NULL)
    // {
    //     printf("Name: %s\n",temp->name);
    //     printf("Id: %s\n",temp->id);
    //     printf("Mobile: %ld\n",temp->mobile);
    //     printf("Member status: %s\n",temp->member_status);
    //     printf("Number of books borrowed: %d\n",temp->num_borrowed_book);
    //     temp=temp->next;
    // }
}
