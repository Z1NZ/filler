#ifndef FILLER_H

#define FILLER_H
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <limits.h>
#include <sys/wait.h>

#define BUFF_SIZE 1024

#define CHECK_BIT(var,pos)	(var & pos)
#define OPT_PLAYER_SET				1
#define OPT_PLAYER1					2
#define OPT_PLAYER2					4
#define OPT_MAP_SET					8
#define OPT_PIECE_SET				16
#define OPT_PLATEAU_SET				32
#define OPT_PIECE_FULL				64
# define COLOR 1

# define RIGHT 1
# define MIDLE 2
# define LEFT  3
# define ABS(number)			(number < 0) ? -(number) : (number)


typedef struct s_piece
{
	int	x;
	int	y;
	int	curent;
	char 			**piece;
}				t_piece;

typedef struct	s_pos
{
	int	x;
	int	y;
	struct s_pos	*next;
}				t_pos;

typedef struct	s_map
{
	char 		**map;
	int	x;
	int	y;
}				t_map;


typedef struct	s_data
{
	int			status;
	t_map		map;
	t_piece		piece;
	t_pos		*pos;
}				t_data;

/*
**
*/

void 	ft_color(char *line);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char const *s, int fd);
/*
** libft
*/
char	*ft_strstr(const char *str, const char *to_find);
int		get_next_line(int const fd, char **line);
void	ft_bzero(void *s, int n);
void	*ft_memalloc(size_t size);
void	*ft_memset(void *b, int c, size_t len);
char	*ft_strchr(const char *s, int c);
char	*ft_strcpy(char *s1, const char *s2);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
char	*ft_strnew(size_t size);
char	**ft_strsplit(char const *s, char c);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
int		ft_isspace(int c);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
void	ft_memdel(void **ap);
int		ft_tablen(char **tab);
void	get_set_piece(t_data *data, char *line);
void	get_piece(t_data *data, char *line);
int		check_piece(char *line);
void	debug(t_data *data);
char	*ft_strtrim(char const *s);
void	ft_striter(char *s, void (*f)(char *));
void	ft_print_tab(char **tab);
void	ft_free(t_data *data);
void	ft_del_list(t_pos * pos);
void	tab_free(char **str);
void	ft_putnbr(int n);
/*
** filler
*/
void	ft_error();
int		check_digit(char *tmp);
void	get_set_map(t_data *data, char *line);
void	get_player(t_data *data, char *line, char *exe);
void	get_map(t_data *data, char *line);
void	resolve(t_data *data);
void	add_pos(t_data *data, int x, int y);
/*
**	LIST POS
*/
t_pos	*top_list(t_data *data, int pos);
t_pos		*bot_list(t_data *data, int pos);

#endif
