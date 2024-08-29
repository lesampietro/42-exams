typedef struct    s_list // declare the node struct in the file
{
    struct s_list *next;
    void          *data;
}                 t_list;

int	ft_list_size(t_list *begin_list)
{
    int size = 0;

    while(begin_list) // it might be not necessary to verify if the list is empty beforing entering while
    {
        size++;
        begin_list = begin_list->next;
    }
    return(size);
}