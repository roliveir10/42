#include "solong.h"

void	game_win(void *d)
{
	ft_putendl("Congratulation You Win !");
	solong_close(d);
}

void	game_over(void *d)
{
	ft_putendl("Game Over");
	solong_close(d);
}
