#include<stdio.h>

#define TRUE 1
#define FALSE 0

int days_in_month[]={0,31,29,31,30,31,30,31,31,30,31,30,31};
char*months[]={
                ""
                ,
                "\n\n\n\nJANUARY",
                "\n\n\n\nFEBRUARY",
                "\n\n\n\nMARCH",
                "\n\n\n\nAPRIL",
                "\n\n\n\nMAY",
                "\n\n\n\nJUNE",
                "\n\n\n\nJULY",
                "\n\n\n\nAUGUST",
                "\n\n\n\nSEPTEMBER",
                "\n\n\n\nOCTOBER",
                "\n\n\n\nNOVEMBER",
                "\n\n\n\nDECEMBER",
              };

int inputyear(void)
{
    int year;
    printf("PLEASE ENTER ANY YEAR: ");
    scanf("%d", &year);
    return year;
}

int determinedaycode (int year)
{
    int daycode;
    int d1,d2,d3;

    d1=(year-1.)/4.0;
    d2=(year-1.)/100.;
    d3=(year-1.)/400.;
    daycode=(year+d1-d2+d3)%7;
    return daycode;
}

int determineleapyear (int year)
{
    if(year%4==FALSE && year%100!=FALSE || year%400==FALSE)
    {
        days_in_month[2]=29;
        return TRUE;
    }
    else
    {
        days_in_month[2]=28;
        return FALSE;
    }
}

void calendar (int year, int daycode)
{
    int month, day;
    for(month=1; month<=12; month++)
        {
		printf("%s", months[month]);
		printf("\n\nSun  Mon  Tue  Wed  Thu  Fri  Sat\n" );


		for ( day = 1; day <= 1 + daycode * 5; day++ )
		{
			printf(" ");
		}


		for ( day = 1; day <= days_in_month[month]; day++ )
		{
			printf("%2d", day );


			if ( ( day + daycode ) % 7 > 0 )
				printf("   " );
			else
				printf("\n " );
		}

			daycode = ( daycode + days_in_month[month] ) % 7;
	}
}
int main(void)
{
	int year, daycode, leapyear;

	year = inputyear();
	daycode = determinedaycode(year);
	determineleapyear(year);
	calendar(year, daycode);
	printf("\n");
}
