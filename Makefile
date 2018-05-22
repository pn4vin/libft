include colors.mk constants.mk sources.mk
LIBNAME = libft.a

######################### LIBFT #########################



LIBFT_HEADNAMES =	libft
LIBFT_HEADERS = $(patsubst %, $(LIBFT_INCDIR)/%.h, $(LIBFT_HEADNAMES))


LIBFT_FILENAMES =	ft_putnbr ft_putchar ft_putstr ft_isalpha ft_atoi ft_bzero \
		ft_isalnum ft_isalpha ft_isascii ft_isdigit ft_isprint ft_strchr ft_strcmp \
		ft_strlen ft_strncmp ft_strnstr ft_strstr ft_tolower ft_toupper \
		ft_strrchr ft_strdup ft_strcpy ft_strncpy  ft_strcat ft_strncat \
		ft_strlcat ft_memalloc ft_memdel ft_strnew ft_strdel ft_strclr \
		ft_striter ft_striteri  ft_strmap ft_strmapi ft_strequ  ft_strnequ \
		ft_strsub ft_strjoin ft_strtrim ft_strsplit ft_itoa  ft_putendl \
		ft_putnbr ft_putchar_fd ft_putstr_fd ft_putendl_fd ft_putnbr_fd ft_lstnew \
		ft_lstdelone ft_lstdel  ft_lstadd ft_lstiter ft_lstmap ft_abs ft_atol \
		ft_strtol ft_ctoi_base ft_itoa_base ft_torot13 ft_isspace ft_lstappend \
		ft_putlst ft_lstsize ft_lstrev ft_lstfree ft_slen ft_strtok ft_strtoutf8 \
		ft_isupper ft_wchrlen ft_wcstombs ft_wctomb ft_wcslen ft_lstpush ft_startswith \
		ft_endswith ft_sjoin ft_concat ft_strtrunc ft_free_and_ret ft_message_and_exit \
		ft_isnumeric ft_arrdel

LIBFT_CFILES = $(patsubst %, $(LIBFT_SRCDIR)/%.c, $(LIBFT_FILENAMES))
LIBFT_OFILES = $(patsubst %, $(ODIR)/%.o, $(LIBFT_FILENAMES))

# FT_PRINTF

PRINTF_O = $(addprefix $(ODIR)/, $(PRINTF_SRCS:.c=.o))

######################### GNLS ##########################

GNL_O = $(addprefix $(ODIR)/, $(GNLS_SRCS:.c=.o))


######################### MEMORY ########################

MEM_O = $(addprefix $(ODIR)/, $(MEM_SRCS:.c=.o))


######################### MAKE_BEGIN ##########################


.PHONY: $(GNLS)

all: $(LIBNAME)

$(LIBNAME): $(ODIR) $(GNL_O)  $(MEM_O) $(PRINTF_O) $(LIBFT_OFILES) \
            $(LIBFT_HEADERS)
	@echo ${CYAN}"Compiling $(LIBNAME)"${NC}
	@ar rc $(LIBNAME) $(LIBFT_OFILES) $(PRINTF_O) $(GNL_O) $(MEM_O)
	@ranlib $(LIBNAME)
	@echo ${GREEN}"[$(LIBNAME) is up to date.]"${NC}


$(GNL_O):
	@echo ${CYAN}"Compiling gnls"${NC}
	@make -C $(GNLS_DIR)
	@/bin/echo ""

$(MEM_O):
	@echo ${CYAN}"Compiling ft_memory"${NC}
	@make -C $(MEM_DIR)
	@/bin/echo ""

$(PRINTF_O):
	@echo ${CYAN}"Compiling ft_printf"${NC}
	@make -C $(PRINTF_DIR)
	@/bin/echo ""

$(ODIR)/%.o: $(LIBFT_SRCDIR)/%.c $(LIBFT_HEADERS)
	@gcc $(FLAGS) -o $@ -c $< $(addprefix -I,$(ALL_INCDIRS))

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
