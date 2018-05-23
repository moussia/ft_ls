# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmottal <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/10 16:35:48 by mmottal           #+#    #+#              #
#    Updated: 2018/05/01 18:31:04 by mmottal          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRC = 	main.c \
		info.c \
		list.c \
		parser.c \
		tri.c \
		ls_l.c \
		ft_re.c \

FLAGS = -Wall -Werror -Wextra

NAME = ft_ls

all: $(NAME)

$(NAME):
	make re -C libft
	gcc -o $(NAME) $(SRC) -Iinclude libft/libft.a -g3
	@echo "$(NAME) \033[92mSUCCESS!\033[0m"
	@echo "\033[0m$(notdir $<)compiled \033[92mDONE!\033[0m"

clean:
	make clean -C libft
	rm -f $(NAME)
	@echo "\033[092mDELETED\033[0m"

fclean: clean
	make fclean -C libft
	@echo "\033[092mDELETED\033[0m"

re: fclean all

.PHONY:
	all clean fclean re
