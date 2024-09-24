#include "get_next_line.h"

int	main(void)
{
    int fd = open("test", O_RDONLY);
    int l_count = 0;
    char    *line;

    while((line = get_next_line(fd)))
    {
        printf("line->%i: %s\n", l_count++, line);
        free(line);
    }
    printf("line->%i: FIM\n", l_count++);

    close(fd);
	return (0);
}
