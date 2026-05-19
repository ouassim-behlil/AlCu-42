#include "include/alcu.h"
#include <stdio.h>

static int	get_user_number(){
	int		n;
	char	c;

	n = 0;
	ft_putstr("Please choose between 1 and 3 items\n");
	while (read(0, &c, 1) > 0){
		if (is_digit(c)){
			n = n * 10 + (c - '0');
		}
		else if (c == '\n'){
			return (n);
		}
		else{
			return (0);
		}
	}
	return (n);
}

void	human_turn(int *board, int *count){
	int		remaining;
	int		n;

	remaining = board[*count];
	n = get_user_number();
	while (n < 1 || n > 3 || n > remaining){
		ft_putstr("Invalid choide\n");
		n = get_user_number();
	}
	board[*count] -= n;
	ft_putstr("\nYou took ");
	ft_putchar(n + '0');
	ft_putchar('\n');
	if (board[*count] == 0){
		(*count)--;
	}
}

int ai_move(int N){
    int		r;

	r = N % 4;
    if (r == 0){
		return (3);
	}
    if (r == 3){
		return (2);
	}
	return (1);
}

void	ai_turn(int *board, int *count){
	int		n;

	n = ai_move(board[*count]);
	board[*count] -= n;
	ft_putstr("\nAI took ");
	ft_putchar(n + '0');
	ft_putchar('\n');
	if (board[*count] == 0){
		(*count)--;
	}
}

int	end_game(int count){
	if (count < 0){
		return (1);
	}
	return (0);
}

void    start_game(int *board, int count){
	while (1){
		print_bord(board, &count);
		human_turn(board, &count);
		if (end_game(count)){
			ft_putstr("AI is the winner, good luck next time.\n");
			return ;
		}
		print_bord(board, &count);
		ai_turn(board, &count);
		if (end_game(count)){
			ft_putstr("You are the winner! Congratulations!\n");
			return ;
		}
	}
}