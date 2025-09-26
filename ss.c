#include <stdio.h>
#include "libft/libft.h"

int main(void)
{
	char *ss = "+12.22";
	double sas= ft_atodbl(ss);
	printf("%f",sas);
}