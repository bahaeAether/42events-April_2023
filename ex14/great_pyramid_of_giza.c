#include <stdlib.h>
#include <stdio.h>

int	str_is_numeric(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int		offset_calc(int n)
{
	return((n + 4) / 2);
}

int		base_calc(int n)
{
	if (n == 1)
		return (7);
	return (base_calc(n - 1) + 2*(n + 1) + 2*offset_calc(n));
}

void	print_line(int n, int max)
{
	int i = -1;

	max /= 2;
	while (++i < max - n / 2)
		printf(" ");
	printf("/");
	i = -1;
	while(++i < n - 2)
		printf("*");
	printf("\\\n");

}

void	print_door(int n, int max, int width) // prints a line that has a door in it (pipes | )
{
	int i = -1;

	max /= 2;
	while (++i < max - n / 2)
		printf(" ");
	printf("/");
	i = -1;
	while(++i < n/2 - width/2 - 1)
		printf("*");
	i = -1;
	while(++i < width)
		printf("|");
	i = -1;
	while(++i < n/2 - width/2 - 1)
		printf("*");
	printf("\\\n");

}

void	print_key(int n, int max, int width) // prints a line that has the key in it (dollar sign $)
{
	int i = -1;

	max /= 2;
	while (++i < max - n / 2)
		printf(" ");
	printf("/");
	i = -1;
	while(++i < n/2 - width/2 - 1)
		printf("*");
	i = -1;
	while(++i < width - 2)
		printf("|");
	printf("$|");
	i = -1;
	while(++i < n/2 - width/2 - 1)
		printf("*");
	printf("\\\n");

}

void	print_layer(int n, int max)
{
	int i = -1;

	while (++i < n + 2)
		print_line(base_calc(n) - 2*(n + 1) + 2*i, max);
}

void	print_final_layer(int n)
{
	int i = -1;

	while (++i < 2 + (n + 1) % 2)
		print_line((base_calc(n) - 2*(n + 1) + 2*i), base_calc(n));
	while (i < (n - 1)/2 + (n + 1)%2 + 2)
		print_door((base_calc(n) - 2*(n + 1) + 2*i++), base_calc(n), n - ((n + 1) % 2));
	if(n > 4)
		print_key((base_calc(n) - 2*(n + 1) + 2*i++), base_calc(n), n - ((n + 1) % 2));
	while (i < n + 2)
		print_door((base_calc(n) - 2*(n + 1) + 2*i++), base_calc(n), n - ((n + 1) % 2));

}

void	sastantua(int n)
{
	int i = 0;

	while (++i < n)
		print_layer(i, base_calc(n));
	print_final_layer(n);
}


int main(int ac, char ** av)
{
	if (ac == 2)
		if (str_is_numeric(av[1])  && atoi(av[1]) > 0)
			sastantua(atoi(av[1]));
		else
		{
			printf("wrong arguments format");
			exit(EXIT_FAILURE);
		}
	else
	{
		printf("wrong arguments count");
		exit(EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}