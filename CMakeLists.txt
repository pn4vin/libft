cmake_minimum_required(VERSION 3.9)

aux_source_directory(ft_gnls GNLS)
aux_source_directory(ft_math MATH)
aux_source_directory(ft_memory MEMORY)
aux_source_directory(ft_printf PRINTF)
aux_source_directory(ft_tell TELL)
aux_source_directory(ft_str STR)
aux_source_directory(ft_strnum STRNUM)
aux_source_directory(ft_lst LST)

set(INCLUDES includes)

add_library(ft STATIC ${GNLS} ${LIBFT} ${PRINTF} ${MATH} ${MEMORY} ${LST}
        ${TELL} ${STR} ${STRNUM} ${INCLUDES})
include_directories(${INCLUDES})
