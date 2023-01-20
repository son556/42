# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chanson <chanson@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/19 17:37:15 by chanson           #+#    #+#              #
#    Updated: 2022/11/22 12:40:56 by chanson          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJS = ft_isalpha.o ft_isdigit.o ft_isalnum.o ft_isascii.o \
		ft_isprint.o ft_strlen.o ft_memset.o ft_bzero.o \
		ft_memcpy.o ft_memmove.o ft_strlcpy.o ft_strlcat.o \
		ft_toupper.o ft_tolower.o ft_strchr.o ft_strrchr.o \
		ft_memchr.o ft_memcmp.o ft_strnstr.o ft_atoi.o \
		ft_calloc.o ft_strdup.o ft_strncmp.o ft_substr.o \
		ft_strjoin.o ft_strtrim.o ft_split.o ft_itoa.o \
		ft_strmapi.o ft_striteri.o ft_putchar_fd.o ft_putstr_fd.o \
		ft_putendl_fd.o ft_putnbr_fd.o

SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
		ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c \
		ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c \
		ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c \
		ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c \
		ft_calloc.c ft_strdup.c ft_strncmp.c ft_substr.c \
		ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
		ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
		ft_putendl_fd.c ft_putnbr_fd.c

SRCS_BONUS = ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
			ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c \
			ft_lstiter.c ft_lstmap.c ft_lstnew.c

OBJS_BONUS = ft_lstadd_front.o ft_lstsize.o ft_lstlast.o \
			ft_lstadd_back.o ft_lstdelone.o ft_lstclear.o \
			ft_lstiter.o ft_lstmap.o ft_lstnew.o

NAME = libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror -c

ifdef WITH_BONUS
	OBJ_FILES = $(OBJS) $(OBJS_BONUS)
else
	OBJ_FILES = $(OBJS)
endif

all:	$(NAME)

$(NAME):	$(OBJ_FILES)
			ar -rsc $(NAME) $(OBJ_FILES)

.c.o:
			$(CC) $(CFLAGS) $<

clean:
			rm -f $(OBJS) $(OBJS_BONUS)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

bonus:
	make WITH_BONUS=1 all

.PHONY:		all clean fclean bonus re