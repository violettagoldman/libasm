NAME = libasm.a
NAME_PRINTF = ft_printf/libftprintf.a

SRC = 	./src/ft_strlen.s \
		./src/ft_strcpy.s \
		./src/ft_strcmp.s \
		./src/ft_write.s \
		./src/ft_read.s \
		./src/ft_strdup.s

SRC_BONUS = ./src/ft_list_size.s \
			./src/ft_list_push_front.s \
			./src/ft_list_sort.s \
			./src/ft_list_remove_if.s \
			./src/ft_atoi_base.s

SRC_TMP = $(subst ./src/,./obj/,${SRC})
SRC_BONUS_TMP = $(subst ./src/,./obj/,${SRC_BONUS})

OBJ = ${SRC_TMP:%.s=%.o}

OBJ_BONUS = ${SRC_BONUS_TMP:%.s=%.o}

CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address

NASM = nasm -fmacho64

all: $(NAME)

$(NAME_PRINTF):
		@make -C ./ft_printf

$(NAME): ${NAME_PRINTF} ${OBJ}
		@printf "\033[0;32mMaking the library...\033[0m\r"
		@mkdir -p ./obj/
		@ar rcs $(NAME) ${OBJ}
		@echo "\033[32;1mThe libasm is done \xE2\x9C\x94\033[0m          "

bonus: ${NAME_PRINTF} ${OBJ} ${OBJ_BONUS}
		@printf "\033[0;32mMaking the library...\033[0m\r"
		@mkdir -p ./obj/
		@ar rcs $(NAME) ${OBJ} ${OBJ_BONUS}
		@echo "\033[32;1mThe bonus library is done \xE2\x9C\x94\033[0m    "

test: $(NAME) main.c
	@gcc ${CFLAGS} -I./ft_printf/inc/. -L./ft_printf -lftprintf -L. -lasm -o main main.c && ./main

test_bonus: bonus main_bonus.c
	@gcc ${CFLAGS} -I./ft_printf/inc/. -L./ft_printf -lftprintf -L. -lasm -o main_bonus main_bonus.c && ./main_bonus

./obj/%.o: ./src/%.s
	@mkdir -p ./obj
	@${NASM} $< -o $@

clean:
	@rm -rf obj
	@make clean -C ./ft_printf
	@echo "\033[32;1mCleaned libasm \xE2\x9C\x94\033[0m"

fclean:	clean
		@rm -rf ${NAME} main main_bonus main.dSYM main_bonus.dSYM
		@make fclean -C ./ft_printf
		@echo "\033[32;1mForced cleaned libasm \xE2\x9C\x94\033[0m"

re:	fclean all

.PHONY: clean fclean all re
