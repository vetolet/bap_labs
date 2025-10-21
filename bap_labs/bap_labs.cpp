#include <stdio.h>
#include <locale.h>
#include "primes_finder.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	int is_prime[MAX_LIMIT + 1], n;

	char continue_answer = 'y';
	do
	{
		n = read_primes_limit();
		if (n >= 2 && n <= MAX_LIMIT)
		{
			find_primes(is_prime, n);
			print_primes(is_prime, n);
		}
		else
			printf("Число не может быть меньше 2 или больше %d\n\n", MAX_LIMIT);
		
		do
		{
			printf("Хотите продолжить? (y/n): ");

			//while(getchar() != '\n');
			//fseek(stdin, 0, SEEK_END);
			//scanf_s("%*[^\n]");
			//scanf_s("%*c");
			rewind(stdin);

			scanf_s("%c", &continue_answer, 1);
		} 
		while (continue_answer != 'y' && continue_answer != 'n');
	}
	while (continue_answer == 'y');

	return 0;
}
