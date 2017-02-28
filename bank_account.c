#include "bank_account.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int is_all_digits(char* s)
{
	int result = 0; 
	if (s != NULL)
	{
		int i = 0; 
		while(i<strlen(s) && isdigit(s[i]))
			i++; 
		result = i == strlen(s); 
	}
	return result; 
}

bank_account* create_account (char* acct_owner, double init_balance, 
				char* acct_num) 
{
	bank_account* acct = NULL; 
	if(acct_owner != NULL && strlen(acct_owner) > 0)
		if(acct_num != NULL && strlen(acct_num) >= 1 && 
				is_all_digits(acct_num))
			if(init_balance >= 0)
			{
				acct = malloc(sizeof(bank_account)); 
				acct->owner = acct_owner; 
				acct->balance = init_balance; 
				acct->num = acct_num; 
			}
	return acct; 
}

int deposit (bank_account* acct, double amount)
{
	int result = 0; 
	if(amount >= 0 && acct != NULL) 
	{ 
		acct->balance += amount; 
		result = 1; 
	}
	return result;  
}

int withdraw (bank_account* acct, double amount)
{
	int result = 0; 
	if(amount >= 0 && amount <= acct->balance && acct != NULL)
	{
		acct->balance -= amount;
		result = 1; 
	} 
	return result; 
}

void display_account (bank_account* acct)
{
	printf("name: %s\n", acct->owner);
	printf("account number: %s\n", acct->num); 
	printf("balance: %f\n", acct->balance); 
}

void delete_account (bank_account* acct)
{
	if(acct != NULL)
	{ 
		free(acct); 
	}
}
