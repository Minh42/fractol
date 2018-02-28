/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minh <minh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 16:07:07 by mpham             #+#    #+#             */
/*   Updated: 2018/02/28 17:48:02 by minh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include "libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include "mlx.h"
# include "math3d.h"
# include <time.h>

# define WIN_WIDTH 800
# define WIN_HEIGHT 600

# define EXIT 53
# define ZOOM_IN 69
# define ZOOM_OUT 78
# define MOVE_UP 126
# define MOVE_DOWN 125
# define MOVE_RIGHT 124
# define MOVE_LEFT 123
# define CIM_UP 13
# define CIM_DOWN 1
# define CRE_UP 2
# define CRE_DOWN 0

// typedef union   u_color;
// {
//   unsigned int  number;
//   unsigned char channels[4];
// };

typedef	struct		s_rgb
{
	float			r; // ∈ [0, 255]
	float			g; // ∈ [0, 255]
	float			b; // ∈ [0, 255]
}					t_rgb;

typedef	struct		s_hsv
{
	float			h; // ∈ [0, 360]
	float			s; // ∈ [0, 1]
	float			v; // ∈ [0, 1]
}					t_hsv;

typedef	struct		s_img
{
	void			*img_ptr;
	int				*data;
	int				sizeline;
	int				bpp;
	int				endian;
}					t_img;

typedef struct      s_mdb
{
	double			pr;
	double			pi;
    double          new_re;
    double          new_im;
    double          old_re;
    double          old_im;
    double          zoom;
    double          movex;
    double          movey;
	double			current_time;
	double			old_time;
	double			frametime;
 	int				max_iter;
	t_rgb			rgb_color;	    
}                   t_mdb;


typedef struct      s_julia
{
    double          c_re;
    double          c_im;
    double          new_re;
    double          new_im;
    double          old_re;
    double          old_im;
    double          zoom;
    double          movex;
    double          movey;
	double			current_time;
	double			old_time;
	double			frametime;
	int				max_iter;
	t_rgb			rgb_color;
}                   t_julia;

// typedef struct      s_newton
// {
    
// }                   t_newton;

typedef	struct		s_env
{
	void			*mlx;
	void			*win;
	t_img			img;
	int				offset_x;
	int				offset_y;
	int				zoom;
	int				scale_z;
	int				angle_x;
	int				angle_y;
	int				angle_z;
	int				color_r;
	int				color_g;
	int				color_b;
	int				fract;
    t_mdb           *mdb;
    t_julia         julia;
    // t_newton        *newton;
}					t_env;

void				ft_create_image(t_env *e);
void    			init_julia_set(t_env *e);
void                ft_draw_julia(t_env *e);
void    			ft_draw_mandelbrot(t_env *e);
void 				ft_draw_burnship(t_env *e);
t_hsv 				ColorHSV(float h, float s, float v);
t_rgb 				ColorRGB(float r, float g, float b);
t_hsv   			rgb2hsv(t_rgb rgb_color);
t_rgb   			hsv2rgb(t_hsv hsv_color);
int 				createRGB(int r, int g, int b);
void				ft_init_img(t_env *e);
void				ft_fill_pixel(t_env *e, int x, int y, int rgb_color);
int					key_hook(int keycode, t_env *e);
void				zoom_hook(int keycode, t_env *e);
void				move_hook(int keycode, t_env *e);
void				shape_hook(int keycode, t_env *e);
void				ft_redraw(t_env *e);


#endif
