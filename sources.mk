INCDIR = includes
SUBINCDIR = ../$(INCDIR)

PRINTF_DIR = ./ft_printf
PRINTF_SRCS = convertors.c float_accurate.c float_convert.c float_fast.c \
              float_helpers.c float_rounding.c ft_arprintf.c ft_dprintf.c \
              ft_fprintf.c ft_printf.c ft_sprintf.c ft_vdprintf.c ft_vprintf.c \
              ft_vsprintf.c lst.c misc_tools.c parsers.c pos_args.c put_float.c \
              put_misc.c put_numbers.c put_string.c tools.c
PRINTF_INDS = ft_printf.h

GNLS_DIR = ./ft_gnls
GNLS_SRCS = ft_gnl.c ft_gnl_v2.c ft_sgnl.c ft_gnw.c ft_tline_replace.c ft_tline_join.c
GNLS_INCDS = ft_gnls.h

MATH_DIR = ./ft_math
MATH_SRCS = ft_pow.c ft_fabs.c bi_add.c bi_blocks.c bi_cmul.c bi_commons.c \
        bi_convert.c bi_div.c bi_helpers.c bi_iadd.c bi_idiv.c bi_imul.c \
        bi_is_divisible.c bi_isub.c bi_memory.c bi_mul.c bi_pow.c bi_ceq.c \
        bi_shift.c bi_showtime.c bi_sub.c  bi_comparisons.c ft_floor.c \
        bi_increment.c
MATH_INCDS = ft_math.h

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

STR_DIR = ./ft_str
STR_SRCS = ft_strnew.c ft_strdel.c ft_strclr.c ft_strdup.c \
			ft_strcpy.c ft_strncpy.c \
			ft_strcat.c ft_strlcat.c ft_strncat.c \
			ft_strlen.c ft_slen.c \
			ft_sjoin.c ft_strjoin.c ft_strsplit.c ft_strtok.c ft_concat.c \
			ft_strmap.c ft_strmapi.c ft_striter.c ft_striteri.c \
			ft_strcmp.c ft_strncmp.c ft_strequ.c ft_strnequ.c \
			ft_strchr.c ft_strrchr.c ft_strstr.c ft_strrstr.c ft_strnstr.c \
			ft_tolower.c ft_toupper.c ft_strtorot13.c \
			ft_strsub.c ft_strtrim.c ft_strtrunc.c ft_strappend.c \
			ft_strtoutf8.c ft_wchrlen.c ft_wcslen.c ft_wctomb.c ft_wcstombs.c \
			ft_startswith.c ft_endswith.c ft_strrev.c ft_strndup.c \
			ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
			ft_isspace.c ft_isupper.c ft_strcnt.c ft_strispaces.c ft_splitspace.c
STR_INCDS = ft_str.h

STRNUM_DIR = ./ft_strnum
STRNUM_SRCS = ft_abs.c ft_atoi.c ft_atol.c ft_strtol.c ft_ctoi_base.c \
				ft_itoa.c ft_itoa_base.c ft_strisnum.c
STRNUM_INCDS = ft_strnum.h
