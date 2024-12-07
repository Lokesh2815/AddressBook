/*
Name: Lokesh.B
Date:17/08/2024
Description: AddressBook Project
*/
#include <stdio.h>
#include<string.h>
#include "contact.h"

int main() 
{
    int choice;
    char input[10];
    AddressBook addressBook;
    initialize(&addressBook); // Initialize the address book

    do {
        printf("\nAddress Book Menu:\n");
        printf("1. Add contact\n");
        printf("2. Search contact\n");
        printf("3. Edit contact\n");
        printf("4. Delete contact\n");
        printf("5. Display contacts\n");
        printf("6. Save contact\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
                
        scanf("%s", input);
        if(strlen(input) == 1 && input[0] >= '1' && input[0] <= '7')
        {
            choice = input[0] - '0';
            switch (choice)
            {
                case 1:
                    createContact(&addressBook);
                    break;
                case 2:
                    searchContact(&addressBook);
                    break;
                case 3:
                    editContact(&addressBook);
                    break;
                case 4:
                    deleteContact(&addressBook);
                    break;
                case 5:
                    listContacts(&addressBook);
                    break;
                case 6:
            	    printf("Saved Successfully\n");
                    saveContactsToFile(&addressBook);
                    break;
                case 7:
                    printf("Exit");
                    break;
                default:
                    printf("Invalid choice. please try again.\n");
                    break;
                    
            }
        }
        else
        {
            printf("Invalid choice. Please try again.\n");
        } 
    }while (choice != 7 );
    
       return 0;
}

