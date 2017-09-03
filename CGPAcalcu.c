#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable :4996)

//CONSTANTS
#define SENTINEL_VALUE 50

//function declarations
void header();
void  gradeCategory(double overallCGPA);

void main()
{
	//Variable declarations
	int creditHrs[SENTINEL_VALUE], sumCreditHrs = 0, amountOfSubjects;
	double  gradePoint[SENTINEL_VALUE], subGradePoints[SENTINEL_VALUE],
		totalGradePoints = 0, overallCGPA;

	header();
	system("pause");
	system("cls");
	//user input
	puts("");
		do {
			printf("Please enter the amount of subjects  [ MAX 50!!!]:");
			scanf("%d", &amountOfSubjects);
			rewind(stdin);
		} while (amountOfSubjects> SENTINEL_VALUE);
	puts("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
	puts("ATTENTION ! (eg Valid input for GradePoint: 0.00, 2.00, 2.50, 3.00, 3.25, 3.50, 3.75, 4.00) ");
	for (int i = 0; i < amountOfSubjects; i++)
	{
		puts("+--------------+");
		printf("|Subject  [%d]  |\n", i+1);
		puts("+--------------+");
		do
		{
			printf("Grade Point :");
			scanf("%lf", &gradePoint[i]);
			if (gradePoint[i] > 4.00)
			{
				rewind(stdin);
				puts("Invalid input !!! Please re-enter =C");

			}
		} while (gradePoint[i] > 4.00); //loop will repeat as long as input is greater than 4
		printf("Credit Hours :");
		scanf("%d", &creditHrs[i]);
		rewind(stdin);
		puts("");
	}

	//calculations
	for (int i = 0; i < amountOfSubjects; i++)
	{
		subGradePoints[i] = gradePoint[i] * creditHrs[i];
		sumCreditHrs += creditHrs[i];
	}
	for (int i = 0; i < amountOfSubjects; i++)
	{
		totalGradePoints += subGradePoints[i];
	}
	for (int i = 0; i < amountOfSubjects; i++)
	{
		overallCGPA = totalGradePoints / sumCreditHrs;
	}

	//output
	system("pause");
	system("cls");
	puts("");
	puts("\t---------------------------------------------------");
	puts("\t|             +==OVERALL CGPA==+                  |");
	puts("\t---------------------------------------------------");
	puts("\t+_________________________________________________+");
	puts("\t|Subject      GPA     Credit Hours     GradePoints|");
	puts("\t|=======     ====     ===========      ===========|");
	for (int i = 0; i < amountOfSubjects; i++)
	{
		printf("\t|%4d     %7.2lf     %6d     %14.2lf   |", i + 1, gradePoint[i], creditHrs[i], subGradePoints[i]);
		puts("");
	}
	puts("\t|_________________________________________________|");
	printf("\tTotal Credit Hours = %d", sumCreditHrs);
	puts("");
	printf("\tOverall CGPA       = %.2lf", overallCGPA);
	//conditions
	puts("");
	gradeCategory(overallCGPA);
	
	puts("\n");
	system("pause");
}
void header()
{
	puts("\n");
	puts("\t*********************************");
	puts("\t*           C-G-P-A             *");
	puts("\t*      C-A-L-C-U-L-A-T-O-R      *");
	puts("\t*********************************");
	puts("\t*  ----    ----    ----    ---- *");
	puts("\t*  |1 |    |2 |    |3 |    |4 | *");
	puts("\t*  ----    ----    ----    ---- *");
	puts("\t*  ----    ----    ----    ---- *");
	puts("\t*  |5 |    |6 |    |7 |    |8 | *");
	puts("\t*  ----    ----    ----    ---- *");
	puts("\t*  ----    ----    ----    ---- *");
	puts("\t*  |9 |    |0 |    |+ |    |- | *");
	puts("\t*  ----    ----    ----    ---- *");
	puts("\t*********************************");
	puts("\n");
}
void gradeCategory(double overallCGPA)
{
	if (overallCGPA == 4.0)
		puts("\tGrade category     : A+ =)");
	else if (overallCGPA >= 3.75)
		puts("\tGrade category     : A");
	else if (overallCGPA >= 3.5)
		puts("\tGrade category     : A-");
	else if (overallCGPA >= 3.25)
		puts("\tGrade category     : B+");
	else if (overallCGPA >= 3.0)
		puts("\tGrade category     : B");
	else if (overallCGPA >= 2.5)
		puts("\tGrade category     : C+");
	else if (overallCGPA >= 2.0)
		puts("\tGrade category     : C");
	else
		puts("\tGrade category     : F !!! =(");

}
