#pragma once

#define SIZE_MAX_LIMIT 8

int input_block_size();
void input_2d_array(int a[SIZE_MAX_LIMIT][SIZE_MAX_LIMIT], int n, int m);
void move_blocks(int a[SIZE_MAX_LIMIT][SIZE_MAX_LIMIT], int n, bool is_clockwise);
void shift_array(int old_values[], int new_values[], int n, int shift);
void print_2d_array(int a[SIZE_MAX_LIMIT][SIZE_MAX_LIMIT], int n, int m);

bool ask_clockwise();
bool ask_continue();