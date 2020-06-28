/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astamm <astamm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 13:29:21 by astamm            #+#    #+#             */
/*   Updated: 2019/12/17 15:16:03 by astamm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"
# include "libftprintf.h"
# include <fcntl.h>

# define BUFF_SIZE_LM			1024
# define MAX_LEN_PATH			500

# define MAX_WAY				60
# define MAX_NTRS_WAYS			MAX_WAY

/*
** Heuristic management
*/

# define ROOM_FREE				-1
# define ROOM_OCCUPIED			1

/*
** Constants status code
*/

# define MALLOC_ERROR			-2
# define HAVE_STEP				2
# define STATUS_NORMAL			HAVE_STEP

# define SUCCESS				1
# define FAIL					0
# define NO_EDGE				-1
# define NUM_COLORS				4

# define OPTIONS "color", "file", "lines", "screen", "matrix", ""
# define O_ERROR				0x80000000
# define O_COLOR				0x00000001
# define O_FILE					0x00000002
# define O_LINES				0x00000004
# define O_SCREEN				0x00000008
# define O_MATRIX				0x00000016

/*
** For screen saver
*/
# define CLEAR				ft_printf("\e[2J");
# define GOTOYX(y,x)		ft_printf("\e[%d;%dH", y, x);
# define VISIBLE_CURSOR 	ft_printf("\e[?25h");
# define HIDE_CURSOR		ft_printf("\e[?25l");
# define RESET_COLOR 		ft_printf("\e[0m");
# define GO_LAST_LINE		ft_printf("\e[505;1H");

typedef enum	e_lem_in_boolean
{
	True = 1,
	False = !True
}				t_boolean;

typedef struct	s_lem_in_point
{
	int			x;
	int			y;
}				t_point;

typedef struct	s_lem_in_edge
{
	struct s_lem_in_room	*next_room;
}				t_edge;

typedef struct	s_lem_in_room
{
	char					*name;
	int						index;
	t_point					coordinates;
	int						index_ant;
	int						amount_edge;
	t_boolean				visited;
	t_boolean				lock;
	t_edge					**arr_edge;
	struct s_lem_in_room	*from_bfs;
	struct s_lem_in_room	*in;
	struct s_lem_in_room	*out;
	struct s_lem_in_room	*parent;
}				t_room;

typedef struct	s_lem_in_list_map
{
	char						*str;
	struct s_lem_in_list_map	*next;
}				t_list_map;

typedef struct	s_lem_in_map
{
	t_list_map	*head;
	t_list_map	*list;
}				t_map;

typedef struct	s_lem_in_graf
{
	int			amount_rooms;
	t_room		**rooms;
	t_room		*start;
	t_room		*end;
}				t_graf;

typedef struct	s_lem_in_bufer
{
	char		begin[BUFF_SIZE_LM];
	char		*current_position;
	char		*end_buf;
}				t_lm_buf;

typedef struct	s_lem_in_way
{
	t_room		*begin;
	t_room		*end;
	char		*color;
	int			amount_room;
	t_room		*arr_rooms[MAX_LEN_PATH];
}				t_way;

typedef struct	s_lem_in_ant
{
	char		name[10];
	t_room		*current_room;
	int			index_current_room;
	t_way		*path;
	t_way		way;
}				t_ant;

typedef struct	s_lem_in_colony
{
	int			amount_ants;
	t_ant		**arr_ants;
}				t_colony;

typedef struct	s_lem_in
{
	t_graf		graf;
	t_boolean	visual;
	t_lm_buf	buf;
	t_way		way;
	t_colony	colony;
}				t_lem_in;

typedef struct	s_lem_in_list_edges_room
{
	t_room							*room;
	struct s_lem_in_list_edges_room *next;
}				t_list_edges_current_room;

typedef struct	s_lem_in_list_edges
{
	t_list_edges_current_room	*head;
	t_list_edges_current_room	*list;
	int							amount_edges;
}				t_current_list_edges;

typedef struct	s_lem_in_valid_parsing
{
	int						start;
	int						end;
	int						i;
	int						index_current_room;
	t_boolean				links_processing;
	t_map					*map_rooms;
	t_map					*map_edges;
	t_current_list_edges	*list_edges;
	char					*str;
	int						amount_rooms;
}				t_valid_pars;

typedef struct	s_lem_in_list_ant
{
	t_ant						*ant;
	struct s_lem_in_list_ant	*next;
	struct s_lem_in_list_ant	*prev;
}				t_list_ant;

typedef struct	s_lem_in_list_rooms
{
	t_room						*room;
	struct s_lem_in_list_rooms	*next;
	struct s_lem_in_list_rooms	*prev;
}				t_list_room;

typedef struct	s_lem_in_room_queue
{
	t_list_room	*top;
	int			size;
}				t_room_queue;

typedef struct	s_lem_in_ant_queue
{
	t_list_ant	*ants_in_start;
	t_list_ant	*ants_in_path;
	t_list_ant	*ants_in_end;
	int			amount_ants_in_start;
	int			amount_ants_in_path;
	int			amount_ants_in_end;
}				t_ants_queue;

typedef struct	s_lem_in_arry_way
{
	t_way		ways[MAX_NTRS_WAYS];
	int			amount;
}				t_arry_way;

typedef struct	s_lem_in_arr_ready_way
{
	t_way		way;
	int			amount_ants;
}				t_ready_ways;

typedef struct	s_solution
{
	t_ready_ways	ready_ways[MAX_WAY];
	int				amount_ways;
	int				amount_lines;
	t_boolean		have_empty_way;
}				t_solution;

/*
**	Main functions.
*/
t_solution		get_solution(t_graf *graf, t_graf *claen, int amount_all_ants);
void			solve(t_solution *m_result, t_lem_in *lem_in);
void			quick_solve(t_lem_in *lem_in);

/*
**	Validation.
*/
int				validation(t_lem_in *lm);
void			valid_name_room(char *str, int *i);
void			valid_coord_room(t_valid_pars *vp);
void			valid_amounts_ants(char **str);
void			valid_str_link(t_valid_pars *vp);
void			valid_str_room(t_valid_pars *vp);

/*
**	Parsing.
*/
int				parsing(t_lem_in *lm, t_valid_pars *vp);
int				parsing_begin_room(t_lem_in *lm, t_valid_pars *vp);
void			parsing_links(t_lem_in *lm, t_valid_pars *vp);
int				search_index_room(t_graf *graf, t_valid_pars *vp,
															char *name_room);
void			parsing_check_valid_links(t_lem_in *lm, t_valid_pars *vp);
void			print_map(t_valid_pars *vp);

/*
**	Save map in list.
*/
void			valid_save_map_rooms(t_valid_pars *vp);
void			valid_inicial_map_edges(t_valid_pars *vp);
void			valid_save_map_edges(t_valid_pars *vp);
void			valid_save_comment(t_valid_pars *vp);

/*
**	Error processing during validation and parsing.
*/
void			error_processing(char *str);
void			print_error_and_free_mem(t_valid_pars *vp, char *str);
void			error_invalid_links(t_graf *graf, t_valid_pars *vp, char **str);
void			error_repeat_commands(t_valid_pars *vp);

/*
**	Debag.
*/
void			print_content_graf(t_graf *i_graf);
void			export_adj_matrix(t_graf *i_graf);
void			write_puth_all_ant_file(t_colony *i_colony, char *name_file);
void			write_ready_puth_file(t_solution *final, char *name_file);
void			print_way(t_way *way);

/*
**	BFS algorithm & functions for it.
*/
t_way			bfs_algorithm(t_graf *graf);
void			mark_rooms_not_visited(t_room *m_room);
void			push_room_queue(t_room_queue *m_room_queue,
														t_room *i_added_room);
t_room			*pop_room_queue(t_room_queue *m_room_queue);

/*
**	Functions for suurballe algorithm.
*/
void			reverse_edge(t_way *m_way);
void			split_rooms_in_way(t_way *m_way);
void			put_room_out(t_room *m_parent);
void			put_room_in(t_room *m_parent);

/*
**	Сonstructors and destructors.
*/
t_colony		new_colony(int	i_amount_ants, t_graf *i_graf);
void			destroy_colony(t_colony *m_colony);
t_ants_queue	new_ants_queue(t_colony *i_colony, int *m_stat);
void			destroy_ants_queue(t_ants_queue *m_ants_queue);
void			destroy_ant_list(t_list_ant **m_top);
void			destroy_graf(t_graf *graf);
void			destroy_solution(t_solution *solution);
void			destroy_room_queue(t_room_queue *m_queue);
t_edge			*new_edge(t_room *i_to_this_room);
t_room			*new_room(char *i_name, int i_index);
t_list_room		*new_list_room(t_room *i_room);
void			free_map_edges(t_valid_pars *vp);
void			free_map_rooms(t_valid_pars *vp);
void			free_list_edges(t_current_list_edges *list_edges);

/*
**	Functions for the queue of ants.
*/
void			push_to_in_path(t_ants_queue *m_ants_queue,
														t_list_ant *m_list_ant);
void			push_to_in_end(t_ants_queue *m_ants_queue,
														t_list_ant *m_list_ant);

/*
** Functions for ant list.
*/
void			push_to_ant_list(t_list_ant *m_insert_list,
													t_list_ant **m_top_list);
void			cut_list_ant(t_list_ant *m_cut_list, t_list_ant **m_top_list);

/*
** Functions for room list.
*/
void			push_to_room_list(t_list_room *m_insert_list,
													t_list_room **m_top_list);
void			cut_list_room(t_list_room *m_cut_list,
													t_list_room **m_top_list);

/*
**	Functions for graph.
*/
t_graf			graf_dup_only_room(t_graf *i_from);
void			push_way_to_clean_graf(t_graf *m_graf, t_way *i_insert_way);
t_arry_way		get_no_intersections_ways(t_graf *clean_graf);
void			add_edge_by_index(t_graf *m_graf, int index_from, int index_to);
void			map_for_each_rooms(t_graf *m_graf, void (*f)(t_room*));

/*
**	Functions for room.
*/
void			del_edge(t_room *m_from, t_room *i_to);
void			del_edge_in_room(t_room *m_from, int index_edge);
int				get_index_edge(t_room *from_room, int index_desired_room);
t_room			**room_dup_without_edges(t_room **i_rooms, int amount_rooms);

/*
**	Function for Ant Distribution.
*/
t_solution		distribute_ants_on_ways(t_arry_way *no_ntrs_ways,
															int amount_ants);

/*
**	Functions for options.
*/
unsigned int	get_options(int ac, char **av);
void			put_color_to_way(t_solution *solution);

/*
**	Output data procedure.
*/
void			write_buff(t_lm_buf *m_buf);
void			add_to_buff(t_lm_buf *m_buf, char *i_data);

/*
**	Screen saver.
*/
void			screen_saver(void);

#endif
