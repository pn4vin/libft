PRINTF_DIR = ./ft_printf
PRINTF_SRCS = convertors.c ft_dprintf.c ft_printf.c ft_sprintf.c lst.c parsers.c \
              posargs.c put_misc.c put_numbers.c put_strings.c tools.c
PRINTF_INDS = ft_printf.h

GNLS_DIR = ./gnls
GNLS_SRCS = ft_gnl.c ft_gnl_v2.c gnl_stripped.c ft_tline_replace.c ft_tline_join.c
GNLS_INDS = gnls.h

MEM_DIR = ./ft_memory
MEM_SRCS = ft_memalloc.c ft_realloc.c ft_memdel.c ft_memset.c ft_bzero.c \
		ft_memcpy.c ft_memcpy_fwd.c ft_memccpy.c ft_memmove.c ft_memsub.c \
		ft_memchr.c ft_memcmp.c ft_memjoin.c ft_arrdel.c ft_memrelease.c
MEM_INCDS = ft_memory.h

LST_DIR = ./ft_lst
LST_SRCS = ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c \
		ft_lstmap.c ft_lstappend.c ft_putlst.c ft_lstsize.c ft_lstrev.c ft_lstfree.c \
		ft_lstpush.c
LST_INCDS = ft_lst.h

TELL_DIR = ./ft_tell
TELL_SRCS = ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c \
			ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c ft_panic.c
TELL_INCDS = ft_tell.h

ALL_DIRS = . $(GNLS_DIR) $(MEM_DIR) $(PRINTF_DIR) $(LST_DIR) $(TELL_DIR)

ALL_INCDIRS = $(addsuffix /includes, $(ALL_DIRS))