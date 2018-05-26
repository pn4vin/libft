include ../constants.mk ../colors.mk ../sources.mk

SRCDIR = .


INCLUDES = $(addprefix $(INCDIR)/, $(LST_INCDS))
SOURCES = $(addprefix $(SRCDIR)/, $(LST_SRCS))
OBJECTS = $(addprefix ../$(ODIR)/, $(LST_SRCS:.c=.o))

ft_lst: $(OBJECTS)

../$(ODIR)/%.o: $(SRCDIR)/%.c
	@$(CC) $(FLAGS) -c $^ -o $@ -I ../$(INCDIR)
	@/bin/echo -n "."
