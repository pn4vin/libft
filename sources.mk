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

ALL_INCDIRS = includes $(GNLS_DIR)/includes $(MEM_DIR)/includes $(FT_PRINTFDIR)/includes