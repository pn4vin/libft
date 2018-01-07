NAME = libft.a
FLAGS = -Wall -Wextra -Werror
HDRS = libft.h ft_printf.h
HEADERS_DIR = include/
HEADERS = ${addprefix $(HEADERS_DIR), $(HDRS)}
OBJS = ft_putnbr.o ft_putchar.o ft_putstr.o ft_isalpha.o ft_atoi.o ft_bzero.o \
		ft_isalnum.o ft_isalpha.o ft_isascii.o ft_isdigit.o ft_isprint.o  \
		ft_memccpy.o ft_memchr.o ft_memcmp.o ft_memcpy.o ft_memmove.o\
		ft_memset.o ft_strchr.o ft_strcmp.o ft_strlen.o ft_strncmp.o\
		ft_strnstr.o ft_strstr.o ft_tolower.o ft_toupper.o ft_strrchr.o\
		ft_strdup.o ft_strcpy.o ft_strncpy.o  ft_strcat.o ft_strncat.o  \
		ft_strlcat.o  ft_memalloc.o ft_memdel.o ft_strnew.o ft_strdel.o\
		ft_strclr.o ft_striter.o ft_striteri.o  ft_strmap.o ft_strmapi.o \
		ft_strequ.o  ft_strnequ.o ft_strsub.o ft_strjoin.o ft_strtrim.o \
		ft_strsplit.o ft_itoa.o  ft_putendl.o ft_putnbr.o ft_putchar_fd.o\
		ft_putstr_fd.o ft_putendl_fd.o ft_putnbr_fd.o ft_lstnew.o ft_lstdelone.o\
		ft_lstdel.o  ft_lstadd.o ft_lstiter.o ft_lstmap.o ft_abs.o ft_atol.o \
		ft_strtol.o ft_ctoi_base.o ft_itoa_base.o ft_torot13.o ft_isspace.o \
		ft_lstappend.o ft_putlst.o ft_lstsize.o ft_lstrev.o ft_lstfree.o \
		ft_slen.o ft_strtok.o ft_strtoutf8.o ft_get_next_line.o ft_isupper.o \
		ft_wchrlen.o ft_wcstombs.o ft_wctomb.o ft_wcslen.o ft_printf.o \
		ft_dprintf.o ft_sprintf.o ft_printf_convertors.o ft_printf_lst.o \
		ft_printf_tools.o ft_printf_parsers.o ft_printf_posargs.o \
		ft_printf_put_misc.o ft_printf_put_numbers.o ft_printf_put_strings.o
OBJDIR = objs
OBJECTS = ${addprefix ${OBJDIR}/, $(OBJS)}

.NOTPARALLEL: re fclean clean all

.PHONY: all clean re fclean

all: $(NAME)

$(NAME): $(OBJECTS)
	@ ar rc $(NAME) $(OBJECTS)
	@ ranlib $(NAME)

${OBJDIR}/%.o: %.c $(HEADERS)
	@ mkdir -p ${OBJDIR}
	gcc -c $(FLAGS) -o $@ $<

clean:
	 @ /bin/rm -f $(OBJECTS)
	 @ /bin/rm -rf ${OBJDIR}

fclean: clean
	 @ /bin/rm -f $(NAME)

re: fclean all
