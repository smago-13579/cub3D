# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smago <smago@student.21-school.ru>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/12 17:13:03 by smago             #+#    #+#              #
#    Updated: 2020/10/06 13:57:49 by smago            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_atoi.c ft_isascii.c ft_memchr.c ft_putchar_fd.c ft_strchr.c \
		ft_strlen.c ft_strtrim.c ft_bzero.c ft_isdigit.c ft_memcmp.c \
		ft_putendl_fd.c ft_strdup.c ft_strmapi.c ft_substr.c ft_calloc.c \
		ft_isprint.c ft_memcpy.c ft_putnbr_fd.c ft_strjoin.c ft_strncmp.c \
		ft_tolower.c ft_isalnum.c ft_itoa.c ft_memmove.c ft_putstr_fd.c \
		ft_strlcat.c ft_strnstr.c ft_toupper.c ft_isalpha.c ft_memccpy.c \
		ft_memset.c ft_split.c ft_strlcpy.c ft_strrchr.c

OBJECTS = ft_atoi.o ft_isascii.o ft_memchr.o ft_putchar_fd.o ft_strchr.o \
		ft_strlen.o ft_strtrim.o ft_bzero.o ft_isdigit.o ft_memcmp.o \
		ft_putendl_fd.o ft_strdup.o ft_strmapi.o ft_substr.o ft_calloc.o \
		ft_isprint.o ft_memcpy.o ft_putnbr_fd.o ft_strjoin.o ft_strncmp.o \
		ft_tolower.o ft_isalnum.o ft_itoa.o ft_memmove.o ft_putstr_fd.o \
		ft_strlcat.o ft_strnstr.o ft_toupper.o ft_isalpha.o ft_memccpy.o \
		ft_memset.o ft_split.o ft_strlcpy.o ft_strrchr.o

SRCSBN = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
		ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c \
		get_next_line.c ft_putendl.c

OBJBN = ft_lstnew.o ft_lstadd_front.o ft_lstsize.o ft_lstlast.o \
		ft_lstadd_back.o ft_lstdelone.o ft_lstclear.o ft_lstiter.o ft_lstmap.o \
		get_next_line.o ft_putendl.o

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS) $(OBJBN)
	ar rc $@ $^
	ranlib $(NAME)

%.o: %.c
	gcc -c $(FLAGS) $< -o $@

bonus: $(OBJECTS) $(OBJBN)
	ar rc $(NAME) $^
	ranlib $(NAME)

clean:
	rm -f $(OBJECTS) $(OBJBN)

fclean: clean
	rm -f $(NAME)

re: fclean all