/*
Name: Lokesh.B
Date:17/08/2024
Description: AddressBook Project
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
#include "populate.h"

void listContacts(AddressBook *addressBook) 
{
    // Display all the Contacts in addressBook
    printf("Name\t\tMobile No.\t\tEmail Id\n");
    printf("----\t\t------ ---\t\t----- --\n");
    for(int i=0;i<addressBook->contactCount;i++)
    {
	printf("%s\t",addressBook->contacts[i].name);
	printf("%s\t",addressBook->contacts[i].phone);
	printf("%s",addressBook->contacts[i].email);
	printf("\n");
    } 
}

void initialize(AddressBook *addressBook) {
    addressBook->contactCount = 0;
    // Load contacts from file during initialization (After files)
    loadContactsFromFile(addressBook);
}

void saveAndExit(AddressBook *addressBook) {
    saveContactsToFile(addressBook); // Save contacts to file
}


void createContact(AddressBook *addressBook)
{
    char name[30];
    int flag_name=0;
    
	while(1)
    {
        printf("Enter the name :\n");
        scanf(" %[^\n]",name);
        getchar();
    for(int i=0;name[i]!='\0';i++)
    {
        if((name[i]>='a' && name[i]<='z') || (name[i]>='A' && name[i]<='Z'))
        {
            flag_name=1;
        }
    }
    if(flag_name==1)
    {
        strcpy(addressBook->contacts[addressBook->contactCount].name,name);
        break;
    }
    else
    {
        printf("Incorrect name\n");
    }
    }
     
    
    char phone[11];
    int checkphone=0;
    while(1)
    {
        printf("Enter the mobile number :\n");
        scanf("%[^\n]",phone);
        getchar();
        int flag=0;
        if(strlen(phone)!=10)
        {
            printf("Error : Invalid Mobile number\n");
        }
        else
        {
            for(int i=0;i<10;i++)
            {
                if(phone[i]>='0' && phone[i]<='9')
                {
                    checkphone=1;
                }
                else
                {
                    flag=1;
                    break;
                }
            }
            if(flag==1)
            {
                printf("Error : Invalid Mobile number Enter the numbers only\n");
            }
            else
            {
                int exists = 0;
                for(int i=0;i<addressBook->contactCount;i++)
                {
                    if(!(strcmp(phone,addressBook->contacts[i].phone)))
                    {
                        exists = 1;
                        printf("Phone number already exists\n");
                        break;
                    }
                }
                if(exists == 0)
                {
                    strcpy(addressBook->contacts[addressBook->contactCount].phone,phone);
                    break;
                }
            }
        }
    }

    char s1[]="@";
    char s2[]=".com";
    char str[30];
    int checkmail=0;
    while(1)
    {
        printf("Enter the Email Id :");
        scanf(" %[^\n]",str);
        getchar();
        if(strstr(str,s1) && strstr(str,s2))
        {
            checkmail=1;
            int exists = 0;
            for(int i=0;i<addressBook->contactCount;i++)
            {
                if(!(strcmp(str,addressBook->contacts[i].email)))
                {
                    exists = 1;
                    printf("Email already exists\n");
                    break;
                }
            }
            if(exists == 0)
            {
                strcpy(addressBook->contacts[addressBook->contactCount].email,str);
                break;
            }
        }
        else
        {
            printf("Invalid email\n");
        }
    }

    addressBook->contactCount++;
     
    printf("------------Display-----------------\n");
    if(checkphone==1 && checkmail==1)
    {
    	printf("Name : %s\n",name);
        printf("Mobile_no : %s\n",phone);
        printf("Email Id : %s\n",str);
    }

	
 
}

void searchContact(AddressBook *addressBook) 
{
    /* Define the logic for search */
    int choose;
    printf("1. Search by Name\n");
    printf("2. Search by Ph.number\n");
    printf("3. Search by Email\n");
    printf("Choose one option");
    scanf("%d",&choose);
    getchar();
    switch(choose)
    {
	case 1:
	    {
		char searchName[30];
		printf("Enter the Name\n");
		scanf(" %[^\n]",searchName);
		int flag=0,i,Index_name;
		for(i=0;i<addressBook->contactCount;i++)
		{
		    if(!(strcmp(searchName,addressBook->contacts[i].name)))
		    {
                Index_name=i;
			    flag=1;
			    break;
		    }
		}
		if(flag==1)
		{
		    printf("Contact Found\n");
		    printf("%s\n",addressBook->contacts[Index_name].name);
		    printf("%s\n",addressBook->contacts[Index_name].phone);
		    printf("%s\n",addressBook->contacts[Index_name].email);
		}
		else
        {
	        printf("Given name contact not Found\n");
		} 		
		break;
	    }
	case 2:
		{
		    char searchphone[11];
		    printf("Enter the mobile number\n");
		    scanf(" %[^\n]",searchphone);
		    int flag=0,i,Index_phone;
		    for(i=0;i<addressBook->contactCount;i++)
		    {
				if(!(strcmp(searchphone,addressBook->contacts[i].phone)))
			    {
					flag=1;
			        Index_phone=i;
			        break;
				}
		    }
		    if(flag==1)
		    {
			    printf("Given phone NUmber found\n");
    			printf("%s\n",addressBook->contacts[Index_phone].name);
    			printf("%s\n",addressBook->contacts[Index_phone].phone);
	    		printf("%s\n",addressBook->contacts[Index_phone].email);
		    }
 		    else
		    {
				printf("Phone number not found");
		
    		}

		    break;
		}
	case 3:
		{
		    char searchemail[30];
		    printf("Enter the email to search:\n");
		    scanf(" %[^\n]",searchemail);
		    getchar();
		    int flag=0,i,Index_email;
		    for(int i=0;i<addressBook->contactCount;i++)
		    {
			if(!(strcmp(searchemail,addressBook->contacts[i].email)))
			{
			    flag=1;
			    Index_email=i;
			    break;
	                    
			}
		    }
		    if(flag==1)
		    {
			printf("Contact found\n");
			printf("%s\n",addressBook->contacts[Index_email].name);
			printf("%s\n",addressBook->contacts[Index_email].phone);
			printf("%s\n",addressBook->contacts[Index_email].email);
		    }
		    else
		    {
                printf("Email given is not Found");
            }
	    
		    break;
		}
    }
}

void editContact(AddressBook *addressBook)
{
	/* Define the logic for Editcontact */
    int choice;
    printf("1. Search by Name\n2. Search by Phone Number\n3. Search by Email\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    getchar();
    int index_foo = -1, flag=0;
    switch(choice)
    {
        case 1:
        {
            char search_name[30];
            int count=0;
            printf("Enter the name to search: ");
            scanf("\n %[^\n]",search_name);
            int indices[addressBook->contactCount];
            for (int i = 0; i < addressBook->contactCount; i++)
            {
                if (strstr(addressBook->contacts[i].name, search_name) != NULL)
                {
                    indices[count] = i;
                    count++;
                    flag = 1;
                }
            } 
            if (flag == 1)
            {
                if (count > 1)
                {
                    printf("Multiple contacts found:\n");
                    for (int i = 0; i < count; i++)
                    {
                        printf("%s\n", addressBook->contacts[indices[i]].name);
                    }
                    printf("Enter the exact name to edit: ");
                    char exactName[30];
                    scanf(" %[^\n]", exactName);
                    for(int i=0;i<addressBook->contactCount;i++)
                    {
                        if(strcmp(addressBook->contacts[i].name,exactName)==0)
                        {
                            index_foo=i;
                            flag=1;
                            break;
                        }
                    }
		        }
			    else
			    {
                    index_foo = indices[0];
                }
	        }
	        
            break;
        }
        case 2:
        {
            char search_phone[11];
            printf("Enter the phone number to search: ");
            scanf(" %[^\n]", search_phone);
            int count=0;
            int indices[addressBook->contactCount];
            for (int i = 0; i < addressBook->contactCount; i++)
            {
                if (strstr(addressBook->contacts[i].phone, search_phone) != NULL)
                {
                    indices[count] = i;
                    count++;
                    flag = 1;
                }
            } 
            if (flag == 1)
            {
                if (count > 1)
                {
                    printf("Multiple contacts found:\n");
                    for (int i = 0; i < count; i++)
                    {
                        printf("%s\n", addressBook->contacts[indices[i]].phone);
                    }
                    printf("Enter the exact name to edit: ");
                    char exactphonenum[30];
                    scanf(" %[^\n]", exactphonenum);
                    for(int i=0;i<addressBook->contactCount;i++)
                    {
                        if(strcmp(addressBook->contacts[i].phone,exactphonenum)==0)
                        {
                            index_foo=i;
                            flag=1;
                            break;
                        }
                    }
		        }
			    else
			    {
                    index_foo = indices[0];
                }
	        }
            break;
        }
        case 3:
        {
            char search_email[30];
            printf("Enter the email to search: ");
            scanf(" %[^\n]", search_email);

            for (int i = 0; i < addressBook->contactCount; i++)
            {
                if (strcmp(addressBook->contacts[i].email, search_email) == 0)
                {
                    index_foo = i;
                    break;
                }
            }
            break;
        }
        default:
            printf("Invalid choice!\n");
            return;
    }

    if (index_foo == -1)
    {
        printf("Contact not found.\n");
        return;
    }

    printf("Contact found: %s - %s - %s\n", addressBook->contacts[index_foo].name, addressBook->contacts[index_foo].phone, addressBook->contacts[index_foo].email);

    if(flag==1)
    {
	int choice;
    	printf("1. Edit name:\n2. Edit phone number:\n3. Edit Email Id:\n");
    	printf("Enter the choice:\n");
    	scanf(" %d",&choice);
    	switch(choice)
    	{
    	    case 1:
    		{
		    char str[20];
    		    printf("Enter the name : ");
    		    scanf(" %[^\n]",str);
    		    for(int i=0;str[i]!='\0';i++)
    		    {
    			addressBook->contacts[index_foo].name[i]=str[i];
    		    }
		    printf("contact edited successfully");
    		    break;
    		}
    	    case 2:
    		{
		    char ph[11];
                int check_ph=0;

		    while(1)
		    {
    			printf("Enter the number : ");
    			scanf(" %[^\n]",ph);
    			if(strlen(ph)!=10)
    			{
    			    printf("Enter number is incorrect\n");
	    		}
    			else
    			{
    			    for(int i=0;i<10;i++)
    			    {
						if(ph[i]>='0' && ph[i]<='9')
						{
							check_ph=1;
    				    }
    			    }
			        break;
    			}
		    }
    			if(check_ph)
    			{
    			    for(int i=0;ph[i]!='\0';i++)
    			    {
    				addressBook->contacts[index_foo].phone[i]=ph[i];
    			    }
    			    printf("Contact updated successfully");
    			}
		    break;
    		}
    	    case 3:
    		{
    		    char mail[30];
    		    char s1[]="@";
				char s2[]=".com";
				int flag=0;
                while(1)
				{
					printf("Enter the email to edit:");
	    			scanf(" %[^\n]",mail);
					if(strstr(mail,s1) && strstr(mail,s2))
					{
						flag=1;
						break;
					}
					else
					{
						printf("Invalid Email");
					}
		        }
    			if(flag)
    			{
			    for(int i=0;mail[i]!='\0';i++)
                {
    				addressBook->contacts[index_foo].email[i]=mail[i];
    			}
    			    printf("Contact updated successfully");
    			}
		    break;
    		}
    	}
    }
  
}

void deleteContact(AddressBook *addressBook)
{
    int choose;
    printf("1. Delete by Name\n");
    printf("2. Delete by Ph.number\n");
    printf("3. Delete by Email\n");
    printf("Choose one option");
    scanf("%d",&choose);
    getchar();
    switch(choose)
    {
        case 1:
        {
            char searchName[30];
            printf("Enter the Name\n");
            scanf(" %[^\n]",searchName);
            int flag=0,i;
            for(i=0;i<addressBook->contactCount;i++)
            {
                if(!(strcmp(searchName,addressBook->contacts[i].name)))
                {
                    flag=1;
                    break;
                }
            }
            if(flag==1)
            {
                for(int j=i;j<addressBook->contactCount;j++)
                {
                    addressBook->contacts[j]=addressBook->contacts[j+1];
                }
                addressBook->contactCount--;
                printf("Contact deleted successfully");
            }
            else
            {
                printf("Given name contact not Found\n");
            }
            break;
        }
        case 2:
        {
            char searchphone[11];
            printf("Enter the mobile number\n");
            scanf(" %[^\n]",searchphone);
            int flag=0,i;
            for(i=0;i<addressBook->contactCount;i++)
            {
                if(!(strcmp(searchphone,addressBook->contacts[i].phone)))
                {
                    flag=1;
                    break;
                }
            }
            if(flag==1)
            {
                for(int j=i;j<addressBook->contactCount;j++)
                {
                    addressBook->contacts[j]=addressBook->contacts[j+1];
                }
                addressBook->contactCount--;
                printf("Contact deleted successfully");
            }
            else
            {
                printf("Phone number not found");
            }
            break;
        }
        case 3:
        {
            char searchemail[30];
            printf("Enter the email to search:\n");
            scanf(" %[^\n]",searchemail);
            getchar();
            int flag=0,i;
            for(i=0;i<addressBook->contactCount;i++)
            {
                if(!(strcmp(searchemail,addressBook->contacts[i].email)))
                {
                    flag=1;
                    break;
                }
            }
            if(flag==1)
            {
                for(int j=i;j<addressBook->contactCount;j++)
                {
                    addressBook->contacts[j]=addressBook->contacts[j+1];
                }
                addressBook->contactCount--;
                printf("Contact deleted successfully");
            }
            else
            {
                printf("Email given is not Found");
            }
            break;
        }
    }
}

