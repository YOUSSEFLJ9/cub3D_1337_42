/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 13:36:46 by youchen           #+#    #+#             */
/*   Updated: 2024/07/22 00:43:27 by ymomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "../MLX42/include/MLX42/MLX42.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# define WIN_WIDTH 1500
# define WIN_HEIGHT 1000
# define WIN_W_MINI 200
# define WIN_H_MINI 200
# define TILE_SIZE 1024
# define MOVE_SPEED 96
# define ROTATION_SPEED 3
# define MINI_TS 20
# define BUFFER_SIZE 42

# define NORTH 78
# define SOUTH 83
# define WEST 87
# define EAST 69

typedef enum e_move
{
	NORMAL,
	WALKING,
	ATTACKING,
}	t_move;

typedef struct s_map_info
{
	int		window_width;
	int		window_height;
	int		rays_num;
	char	*north_txt;
	char	*south_txt;
	char	*west_txt;
	char	*east_txt;
	char	*ceiling;
	char	*door;
	int		floor;
	char	**map;
	int		height_map;
	int		width_map;
}	t_map_info;

typedef struct s_player
{
	double	x;
	double	y;
	double	fov;
	int		offset_x;
	int		offset_y;
	double	move_speed;
	double	rotation_speed;
	double	rotation_angle;
	int		position_side;
	int		release_mouse;
}	t_player;

typedef struct s_img
{
	mlx_t		*mlx;
	mlx_image_t	*map;
	mlx_image_t	*minimap;
	mlx_image_t	*amination;
	mlx_image_t	*north;
	mlx_image_t	*south;
	mlx_image_t	*west;
	mlx_image_t	*east;
	mlx_image_t	*ceiling;
	mlx_image_t	*door;
}	t_img;

typedef struct s_ray_horz
{
	double		wall_hit_x;
	double		wall_hit_y;
	double		found_hit;
	int			door;
}	t_ray_horz;

typedef struct s_ray_vert
{
	double		wall_hit_x;
	double		wall_hit_y;
	double		found_hit;
	int			door;
}	t_ray_vert;

typedef struct s_ray
{
	double			was_hit_vertical;
	double			wall_hit_x;
	double			wall_hit_y;
	double			distance;
	double			ray_angle;
	bool			door;
}	t_ray;

typedef struct s_data
{
	t_move				move;
	t_img				imgs;
	t_map_info			map_info;
	t_player			player;
	t_ray				rays[WIN_WIDTH];
	bool				rand;
}	t_data;

typedef struct s_horz_info
{
	double	x_step;
	double	y_step;
	double	x_intercept;
	double	y_intercept;
	double	next_horz_touch_x;
	double	next_horz_touch_y;
	double	down;
	double	up;
	double	right;
	double	left;
}	t_horz_info;

typedef struct s_vert_info
{
	double	x_step;
	double	y_step;
	double	x_intercept;
	double	y_intercept;
	double	next_vert_touch_x;
	double	next_vert_touch_y;
	double	right;
	double	left;
	double	down;
	double	up;
}	t_vert_info;

/****************************** |ADD BY YOUSSEF| *****************************/

		/*Linked_ls*/
typedef struct s_list
{
	char			*str;
	struct s_list	*next;
}	t_list;

typedef struct s_cord
{
	int	x;
	int	y;
}	t_cord;

void		ft_lstclear(t_list **lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
t_list		*ft_lstnew(char *content);
int			ft_lstsize(t_list *lst);
void		print_list(t_list *head);

		/* FUNCTIONS */
void		ft_draw_line(t_cord strt, t_cord end, t_data *data, int color);
void		ft_mini_map(t_data *data, int x, int y);
void		animation(void *arg);
void		open_door(t_data *data);
void		close_door(t_data *data);
void		draw_img(t_data *data, t_cord cord, mlx_image_t *img, int wall);
char		*ft_itoa(int n);
void		open_image(char *path, mlx_image_t **img, t_data *data);
void		free_imgs(t_data *data);
int			ft_check_door(t_map_info *map, int i, int j);
void		open_textures(t_data *data);
void		set_retation(t_data *data);
void		trime(t_data *data);
int			ft_strchr( char *s, int c);
int			ft_strchr( char *s, int c);
size_t		len_map(t_list *hd);
int			check_map_line(char *line);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
void		*ft_memset(void *b, int c, size_t len);
void		free_it_v2(char **s, int i);
void		second_parse(int fd, t_data *data, char *lst_line);
void		free_map_info(t_data *data);
int			parce_color(char *line);
int			ft_isdigit(int c);
char		*ft_strtrim( char *s1, char *set);
char		*ft_monstrdup( char *s1, size_t size);
int			ft_strncmp( char *s1, char *s2, size_t n );

void		read_file_parse(int ac, char **av, t_data *data);
int			ft_strcmp(char *s1, char *s2);
void		error_and_exit(char *s, int exite);
int			ft_strlen(char *s);

/*get_next_line*/
char		*read_and_getline(char *buf, int fd, char *line);
void		free_it(char *str);
char		*ft_strjoin1(char *line, char *buf);
void		shift(char *buf, int endl);
int			ft_strlen1(char *s);
int			ft_strchr1( char *s, int readit);
char		*get_next_line(int fd);
/******************************************************************************/

int			hit_wall(t_data *data, int x, int y);
void		draw(void *data);
void		cast_all_rays(t_data *data, t_ray *rays);
void		cast_ray(double ray_angle, t_data *data, t_ray *ray);
t_ray_horz	cast_horz_ray(double ray_angle, t_data *data);
t_ray_vert	cast_vert_ray(double ray_angle, t_data *data);
double		normalize_angle(double angle);
double		distance_between_points(double x1, double y1, double x2, double y2);
int			keep_checking(t_data *data, int x, int y);
int			hit_vert(t_data *data, t_vert_info info);
int			hit_horz(t_data *data, t_horz_info info);
void		render_walls(t_data *data, t_ray *rays);
/// movement
void		movement(void *arg);
void		move_forward(t_data *data);
void		move_backward(t_data *data);
void		move_left(t_data *data);
void		move_right(t_data *data);
int			validate_step(t_data *data, int x, int y, int dir);
void		rotate_left(t_data *data);
void		rotate_right(t_data *data);
void		running_forward(t_data *data);
#endif