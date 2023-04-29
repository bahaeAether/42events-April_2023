#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count_longest_word(char *av)
{
	int i = 0;
	int j = 0;
	int n = 0;
	while(av[i] != '\0')
	{
		while(av[i] != ' ' && av[i] != '\0')
		{
			i++;
			n++;
		}
		while(av[i] == ' ' && av[i] != '\0')
			i++;
		if(n > j)
			j = n;
		n = 0;
	}
	return j;
}
int main(int argc, char **argv)
{
	int n = 0;
	int x = 0;
	int i = 1;
	int j = 0;
	int count = 0;
	char *av;

	if(argc > 1)
	{
		while (i < argc)
			count += strlen(argv[i++]) + 1;
		i = 1;
		av = malloc(count + 1);
		if (!av)
			exit(EXIT_FAILURE);
		av[count] = 0;
		strlcpy(av, argv[1], strlen(argv[1]) + 1);
		while (++i < argc)
		{
			strlcat(av, " ", strlen(av) + 2);
			strlcat(av, argv[i], strlen(av) + strlen(argv[i]) + 1);
		}


		i = count_longest_word(av);
		while(j  < i + 4)
		{
			printf("*");
			j++;
		}
		printf("\n");
		j = 0;
		while(av[j] != '\0')
		{
			x = 0;
			n = 0;
			printf("* ");
			while(av[j] == ' ')
				j++;
			while(av[j] != ' ' && av[j] != '\0')
			{
				printf("%c", av[j]);
				j++;
				x++;
			}
			if(av[j] == ' ' && av[j + 1] != '\0')
			{
				while(n < i - x + 1)
				{
					printf(" ");
					n++;
				}
				// printf("%d %d", n, x);
				printf("*\n");
			}
			while(av[j] == ' ')
				j++;
		}
		while(n < i - x + 1)
		{
			printf(" ");
			n++;
		}
		printf("*\n");
		j = 0;
		while(j < i + 4)
		{
			printf("*");
			j++;
		}
		printf("\n");
		free (av);
	}
}