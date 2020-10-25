# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: home <home@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/07 02:00:29 by kmira             #+#    #+#              #
#    Updated: 2020/10/24 17:24:10 by home             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = kmira.filler

FLAGS = -Wall -Wextra -Werror
INCS = -I includes
LIBFT = srcs/libft/libft.a

FILES = \
	free_context \
	heatmap_color \
	heatmap_display \
	heatmap \
	initialize_game \
	main \
	piece_place \
	piece_get \
	stdin_ptr_move \
	update_game_state \
	verify_piece \

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

fclean: clean
	rm -f $(NAME)
# make fclean -C srcs/libft/

re: fclean all

quick: re
	make clean
	mv $(NAME) resource/players/

save: fclean
	git add .
	git commit -m "$(MSG)"
	git push
	git push https://github.com/MrColour/filler.git

play:
	./filler_vm -f resources/maps/map00 -p1 ./$(NAME) > /dev/null

hard:
	./filler_vm -p1 ./kmira.filler -p2 resources/players/hcao.filler -f resources//maps/map01 > /dev/null

.PHONY: all clean fclean re quick save
