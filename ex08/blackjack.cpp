#include <iostream>

using namespace std;

int blackjack(char **av)
{
	int i = 0, count = 0;
	int aces = 0;
	while (av[1][i] != '\0')
	{
		if(av[1][i] >= '2' && av[1][i] <= '9')
			count += av[1][i] - '0';
		else if(av[1][i] == 'T' || av[1][i] == 'J' ||av[1][i] == 'D' || av[1][i] == 'K')
			count += 10;
		else if(av[1][i] == 'A')
		{
			count += 11;
			aces++;
		}
		else
		{
			cout << "invalid cards" << endl;
			exit(EXIT_FAILURE);
		}
		i++;
	}
	while (count > 21 && aces--)
		count -= 10;
	return (count);
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		cout << "wrong arguments format" << endl;
		return(EXIT_FAILURE);
	}
	int count = blackjack(argv);
	if (count == 21)
		cout << "Blackjack!" << endl;
	else
		cout << count << endl;
	return (EXIT_SUCCESS);
}