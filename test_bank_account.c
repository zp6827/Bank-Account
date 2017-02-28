#include "bank_account.h"
#include <stdlib.h>
#include <stdio.h>

int main()
{
	bank_account* acct = create_account("Zach Pate", 100.0, "001");
	int depositResult = deposit(acct, 50.0); 
	int withdrawResult = withdraw(acct, 50.0);

	bank_account* badAcct = create_account("Zach", 50.0, "002"); 
	int badDeposit = deposit(badAcct, -50.0); 
	int badWithdraw = withdraw(badAcct, 1000.0); 

	if(depositResult == 1 && withdrawResult == 1)
	{
		printf("Good data test successful\n");
	}
	else 
	{
		printf("Good data test failed\n"); 
	}

	if(badDeposit == 0 && badWithdraw == 0)
	{
		printf("Bad data test successful\n");
	}
	else 
	{
		printf("Bad data test failed\n"); 
	}
	return 0;
}
