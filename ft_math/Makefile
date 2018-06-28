include ../constants.mk ../colors.mk ../sources.mk

INCDIR = includes
SRCDIR = .


INCLUDES = $(addprefix $(INCDIR)/, $(MATH_INCDS))
SOURCES = $(addprefix $(SRCDIR)/, $(MATH_SRCS))
OBJECTS = $(addprefix ../$(ODIR)/, $(MATH_SRCS:.c=.o))

ft_math: $(OBJECTS)

../$(ODIR)/%.o: $(SRCDIR)/%.c
	@$(CC) $(FLAGS) -c $^ -o $@ -I $(SUBINCDIR)
	@/bin/echo -n "."
