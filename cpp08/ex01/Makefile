NAME	:= prg
CC	    := c++
CFLAGS	:= -Wall -Wextra -Werror -std=c++98

OBJS_DIR	:= obj

define SRC :=
	main.cpp
	Span.cpp
endef
SRC := $(strip $(SRC))

OBJS := $(patsubst %.cpp,$(OBJS_DIR)/%.o,$(SRC))

$(NAME): $(OBJS)
	@echo '* Assembling $(NAME)'
	@$(CC) $(CFLAGS) $(OBJS) -o $@

$(OBJS_DIR)/%.o: %.cpp
	@echo '- Compiling $<'
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c -o $@ $<

.PHONY: all
all: $(NAME)

.PHONY: clean
clean:
	@echo '! Removing objs'
	@rm -rf $(OBJS) $(OBJS_BONUS)

.PHONY: fclean
fclean: clean
	@echo '! Removing $(NAME)'
	@rm -rf $(NAME)

.PHONY: re
re: fclean $(NAME)
