#Include <stdio.h>
#Include <math.h>

int main ()
{
	int fullInteger, digitSeperate;
	
	printf("Enter a 5 digit integer:");
	scanf("%i, &fullInteger);
	
	for (i=5; i>0; i--;)
	{
		digitSeperate = fullInteger / 10^i;
		floor(digitSeperate);
		fullInteger = fullInteger % 10^i;
		printf(" %i   ", digitSeperate);
	}
	
	digitSeperate = fullInteger % 10;
	printf("%i", digitSeperate);
}