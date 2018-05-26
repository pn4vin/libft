cmake_minimum_required(VERSION 3.9)

aux_source_directory(gnls/src GNLS)
aux_source_directory(ft_memory/src MEMORY)
aux_source_directory(ft_printf/src PRINTF)
aux_source_directory(ft_tell/src TELL)
aux_source_directory(ft_str/src STR)
aux_source_directory(ft_lst/src LST)
aux_source_directory(sources LIBFT)

set(INCLUDES ft_printf/includes gnls/includes ft_memory/includes ft_lst/includes
        ft_tell/includes ft_str/includes includes)

add_library(ft STATIC ${GNLS} ${LIBFT} ${PRINTF} ${MEMORY} ${LST} ${TELL} ${STR} ${INCLUDES})
include_directories(${INCLUDES})

add_subdirectory(tests)