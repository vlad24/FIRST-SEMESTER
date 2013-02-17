#include <stdio.h>

struct Date
{
	int day;
	int month;
	int year;
};

void initializeMin(Date* &minDate ,int tmpDay ,int tmpMonth ,int tmpYear )
{
		minDate->year = tmpYear;
		minDate->month = tmpMonth;
		minDate->day = tmpDay;
}
int main()
{
	FILE* datesFile = fopen("datesdates.txt","r");
	Date* minDate = new Date;
	int tmpYear = 247483640;
	int tmpMonth = 247483620;
	int tmpDay = 247483640;
	char mover = 'm';
	initializeMin(minDate,tmpDay,tmpMonth,tmpYear);
	//
	while (!(feof(datesFile)))
	{
		
		fscanf(datesFile,"%d.",&tmpDay);
		fscanf(datesFile,"%d.",&tmpMonth);
		fscanf(datesFile,"%d",&tmpYear);
		fscanf(datesFile,"%c", &mover);

		if (tmpYear < minDate->year)
			initializeMin(minDate,tmpDay,tmpMonth,tmpYear);
		else if (tmpYear == minDate->year)
			{
				if (tmpMonth < minDate->month)
					initializeMin(minDate,tmpDay,tmpMonth,tmpYear);
				else if (tmpMonth == minDate->month)
				{
					if (tmpDay < minDate->day)
					initializeMin(minDate,tmpDay,tmpMonth,tmpYear);
					else if (tmpMonth == minDate->month)
						initializeMin(minDate,tmpDay,tmpMonth,tmpYear);
				}
			}
		
	}
	//
	printf("Minimum Date : %d.%d.%d \n",minDate->day,minDate->month,minDate->year);
	delete minDate;
	fclose(datesFile);
	getc(stdin);
}