/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubeddd.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan <juan@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 14:40:49 by jdel-ros          #+#    #+#             */
/*   Updated: 2020/07/14 15:45:47 by juan             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBEDDD_H
# define CUBEDDD_H

# include "../minilibx_opengl_20191021/mlx.h"
# include "../libft/libft.h"
# include <math.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>

# define KEY_ESCAPE         53
# define KEY_F1             122
# define KEY_F2             120
# define KEY_F3             99
# define KEY_F4             118
# define KEY_F5             96
# define KEY_F6             97
# define KEY_F7             98
# define KEY_F8             100
# define KEY_F9             101
# define KEY_F10            109
# define KEY_F11            103
# define KEY_F12            111
# define KEY_F13            105
# define KEY_F14            107
# define KEY_F15            113
# define KEY_F16            106
# define KEY_F17            64
# define KEY_F18            79
# define KEY_F19            80
# define KEY_TILDE          50
# define KEY_1              18
# define KEY_2              19
# define KEY_3              20
# define KEY_4              21
# define KEY_5              23
# define KEY_6              22
# define KEY_7              26
# define KEY_8              28
# define KEY_9              25
# define KEY_0              29
# define KEY_MINUS          27
# define KEY_EQUAL          24
# define KEY_BACKSPACE      51
# define KEY_TAB            48
# define KEY_Q              12
# define KEY_W              13
# define KEY_E              14
# define KEY_R              15
# define KEY_T              17
# define KEY_Y              16
# define KEY_U              32
# define KEY_I              34
# define KEY_O              31
# define KEY_P              35
# define KEY_OPEN_BRACKET   33
# define KEY_OPEN_BRACE     33
# define KEY_CLOSE_BRACKET  30
# define KEY_CLOSE_BRACE    30
# define KEY_BACKSLASH      42
# define KEY_PIPE           42
# define KEY_CAPSLOCK       272
# define KEY_A              0
# define KEY_S              1
# define KEY_D              2
# define KEY_F              3
# define KEY_G              5
# define KEY_H              4
# define KEY_J              38
# define KEY_K              40
# define KEY_L              37
# define KEY_COLON          41
# define KEY_SEMI_COLON     41
# define KEY_SIMPLE_QUOTE   39
# define KEY_DOUBLE_QUOTES  39
# define KEY_ENTER          36
# define KEY_SHIFT_LEFT     257
# define KEY_Z              6
# define KEY_X              7
# define KEY_C              8
# define KEY_V              9
# define KEY_B              11
# define KEY_N              45
# define KEY_M              46
# define KEY_LESS_THAN      43
# define KEY_COMMA          43
# define KEY_GREATER_THAN   47
# define KEY_DOT            47
# define KEY_SLASH          44
# define KEY_QUESTION_MARK  44
# define KEY_SHIFT_RIGHT    258
# define KEY_CTRL_LEFT      256
# define KEY_COMMAND_LEFT   259
# define KEY_OPTION_LEFT    261
# define KEY_ALT            261
# define KEY_SPACEBAR       49
# define KEY_COMMAND_RIGHT  260
# define KEY_ALT_GR         262
# define KEY_FN             279
# define KEY_CTRL_RIGHT     269
# define KEY_LEFT           123
# define KEY_DOWN           125
# define KEY_RIGHT          124
# define KEY_UP             126
# define KEY_DEL            117
# define KEY_HOME           115
# define KEY_END            119
# define KEY_PAGE_UP        116
# define KEY_PAGE_DOWN      121
# define KEY_CLEAR          71
# define KEY_PAD_1          83
# define KEY_PAD_2          84
# define KEY_PAD_3          85
# define KEY_PAD_4          86
# define KEY_PAD_5          87
# define KEY_PAD_6          88
# define KEY_PAD_7          89
# define KEY_PAD_8          91
# define KEY_PAD_9          92
# define KEY_PAD_0          82
# define KEY_PAD_EQUAL      81
# define KEY_PAD_DIVIDE     75
# define KEY_PAD_MULTIPLY   67
# define KEY_PAD_SUB        78
# define KEY_PAD_ADD        69
# define KEY_PAD_ENTER      76
# define KEY_PAD_DOT        65

typedef struct		s_bitmap_file_header
{
	unsigned char	bitmap_type[2];
	int				file_size;
	short			reserved1;
	short			reserved2;
	unsigned int	offset_bits;
}					t_bfh;

typedef struct		s_bitmap_image_header
{
	unsigned int	size_header;
	unsigned int	width;
	unsigned int	height;
	short int		planes;
	short int		bit_count;
	unsigned int	compression;
	unsigned int	image_size;
	unsigned int	ppm_x;
	unsigned int	ppm_y;
	unsigned int	clr_used;
	unsigned int	clr_important;
}					t_bih;

typedef struct		s_img
{
	void			*img;
	int				bpp;
	int				sline;
	int				endian;
	int				*data;
	int				width;
	int				height;
	void			*ptr;
	int				setup;
}					t_img;

typedef	struct		s_sprite
{
	double			posx;
	double			posy;
	double			dist;
}					t_sprite;

typedef struct		s_color
{
	int				color;
}					t_color;

typedef struct		s_vector_int
{
	int				x;
	int				y;
}					t_vector_int;

typedef struct		s_keys
{
	int				leftarrow;
	int				rightarrow;
	int				w;
	int				a;
	int				d;
	int				s;
	int				q;
	int				e;
	int				esc;
}					t_keys;

typedef struct		s_perm
{
	int				x;
	int				y;
}					t_perm;

typedef struct		s_vector
{
	double			x;
	double			y;
}					t_vector;

typedef struct		s_texture
{
	t_img			e;
	t_img			n;
	t_img			s;
	t_img			w;
	t_img			sp;
	double			texturex;
	double			texturey;
}					t_texture;

typedef struct		s_pars
{
	char			*temp_two;
	int				screenwidth;
	int				screenheight;
	char			*width_str;
	char			*height_str;
	int				ground_r;
	int				ground_g;
	int				ground_b;
	int				sky_r;
	int				sky_g;
	int				sky_b;
	char			*texture_n;
	char			*texture_s;
	char			*texture_e;
	char			*texture_w;
	char			*texture_sprite;
	char			*str;
	char			*temp;
	int				x;
	int				y;
	int				width;
	int				twidth;
	int				width_map;
	int				height;
	int				perm;
}					t_pars;

typedef struct		s_cube
{
	t_vector		front;
	t_vector		down;
	t_vector		left;
	t_vector		right;
	t_vector		hiit;
	t_vector		sprite;
	t_vector		pos;
	t_vector_int	map_pars;
	t_keys			keys;
	t_img			img;
	t_img			text_spr;
	t_img			file;
	t_perm			perm;
	t_pars			pars;
	t_texture		texture;
	t_sprite		sprites;
	t_bih			bih;
	t_bfh			bfh;
	char			**map_temp;
	void			*mlx;
	void			*window;
	void			*window_bmp;
	int				draw_start_x;
	int				draw_start_y;
	int				draw_end_x;
	int				draw_end_y;
	int				mapx;
	int				mapy;
	int				a;
	int				b;
	int				error_parsing;
	int				tex_x;
	int				tex_y;
	int				stripe;
	int				sp_w;
	int				sp_h;
	int				sp_x;
	int				stepx;
	int				stepy;
	int				hit;
	int				side;
	int				nb_sprite;
	int				error;
	int				error_two;
	int				floor_color;
	int				sky_color;
	int				**worldmap;
	int				i;
	int				j;
	int				swapx;
	int				swapy;
	int				swapdist;
	int				floorsize;
	int				skysize;
	int				wallheight;
	int				fd;
	int				perm_save;
	double			tramy;
	double			tramx;
	double			inv_det;
	double			pi;
	double			posx;
	double			*zbuffer;
	double			posy;
	double			dirx;
	double			diry;
	double			planex;
	double			planey;
	double			temps;
	double			camerax;
	double			raydirx;
	double			raydiry;
	double			sidedistx;
	double			sidedisty;
	double			deltadistx;
	double			deltadisty;
	double			perpwalldist;
	double			movespeed;
	double			rotspeed;
}					t_cube;

void				ft_verline(int h, int x, t_cube *cube);
int					ft_releaseinput(int key, t_cube *cube);
int					deal_key(t_cube *cube);
int					ft_holdinput(int key, t_cube *cube);
double				ft_raycasting(t_cube *cube, int x);
int					ft_move_up_front(t_cube *cube, t_vector *futur_move);
int					ft_move_up_down(t_cube *cube, t_vector *futur_move);
int					ft_dir_up_right(t_cube *cube);
int					ft_dir_up_left(t_cube *cube);
int					ft_move_cam_leftarrow(t_cube *cube);
int					ft_move_cam_rightarrow(t_cube *cube);
int					ft_move_up_right(t_cube *cube, t_vector *futur_move);
int					ft_move_up_left(t_cube *cube, t_vector *futur_move);
int					ft_exit_hook(t_cube *cube);
int					ft_print_ray(t_cube *cube);
void				ft_initvar(t_cube *cube);
void				ft_collision(t_cube *cube, t_vector futur_move);
void				ft_init_map_two(t_cube *cube, int in_char);
void				ft_init_map(t_cube *cube, int in_char);
int					ft_read_map(t_cube *cube);
int					ft_find(const char c, const char *str);
char				*ft_strdup_without_space(char *str);
int					ft_resolution_two(char *str, t_cube *cube, int i, int j);
int					ft_puterror(t_cube *cube, char *str);
void				ft_print_var(t_cube *cube);
int					ft_texture_init(t_cube *cube);
char				ft_wall_in_face(t_cube *cube);
t_img				ft_choose_texture(t_cube *cube);
void				ft_texture_to_image(t_img texture, t_cube *cube, int i);
void				ft_recover_sprite(t_cube *cube);
void				ft_raycasting_sprite(t_cube *cube);
int					ft_fill_map(t_cube *cube);
int					ft_fill_map_two(t_cube *cube, int x, int y);
void				ft_recover_sprite_two(t_cube *cube, int x, int y, int i);
int					ft_check_map(t_cube *cube);
int					ft_check_wall(int x, int y, t_cube *cube);
int					ft_check_map_char(char *str);
int					ft_check_parsing(t_cube *cube);
int					ft_parsing(t_cube *cube, char *str);
int					ft_parsing_start(char *s, t_cube *cube);
int					ft_parsing_map(t_cube *cube);
void				ft_parsing_map_two(t_cube *cube, int count, char *line);
int					ft_parsing_map_three(t_cube *cube);
int					ft_parsing_ground_sky(char *s, t_cube *cube);
int					ft_parsing_ground_sky_two(char *str, int i, t_cube *cube);
int					ft_parsing_resolution(char *s, t_cube *cube);
int					ft_parsing_choose(t_cube *cube, char *line);
char				*ft_parsing_texture(char *s, t_cube *cube);
int					ft_save_bitmap(const char *filename, t_cube *cube);
int					ft_check_arg_map(t_cube *cube, char *map);
int					ft_check_arg_save(t_cube *cube, char *save);
void				ft_free(t_cube *cube);
int					main(int argc, char **argv);
void				ft_colors(t_cube *cube);
int					ft_check_line(t_cube *cube, char *line);
int					ft_puterror_two(t_cube *cube, char *str);
#endif
