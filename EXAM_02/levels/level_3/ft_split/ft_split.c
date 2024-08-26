/*Assignment name  : ft_split
Expected files   : ft_split.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write a function that takes a string, splits it into words, and returns them as
a NULL-terminated array of strings.

A "word" is defined as a part of a string delimited either by spaces/tabs/new
lines, or by the start/end of the string.

Your function must be declared as follows:

char    **ft_split(char *str);*/

#include <stdlib.h>

char    *ft_strncpy(char *s1, char *s2, int n)
{
    int i = -1;

    while(++i < n && s2[i])
        s1[i] = s2[i];
    s1[i] = '\0'; //do not forget to null terminate the string!
    return(s1);
}

int ft_isspace(char c)
{
    return(c == ' ' || c == '\t' || c == '\n');
}

char **ft_split(char *av)
{
    int i = 0;
    int j = 0;
    int k = 0; //is the index for the new string array
    int word_count = 0;

while (av[i]) //first loop to check how many words are there and alocate the array of strings
	{
		while (av[i] && (av[i] == ' ' || av[i] == '\t' || av[i] == '\n')) //iterate until no space characters are found
			i++;
		if (av[i]) //find a character that isn't in the "space" espectrum, increment word count
			word_count++;
		while (av[i] && (av[i] != ' ' && av[i] != '\t' && av[i] != '\n')) //iterate till the end of the word - until finding space 
			i++;
	}
	
	char **words = (char **)malloc(sizeof(char *) * (word_count + 1));
	i = 0;
	
	while (av[i]) //second loop to create strings for the new array by copying it from the original input
	{
		while (av[i] && (av[i] == ' ' || av[i] == '\t' || av[i] == '\n'))
			i++;
		j = i; //marking the index of the word's first character
		while (av[i] && (av[i] != ' ' && av[i] != '\t' && av[i] != '\n'))
			i++; //marking the index for word's last character
		if (i > j)
		{
			words[k] = (char *)malloc(sizeof(char) * ((i - j) + 1)); //allocating memory for the word using both indexes (i and j)
			ft_strncpy(words[k++], &av[j], i - j);
		}
	}
	words[k] = NULL; //use NULL to mark the end of the wrd array
	return (words);
}
