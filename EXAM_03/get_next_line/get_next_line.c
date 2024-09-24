#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h> //manipulate the fd
#include <unistd.h> //read function

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

char    *ft_strdup(char *src)
{
    int i = 0;
    char    *dest = NULL;

    while (src[i])
        i++;
    dest = (char *)malloc(sizeof(char) * (i + 1));
    i = 0;
    while (src[i])
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return(dest);
}

char *get_next_line(int fd)
{
    static char buffer[BUFFER_SIZE]; // why static?
    char        line[70000];
    static int  buffer_read = 0; // why static?
    static int  buffer_pos = 0; // why static?
    int i = 0;

    if(fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    while(1)
    {
        if(buffer_pos >= buffer_read) //buffer_read will only be used if buffer_pos got to the end
        {
            buffer_read = read(fd, buffer, BUFFER_SIZE);
            buffer_pos = 0;
            printf("%i\n", buffer_read); 
            if(buffer_read <= 0) //if no bytes were read (in case there i nothing else to be read from the fd), break the loop
                break ;
        }
        line[i++] = buffer[buffer_pos++];
        if(line[i - 1] == '\n') // loop breaks if encounters a '\n' - subtract 1?
            break ;
    }
    line[i] = '\0';
    if(i == 0) //if no bytes were read, return NULL
        return (NULL);
    return (ft_strdup(line)); // returns the line to be printed
}


/*int main(void)
{
    /*char    *src = "Hello, hello";
    char    *res;
    int i = 0;

    i = printf("%s\n", src);
    printf("byte count src: %i\n", i);
    res = ft_strdup(src);
    i = printf("%s\n", res);
    printf("byte count res: %i\n", i);
    */
    
    return (0);
}*/
