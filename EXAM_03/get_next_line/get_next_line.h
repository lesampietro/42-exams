#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h> //manipulate the fd (open function)
#include <unistd.h> //read function

char    *get_next_line(int fd);

#endif