#	Library output
NAME = srabah.filler

#	GCC flags
CFLAGS = -Wall -Wextra -Werror -g

#	Includes directories
INC_TR = includes
INCLUDES += $(addprefix -iquote , $(INC_TR))

#	Sources
FILLER_SOURCES = $(shell find lib | grep "\.c$$" | sed "s/\.c$$//g")
FILLER_HEADERS = $(shell find includes | grep "\.h$$")
SRCS = $(addsuffix .c, $(FILLER_SOURCES))
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@echo ">>>>> Génération de FILLER"
	@gcc $(OBJS) -o $(NAME)
	@echo "Terminée"

# To obtain object files
%.o: %.c $(FILLER_HEADERS)
	@$(CC) -c $(CFLAGS) $(INCLUDES) $< -o $@

# To remove generated files
clean:
	@echo "RM\ttous les objects (.o)"
	@$(RM) $(OBJS)

fclean: clean
	@echo "RM\tprojet ($(NAME))"
	@$(RM) $(NAME)

re: fclean all

git:
	@git add .
	@echo "Enter Your Commit :"
	@read var1 ; git commit -m "$$var1"
	@git push
