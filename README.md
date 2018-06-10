# libft - write your own library

Have you ever wondered: "wow, those functions from the standard library are so neat. How were they implemented"?
Yeah, me neither. This was a fun task to do, albeit somewhat mundane.
There are some additional gems hiding here and there - make sure you check out `ft_strtok` and `ft_strtol`.
Every function has carefully-written docstring, succinctly explaining it's behavior.

# Installation

`make`, duh.

# Usage

Compile your code with `libft.a`: `gcc kittens_are_cute.c -L . -l ft`.

## Custom functions

#### ft_gnl
|        function                                  |                  description                                              |
|--------------------------------------------------|---------------------------------------------------------------------------|
| `ft_sgnl(int fd, char **line)`               | Stripped `ft_gnl`. No multi-fd, some overall improvements. Preffered way of reading a file   |
| `ft_gnl_v2(int fd, t_line *line, t_bool lb)` | `ft_gnl` for binary files. Uses `t_line` structure to store the actual length of the string, since `ft_slen()` <br /> will lie to you if there are any null-terminators (`\0`) before the actual end of the string. |
| `ft_tline_join()`, `ft_tline_replace()` | Special functions operating on `t_line` structure to join two `t_line`s or replace one with another, respectively |

#### ft_memory
|        function                                  |                  description                                              |
|--------------------------------------------------|---------------------------------------------------------------------------|
| `ft_realloc()`                                   | Realloc memory by copy, releasing the old memory optionally               |
| `ft_memcpy_fwd()`                                | Forward copy of memory   |
| `ft_memrelease()`                                | Release the memory, returning the address. Useful for pipelining it in if or smth |

#### ft_printf
|        function                                  |                  description                                              |
|--------------------------------------------------|---------------------------------------------------------------------------|
| `ft_dprintf(int fd, char *format, ...)`         | Same as `ft_printf()`, but instead of STDOUT, writes the result into fd. Simple enough |
| `ft_sprintf(char *format, ...)`                 | Returns a string, instead of the number of bytes written to stdout |

#### ft_str
|        function                                  |                  description                                              |
|--------------------------------------------------|---------------------------------------------------------------------------|
| `ft_slen()`    | safe analogue to `ft_strlen()`             |
| `ft_concat()`                                    | Concatenate two strings, optionally freeing both of them                   |
| `ft_startswith(char *str, char *prefix)`         | Check if `str` starts with `prefix`                                          |
| `ft_endswith(char *str, char *suffix)`         | Check if `str` ends with `suffix`                                          |
| `ft_sjoin()`   | concatenate nul-terminated strings together |
| `ft_strispaces()` | check if string consists of space characters |
| `ft_strtok(char *str, char *sep)`                | Cut `str` in tokens separating by `sep`. If called with `NULL` in `str`, returns the next token of the not-`NULL` call |
| `ft_strtoutf8()`  | Convert `char` string to `wchar_t` string |
| `ft_strtrim()`    | Create a string by trimming spaces from both ends |
| `ft_strtrunc()`   | Truncate string if its length exceeds the `len` argument. Freeing optionally |
| `ft_strtorot13()` | ROT13 substitution applied to string |
| `ft_wchrlen()`    | Length of wide char in bytes |
| `ft_wcslen()`     | Length of `wchar_t` string in bytes |
| `ft_wctomb()`     | Convert `wchar_t` to multibyte representation |
| `ft_wcstombs()`   | Convert `wchar_t` string to multibyte sequence |

#### ft_strnum
|        function                                  |                  description                                              |
|--------------------------------------------------|---------------------------------------------------------------------------|
| `ft_strisnum(char *str, size_t base)`            | Check if the given string consists only of digits in the given base. Digits are uppercase (e.g. `ft_strisnum("FFF", 16)` returns `TRUE` |

#### ft_tell
|        function                                  |                  description                                              |
|--------------------------------------------------|---------------------------------------------------------------------------|
| `ft_panic(char *message, int where, int exit_value)` | Output `message` to `where` (FD) and stop program execution with `exit_value` return value |

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

