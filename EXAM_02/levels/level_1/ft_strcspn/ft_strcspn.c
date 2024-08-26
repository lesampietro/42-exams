/*Assignment name	: ft_strcspn
Expected files	: ft_strcspn.c
Allowed functions: None
---------------------------------------------------------------

Reproduce exactly the behavior of the function strcspn
(man strcspn).

The function should be prototyped as follows:

size_t	ft_strcspn(const char *s, const char *reject);*/

#include <stddef.h> //for size_t

//The C library function strcspn() calculates the length of the number 
//of characters before the 1st occurrence of character present in both the string.
size_t	ft_strcspn(const char *s, const char *reject)
{
    int i = 0;
    int j = 0;
    size_t  result = 0;
    while(s[i]){
        j = 0;
        while(reject[j])
        {
            if(reject[j] == s[i])
            {
                result = i;
                return(result);
            }
            j++;
        }
        i++;
    }
    result = i; //if there are no matching characters, return the size of *s;
    return(result);
}

//SIZE_T
//size_t is a special unsigned integer type defined in the standard library of C and C++ languages. 
//It is the type of the result returned by the sizeof and alignof operators. 
//The size_t is chosen so that it can store the maximum size of a theoretically possible array or an object.