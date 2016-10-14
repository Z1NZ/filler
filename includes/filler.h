#ifndef FILLER_H

# define FILLER_H
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <unistd.h>
# include <sys/wait.h>

# define BUFF_SIZE 1024
/*
**
*/


/*
** libft
*/
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
/*
**
*/

#endif
