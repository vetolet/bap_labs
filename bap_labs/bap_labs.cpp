#include <stdio.h>
#include <locale.h>
#include "matrix_rotation.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	int a[SIZE_MAX_LIMIT][SIZE_MAX_LIMIT], n, block_size;
	bool is_clockwise, is_continue = true;

	printf("Программа поворачивает блоки размером n*n в массиве 2n*2n но часовой или против часовой стрелки\n");
	do
	{
		block_size = input_block_size();
		n = block_size * 2;
		if (n == 0)
		{
			printf("Неправильный размер блока\n\n");
			continue;
		}

		input_2d_array(a, n, n);
		
		printf("Входной массив:\n");
		print_2d_array(a, n, n);
		
		is_clockwise = ask_clockwise();
		move_blocks(a, block_size, is_clockwise);

		printf("\nМассив после преобразования:\n");
		print_2d_array(a, n, n);
		
		is_continue = ask_continue();
		
		printf("====================\n\n");
	}
	while (is_continue);

	return 0;
}
