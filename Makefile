NAME = lem-in

HEADER_DIR = include/

LIB_FT_PATH = libraries/libft/
LIB_PRINTF_PATH = libraries/libftprintf/

LIB_FT_A = $(LIB_FT_PATH)libft.a
LIB_PRINTF_A = $(LIB_PRINTF_PATH)libftprintf.a

SRC_DIR = source/
OBJ_DIR = objects/

SRC_FILE = lem_in.c validation.c valid_links.c valid_room.c valid_coord_room.c\
		   parsing.c parsing_room.c parsing_links.c check_valid_links.c\
		   save_map_in_list.c error_processing.c error_valid_in_parsing.c\
		   \
		   bfs_algorithm.c cut_list_room.c push_to_room_list.c\
		   push_room_queue.c pop_room_queue.c new_list_room.c\
		   print_way.c del_edge.c reverse_edge.c map_for_each_rooms.c\
		   mark_rooms_not_visited.c get_index_room.c new_edge.c new_room.c\
		   put_room_out.c split_room.c put_room_in.c solve.c\
		   room_dup_without_edges.c graf_dup_only_room.c\
		   push_way_to_clean_graf.c del_edge_in_room.c add_edge_by_index.c\
		   get_solution.c get_no_intersections_ways.c distribute_ants_on_ways.c\
		   destroy_graf.c destroy_room_queue.c\
		   put_color_to_way.c get_options.c\
		   destroy_solution.c quick_solve.c\
		   \
		   push_to_in_end.c push_to_in_path.c\
		   new_colony.c destroy_colony.c\
		   destroy_ants_queue.c\
		   new_ants_queue.c\
		   cut_list_ant.c\
		   push_to_ant_list.c\
		   destroy_ant_list.c\
		   \
		   write_puth_all_ant_file.c add_to_buff.c write_buff.c free_memory.c\
		   export_adj_matrix.c print_content_graf.c screen_saver.c

SOURCE = $(addprefix $(SRC_DIR)/, $(SRC_FILE)) 
OBJECTS = $(addprefix $(OBJ_DIR), $(SRC_FILE:.c=.o))

FLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re libft libftprintf

all: libft libftprintf $(NAME)

$(NAME): $(OBJ_DIR) $(OBJECTS) $(HEADER_DIR)lem_in.h $(LIB_FT_A) $(LIB_PRINTF_A)
	@gcc $(FLAGS) $(OBJECTS) -I $(HEADER_DIR) -L $(LIB_FT_PATH) -lft -L $(LIB_PRINTF_PATH) -lftprintf -o $(NAME)
	@echo "Done compilling $(NAME)!"

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(OBJECTS): $(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADER_DIR)lem_in.h
	@gcc $(FLAGS) -c $< -I $(HEADER_DIR) -I $(LIB_FT_PATH) -I $(LIB_PRINTF_PATH) -o $@

$(LIB_PRINTF_A): libftprintf

$(LIB_FT_A): libft

libft:
	@make -C $(LIB_FT_PATH)

libftprintf:
	@make -C $(LIB_PRINTF_PATH)

clean:
	@rm -fr $(OBJ_DIR)
	@make clean -C $(LIB_FT_PATH)
	@make clean -C $(LIB_PRINTF_PATH)
	@echo "Object file lem-in deleted!"

fclean: clean
	@make fclean -C $(LIB_FT_PATH)
	@make fclean -C $(LIB_PRINTF_PATH)
	@rm -fr $(NAME)

re: fclean all
