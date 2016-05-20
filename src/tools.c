/*
** tools.c for tools in /home/morgan/rendu/CPE_2015_BSQ/src
**
** Made by Morgan Simon
** Login   <morgan@epitech.net>
**
** Started on  Mon Dec  7 19:47:40 2015 Morgan Simon
** Last update Sun Dec 20 16:33:27 2015 Morgan Simon
*/

#include <unistd.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

void	my_putstr(char *str)
{
  write(1, str, my_strlen(str));
}
