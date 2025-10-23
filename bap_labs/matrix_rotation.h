#pragma once

#define MAX_SIZE 8

int input_block_size();
void input_2d_array(float a[MAX_SIZE][MAX_SIZE], int n, int m);
void move_blocks(float a[MAX_SIZE][MAX_SIZE], int n, bool is_clockwise);
void shift_array(float old_values[], float new_values[], int n, int shift);
void print_2d_array(float a[MAX_SIZE][MAX_SIZE], int n, int m);

bool ask_clockwise();
bool ask_continue();