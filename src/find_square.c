/*
** find_square.c for BSQ in /home/morgan/rendu/CPE_2015_BSQ/src/
**
** Made by Morgan Simon
** Login   <simon_z@epitech.eu>
**
** Started on  Sun Dec 20 14:53:22 2015 Morgan Simon
** Last update Sun Dec 20 16:34:01 2015 Morgan Simon
*/

#include "my.h"

int	**alloc_square(t_size *size, int **square)
{
  int	i;

  i = 0;
  if ((square = malloc(sizeof(int*) * size->row)) == NULL)
    return (NULL);
  while (i < size->row)
    {
      if ((square[i] = malloc(sizeof(int) * size->column)) == NULL)
	return (NULL);
      i++;
    }
  return (square);
}

void	fill_square(t_size *size, char **map, int **square)
{
  int	i;

  i = 0;
  while (map[size->row - 1][i])
    {
      if (map[size->row - 1][i] == '.')
	square[size->row -1][i] = 1;
      else
	square[size->row -1][i] = 0;
      i++;
    }
  i = 0;
  while (i < size->row)
    {
      if (map[i][size->column - 1] == '.')
	square[i][size->column - 1] = 1;
      else
	square[i][size->column - 1] = 0;
      i++;
    }
}

void		get_square(t_size *size, char **map, int **square)
{
  int		i;
  int		j;
  int		min;

  size->square = 0;
  j = size->row - 2;
  while (j >= 0)
    {
      i = size->column - 2;
      while (i >= 0)
	{
	  if (map[j][i] == '.')
	    {
	      (square[j][i + 1] < square[j + 1][i + 1]) ?
	      (min = square[j][i + 1]) : (min = square[j + 1][i + 1]);
	      (min > square[j + 1][i]) ? (min = square[j + 1][i]) : (0);
	      square[j][i] = min + 1;
	    }
	  else
	    square[j][i] = 0;
	  i--;
	}
      j--;
    }
}

void		big_square(t_size *size, int **square)
{
  int		i;
  int		j;

  size->square = 0;
  j = size->row - 1;
  while (j >= 0)
    {
      i = size->column - 1;
      while (i >= 0)
	{
	  if (square[j][i] >= size->square)
	    {
	      size->square = square[j][i];
	      size->x = i;
	      size->y = j;
	    }
	  i--;
	}
      j--;
    }
}

void		print_res(t_size *size, char **map)
{
  int		i;
  int		j;
  int		max_x;
  int		max_y;

  max_x = size->x + size->square;
  max_y = size->y + size->square;
  j = 0;
  while (j < size->row)
    {
      i = 0;
      while (i < size->column)
	{
	  if ((i >= size->x && i < max_x) &&
	      (j >= size->y && j < max_y))
	    write(1, "\033[1;32mx\033[m", 11);
	  else
	    write(1, &map[j][i], 1);
	  i++;
	}
      write(1, "\n", 1);
      j++;
    }
}
