LIBNAME = libft.a
ODIR = ./obj

FLAGS = -Wall -Wextra -Werror

# COLORS

BLACK = '\033[0;30m'
RED = '\033[0;31m'
GREEN = '\033[0;32m'
BROWN = '\033[0;33m'
BLUE = '\033[0;34m'
PURPLE = '\033[0;35m'
CYAN = '\033[0;36m'
LGRAY = '\033[0;37m'
DGRAY = '\033[1;30m'
LRED = '\033[1;31m'
LGREEN = '\033[1;32m'
YELLOW = '\033[1;33m'
LBLUE = '\033[1;34m'
PINK = '\033[1;35m'
LCYAN = '\033[1;36m'
WHITE = '\033[1;37m'
NC = '\033[0m'

# LIBFT

LIBFTDIR = .
LIBFT_SRCDIR = $(LIBFTDIR)/sources
LIBFT_INCDIR = $(LIBFTDIR)/includes

LIBFT_HEADNAMES =	libft
LIBFT_HEADERS = $(patsubst %, $(LIBFT_INCDIR)/%.h, $(LIBFT_HEADNAMES))

LIBFT_FILENAMES =	ft_putnbr ft_putchar ft_putstr ft_isalpha ft_atoi ft_bzero \
		ft_isalnum ft_isalpha ft_isascii ft_isdigit ft_isprint ft_memccpy \
		ft_memchr ft_memcmp ft_memcpy ft_memmove ft_memset ft_strchr ft_strcmp \
		ft_strlen ft_strncmp ft_strnstr ft_strstr ft_tolower ft_toupper \
		ft_strrchr ft_strdup ft_strcpy ft_strncpy  ft_strcat ft_strncat \
		ft_strlcat ft_memalloc ft_memdel ft_strnew ft_strdel ft_strclr \
		ft_striter ft_striteri  ft_strmap ft_strmapi ft_strequ  ft_strnequ \
		ft_strsub ft_strjoin ft_strtrim ft_strsplit ft_itoa  ft_putendl \
		ft_putnbr ft_putchar_fd ft_putstr_fd ft_putendl_fd ft_putnbr_fd ft_lstnew \
		ft_lstdelone ft_lstdel  ft_lstadd ft_lstiter ft_lstmap ft_abs ft_atol \
		ft_strtol ft_ctoi_base ft_itoa_base ft_torot13 ft_isspace ft_lstappend \
		ft_putlst ft_lstsize ft_lstrev ft_lstfree ft_slen ft_strtok ft_strtoutf8 \
		ft_gnl ft_isupper ft_wchrlen ft_wcstombs ft_wctomb ft_wcslen \
		ft_lstpush ft_startswith ft_endswith ft_sjoin ft_concat \
		ft_strtrunc ft_gnl_v2 ft_memsub ft_realloc ft_memjoin ft_free_and_ret \
		ft_tline_replace ft_tline_join ft_message_and_exit ft_isnumeric \
		ft_arrdel

LIBFT_CFILES = $(patsubst %, $(LIBFT_SRCDIR)/%.c, $(LIBFT_FILENAMES))
LIBFT_OFILES = $(patsubst %, $(ODIR)/%.o, $(LIBFT_FILENAMES))

# FT_PRINTF

FT_PRINTFDIR = ft_printf
FT_PRINTF_SRCDIR = $(FT_PRINTFDIR)/sources
FT_PRINTF_INCDIR = $(FT_PRINTFDIR)/includes

FT_PRINTF_HEADNAMES = ft_printf
FT_PRINTF_HEADERS = $(patsubst %, $(FT_PRINTF_INCDIR)/%.h, $(FT_PRINTF_HEADNAMES))

FT_PRINTF_FILENAMES = ft_printf ft_dprintf ft_sprintf convertors lst tools \
		parsers posargs put_misc put_numbers put_strings
FT_PRINTF_CFILES = $(patsubst %, $(FT_PRINTF_SRCDIR).c, $(FT_PRINTF_FILENAMES))
FT_PRINTF_OFILES = $(patsubst %, $(ODIR)/$(FT_PRINTFDIR)/%.o, $(FT_PRINTF_FILENAMES))

all: $(LIBNAME)

$(LIBNAME): $(ODIR) $(LIBFT_OFILES) $(LIBFT_HEADERS) $(FT_PRINTF_OFILES) $(FT_PRINTF_HEADERS)
	@echo ${CYAN}"Compiling $(LIBNAME)"${NC}
	@ar rc $(LIBNAME) $(LIBFT_OFILES) $(FT_PRINTF_OFILES)
	@ranlib $(LIBNAME)
	@echo ${GREEN}"[$(LIBNAME) is up to date.]"${NC}

$(ODIR)/$(FT_PRINTFDIR)/%.o: $(FT_PRINTF_SRCDIR)/%.c $(LIBFT_HEADERS) $(FT_PRINTF_HEADERS)
	@gcc $(FLAGS) -o $@ -c $< -I$(LIBFT_INCDIR) -I$(FT_PRINTF_INCDIR)

$(ODIR)/%.o: $(LIBFT_SRCDIR)/%.c $(LIBFT_HEADERS)
	@gcc $(FLAGS) -o $@ -c $< -I$(LIBFT_INCDIR) -I$(FT_PRINTF_INCDIR)

$(ODIR):
	@mkdir -p $(ODIR)
	@mkdir -p $(ODIR)/$(FT_PRINTFDIR)

clean:
	@echo ${RED}"[Removing *.o files]"${NC}
	@/bin/rm -rf $(ODIR)

fclean: clean
	@echo ${RED}"[Removing $(LIBNAME)]"${NC}
	@/bin/rm -f $(LIBNAME)

re: fclean all
