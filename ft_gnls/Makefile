include ../constants.mk ../colors.mk ../sources.mk

SRCDIR = .

SOURCES = $(addprefix $(SRCDIR)/, $(GNLS_SRCS))
OBJECTS = $(addprefix ../$(ODIR)/, $(GNLS_SRCS:.c=.o))

gnls: $(OBJECTS)

../$(ODIR)/%.o: $(SRCDIR)/%.c
	@$(CC) $(FLAGS) -c $^ -o $@ -I ../$(INCDIR)
	@/bin/echo -n "."
