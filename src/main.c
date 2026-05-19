# include "include/alcu.h"
#include <stdio.h>

int	main(int argc, char **argv){
	int		board[100];
	int		count;

	if (argc > 2){
		write(2, "Error: Invalid number of parameters!\n", 37);
		return (-1);
	}
	count = read_board(argc, argv, board);
	if (count <= 0)
	{
		write(2, "Error: Invalid map file!\n", 26);
		return (-1);
	}
	start_game(board, count - 1);
	return (0);
}