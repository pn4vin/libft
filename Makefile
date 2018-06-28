include colors.mk constants.mk sources.mk
LIBNAME = libft.a

######################### LIBFT #########################

# FT_PRINTF

PRINTF_O = $(addprefix $(ODIR)/, $(PRINTF_SRCS:.c=.o))

######################### GNLS ##########################

GNL_O = $(addprefix $(ODIR)/, $(GNLS_SRCS:.c=.o))

######################### MATH ##########################

MATH_O = $(addprefix $(ODIR)/, $(MATH_SRCS:.c=.o))

######################### MEMORY ########################

MEM_O = $(addprefix $(ODIR)/, $(MEM_SRCS:.c=.o))

######################### LST ########################

LST_O = $(addprefix $(ODIR)/, $(LST_SRCS:.c=.o))

######################### TELL ########################

TELL_O = $(addprefix $(ODIR)/, $(TELL_SRCS:.c=.o))

######################### STR ########################

STR_O = $(addprefix $(ODIR)/, $(STR_SRCS:.c=.o))

######################### STRNUM ########################

STRNUM_O = $(addprefix $(ODIR)/, $(STRNUM_SRCS:.c=.o))

######################### MAKE_BEGIN ##########################


.PHONY: $(GNLS)

all: $(LIBNAME)

$(LIBNAME): $(ODIR) $(GNL_O) $(LST_O) $(MEM_O) $(MATH_O) $(TELL_O) $(PRINTF_O) $(STR_O) $(STRNUM_O)
	@echo ${CYAN}"Compiling $(LIBNAME)"${NC}
	@ar rc $(LIBNAME) $(PRINTF_O) $(GNL_O) $(MATH_O) $(MEM_O) $(LST_O) $(STR_O) $(STRNUM_O) $(TELL_O)
	@ranlib $(LIBNAME)
	@echo ${GREEN}"[$(LIBNAME) is up to date.]"${NC}


$(GNL_O):
	@echo ${CYAN}"Compiling ft_gnls"${NC}
	@make -C $(GNLS_DIR)
	@/bin/echo ""

$(MATH_O):
	@echo ${CYAN}"Compiling ft_math"${NC}
	@make -C $(MATH_DIR)
	@/bin/echo ""

$(MEM_O):
	@echo ${CYAN}"Compiling ft_memory"${NC}
	@make -C $(MEM_DIR)
	@/bin/echo ""

$(LST_O):
	@echo ${CYAN}"Compiling ft_lst"${NC}
	@make -C $(LST_DIR)
	@/bin/echo ""

$(TELL_O):
	@echo ${CYAN}"Compiling ft_tell"${NC}
	@make -C $(TELL_DIR)
	@/bin/echo ""

$(PRINTF_O):
	@echo ${CYAN}"Compiling ft_printf"${NC}
	@make -C $(PRINTF_DIR)
	@/bin/echo ""

$(STR_O):
	@echo ${CYAN}"Compiling ft_str"${NC}
	@make -C $(STR_DIR)
	@/bin/echo ""

$(STRNUM_O):
	@echo ${CYAN}"Compiling ft_strnum"${NC}
	@make -C $(STRNUM_DIR)
	@/bin/echo ""


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
