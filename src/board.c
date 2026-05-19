#include "include/alcu.h"


int	read_board(int ac, char **av, int *board){
	char	c;
	int		fd;
	int		number;
	int		count;
	int		has_digit;

	fd = 0;
	if (ac == 2){
		fd = open(av[1], O_RDONLY);
		if (fd < 0){
			return (-1);
		}
	}
	number = 0;
	has_digit = 0;
	count = 0;
	while (read(fd, &c, 1) > 0){
		if (is_digit(c)){
			number = number * 10 + (c - '0');
			has_digit = 1;
		}
		else{
			if (c == '\n'){
				if (has_digit == 0){
					if (fd != 0){
						close(fd);
					}
					return (count);
				}
				board[count++] = number;
				number = 0;
				has_digit = 0;
			}
			else{
				if (fd != 0){
					close(fd);
				}
				return (-1);
			}
		}
	}

	if (fd != 0){
		close(fd);
	}
	return (count);
}