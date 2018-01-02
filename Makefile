
NAME = libft.a

FLAGS = -c -Wall -Wextra -Werror

HEADER = libft.h

SRCS = ft_putnbr.c ft_putchar.c ft_putstr.c ft_isalpha.c ft_atoi.c ft_bzero.c \
	   ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c  \
	   ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c\
	   ft_memset.c ft_strchr.c ft_strcmp.c ft_strlen.c ft_strncmp.c\
	   ft_strnstr.c ft_strstr.c ft_tolower.c ft_toupper.c ft_strrchr.c\
	   ft_strdup.c ft_strcpy.c ft_strncpy.c  ft_strcat.c ft_strncat.c  \
	   ft_strlcat.c  ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c\
	   ft_strclr.c ft_striter.c ft_striteri.c  ft_strmap.c ft_strmapi.c \
	   ft_strequ.c  ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c \
	   ft_strsplit.c ft_itoa.c  ft_putendl.c ft_putnbr.c ft_putchar_fd.c\
	   ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c\
	   ft_lstdelone.c ft_lstdel.c  ft_lstadd.c ft_lstiter.c ft_lstmap.c\
	   ft_abs.c ft_atol.c ft_strtol.c ft_ctoi_base.c ft_itoa_base.c\
	   ft_torot13.c ft_isspace.c ft_lstappend.c ft_putlst.c ft_lstsize.c \
	   ft_lstrev.c ft_lstfree.c ft_slen.c ft_strtok.c ft_strtoutf8.c\
	   ft_get_next_line.c ft_isupper.c

OBJDIR = objs

BINS = ${addprefix ${OBJDIR}/, $(SRCS:.c=.o)}

.NOTPARALLEL: re fclean clean all

.PHONY: all clean re fclean

all: $(NAME)

$(NAME): $(BINS)
	@ ar rc $(NAME) $(BINS)
	@ ranlib $(NAME)

${OBJDIR}/%.o: %.c $(HEADER)
	@ mkdir -p ${OBJDIR}
	gcc   $(FLAGS) -o  $@ $<

clean:
	 @ /bin/rm -f $(BINS)
	 @ /bin/rm -rf ${OBJDIR}

fclean: clean
	 @ /bin/rm -f $(NAME)

re: fclean all
