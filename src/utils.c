#include "include/alcu.h"

void	ft_putchar(char c){
	write(1, &c, 1);
}

void	ft_putstr(const char *s){
	while (*s){
		ft_putchar(*s);
		s++;
	}
}

int	is_digit(char c){
	return (c >= '0' && c <= '9');
}

void	print_bord(int	*board, int *count){
	int		line;
	int		i;

	line = 0;
	ft_putchar('\n');
	while (line <= (*count)){
		i = 0;
		while (i < board[line]){
			ft_putstr(" | ");
			i ++;
		}
		ft_putchar('\n');
		line ++;
	}
	ft_putchar('\n');
}