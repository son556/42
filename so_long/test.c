#include <stdio.h>
#include <stdlib.h>

char	*ft_itoa(int n)
{
	int			i;
	int			x;
	char		*result;
	char		*str;

	str = "0123456789";
	x = n;
	i = 0;
	if (n == -2147483648)
		return ("-2147483648");
	if (n == 0)
		return ("0");
	while (x)
	{
		x /= 10;
		i++;
	}
	if (n >= 0)
	{
		result = (char *)malloc(sizeof(char) * i);
		i--;
	}
	else
	{
		result = (char *)malloc(sizeof(char) * (i + 1));
		result[0] = '-';
		n *= -1;
	}
	x = 0;
	while (n)
	{
		x = n % 10;
		n /= 10;
		result[i] = '0' + x;
		i--;
	}
	return (result);
}

int main()
{
	int n = 10;
	char	*line = ft_itoa(n);
	printf("result: %s\n", line);
	free(line);
	system("leaks a.out");
}
