/*
** main.c for BSQ in /home/simon_z/rendu/CPE_2015_BSQ/src
**
** Made by Morgan Simon
** Login   <simon_z@epitech.net>
**
** Started on  Mon Nov 30 11:11:34 2015 Morgan Simon
** Last update Sun Dec 20 15:34:24 2015 Morgan Simon
*/

#include "my.h"

int		**free_square(int **square, t_size *size)
{
  int		i;

  i = 0;
  while (i < size->row)
    free(square[i++]);
  free(square);
  return (square);
}

void	check_file(char *buf)
{
  int	i;

  i = 0;
  while (buf[i] != '\n')
    {
      if (buf[i] < '0' || buf[i] > '9')
	{
	  free(buf);
	  exit (1);
	}
      i++;
    }
  if (buf[i+1] == '\0')
      exit (1);
  while (buf[i])
    {
      if (buf[i] != '.' && buf[i] != 'o' && buf[i] != '\n' && buf[i] != '\0')
	{
	  free(buf);
	  exit (1);
	}
      i++;
    }
}

int		bsq(char *buf)
{
  t_size	*size;
  char		**map;
  int		**square;

  map = NULL;
  square = NULL;
  if ((size = malloc(sizeof(t_size))) == NULL)
    return (1);
  map = malloc_map(buf, map, size);
  map = put_in_map(buf, map, size);
  square = alloc_square(size, square);
  fill_square(size, map, square);
  get_square(size, map, square);
  big_square(size, square);
  print_res(size, map);
  free_map(map, size);
  free_square(square, size);
  free(size);
  return (0);
}

int		main(int ac, char **av)
{
  int		file;
  char		*buf;
  struct stat	st;
  ssize_t	ret;
  int		size;

  if (ac != 2)
    exit(1);
  if ((file = open(av[1], O_RDONLY)) < 0)
    exit(1);
  stat(av[1], &st);
  size = st.st_size;
  if ((buf = malloc(sizeof(char) * size + 1)) == NULL)
    return (1);
  if ((ret = read(file, buf, size)) <= 0)
    exit(1);
  buf[ret] = '\0';
  check_file(buf);
  bsq(buf);
  close(file);
  free(buf);
  return (0);
}
