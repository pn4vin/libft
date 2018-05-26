include ../constants.mk ../colors.mk ../sources.mk

INCDIR = includes
SRCDIR = src


INCLUDES = $(addprefix $(INCDIR)/, $(TELL_INCDS))
SOURCES = $(addprefix $(SRCDIR)/, $(TELL_SRCS))
OBJECTS = $(addprefix ../$(ODIR)/, $(TELL_SRCS:.c=.o))

ft_tell: $(OBJECTS)

../$(ODIR)/%.o: $(SRCDIR)/%.c
	@$(CC) $(FLAGS) -c $^ -o $@ -I $(SUBINCDIR)
	@/bin/echo -n "."
