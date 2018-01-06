# libft - write your own library

Have you ever wondered: "wow, those functions from the standard library are so neat. How were they implemented"?
Yeah, me neither. This was a fun task to do, albeit somewhat mundane.
There are some additional gems hiding here and there - make sure you check out `ft_strtok` and `ft_strtol`.
Every function has carefully-written docstring, succinctly explaining it's behavior.

# Installation

`make`

# Usage

Compile your code with `libft.a` static library.

# Details

### Operations on list

|        function                                  |                  description                                              |
|--------------------------------------------------|---------------------------------------------------------------------------|
| `ft_lstnew(void *content, size_t content_size)`  | Create a new element of the linked list                                   |
| `ft_lstdelone(**alst, (*del)(void *, size_t))`   | Remove one element of the list by applying a function to it's content     |
| `ft_lstdel(**alst, (*del)(void *, size_t))`      | Traverse list and remove each node by applying a function to it's content |
| `ft_lstfree(void *content, size_t content_size)` |Free the content fiend of the node                                         |
| `ft_lstsize(t_list *lst) `                       |Calculate the "length" of the linked list                                  |
| `ft_lstrev(t_list **alst)`                       |Reverse list by switching pointers around                                  |
| `ft_lstiter(t_list *lst, void (*f)(t_list *)) `  |Apply function to each element of the list                                 |
| `ft_lstmap(t_list *lst, t_list (*f)(t_list *elem))` |Create a new list, modifying each node of `lst` using `f` on it         |
| `ft_lstappend(t_list **alst, t_list *new)`       |Append a new element to the list                                           |

