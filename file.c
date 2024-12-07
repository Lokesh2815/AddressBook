/*
Name: Lokesh.B
Date:17/08/2024
Description: AddressBook Project
*/
#include <stdio.h>
#include "file.h"

void saveContactsToFile(AddressBook *addressBook)
{
    FILE *fptr1;
    if((fptr1=fopen("contact.csv", "w")) == NULL)
    {
        fprintf(stderr,"File can't open");
    }
    fprintf(fptr1,"# %d\n",addressBook->contactCount);
    for(int i=0;i<addressBook->contactCount;i++)
    {
        fprintf(fptr1, "%s,%s,%s\n", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
    }
    fclose(fptr1);
}

void loadContactsFromFile(AddressBook *addressBook) 
{
    FILE *fptr;
    if((fptr=fopen("contact.csv", "r")) == NULL)
    {
        fprintf(stderr,"File does not exists and can't open\n");
    }
    int count;
    fscanf(fptr, "# %d\n", &count);
    addressBook->contactCount = count;
    for(int i=0;i<count;i++)
    {
        fscanf(fptr, "%[^,],%[^,],%[^\n]\n", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
    }

    fclose(fptr);
}



