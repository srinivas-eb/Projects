#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct book 
{
    char book_name[100];
    char letter; 
    char author_name[100];
    int pages;
    int no_books;
    int cost;
    struct book *next;
};

struct details
{
    char names[50];
    int passwords;
    char book_names[3][100];
    int n;
    struct details *next;
};

int main() 
{
    struct book *head = NULL;
    struct details *head1 = NULL;
    struct book *temp, *tail = NULL, *newbook;
    struct details *temp1, *tail1 = NULL, *newdetails;
    
    int password;
    char name[100], book[100];
    int enter = 0, login = 0, check = 0, search;

    printf("\t\t\t*********WELCOME TO OUR E-LIBRARY***********\n");
    printf("\t\t\tENTER YOUR CREDENTIALS TO ENTER INTO THE E-LIBRARY\n");

    while (1) {
        
        enter = 0;

        printf("\t\t\tARE YOU REGISTERED BEFORE IN THIS E-LIBRARY? ENTER 1 OR 0\n");
        scanf("%d", &login);
        getchar();

        if (login == 0) 
        {
            newdetails = (struct details *)malloc(sizeof(struct details));
            newdetails->next = NULL; 
            
            printf("\t\t\tPLEASE REGISTER\n");
            printf("\t\t\tENTER YOUR NAME\n");
            scanf("%[^\n]%*c", newdetails->names);
            newdetails->n = 0;

            printf("\t\t\tENTER YOUR PASSWORD WITH INTEGERS ONLY\n");
            scanf("%d", &newdetails->passwords);
            getchar();
            
            temp1 = head1;
            check = 0;
            while (temp1 != NULL)
            {
                if (strcmp(temp1->names, newdetails->names) == 0)
                {
                    printf("\n\t\t\tUSER NAME ALREADY EXISTS\n\t\t\tPLEASE TRY AGAIN\n");
                    check = 1;
                    break;
                }
                temp1 = temp1->next;
            }
            
            if (check == 1)
            {
                free(newdetails);
                continue;
            }
            system("clear");
            printf("\t\t\tYOUR CREDENTIALS ARE SUCCESSFULLY ADDED\n");
            if (head1 == NULL)
            {
                head1 = tail1 = newdetails;
            }
            else
            {
                tail1->next = newdetails;
                tail1 = newdetails;
            }
            continue;
        }

        if (login == 1) 
        {
            printf("\t\t\tENTER YOUR NAME \n");
            scanf("%[^\n]%*c", name);
            

            printf("\t\t\tENTER YOUR PASSWORD IN INTEGERS\n");
            scanf("%d", &password);
            getchar();

            temp1 = head1;
            while (temp1 != NULL)
            {
                if (strcmp(temp1->names, name) == 0 && temp1->passwords == password)
                {
                    printf("\n\t\t\tYOUR DETAILS ARE MATCHED\n");
                    printf("\n\t\t\tYOU SUCCESSFULLY LOGGED IN\n");
                    enter = 1;
                    break;
                }
                temp1 = temp1->next;
            }

            if (enter == 0) 
            {
                printf("\t\t\tYOUR IDENTITY IS NOT MATCHED WITH OUR DATA\n");
                printf("\t\t\tPLEASE REENTER YOUR CREDENTIALS OR SIGN IN\n");
                continue;
            }

            do 
            {
                printf("\n\t\t\tWELCOME %s\n", name);
                
                printf("\n\t\t\t1 : LIST OUT BOOKS IN THIS LIBRARY\n");
                printf("\n\t\t\t2 : ADD NEW BOOK INFORMATION\n");
                printf("\n\t\t\t3 : TO LIST ALL BOOKS OF A GIVEN AUTHOR\n");
                printf("\n\t\t\t4 : TO LIST OUT COUNT OF BOOKS IN THE LIBRARY\n");
                printf("\n\t\t\t5 : TO KNOW THE PREVIOUS MEMBERS VISITED TO THE LIBRARY\n");
                printf("\n\t\t\t6 : TAKE THE BOOK FROM THE LIBRARY\n");
                printf("\n\t\t\t7 : LIST OF BOOKS YOU HAVE TO RETURN TO THE LIBRARY\n");
                printf("\n\t\t\t8 : RETURN THE TAKEN BOOK\n");
                printf("\n\t\t\t9 : LOG OUT\n");
                printf("\n\n\n\t10:To no the details of the register candidates\n");
               
                printf("\n\t\t\tENTER THE ABOVE OPTION\t\t\t\n");
                scanf("%d", &search);
                getchar();

                switch (search) 
                {
                    case 1:
                        if (head == NULL) 
                        {
                            printf("\n\t\t\tTHERE ARE NO BOOKS IN THE LIBRARY\n");
                        } 
                        else 
                        {
                            temp = head;
                            while (temp != NULL) 
                            {
                                printf("BOOK NAME: %s, AUTHOR NAME: %s, NUMBER OF PAGES: %d, QUANTITY: %d, COST: %d\n",
                                       temp->book_name, temp->author_name, temp->pages, temp->no_books, temp->cost);
                                temp = temp->next;
                            }
                        }
                        break;

                    case 2:
                        newbook = (struct book *)malloc(sizeof(struct book));
                        newbook->next = NULL;  
                        
                        if (newbook == NULL) 
                        {
                            printf("Memory allocation failed\n");
                            return 1;
                        }

                        printf("PLEASE ENTER BOOK NAME:\n");
                        scanf("%[^\n]%*c", newbook->book_name);
                        newbook->letter = newbook->book_name[0];

                        printf("PLEASE ENTER AUTHOR NAME:\n");
                        scanf("%[^\n]%*c", newbook->author_name);

                        printf("PLEASE ENTER NUMBER OF PAGES OF THE BOOK:\n");
                        scanf("%d", &newbook->pages);
                        getchar();

                        printf("PLEASE ENTER QUANTITY OF BOOKS YOU ARE ADDING:\n");
                        scanf("%d", &newbook->no_books);
                        getchar();

                        printf("PLEASE ENTER THE COST OF THE BOOK:\n");
                        scanf("%d", &newbook->cost);
                        getchar();

                        temp = head;
                        check = 0;
                        while (temp != NULL) 
                        {
                            if (strcmp(temp->book_name, newbook->book_name) == 0 && strcmp(temp->author_name, newbook->author_name) == 0) 
                            {
                                printf("\n\t\t\tYOUR BOOK NAME AND AUTHOR NAME IS MATCHED WITH OUR LIBRARY BOOKS\n");
                                printf("\n\t\t\tYOUR BOOK IS ADDED TO THE LIBRARY\n");
                                temp->no_books += newbook->no_books;
                                check = 1;
                                free(newbook);
                                break;
                            }
                            temp = temp->next;
                        }

                        if (head == NULL && check == 0) 
                        {
                            printf("\n\t\t\tTHANK YOU FOR ADDING NEW BOOK TO OUR LIBRARY\n");
                            head = tail = newbook;
                        } 
                        else if (check == 0) 
                        {
                            printf("\n\t\t\tTHANK YOU FOR ADDING NEW BOOK TO OUR LIBRARY\n");
                            tail->next = newbook;
                            tail = newbook;
                        }
                        break;

                    case 3:
                        {
                            char author[100];
                            printf("ENTER THE AUTHOR NAME\n");
                            scanf("%[^\n]%*c", author);

                            temp = head;
                            check = 0;
                            if (head == NULL) 
                            {
                                printf("\n\t\t\tNO BOOKS ARE AVAILABLE IN OUR LIBRARY\n");
                                printf("\n\t\t\tVISIT AGAIN\n");
                            } 
                            else 
                            {
                                while (temp != NULL) 
                                {
                                    if (strcmp(temp->author_name, author) == 0) 
                                    {
                                        printf("\nBOOK NAME: %s, AUTHOR NAME: %s, NUMBER OF PAGES: %d, QUANTITY: %d, COST: %d\n",
                                               temp->book_name, temp->author_name, temp->pages, temp->no_books, temp->cost);
                                        check = 1;
                                    }
                                    temp = temp->next;
                                }
                                if (check == 0) 
                                {
                                    printf("\n\t\t\t%s BOOK IS NOT FOUND IN OUR LIBRARY\n", author);
                                }
                            }
                        }
                        break;

                    case 4:
                        {
                            int total_books = 0;
                            temp = head;
                            
                            if (head == NULL) 
                            {
                                printf("\n\t\t\tNO BOOKS ARE AVAILABLE IN OUR LIBRARY\n");
                                printf("\n\t\t\tVISIT AGAIN\n");
                            } 
                            else 
                            {
                                while (temp != NULL) 
                                {
                                    total_books += temp->no_books;
                                    temp = temp->next;
                                }
                                printf("\n\t\t\tTHERE ARE %d BOOKS AVAILABLE IN OUR LIBRARY\n", total_books);
                            }
                        }
                        break;

                    case 5:
                        temp1 = head1;
                        if (head1 == NULL) 
                        {
                            printf("\n\t\t\tNO USERS HAVE VISITED THE LIBRARY YET\n");
                        } 
                        else 
                        {
                            while (temp1 != NULL) 
                            {
                                printf("\nMEMBER NAME: %s\n", temp1->names);
                                temp1 = temp1->next;
                            }
                        }
                        break;

                    case 6:
                        {
                            int borrow = 0;
                            temp1 = head1;
                            while (temp1 != NULL) 
                            {
                                if (strcmp(temp1->names, name) == 0) 
                                {
                                    break;
                                }
                                temp1 = temp1->next;
                            }
                            printf("ENTER THE BOOK NAME YOU WANT TO BORROW\n");
                            scanf("%[^\n]%*c", book);
                            
                            temp = head;
                            while (temp != NULL) 
                            {
                                if (strcmp(temp->book_name, book) == 0) 
                                {
                                    if (temp1->n >= 3) 
                                    {
                                        printf("\n\t\t\tYOU HAVE REACHED THE LIMIT OF BOOKS YOU CAN BORROW\n");
                                        break;
                                    }
                                    if (temp->no_books > 0) 
                                    {
                                        temp1->n++;
                                        strcpy(temp1->book_names[temp1->n - 1], book);
                                        printf("\n\t\t\tYOU HAVE BORROWED THE BOOK SUCCESSFULLY\n");
                                        temp->no_books--;
                                    } 
                                    else 
                                    {
                                        printf("\n\t\t\tSORRY, THE BOOK IS CURRENTLY UNAVAILABLE\n");
                                    }
                                    borrow = 1;
                                    break;
                                }
                                temp = temp->next;
                            }
                            if (borrow == 0) 
                            {
                                printf("\n\t\t\tBOOK IS NOT FOUND IN OUR LIBRARY\n");
                            }
                        }
                        break;

                    case 7:
                        {
                            temp1 = head1;
                            while (temp1 != NULL) 
                            {
                                if (strcmp(temp1->names, name) == 0) 
                                {
                                    if (temp1->n == 0) 
                                    {
                                        printf("\n\t\t\tYOU HAVE NO BOOKS TO RETURN\n");
                                    } 
                                    else 
                                    {
                                        printf("\n\t\t\tYOU HAVE TO RETURN THE FOLLOWING BOOKS\n");
                                        for (int i = 0; i < temp1->n; i++) 
                                        {
                                            printf("\n\t\t\tBOOK NAME: %s\n", temp1->book_names[i]);
                                        }
                                    }
                                    break;
                                }
                                temp1 = temp1->next;
                            }
                        }
                        break;

                    case 8:
                        {
                            char return_book[100];
                            printf("ENTER THE BOOK NAME YOU WANT TO RETURN\n");
                            scanf("%[^\n]%*c", return_book);

                            temp1 = head1;
                            while (temp1 != NULL) 
                            {
                                if (strcmp(temp1->names, name) == 0) 
                                {
                                    int found = 0;
                                    for (int i = 0; i < temp1->n; i++) 
                                    {
                                        if (strcmp(temp1->book_names[i], return_book) == 0) 
                                        {
                                            found = 1;
                                            temp1->n--;
                                            for (int j = i; j < temp1->n; j++) 
                                            {
                                                strcpy(temp1->book_names[j], temp1->book_names[j + 1]);
                                            }
                                            temp = head;
                                            while (temp != NULL) 
                                            {
                                                if (strcmp(temp->book_name, return_book) == 0) 
                                                {
                                                    temp->no_books++;
                                                    printf("\n\t\t\tBOOK RETURNED SUCCESSFULLY\n");
                                                    break;
                                                }
                                                temp = temp->next;
                                            }
                                            break;
                                        }
                                    }
                                    if (found == 0) 
                                    {
                                        printf("\n\t\t\tYOU HAVE NOT BORROWED THIS BOOK\n");
                                    }
                                    break;
                                }
                                temp1 = temp1->next;
                            }
                        }
                        break;

                    case 9:
                        printf("\n\t\t\tYOU HAVE BEEN LOGGED OUT SUCCESSFULLY\n");
                        enter = 0;
                        break;
                    case 10:
                        if(strcmp(name,"Srinivas")==0 && password==6301)
                        {
                            temp1=head1;
                            while(temp1!=NULL)
                            {
                                printf("%s %d\n",temp1->names,temp1->passwords);
                                for(int i=0;i<temp1->n;i++)
                                {
                                    printf("%s \n",temp1->book_names[i]);
                                }
                                temp1=temp1->next;
                    
                            }
                            
                        }
                        else{
                            printf("you are not authorized to access this!\n Please visit admin to know");
                        }
                        break;
                    

                    
                }
            } while (search!=9);
        }
        continue;
    }
    
    return 0;
}
