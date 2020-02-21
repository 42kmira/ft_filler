# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmira <kmira@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/07 02:00:29 by kmira             #+#    #+#              #
#    Updated: 2020/02/20 16:20:04 by kmira            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = kmira.filler

FLAGS = -Wall -Wextra -Werror
INCS = -I includes
LIBFT = srcs/libft/libft.a

FILES = \
	debug \
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
	./filler_vm -p1 resource/players/$(NAME) -f resource/maps/map00

hard:
	./filler_vm -p1 resource/players/$(NAME) -p2 resource/players/quiet.filler -f resource/maps/map05 > /dev/null

map:
	./filler_vm -p1 resource/players/$(NAME) -f resource/maps/$(MAP)

.PHONY: all clean fclean re quick save
