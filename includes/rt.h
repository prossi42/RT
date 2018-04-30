/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgaillar <jgaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 14:06:29 by jgaillar          #+#    #+#             */
/*   Updated: 2018/04/23 12:23:43 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H

# define RT_H
# define WIDTH 1280
# define LENGTH 720
# define RATIO WIDTH / LENGTH
# define FOV 20
# define FOVCAMSD 20
# define MT 4
# define MTI 2
# define RAY 10
# define BUFF_SIZE 0xfffff
# define LENGHT_PROCED 1
# define SPHERE 0
# define PLAN 1
# define CYLINDRE 2
# define CONE 3
# define LIGHT 4
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include <pthread.h>
# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <stdio.h>
# include <dirent.h>
# include <sys/stat.h>
# include <errno.h>
# define WIN_X 1800
# define WIN_Y 1000

typedef struct		s_xycoef
{
	int				x;
	int				y;
	int				coef;
}					t_xycoef;

typedef struct		s_pos
{
	int				x;
	int				y;
	int				z;
}					t_pos;

typedef struct		s_vec
{
	double			x;
	double			y;
	double			z;
	double			length;
}					t_vec;

typedef struct		s_mat
{
	double			angle;
	double			radian;
	double			value;
	char			type;
	char			axe;
	int				type_sujet;
	t_vec			tmp_pos;
}					t_mat;

typedef struct		s_seg
{
	int				dx;
	int				dy;
	int				sx;
	int				sy;
	int				err;
	int				e2;
}					t_seg;

typedef struct		s_rgb
{
	int				r;
	int				g;
	int				b;
}					t_rgb;

typedef struct		s_d
{
	int				nbmsph;
	int				nbmpla;
	int				nbmlight;
	int				nbmcyl;
	int				nbmcone;
	int				nbl;
	int				equal;
	int				dot;
	int				i;
	double			*tabd;
	double			*tabdpla;
	double			*tabdlight;
	double			*tabdcyl;
	double			*tabdcone;
	double			scol;
	double			scolsph;
	double			scolpla;
	double			scolcyl;
	double			scolcone;
	double			refrac;
	double			refracsph;
	double			refracpla;
	double			refraccyl;
	double			refraccone;
	t_rgb			color;
	t_rgb			colsph;
	t_rgb			colpla;
	t_rgb			colcyl;
	t_rgb			colcone;
}					t_d;

typedef struct		s_c
{
	double			distvue;
	double			longvue;
	double			largvue;
	int				posx;
	int				posy;
	double			xindent;
	double			yindent;
	int				i;
	int				n;
	double			dist;
	double			distsph;
	double			distpla;
	double			distcyl;
	double			distcone;
	double			distlight;
	int				obj;
	int				objsph;
	int				objpla;
	int				objcyl;
	int				objcone;
	int				objlight;
	double			reflex;
	double			reflexsph;
	double			reflexpla;
	double			reflexcyl;
	double			reflexcone;
	double			refrac;
	double			refracsph;
	double			refracpla;
	double			refraccyl;
	double			refraccone;
	double			conscol;
	double			conscolsph;
	double			conscolpla;
	double			conscolcyl;
	double			conscolcone;
	t_rgb			colorf;
	t_vec			inter;
	int				blurx;
	int				blury;
}					t_c;

typedef struct		s_b
{
	int				fd;
	char			buf[BUFF_SIZE + 1];
	char			**tab;
	char			*tmp;
	char			*tmp2;
	char			*tmp3;
	double			*tabd;
	int				i;
	int				y;
}					t_b;

typedef struct		s_texture
{
	t_rgb			c1;
	t_rgb			c2;
	t_rgb			c3;
}					t_texture;

typedef struct		s_sphere
{
	struct s_sphere	*prev;
	t_vec			pos;
	double			ray;
	t_rgb			color;
	double			det;
	double			t1;
	double			t2;
	double			t;
	double			refrac;
	double			reflex;
	double			conscol;
	t_vec			norm;
	t_texture		text;
	int				nm;
	struct s_sphere	*next;
}					t_sphere;

typedef struct		s_plan
{
	struct s_plan	*prev;
	t_vec			norm;
	t_vec			norml;
	t_vec			pos;
	t_rgb			color;
	t_texture		text;
	double			t;
	double			refrac;
	double			reflex;
	double			conscol;
	int				nm;
	double			ray;
	struct s_plan	*next;
}					t_plan;

typedef struct		s_cyl
{
	struct s_cyl	*prev;
	t_vec			norm;
	t_vec			norml;
	t_vec			pos;
	double			ray;
	t_rgb			color;
	t_texture		text;
	double			t1;
	double			t2;
	double			t;
	double			det;
	double			refrac;
	double			reflex;
	double			conscol;
	int				nm;
	struct s_cyl	*next;
}					t_cyl;

typedef struct		s_cone
{
	struct s_cone	*prev;
	t_vec			norm;
	t_vec			norml;
	t_vec			pos;
	t_rgb			color;
	t_texture		text;
	double			angle;
	double			t1;
	double			t2;
	double			t;
	double			det;
	double			refrac;
	double			reflex;
	double			conscol;
	int				nm;
	struct s_cone	*next;
}					t_cone;

typedef struct		s_light
{
	struct s_light	*prev;
	t_vec			pos;
	t_vec			norm;
	t_vec			lightdir;
	t_rgb			color;
	t_texture		text;
	double			ray;
	double			det;
	double			t1;
	double			t2;
	double			t;
	double			amb;
	double			diff;
	int				nm;
	struct s_light	*next;
}					t_light;

typedef	struct		s_tmp
{
	t_sphere		*tmpsph;
	t_plan			*tmpplan;
	t_cyl			*tmpcyl;
	t_cone			*tmpcone;
	t_light			*tmplight;
	t_rgb			tmpcolor;
}					t_tmp;

typedef struct		s_img
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	void			*img_ptri;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
	int				size;
	char			*data;
}					t_img;

typedef	struct		s_tree
{
	struct s_tree	*prev;
	t_vec			tmpinter;
	t_sphere		*tmpsph;
	t_plan			*tmpplan;
	t_cyl			*tmpcyl;
	t_cone			*tmpcone;
	t_light			*tmplight;
	t_rgb			tmpcolor;
	t_rgb			tmpscolor;
	int				tmpnm;
	int				tmpl;
	int				tmptest;
	int				objet;
	int				id;
	double			conscol;
	double			refrac;
	struct s_tree	*left;
	struct s_tree	*right;
}					t_tree;

typedef struct		s_data
{
	t_vec			pos;
	t_vec			dir;
	t_rgb			color;
	t_texture		text;
	double			ray;
	double			angle;
	double			amb;
	double			diff;
	double			refrac;
	double			reflex;
	double			conscol;
}					t_data;

typedef struct		s_mlx
{
	struct s_mlx	*prev;
	void			*img;
	char			*map;
	int				bpp;
	int				size_line;
	int				endian;
	int				nmail;
	int				img_x;
	int				img_y;
	t_data			data;
	struct s_mlx	*next;
}					t_mlx;

typedef struct		s_damier
{
	int				x1;
	int				y1;
	int				z1;
	double			px;
	double			py;
	double			pz;
}					t_damier;

typedef struct		s_intermat
{
	int				act_rot;
	int				act_trans;
	int				col_box;
	int				col_fond;
	int				dir_or_pos;
	int				act_xyz;
	int				act_angle;
	int				act_value;
	int				settings;
}					t_intermat;

typedef struct		s_interterm
{
	char			**tab;
	int				index;
	int				indextab;
	int				first;
	char			*wbuf;
	int				tabfill;
	int				dot;
}					t_interterm;

typedef struct		s_newobj
{
	int				act_obj;
	int				first;
	int				type;
	int				open;
	int				old_open;
	int				power;
	int				settings;
}					t_newobj;

typedef struct		s_curobj
{
	char			**tab;
	int				power;
	int				settings;
}					t_curobj;

typedef struct		s_loads
{
	int				index_load;
	DIR				*dir_stream;
	struct dirent	*dir_list;
	int				nb_dir;
	char			**tab;
	int				index;
	int				select;
	int				first;
	int				act_load;
	int				act_erase;
	char			buf[BUFF_SIZE + 1];
	char			**tab_load;
	int				nbl;
	int				nsph;
	int				ncyl;
	int				ncone;
	int				npla;
	int				nlight;
	double			*tabdsph;
	double			*tabdpla;
	double			*tabdlight;
	double			*tabdcyl;
	double			*tabdcone;
}					t_loads;

typedef struct		s_saves
{
	int				select;
	int				settings;
	int				act_save;
	char			*save_dir;
	char			*u_save_dir;
	char			*u_save_file;
	int				fd;
	struct stat		st;
	char			*save_buf;
	char			*tmp_buf;
}					t_saves;

typedef struct		s_scouleur
{
	int				col1;
	int				col2;
	int				col3;
}					t_scouleur;

typedef struct		s_couleur
{
	t_scouleur		nobj;
	t_scouleur		cobj;
	t_scouleur		saves;
	t_scouleur		mat;
	int				**tab;
	int				**tabxd;
	int				**tabxf;
	int				**tabyd;
	int				**tabyf;
	int				padx;
	int				pady;
}					t_couleur;

typedef struct		s_multiobj
{
	int				first;
	int				len;
	double			ray;
	t_vec			pos;
	t_rgb			color;
	double			refrac;
	double			reflex;
	double			conscol;
	int				start;
	int				end;
}					t_multiobj;

typedef struct		s_screenshot
{
	char			*path;
	int				height;
	int				width;
	int				fd;
	struct stat		st;
	int				act_scr;
}					t_screenshot;

typedef	struct		s_ntmgtk
{
	int				nb_img;
	t_mlx			*mlx;
	t_mlx			*tmp_mlx;
	int				first;
	int				img_x;
	int				img_y;
	t_vec			poscam;
	t_vec			preg;
	t_vec			dircam;
	t_vec			vecdroit;
	t_vec			upleft;
	int				objet;
	int				each_obj;
	t_intermat		mat;
	t_interterm		term;
	t_newobj		nobj;
	t_curobj		cobj;
	t_saves			save;
	t_couleur		color;
	t_loads			load;
	int				filtre;
	int				multi;
	t_multiobj		mobj;
	t_screenshot	scr;
	t_vec			raydir;
	int				perlin;
	double			perlin_stain;
	int				wave;
	int				reflex;
	int				refrac;
	int				damier;
	t_rgb			col_dam1;
	t_rgb			col_dam2;
	int				i;
}					t_ntmgtk;

typedef struct		s_letter
{
	char			charac;
	unsigned long	couleur;
	int				posx;
	int				posy;
	double			coeff;
	int				space;
}					t_letter;

typedef struct		s_bres
{
	int				dx;
	int				dy;
	int				xi;
	int				xf;
	int				yi;
	int				yf;
	int				cumul;
	int				xinc;
	int				yinc;
	double			ray_arc;
	int				x_arc;
	int				y_arc;
	int				width;
	int				height;
	int				a2;
	int				b2;
	int				fa2;
	int				fb2;
	int				sigma;
	int				x;
	int				y;
}					t_bres;

typedef struct		s_camera
{
	struct s_camera	*prev;
	t_vec			poscam;
	int				nm;
	struct s_camera *next;
}					t_camera;

typedef struct		s_perlin
{
	int				x1;
	int				y1;
	int				z1;
	double			x;
	double			y;
	double			z;
	double			x_pos;
	double			y_pos;
	double			z_pos;
	double			g000;
	double			g001;
	double			g010;
	double			g011;
	double			g100;
	double			g101;
	double			g110;
	double			g111;
	double			u;
	double			v;
	double			w;
	double			x00;
	double			x10;
	double			x01;
	double			x11;
	double			xy0;
	double			xy1;
	double			xyz;
	unsigned char	perm[298];
	int				grad3[16][3];
}					t_perlin;

typedef struct		s_uv
{
	double			x;
	double			y;
}					t_uv;

typedef struct		s_skybox
{
	char			is_init;
	void			*ptr;
	char			*data;
	int				bpp;
	int				sizl;
	int				endian;
	int				width;
	int				height;
	int				act_skybox;
}					t_skybox;

typedef	struct		s_stuff
{
	t_tree			*tree;
	t_tmp			ref;
	t_b				b;
	t_c				c;
	t_d				d;
	t_img			img;
	t_vec			poscam;
	t_vec			pr;
	t_vec			vech;
	t_vec			vecupleft;
	t_vec			vecdroit;
	t_vec			raydir;
	t_vec			dircam;
	t_sphere		*sph;
	t_sphere		*tmp;
	t_plan			*pla;
	t_plan			*tmppla;
	t_light			*light;
	t_light			*tmplight;
	t_cyl			*cyl;
	t_cyl			*tmpcyl;
	t_cone			*cone;
	t_cone			*tmpcone;
	t_seg			seg;
	t_perlin		p;
	int				pix;
	int				fd;
	char			buf[BUFF_SIZE + 1];
	int				l;
	int				test;
	int				ray;
	int				imt;
	int				jmt;
	double			start;
	double			end;
	double			start2;
	double			end2;
	t_mat			m;
	t_ntmgtk		i;
	t_letter		lt;
	t_bres			bs;
	int				s;
	double			rotx;
	double			rotx2;
	double			roty;
	double			rotz;
	int				u;
	t_skybox		tex;
}					t_stuff;

void				vectorcalc(t_stuff *e);
void				reboot_list(t_stuff *e);
void				print_list(t_stuff *e);
void				reboot_list_loop(t_stuff *e, int option);
int					ft_check(t_stuff *e);
int					ft_parsing(t_stuff *e);
int					ft_parsing_sd(t_stuff *e);
int					ft_compare_camera(char *str, int i);
int					check_format(t_stuff *e);
int					check_data_sphere(t_stuff *e, int y);
int					ft_compare_sphere(char *str, int i);
int					init_list_sph(t_sphere **sph);
void				fill_list_sph(t_sphere **sph, double *tabd, int nbm);
int					check_data_plan(t_stuff *e, int y);
int					init_list_pla(t_plan **pla);
int					ft_compare_plan(char *str, int i);
void				fill_list_pla(t_plan **pla, double *tabdpla, int nbmpla);
int					ft_compare_light(char *str, int i);
int					check_data_light(t_stuff *e, int y);
int					init_list_light(t_light **light);
void				fill_list_light(t_light **light, double *tabdlight, \
					int nbmlight);
int					init_list_cyl(t_cyl **cyl);
int					check_data_cylindre(t_stuff *e, int y);
void				fill_list_cyl(t_cyl **cyl, double *tabdcyl, int nbmcyl);
int					ft_compare_cylindre(char *str, int i);
t_rgb				getlight(t_vec *norm, t_light **light, t_rgb *colorobj, \
					t_stuff *es);
void				ft_exit(int code, t_stuff *e);
void				ft_init_struct(t_stuff *e, int option);
void				create_image(t_stuff *e);
void				*aff(void *e);
void				multi_thread(t_stuff *e);
void				multi_thread2(t_stuff *e);
int					release(int keycode, t_stuff *e);
void				dedouble_list(t_stuff *tmp);
void				vecsous(t_vec *res, t_vec *i, t_vec *j);
void				vecadd(t_vec *res, t_vec *i, t_vec *j);
double				dot_product(t_vec *i, t_vec *j);
void				cross_product(t_vec *res, t_vec *i, t_vec *j);
void				vecpuivec(t_vec *res, t_vec *i, t_vec *j);
void				upleft(t_stuff *e);
void				raydir(t_stuff *e, int x, int y);
void				checksphere(t_sphere *sphere, t_vec *raydir, t_vec *poscam);
void				checkplan(t_plan *plan, t_vec *raydir, t_vec *poscam);
void				mlx_pixel_put_to_image(t_img img, int x, int y, int color);
int					hooks(int keycode, t_stuff *e);
void				echap(int keycode, t_stuff *e);
void				cleanexit(t_stuff *e);
void				vecnorm(t_vec *i);
void				veclength(t_vec *i);
void				getintersection(t_stuff *e, double dist, \
	t_vec *raydir, t_vec *pos);
void				movement(int keycode, t_stuff *e);
t_rgb				raythingy(t_stuff *e, t_vec *raydir, t_vec *pos);
double				rgbtohexa(int r, int g, int b);
void				checklight(t_light *light, t_vec *raydir, t_vec *poscam);
void				checkcyl(t_cyl *cyl, t_vec *raydir, t_vec *poscam);
void				checkcone(t_cone *cone, t_vec *raydir, t_vec *poscam);
int					cone(t_stuff *e, int y);
int					init_list_cone(t_cone **cone);
int					check_data_cone(t_stuff *e, int y);
void				fill_list_cone(t_cone **cone, double *tabdcone, \
					int nbmcone);
int					ft_compare_cone(char *str, int i);
void				searchlist(t_stuff *e, int nmail, int nlist);
void				check_dist(t_stuff *e, int option);
void				check(t_stuff *e, t_vec *raydir, t_vec *pos, int option);
int					cylindre(t_stuff *e, int y);
int					light(t_stuff *e, int y);
int					plan(t_stuff *e, int y);
int					sphere(t_stuff *e, int y);
int					cone(t_stuff *e, int y);
int					ft_compare_cone_sd(char *str, int i);
double				shadows(t_stuff *e, t_vec *inter, t_rgb color);
int					mouse_hook(int button, int x, int y, t_stuff *e);
void				ft_segment(t_stuff *e, int x1, int y1, double color);
void				rgb_add(t_rgb *res, t_rgb i, t_rgb j, double k);
void				getlightdir(t_stuff *e, t_vec inter);
void				getspeclight(t_stuff *e, t_vec *norm, t_rgb *color, \
					t_light **light);
t_vec				getrefray(t_vec *norm, t_vec *pos, \
					t_vec *inter);
void				oklm(t_stuff *e);
int					raythingydebug(t_stuff *e);
void				matrice(char type, char axe, t_stuff *e, t_vec *sujet);
void				rotation_z(t_vec *sujet, double radian);
void				rotation_x(t_vec *sujet, double radian);
void				rotation_y(t_vec *sujet, double radian);
void				translation_x(t_vec *sujet, double value);
void				translation_y(t_vec *sujet, double value);
void				translation_z(t_vec *sujet, double value);
void				convert_deg_in_rad(int angle_degre, t_stuff *e);
t_rgb				reflect(t_stuff *e, int obj);
t_vec				getspeclight2(t_stuff *e, t_vec *norm, t_vec *light);
t_vec				revvec(t_vec vec);
t_vec				getrefracray(t_vec *norm, t_vec *pos, t_vec *inter, \
					double fac);
t_rgb				refrac(t_stuff *e, int obj);
int					init_tree(t_tree **tree);
t_rgb				rgb_ave(t_rgb i, t_rgb j, double k);
void				damier(t_stuff *e, t_rgb *color, t_vec *pos);
void				damier_sd(t_stuff *e, t_rgb *color, t_damier *a);
void				dam(t_stuff *e, int obj);
int					init_tree(t_tree **tree);
void				refraction(t_stuff *e);
void				reflexion(t_stuff *e);
void				perlin_sphere(t_stuff *e);
void				perlin_cone(t_stuff *e);
void				perlin_cyl(t_stuff *e);
void				perlin_plan(t_stuff *e);
int					checkdisk(t_plan *plan, t_vec *raydir, t_vec *poscam);
void				init_raythingy(t_stuff *e, t_vec *raydir, t_vec *pos);
void				light_sph(t_stuff *e);
void				light_plan(t_stuff *e, t_vec *raydir);
void				light_cyl(t_stuff *e);
void				light_cone(t_stuff *e);
void				lumos_maxima(t_stuff *e, t_vec *raydir);
void				light_set(t_stuff *e);
void				after_light(t_stuff *e);
void				init_rgb(t_rgb *rgb, int r, int g, int b);
void				pixelisation(t_stuff *e, double color);
t_vec				fix(t_vec inter, t_vec norm, t_vec pos);
void				perlin_tab_eld(t_perlin *p);
double				smooth_noise_3d(double x_pos, double y_pos, \
	double z_pos, t_stuff *e);
void				perlin_tab_sid(t_perlin *p);
void				perlin_tab(t_perlin *p);
double				fast_dot(const int *v, const double x, \
	const double y, const double z);
int					*get_grad(int x, int y, int z, t_perlin *p);
double				quintic_poly(const double t);
void				int_and_frac(double value, int *int_part, \
	double *fractional_part);
double				linear_interpolate(double a, double b, double t);
int					init_tree(t_tree **tree);
char				color_is_black(t_rgb *color);
t_rgb				skybox(t_stuff *e, t_rgb color, t_vec *raydir);
void				parse_skybox(t_stuff *e);
t_rgb				get_sky_rgb(int x, int y, t_skybox tex);
void				ntmleaks(t_stuff *e);
void				grad_tab(t_perlin *p);
void				tree_set(t_stuff *e, t_tree **tmp, int option);
void				fill_tree(t_stuff *e, int option);
void				dist_sph(t_stuff *e, t_vec *raydir, t_vec *pos, int option);
void				dist_pla(t_stuff *e, t_vec *raydir, t_vec *pos, int option);
void				dist_cyl(t_stuff *e, t_vec *raydir, t_vec *pos, int option);
void				dist_con(t_stuff *e, t_vec *raydir, t_vec *pos, int option);
void				dist_sph_sd(t_stuff *e);
void				dist_pla_sd(t_stuff *e);
void				dist_cyl_sd(t_stuff *e);
void				dist_con_sd(t_stuff *e);
void				init_dist(t_stuff *e);
void				fill_list_light_sd(t_light **light, double *tabdlight);
void				movement_matrice(int keycode, t_stuff *e);
void				move_objet(int keycode, t_vec *pos_obj, t_stuff *e);
void				move_multiobj(t_stuff *e, int keycode);
void				choose_sujet(t_stuff *e);
void				ft_init_value_aff_data_cone_sth(t_stuff *e, int \
	option, int len);
void				ft_init_value_aff_data_cylindre_sth(t_stuff *e, \
	int option, int len);
void				ft_init_value_aff_data_plan_sth(t_stuff *e, int option, \
	int len);
void				mouse_hook_matrice_save_color(t_stuff *e, int x, int y);
void				freetabmt(t_stuff *e, t_stuff *tab);

int					launch_interface(t_stuff *e);
void				init_struct(t_stuff *e, int option);
void				pixel_put_to_img(t_mlx **mlx, int x, int y, int color);
int					new_img(t_stuff *e);
int					init_img(t_mlx **mlx);
void				fill_img(t_mlx **mlx, int nbmail, t_stuff *e);
void				objet_courant(t_stuff *e);
void				reboot_list_interface(t_stuff *e, int option);
void				searchlist_interface(t_stuff *e, int nmail);
void				apercu_courant(t_stuff *e);
void				fill_value_current(t_stuff *e);
void				get_value_current(t_stuff *e);
void				terminal(t_stuff *e);
void				create_obj(t_stuff *e);
void				terminal(t_stuff *e);
void				matrice_interface(t_stuff *e);
void				mouse_hook_interface(t_stuff *e, int x, int y);
void				key_hook_interface(int keycode, t_stuff *e);
void				malloc2d(t_stuff *e);
void				free2d(t_stuff *e);
void				mouse_hook_newobj(t_stuff *e, int x, int y);
void				aff_new_sphere(t_stuff *e);
void				end_aff_new_sphere(t_stuff *e);
void				aff_new_plan(t_stuff *e);
void				end_aff_new_plan(t_stuff *e);
void				aff_new_cylindre(t_stuff *e);
void				end_aff_new_cylindre(t_stuff *e);
void				aff_new_cone(t_stuff *e);
void				end_aff_new_cone(t_stuff *e);
void				aff_new_light(t_stuff *e);
void				end_aff_new_light(t_stuff *e);
int					mouse_move(int x, int y, t_stuff *e);
void				mouse_move_new_obj(int x, int y, t_stuff *e);
void				set_value_new_objet(t_stuff *e);
void				del_sphere(t_stuff *e);
void				del_plan(t_stuff *e);
void				del_cylindre(t_stuff *e);
void				del_cone(t_stuff *e);
void				del_light(t_stuff *e);
void				ft_init_value_draw_camera(t_stuff *e, int option);
void				ft_init_value_draw_camera_sd(t_stuff *e, int option);
void				ft_init_value_draw_camera_td(t_stuff *e, int option);
void				draw_central_background(t_stuff *e);
void				init_value_draw_background(t_stuff *e, int option);
void				draw_side_background(t_stuff *e);
void				ft_init_value_draw_sphere(t_stuff *e, int option);
void				ft_init_value_draw_plan(t_stuff *e, int option);
void				ft_init_value_draw_plan_sd(t_stuff *e, int option);
void				ft_init_value_draw_plan_td(t_stuff *e, int option);
void				ft_init_value_draw_cylindre_cone(t_stuff *e, int option);
void				ft_init_value_draw_light(t_stuff *e, int option);
void				ft_init_value_draw_light_sd(t_stuff *e, int option);
void				draw_light(t_stuff *e);
void				switch_next_objet(t_stuff *e);
void				switch_prev_objet(t_stuff *e);
void				draw_moins(t_stuff *e);
void				ft_init_value_draw_moins(t_stuff *e, int option);
void				draw_plus(t_stuff *e);
void				ft_init_value_draw_plus(t_stuff *e, int option);
void				draw_ellipse_background(t_stuff *e);
void				ft_init_value_draw_ellipse_background(t_stuff *e, \
	int option);
void				aff_data_camera(t_stuff *e);
void				aff_data_sphere(t_stuff *e);
void				aff_data_plan(t_stuff *e);
void				aff_data_light(t_stuff *e);
void				aff_data_cylindre(t_stuff *e);
void				aff_data_cone(t_stuff *e);
unsigned long		rgba_to_hexa(int r, int g, int b, int a);
void				draw_title_background(t_stuff *e);
void				ft_init_value_draw_title_background(t_stuff *e, int \
	option);
void				ft_init_value_aff_data_camera(t_stuff *e, int option, \
	int len);
void				ft_init_value_aff_data_sphere(t_stuff *e, int option, \
	int len);
void				ft_init_value_aff_data_plan(t_stuff *e, int option, \
	int len);
void				ft_init_value_aff_data_light(t_stuff *e, int option, \
	int len);
void				ft_init_value_aff_data_cylindre(t_stuff *e, int option, \
	int len);
void				ft_init_value_aff_data_cone(t_stuff *e, int option, \
	int len);
void				save_scene(t_stuff *e);
void				save_scene_draw_ellipse_background(t_stuff *e);
void				save_scene_draw_title_background(t_stuff *e);
void				new_sphere(t_stuff *e);
void				new_plan(t_stuff *e);
void				new_cone(t_stuff *e);
void				new_cylindre(t_stuff *e);
void				new_light(t_stuff *e);
void				matrice_draw_ellipse_background(t_stuff *e);
void				matrice_draw_title_background(t_stuff *e);
void				ft_init_value_draw_settings(t_stuff *e, int option);
void				save_scene_create_save(t_stuff *e);
int					**ft_tabint(int x, int y);
void				fill_tab_color(int **tab);
void				fill_tab_color_sd(int **tab);
void				fill_tab_color_td(int **tab);
int					check_existing_save_dir(t_stuff *e);
int					check_existing_user_save_dir(t_stuff *e);
int					check_existing_user_save_file(t_stuff *e);
int					check_existing_save_file(t_stuff *e);
void				save_scene_load_save(t_stuff *e);
void				save_scene_load_save_draw_ellipse_background(t_stuff *e);
void				save_scene_load_save_draw_title_background(t_stuff *e);
void				free_tab(t_stuff *e);
int					save_scene_fill_save(t_stuff *e);
int					save_scene_parsing_save(t_stuff *e);
int					save_scene_erase_save(t_stuff *e);
int					parsing_sphere(t_stuff *e, int y);
int					parsing_plan(t_stuff *e, int y);
int					parsing_light(t_stuff *e, int y);
int					parsing_cylindre(t_stuff *e, int y);
int					parsing_cone(t_stuff *e, int y);
void				exit_interface(t_stuff *e);
void				settings_color(t_stuff *e);
void				freetabint(int **tab, int ymax);
void				mouse_hook_objet_courant(t_stuff *e, int x, int y);
void				mouse_hook_matrice(t_stuff *e, int x, int y);
void				mouse_hook_matrice_save(t_stuff *e, int x, int y);
void				mouse_hook_save_scene(t_stuff *e, int x, int y);
void				mouse_hook_load_scene(t_stuff *e, int x, int y, \
	int borderx);
void				shortcuts(t_stuff *e);
void				shortcuts_black_n_white(t_stuff *e);
void				shortcuts_cartoon(t_stuff *e);
void				shortcuts_blur(t_stuff *e);
void				shortcuts_cubespheres(t_stuff *e);
void				shortcuts_pyraspheres(t_stuff *e);
void				shortcuts_pixelisation(t_stuff *e);
void				shortcuts_antialiasing(t_stuff *e);
void				shortcuts_damier(t_stuff *e);
void				interface_filtres(t_stuff *e);
void				mouse_hook_shortcuts(t_stuff *e, int x, int y);
void				multiobj_create(t_stuff *e);
void				save_scene_fill_list_sph(t_stuff *e);
void				save_scene_fill_list_pla(t_stuff *e);
void				save_scene_fill_list_light(t_stuff *e);
void				save_scene_fill_list_cyl(t_stuff *e);
void				save_scene_fill_list_cone(t_stuff *e);
void				end_aff_multiobj_cubesphere(t_stuff *e);
void				aff_new_multiobj_cubesphere(t_stuff *e);
void				reboot_multiobj_value(t_stuff *e, int option);
void				shortcuts_screenshot(t_stuff *e);
void				shortcuts_perlin(t_stuff *e);
void				shortcuts_refraction(t_stuff *e);
void				shortcuts_reflexion(t_stuff *e);
void				screenshots_img(t_stuff *e);
void				up_vec_create(t_vec *vec);
void				right_vec_create(t_vec *vec);
void				forward_vec_create(t_vec *vec);
void				angle_increase(t_stuff *e, double z, double y, double x);
t_vec				y_rotation(t_vec vec, double angle);
t_vec				z_rotation(t_vec vec, double angle);
t_vec				x_rotation(t_vec vec, double angle);
void				rotation_apply(t_stuff *e, t_vec *dir);
void				rotation_apply2(t_stuff *e, t_vec *dir);
t_vec				wave(t_vec norm, t_vec inter, char axe, double coef);
void				shortcuts_wave(t_stuff *e);
char				*ft_mydtoa(double nb, char *str);
int					screenshots(t_stuff *e);
void				fill_value_apercu(t_stuff *e);
void				*aff_apercu(void *ev);
void				ft_init_value_create_obj_color(t_stuff *e, int option);
void				draw_sphere(t_stuff *e);
void				draw_plan(t_stuff *e);
void				draw_cylindre(t_stuff *e);
void				draw_cone(t_stuff *e);
void				draw_light(t_stuff *e);
void				draw_camera(t_stuff *e);
void				shortcuts_skybox(t_stuff *e);
void				shortcuts_negatif(t_stuff *e);
void				del_sphere_tools_fh(t_stuff *e);
void				del_sphere_tools_td(t_stuff *e);
void				del_sphere_tools_sd(t_stuff *e);
void				ft_init_value_draw_ellipse_background_sih(t_stuff *e, \
	int option);
void				init_struct(t_stuff *e, int option);
void				init_struct_sh(t_stuff *e, int option);
void				redraw_ellipse(t_stuff *e);
void				end_aff_perlin(t_stuff *e);
void				end_aff_save(t_stuff *e);
void				draw_terminal(t_stuff *e);
void				end_aff_screenshots(t_stuff *e);
void				end_aff_damier(t_stuff *e);
void				end_aff_matrice(t_stuff *e);
void				end_aff_multiobj(t_stuff *e);
void				aff_damier(t_stuff *e);
void				aff_save(t_stuff *e);
void				aff_angle(t_stuff *e);
void				aff_value(t_stuff *e);
void				end_aff_newobj(t_stuff *e);
void				aff_new_obj(t_stuff *e);
void				aff_perlin(t_stuff *e);
void				aff_screenshots(t_stuff *e);
void				aff_tab(t_stuff *e);
void				end_aff_new_sphere_seh(t_stuff *e, char *tmp);
char				*end_aff_new_sphere_sh(t_stuff *e, char *str);
void				end_aff_new_plan_seh(t_stuff *e, char *tmp);
char				*end_aff_new_plan_sh(t_stuff *e, char *tmp);
void				redraw_tab(t_stuff *e);
void				end_aff_new_light_sh(t_stuff *e, char *tmp);
void				end_aff_new_cylindre_seh(t_stuff *e, char *tmp);
char				*end_aff_new_cylindre_sh(t_stuff *e, char *tmp);
void				end_aff_new_cone_seh(t_stuff *e, char *tmp);
char				*end_aff_new_cone_sh(t_stuff *e, char *tmp);
void				end_aff_multiobj_cubesphere_seh(t_stuff *e, char *tmp);
char				*end_aff_multiobj_cubesphere_sh(t_stuff *e, char *tmp);
void				draw_square_shortcuts(t_stuff *e);
void				draw_shortcuts(t_stuff *e);
void				draw_arrow_shortcuts_refraction(t_stuff *e, \
	int centerx, int centery);
void				draw_ray_shortcuts_refraction(t_stuff *e, \
	int centerx, int centery);
void				draw_arrow_shortcuts_reflexion(t_stuff *e, \
	int centerx, int centery);
void				draw_bier_blur(t_stuff *e);
void				fill_ellipse_blur(t_stuff *e);
void				fill_arc_blur(t_stuff *e);
void				fill_beer_foam(t_stuff *e, int option);
void				draw_settings_color(t_stuff *e);
void				fill_tab_pix_sd(t_stuff *e);
void				fill_tab_pix(t_stuff *e);
void				ft_init_value_settings_color(t_stuff *e, \
	int option, t_scouleur trio);
void				settings_color_bind(t_stuff *e, t_scouleur trio);
void				del_excessed_mail_cone(t_stuff *e);
void				del_excessed_mail_cylindre(t_stuff *e);
void				del_excessed_mail_light(t_stuff *e);
void				del_excessed_mail_plan(t_stuff *e);
void				del_excessed_mail_sphere(t_stuff *e);
void				set_to_zero_list_sph(t_stuff *e);
void				set_to_zero_list_plan(t_stuff *e);
void				set_to_zero_list_light(t_stuff *e);
void				set_to_zero_list_cylindre(t_stuff *e);
void				set_to_zero_list_cone(t_stuff *e);
int					parsing_format_each_objet(t_stuff *e);
int					parsing_format(t_stuff *e);
void				del_excessed_mail(t_stuff *e);
void				empty_list(t_stuff *e);
void				free_tab_parsing(t_stuff *e);
void				save_scene_fill_list_sph(t_stuff *e);
void				save_scene_fill_list_pla(t_stuff *e);
void				save_scene_fill_list_light(t_stuff *e);
void				save_scene_fill_list_cyl(t_stuff *e);
void				save_scene_load_save_fhh(t_stuff *e);
void				save_scene_load_save_thh(t_stuff *e);
void				save_scene_load_save_twh(t_stuff *e);
void				save_scene_load_save_elh(t_stuff *e);
void				save_scene_load_save_th(t_stuff *e);
void				save_scene_load_save_nh(t_stuff *e);
void				save_scene_load_save_hh(t_stuff *e);
void				save_scene_load_save_seh(t_stuff *e);
void				save_scene_load_save_sh(t_stuff *e);
void				save_scene_load_save_fih(t_stuff *e);
void				save_scene_load_save_fh(t_stuff *e);
void				save_scene_load_save_td(t_stuff *e);
void				save_scene_load_save_sd(t_stuff *e);
void				save_scene_load_save(t_stuff *e);
int					save_scene_open_load_save(t_stuff *e);
int					save_scene_load_save_select_dir(t_stuff *e);
void				init_value_draw_title_background(t_stuff *e, int option);
void				fill_save_cylindre(t_stuff *e);
void				fill_save_light(t_stuff *e);
void				fill_save_plan(t_stuff *e);
void				fill_save_sphere(t_stuff *e);
void				ft_init_value_objet_courant_color(t_stuff *e, int option);
void				fill_value_current(t_stuff *e);
void				draw_objet_courant(t_stuff *e);
void				draw_ellipse_background_sh(t_stuff *e);
void				set_to_value(t_stuff *e);
void				create_pyrasphere(t_stuff *e);
void				create_cubesphere(t_stuff *e);
void				mouse_move_save_scene(int y, int x, t_stuff *e);
void				mouse_hook_shortcuts_filtres(t_stuff *e, int x);
void				mouse_hook_shortcuts_divers(t_stuff *e, int x);
void				mouse_hook_shortcuts_multiobj(t_stuff *e, int x);
void				mouse_hook_shortcuts_multiobj_sh(t_stuff *e);
void				set_del_objet(t_stuff *e);
void				set_new_obj(t_stuff *e);
void				mouse_hook_new_obj_color(t_stuff *e, int x, int y);
void				mouse_hook_matrice_hh(t_stuff *e);
void				mouse_hook_matrice_seh(t_stuff *e);
void				mouse_hook_matrice_sh(t_stuff *e);
void				mouse_hook_matrice_fih(t_stuff *e);
void				mouse_hook_matrice_save_select_color(t_stuff *e, \
	int x, int y);
void				hook_chiffre(int keycode, t_stuff *e);
void				hook_letres(int keycode, t_stuff *e);
t_rgb				get_pixel(int x, int y, t_img *img);
void				blur(t_stuff *e, int option);
t_rgb				blur_td_td(t_rgb alo, int i);
t_rgb				blur_td_sd(t_rgb alo, t_rgb tmp);
t_rgb				blur_td_sh(t_stuff *e, t_xycoef trio, \
	t_rgb tmp, t_rgb alo);
t_rgb				blur_td_fih(t_stuff *e, t_xycoef trio, \
	t_rgb tmp, t_rgb alo);
t_rgb				blur_td_fh(t_stuff *e, t_xycoef trio, t_rgb tmp, t_rgb alo);
void				raydir_apercu(t_stuff *e, int y, int z);

void				a(t_stuff *e);
void				b(t_stuff *e);
void				c(t_stuff *e);
void				d(t_stuff *e);
void				ee(t_stuff *e);
void				f(t_stuff *e);
void				g(t_stuff *e);
void				h(t_stuff *e);
void				i(t_stuff *e);
void				j(t_stuff *e);
void				k(t_stuff *e);
void				l(t_stuff *e);
void				m(t_stuff *e);
void				n(t_stuff *e);
void				o(t_stuff *e);
void				p(t_stuff *e);
void				q(t_stuff *e);
void				r(t_stuff *e);
void				s(t_stuff *e);
void				t(t_stuff *e);
void				u(t_stuff *e);
void				v(t_stuff *e);
void				w(t_stuff *e);
void				x(t_stuff *e);
void				y(t_stuff *e);
void				z(t_stuff *e);
void				zero(t_stuff *e);
void				one(t_stuff *e);
void				two(t_stuff *e);
void				three(t_stuff *e);
void				four(t_stuff *e);
void				five(t_stuff *e);
void				six(t_stuff *e);
void				seven(t_stuff *e);
void				eight(t_stuff *e);
void				nine(t_stuff *e);
void				dot(t_stuff *e);
void				minus(t_stuff *e);
void				colons(t_stuff *e);
void				slash(t_stuff *e);
void				hashtag(t_stuff *e);
void				exclamation(t_stuff *e);
void				ft_segment_letter(t_stuff *e);
void				ft_arc(t_stuff *e, int option);
void				awklm_string_put(char *str, t_stuff *e);
void				ft_ellipse(t_stuff *e, int piece, int option);
void				settings(t_stuff *e);
void				full_box(t_stuff *e);
void				empty_box(t_stuff *e);
void				ft_full_ellipse(t_stuff *e, int piece, int option);
void				ft_full_arc(t_stuff *e, int option);
void				ft_init_segment_a(t_stuff *e, int option);
void				ft_init_segment_b(t_stuff *e, int option);
void				ft_init_segment_e(t_stuff *e, int option);
void				draw_high_letter(t_stuff *e);
void				ft_arc_sd(t_stuff *e, int option, int x, int y);
void				select_part_height_sd(t_stuff *e, int x, int y, int option);
void				select_part_height(t_stuff *e, int x, int y, int option);
void				select_part_width_sd(t_stuff *e, int x, int y, int option);
void				select_part_width(t_stuff *e, int x, int y, int option);
void				ft_init_value_settings(t_stuff *e, int option);
void				ft_init_value_two(t_stuff *e, int option);

t_sphere			*copysphlist(t_sphere *sph);
t_light				*copylightlist(t_light *light);
t_plan				*copyplalist(t_plan *pla);
t_cone				*copyconelist(t_cone *cone);
t_cyl				*copycyllist(t_cyl *cyl);

#endif
