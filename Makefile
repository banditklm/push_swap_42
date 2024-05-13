NAME = push_swap

BONUS = checker

CC = cc

FLAGS = -Wextra -Wall -Werror

SRCS = push_swap.c parser.c parser2.c utils.c utils2.c utils3.c utils4.c actions.c actions2.c actions3.c indexing.c sorting1.c sorting2.c chunking.c

SRCSB = Bonus/checker_bonus.c Bonus/parser_bonus.c Bonus/parser2_bonus.c Bonus/actions_bonus.c Bonus/actions2_bonus.c Bonus/actions3_bonus.c Bonus/utils_bonus.c Bonus/utils2_bonus.c Bonus/utils3_bonus.c Bonus/utils4_bonus.c Bonus/get_next_line_bonus.c Bonus/get_next_line_utils_bonus.c

HEADERS = push_swap.h

HEADERSB = Bonus/checker_bonus.h

OBJS = $(SRCS:.c=.o)

OBJSB = $(SRCSB:.c=.o)


all : $(NAME)

bonus : $(BONUS)

$(BONUS) : $(OBJSB)
	@$(CC) $(FLAGS) $^ -o $@
	@echo "\033[35mMaking Bonus 🥳🌸"

$(NAME) : $(OBJS)
	@$(CC) $(FLAGS) $^ -o $@
	@echo "\033[32mMaking Completed ✅😜"

$(OBJS) : %.o: %.c $(HEADERS) Makefile
	@$(CC) $(FLAGS) -c $< -o $@

$(OBJSB) : %.o: %.c $(HEADERSB) Makefile
	@$(CC) $(FLAGS) -c $< -o $@

clean :
	@rm -f $(OBJS) $(OBJSB)
	@echo "\033[0;33mCleaning Completed 🧼✨"

fclean : clean
	@rm -f $(NAME) $(BONUS)
	@echo "\033[0;31mRemoving Completed 🗑 💔"

re : fclean all

.PHONY : clean