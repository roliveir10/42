#ifndef SOLONG_H
# define SOLONG_H

# include "libft.h"

# define WIN_TITLE "SoLong"
# define SCREENX_MAX 1600
# define SCREENY_MAX 1600

typedef enum e_event
{
	KEYPRESS = 2,
	REDBUTTON = 17
}	t_event;

# define MAX_KEY 5

typedef enum e_key
{
	KESCAP = 53,
	KW = 13,
	KS = 1,
	KA = 0,
	KD = 2
}	t_key;

typedef struct s_img
{
	void			*img;
	unsigned int	*addr;
	int				bpp;
	int				size_line;
	int				endian;
}	t_img;

typedef struct s_mlx
{
	void			*mlx;
	void			*win;
	t_point2d		screen;
	t_img			img;
}	t_mlx;

typedef struct s_player
{
	int				pos;
}	t_player;

# define MAP_CHAR "01CEP"
# define MAP_CHAR_MAX 5

# define PLAYER 'P'
# define END 'E'
# define CONSO 'C'
# define EMPTY '0'
# define WALL '1'

typedef struct s_map
{
	char			*map;
	t_point2d		size;
}	t_map;

typedef struct s_game
{
	int				move;
	int				conso;
	int				pos_end;
	int				win;
	int				lose;
}	t_game;

typedef struct s_env
{
	t_game			game;
	t_map			map;
	t_player		p;
//	t_conso			*c;
	t_mlx			mlx;
}	t_env;

int		so_long(char *file);
char	*file_to_map(char *file, int *width, int *height);
void	solong_display(t_mlx *mlx, t_map *map);//, t_player p);//, t_conso *c);
void	exit_solong(int error, char *file, char *error_msg, void **data);

/*
** PLAYER
*/

int		player_move(t_env *env, int keycode);
int		player_valid_in_map(t_player *p, t_map *map);

/*
** CONSO
*/

int		conso_total(char *map);
int		end_point2d(t_map *map);

/*
** GAMEOVER
*/

void	game_win(void *d);

/*
**	MLX
*/

int		solong_mlx_initialize(t_mlx *mlx);
void	solong_img_write(t_img *img, int x, int y, int color);
int		solong_mlx_destroy(t_mlx *mlx);

/*
**	EVENT
*/

int		solong_close(void *d);
int		solong_keypress(int keycode, void *d);

#endif
