# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/15 17:18:08 by marvin            #+#    #+#              #
#    Updated: 2022/01/15 17:18:08 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror

AR = ar rc

SRCS =	dependencies/errors.c dependencies/pipex.c \
		dependencies/processes.c dependencies/setup.c \
		dependencies/utils.c dependencies/ft_memcpy.c \
		dependencies/ft_split.c dependencies/ft_substr.c

OBJS = $(SRCS:.c=.o)

B_SRCS = dependencies/setup.c dependencies/errors.c \
		b_dependencies/b_pipex.c b_dependencies/b_processes.c \
		b_dependencies/get_next_line.c dependencies/utils.c \
		dependencies/ft_memcpy.c dependencies/ft_split.c \
		dependencies/ft_substr.c

B_OBJS = $(B_SRCS:.c=.o)

NAME = dependencies/mandatory.a

BONUS = b_dependencies/bonus.a

all : $(NAME)

$(NAME) : $(LIBFT) $(OBJS)
	rm -f $(BONUS)
	$(AR) $(NAME) $(OBJS)
	$(CC) $(CFLAGS) $(NAME) $(LIBFT) -o pipex

bonus : $(BONUS)

$(BONUS) : $(B_OBJS)
	rm -f $(NAME)
	$(AR) $(BONUS) $(B_OBJS)
	$(CC) $(CFLAGS) $(BONUS) -o pipex

clean :
	rm -f $(NAME) $(BONUS)

fclean : clean
	rm -f $(OBJS) $(B_OBJS)

re : fclean all

.PHONY : all bonus clean fclean re