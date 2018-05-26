include ../constants.mk ../colors.mk ../sources.mk

INCDIR = includes
SRCDIR = src


INCLUDES = $(addprefix $(INCDIR)/, $(STR_INCDS))
SOURCES = $(addprefix $(SRCDIR)/, $(STR_SRCS))
OBJECTS = $(addprefix ../$(ODIR)/, $(STR_SRCS:.c=.o))

ft_str: $(OBJECTS)

../$(ODIR)/%.o: $(SRCDIR)/%.c
	@$(CC) $(FLAGS) -c $^ -o $@ -I $(SUBINCDIR)
	@/bin/echo -n "."
