#ifndef ALCU_H
# define ALCU_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_heap   t_heap;

struct s_heap{
	int         size;
	t_heap      *previous;
};

int     is_digit(char c);
void	ft_putchar(char c);
void	ft_putstr(const char *s);
int	    read_board(int ac, char **av, int *board);
void	print_bord(int	*board, int *count);
void    start_game(int *board, int count);
#endif