cmake_minimum_required(VERSION 3.9)

aux_source_directory(gnls/src GNLS)
aux_source_directory(ft_memory/src ft_memory)
aux_source_directory(sources LIBFT)
aux_source_directory(ft_printf/src FT_PRINTF)

set(INCLUDES ft_printf/includes gnls/includes ft_memory/includes includes)

add_library(ft STATIC ${GNLS} ${LIBFT} ${FT_PRINTF} ${MEMORY} ${INCLUDES})
include_directories(${INCLUDES})

add_subdirectory(tests)