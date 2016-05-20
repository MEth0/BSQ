/*
** my.h for my in /home/morgan/rendu/CPE_2015_BSQ/src
**
** Made by Morgan Simon
** Login   <morgan@epitech.net>
**
** Started on  Mon Dec  7 19:49:45 2015 Morgan Simon
** Last update Sun Dec 20 15:30:02 2015 Morgan Simon
*/

#ifndef MY_H_
# define MY_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct	s_size
{
  int		row;
  int		column;
  int		start;
  int		square;
  int		x;
  int		y;
}		t_size;

char		**free_map(char **map, t_size *size);
char		**allocation(char **map, t_size *size);
char		**put_in_map(char *str, char **map, t_size *size);
char		**malloc_map(char *str, char **map, t_size *size);
void    	my_putchar(char c);
int     	my_strlen(char *str);
void    	my_putstr(char *str);
int     	my_getnbr(char *str);
int		**alloc_square(t_size *size, int **square);
void		fill_square(t_size *size, char **map, int **square);
void		get_square(t_size *size, char **map, int **square);
void		big_square(t_size *size, int **square);
void		print_res(t_size *size, char **map);

#endif /* !MY_H_ */
