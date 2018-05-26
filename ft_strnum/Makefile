include ../constants.mk ../colors.mk ../sources.mk

INCDIR = includes
SRCDIR = .


INCLUDES = $(addprefix $(INCDIR)/, $(STRNUM_INCDS))
SOURCES  = $(addprefix $(SRCDIR)/, $(STRNUM_SRCS))
OBJECTS  = $(addprefix ../$(ODIR)/, $(STRNUM_SRCS:.c=.o))

ft_strnum: $(OBJECTS)

../$(ODIR)/%.o: $(SRCDIR)/%.c
	@$(CC) $(FLAGS) -c $^ -o $@ -I $(SUBINCDIR)
	@/bin/echo -n "."
