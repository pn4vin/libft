include ../constants.mk ../colors.mk ../sources.mk

INCDIR = includes
SRCDIR = src


INCLUDES = $(addprefix $(INCDIR)/, $(GNLS_INDS))
SOURCES = $(addprefix $(SRCDIR)/, $(GNLS_SRCS))
OBJECTS = $(addprefix ../$(ODIR)/, $(GNLS_SRCS:.c=.o))

gnls: $(OBJECTS)

../$(ODIR)/%.o: $(SRCDIR)/%.c
	@$(CC) $(FLAGS) -c $^ -o $@ -I $(INCDIR) $(addprefix -I../, $(ALL_INCDIRS))
	@/bin/echo -n "."
