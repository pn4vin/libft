include ../constants.mk ../colors.mk ../sources.mk

INCDIR = includes
SRCDIR = .


INCLUDES = $(addprefix $(INCDIR)/, $(PRINTF_INDS))
SOURCES = $(addprefix $(SRCDIR)/, $(PRINTF_SRCS))
OBJECTS = $(addprefix ../$(ODIR)/, $(PRINTF_SRCS:.c=.o))

ft_printf: $(OBJECTS)
	@/bin/echo -n ""

../$(ODIR)/%.o: $(SRCDIR)/%.c
	@$(CC) $(FLAGS) -c $^ -o $@ -I $(SUBINCDIR)
	@/bin/echo -n "."
