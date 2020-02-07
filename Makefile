# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmira <kmira@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/07 02:00:29 by kmira             #+#    #+#              #
#    Updated: 2020/02/07 03:03:47 by kmira            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = kmira.filler

FLAGS = -Wall -Wextra -Werror
INCS = -I includes
LIBFT = srcs/libft/libft.a

FILES = \
	main \

SRCS = $(addsuffix .c, $(addprefix srcs/, $(FILES)))

OBJS = $(addsuffix .o, $(FILES))

all: $(LIBFT) $(OBJS)
	gcc -o $(NAME) $(FLAGS) $(LIBFT) $(OBJS)

$(OBJS):
	gcc -c $(FLAGS) $(INCS) $(SRCS)

$(LIBFT):
	make -C srcs/libft/

clean:
	rm -f $(OBJS)
	make clean -C srcs/libft/

fclean:
	rm -f $(NAME)
# make fclean -C srcs/libft/

re: fclean all

quick: re clean

save: fclean
	git add .
	git commit -m "$(MSG)"
	git push
	git push https://github.com/MrColour/filler.git

.PHONY: all clean fclean re quick save
