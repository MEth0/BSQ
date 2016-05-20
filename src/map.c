/*
** map.c for BSQ in /home/morgan/rendu/CPE_2015_BSQ/src/
**
** Made by Morgan Simon
** Login   <simon_z@epitech.eu>
**
** Started on  Wed Dec 16 16:42:12 2015 Morgan Simon
** Last update Fri Dec 18 14:29:51 2015 Morgan Simon
*/

#include "my.h"

char		**free_map(char **map, t_size *size)
{
  int		i;

  i = 0;
  while (i < size->row)
    free(map[i++]);
  free(map);
  return (map);
}

char		**allocation(char **map, t_size *size)
{
  int		i;

  if ((map = malloc(size->row * sizeof(char *))) == NULL)
    return (NULL);
  i = 0;
  while (i < size->row)
    {
      if ((map[i] = malloc(size->column * sizeof(char) + 1)) == NULL)
	return (NULL);
      i++;
    }
  return (map);
}

char		**put_in_map(char *str, char **map, t_size *size)
{
  int		i;
  int		j;

  i = 0;
  while (i < size->row)
    {
      j = 0;
      while (j < size->column)
	{
	  map[i][j] = str[size->start];
	  j++;
	  size->start++;
	}
      map[i][j] = '\0';
      size->start++;
      i++;
    }
  return (map);
}

char		**malloc_map(char *str, char **map, t_size *size)
{
  char		lines[32];
  int		i;
  int		x;

  i  = 0;
  while (str[i] != '\n')
    {
      lines[i] = str[i];
      i++;
    }
  lines[i] = '\0';
  size->row = my_getnbr(lines);
  i += 1;
  size->start = i;
  x = 0;
  while (str[i] != '\n')
    {
      i++;
      x++;
    }
  size->column = x;
  map = allocation(map, size);
  return (map);
}
