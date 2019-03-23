NAME		= 	ft_strace

SRCS		= 	ft_strace.c \
				handle_signal.c \
                handle_read.c \
                handle_write.c \
                handle_execve.c \
                handle_openat.c \
                handle_getdents.c \
                handle_default.c \
                get_string.c \
                get_chars.c \
                get_format.c \
                get_flags.c \
                get_entries.c \
                get_vars.c \
                get_args.c \
                get_prot.c \
                get_map.c \
                get_error.c

OBJ		= $(SRCS:.c=.o)


HEADER  = ./ft_strace.h \
		  ./syscall64.h \
		  ./syscall32.h

INCLUDE	= -I.

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

all: $(NAME)

%.o:%.c $(HEADER)
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ -c $< 

$(NAME): $(OBJ) $(HEADER) 
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(INCLUDE) 


clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
