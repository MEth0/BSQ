/*
** my_atoi.c for BSQ in /home/simon_z/rendu/CPE/Bonus_BSQ
**
** Made by Morgan SIMON
** Login   <simon_z@epitech.net>
**
** Started on  Fri May 20 16:46:06 2016 Morgan SIMON
** Last update Fri May 20 16:46:10 2016 Morgan SIMON
*/

int     my_getnbr(char *p)
{
  int   i;
  char  *n;

  i = 0;
  n = (*p == '-' ? p++ : 0);
  while (*p)
    i = i * 10 + *p++ - '0';
  return (n ? -i : i);
}
