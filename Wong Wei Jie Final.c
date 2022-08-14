#include <stdio.h>
#include <stdlib.h>
#pragma warning (disable :4996)
#define A 24.50
#define B 26.00
#define C 27.50
#define D 29.00
#define DELIVERY 5.00

int menu();
void logo();

//logo
void logo() {
	printf("                                    *********************************************   \n");
	printf("                                   *    ****      *     *      ****      *****   *  \n");
	printf("                                  *    *          *     *     *    *     *        * \n");
	printf("                                  *    *   **     * *** *     *    *     ****     * \n");
	printf("                                  *    *    *     *     *     *    *     *        * \n");
	printf("                                  *     *****     *     *     *    *     *        * \n");
	printf("                                   *        *  *  *     *  *   ****   *  *       *  \n");
	printf("                                    *********************************************   \n\n");

	printf("                             < Welcome to GH Organic Farm's Vegetable Ordering System >\n\n\n");
}

//menu function
int menu() {
	int choices;

	do
	{
		logo();
		printf("Choose a number for further \n");
		printf("1. Enter Customer Order\n");
		printf("2. Pakage Details\n");
		printf("3. Exit\n\n");
		printf("Enter your choices > ");
		scanf("%d", &choices);
		rewind(stdin);
		printf("\n");

		if (choices != 1 && choices != 2 && choices != 3)
		{
			printf("Invalid number please enter again ..... \n\n");
			system("pause");
			system("cls");
		}

	} while (choices != 1 && choices != 2 && choices != 3);


	return choices;
}

//main function
void main() {
	char name[50], phNo[50];
	char address1[99], address2[99], address3[99];
	char loop;
	int qtyA, qtyB, qtyC, qtyD;
	int check, choices;
	int customerNum = 0;
	int ttlQty = 0, ttlQtyA = 0, ttlQtyB = 0, ttlQtyC = 0, ttlQtyD = 0;
	double pkgA, pkgB, pkgC, pkgD;
	double ttlPkgA = 0, ttlPkgB = 0, ttlPkgC = 0, ttlPkgD = 0;
	double ttlPkg = 0, allSum=0;
	double ttlCharges, ttlSum, ttlDiscount;
	double NOCHARGES = 0;
	
	choices = menu();
	
	if (choices == 1)
	{
		
		do
			{
				system("cls");
				logo();

				//data input
				customerNum++;
				printf("Customer No. : %d\n", customerNum);

				printf("Enter Your Name :");
				gets(name);
				printf("\n");

				do
				{
					check = 0;

					printf("Enter Your Phone Number (only number) :");
					gets(phNo);
					printf("\n");

					for (int i = 0; i <= strlen(phNo); i++) {
						if (isalpha(phNo[i])) {
							check++;
							break;
						}
					}
					if (check)
						printf("Invalid character has entered\n");
				} while (check);


				printf("Enter Your Address 1 :");
				gets(address1);
				rewind(stdin);
				printf("\n");

				printf("Enter Your Address 2 :");
				gets(address2);
				rewind(stdin);
				printf("\n");

				printf("Enter Your Address 3 :");
				gets(address3);
				rewind(stdin);
				printf("\n\n");

				printf("Please Enter The Quantity of the Packages (Note : All negative number will become absolute number.) :\n");

				printf("Package A RM24.90 :");
				scanf("%d", &qtyA);
				qtyA = abs(qtyA);
				printf("\n");

				printf("Package B RM26.00 :");
				scanf("%d", &qtyB);
				qtyB = abs(qtyB);
				printf("\n");

				printf("Package C RM27.50 :");
				scanf("%d", &qtyC);
				qtyC = abs(qtyC);
				printf("\n");

				printf("Package D RM29.00 :");
				scanf("%d", &qtyD);
				qtyD = abs(qtyD);
				printf("\n");

				system("cls");

				logo();

				//invoice
				printf("                                                   INVOICE\n\n");

				printf("Customer No. : %d\n", customerNum);
				printf("Name      : %s\n", name);
				printf("Telephone : %s\n", phNo);
				printf("Address 1 : %s\n", address1);
				printf("Address 2 : %s\n", address2);
				printf("Address 3 : %s\n", address3);

				pkgA = qtyA * A;
				pkgB = qtyB * B;
				pkgC = qtyC * C;
				pkgD = qtyD * D;
				ttlCharges = pkgA + pkgB + pkgC + pkgD;

				//customer order 
				if (ttlCharges >= 100)
				{
					ttlDiscount = ttlCharges * 0.15;
					ttlSum = ttlCharges - ttlDiscount;

					printf("                                                CUSTOMER ORDERS\n\n");
					printf("PACKAGE A %4d @ RM24.90 : RM%8.2lf\n", qtyA, pkgA);
					printf("PACKAGE B %4d @ RM26.00 : RM%8.2lf\n", qtyB, pkgB);
					printf("PACKAGE C %4d @ RM27.50 : RM%8.2lf\n", qtyC, pkgC);
					printf("PACKAGE D %4d @ RM29.00 : RM%8.2lf\n\n", qtyD, pkgD);

					printf("Total Packages Charges : RM%8.2lf\n", ttlCharges);
					printf("Discount               : RM%8.2lf\n", ttlDiscount);
					printf("Delivery Fess          : RM%8.2lf\n", NOCHARGES);
					printf("Total payment          : RM%8.2lf\n\n\n", ttlSum);

				}
				else if (ttlCharges == 0 || ttlCharges >= 80)
				{
					ttlSum = ttlCharges;
					if (ttlCharges == 0)
					{
						customerNum = 0;
					}

					printf("                                                CUSTOMER ORDERS\n\n");
					printf("PACKAGE A %4d @ RM24.90 : RM%8.2lf\n", qtyA, pkgA);
					printf("PACKAGE B %4d @ RM26.00 : RM%8.2lf\n", qtyB, pkgB);
					printf("PACKAGE C %4d @ RM27.50 : RM%8.2lf\n", qtyC, pkgC);
					printf("PACKAGE D %4d @ RM29.00 : RM%8.2lf\n\n", qtyD, pkgD);

					printf("Total Packages Charges : RM%8.2lf\n", ttlCharges);
					printf("Discount               : RM%8.2lf\n", NOCHARGES);
					printf("Delivery Fess          : RM%8.2lf\n", NOCHARGES);
					printf("Total payment          : RM%8.2lf\n\n\n", ttlSum);
				}
				else
				{
					ttlSum = ttlCharges + DELIVERY;

					printf("                                                CUSTOMER ORDERS\n\n");
					printf("PACKAGE A %4d @ RM24.90 : RM%8.2lf\n", qtyA, pkgA);
					printf("PACKAGE B %4d @ RM26.00 : RM%8.2lf\n", qtyB, pkgB);
					printf("PACKAGE C %4d @ RM27.50 : RM%8.2lf\n", qtyC, pkgC);
					printf("PACKAGE D %4d @ RM29.00 : RM%8.2lf\n\n", qtyD, pkgD);

					printf("Total Packages Charges : RM%8.2lf\n", ttlCharges);
					printf("Discount               : RM%8.2lf\n", NOCHARGES);
					printf("Delivery Fess          : RM%8.2lf\n", DELIVERY);
					printf("Total payment          : RM%8.2lf\n\n\n", ttlSum);
				}

				//calculation for total product sales
				ttlQtyA += qtyA;
				ttlQtyB += qtyB;
				ttlQtyC += qtyC;
				ttlQtyD += qtyD;

				ttlPkgA += pkgA;
				ttlPkgB += pkgB;
				ttlPkgC += pkgC;
				ttlPkgD += pkgD;

				allSum += ttlSum;
				// loop function for more customer

				rewind(stdin);
				printf("Continue? (Enter 'Y' to continue and enter any other key to exit) > ");
				scanf("%c", &loop);
				printf("\n\n");
				rewind(stdin);

				

			} while (loop == 'y' || loop == 'Y');

		//total customer and product sale
		printf("            Daily Sales Summary \n");
		printf("Total customer            : %d\n\n", customerNum);
		printf("Total Sales for Package A : %3d * RM%5.2lf = RM%8.2lf\n", ttlQtyA, A, ttlPkgA);
		printf("Total Sales for Package B : %3d * RM%5.2lf = RM%8.2lf\n", ttlQtyB, B, ttlPkgB);
		printf("Total Sales for Package C : %3d * RM%5.2lf = RM%8.2lf\n", ttlQtyC, C, ttlPkgC);
		printf("Total Sales for Package D : %3d * RM%5.2lf = RM%8.2lf\n", ttlQtyD, D, ttlPkgD);

		ttlQty += ttlQtyA + ttlQtyB + ttlQtyC + ttlQtyD;
		ttlPkg += ttlPkgA + ttlPkgB + ttlPkgC + ttlPkgD;

		printf("Total Package Sales       : %3d pkg sold  = RM%8.2lf\n", ttlQty, ttlPkg);
		printf("Total Today Sales (+delivery & -discount) = RM%8.2lf\n\n",allSum);

		printf("                Thank You, Have a Nice Day. \n\n");

	}
	//product details
	else if (choices == 2)
	{
	system("cls");
	logo();
	printf("                                              < Package Details >\n\n\n");

	printf("Package A (kangkung, cabbage, Ladies finger, banana)   = RM%.2lf\n", A);
	printf("Package B (Yam leaves, long bean, brinjal, guava)      = RM%.2lf\n", B);
	printf("Package C (snake beans, broccoli, spinach, papaya)     = RM%.2lf\n", C);
	printf("Package D (bak choy, asparagus, brinjal, dragon fruit) = RM%.2lf\n\n", D);

	printf("Press any key to back to menu.");
	system("pause");
	system("cls");
	}



	//exit
	else
	{
	printf("                Thank You, Have a Nice Day. \n\n");
	}
}

