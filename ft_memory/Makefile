include ../constants.mk ../colors.mk ../sources.mk

INCDIR = includes
SRCDIR = src


INCLUDES = $(addprefix $(INCDIR)/, $(MEM_INCDS))
SOURCES = $(addprefix $(SRCDIR)/, $(MEM_SRCS))
OBJECTS = $(addprefix ../$(ODIR)/, $(MEM_SRCS:.c=.o))

ft_memory: $(OBJECTS)

../$(ODIR)/%.o: $(SRCDIR)/%.c
	@$(CC) $(FLAGS) -c $^ -o $@ -I $(INCDIR) -I ../$(LIBFT_INCDIR)
	@/bin/echo -n "."
