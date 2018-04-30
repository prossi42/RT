# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgaillar <jgaillar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/26 20:10:24 by jgaillar          #+#    #+#              #
#    Updated: 2018/04/23 12:45:13 by prossi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH = src/

SRC_NAME = main.c raytracing.c struct.c image.c vector.c vector2.c hooks.c \
			check_data_plan.c check_data_light.c check_data_sphere.c \
			check_data_cylindre.c ft_check.c ft_compare_sd.c ft_compare.c \
			ft_parsing_sd.c ft_parsing.c list_tools.c vectorcalc.c \
			check_format.c check_format_obj.c check_data_cone.c check_obj.c \
			shadows.c mouse_hook.c matrice.c rot_matrice.c trans_matrice.c \
			init_list.c fill_list.c ft_compare_td.c damier.c copy_list.c \
			perlin.c perlin_test.c calc_light.c light_obj.c reflection.c \
			refraction.c perlin_tab.c perlin_tab_sd.c perlin_tab_td.c \
			grad_tab.c init_tree.c skybox.c check_obj_sd.c check.c check_sd.c \
			check_dist.c raytracing_sd.c fill_list_sd.c light_obj_sd.c \
			hooks_sd.c hooks_td.c vector3.c perlin_test_sd.c main_sd.c \
			freetabmt.c

PATH_INTERFACE = src/interface/

PATH_LIB_LETTER = src/interface/lib_letter

SRC_NAME_INTERFACE = init_interface.c interface_list_tools.c pixel_put_to_img.c\
 objet_courant.c apercu_courant.c create_obj.c terminal.c matrice_interface.c \
mouse_hook_interface.c key_hook_interface.c mouse_hook_newobj.c \
terminal_aff_new_sphere.c terminal_end_aff_new_sphere.c \
terminal_aff_new_plan.c terminal_end_aff_new_plan.c terminal_aff_new_cylindre.c\
 terminal_end_aff_new_cylindre.c terminal_end_aff_new_cone.c\
 terminal_aff_new_cone.c terminal_aff_new_light.c terminal_end_aff_new_light.c \
mouse_move.c mouse_move_new_obj.c newobj_sphere.c newobj_plan.c \
newobj_cylindre.c newobj_cone.c newobj_light.c del_sphere.c del_plan.c \
del_cylindre.c del_cone.c del_light.c create_obj_draw_camera.c \
ft_init_value_draw_camera.c ft_init_value_draw_camera_sd.c \
ft_init_value_draw_camera_td.c ft_init_value_draw_background.c \
create_obj_draw_central_background.c create_obj_draw_side_background.c \
create_obj_draw_objects.c ft_init_value_draw_sphere.c ft_init_value_draw_plan.c\
  ft_init_value_draw_plan_sd.c ft_init_value_draw_plan_td.c \
 ft_init_value_draw_cylindre_cone.c create_obj_draw_light.c \
ft_init_value_draw_light.c ft_init_value_draw_light_sd.c \
create_obj_switch_next_objet.c create_obj_switch_prev_objet.c \
create_obj_draw_moins.c ft_init_value_draw_moins.c create_obj_draw_plus.c \
ft_init_value_draw_plus.c ft_init_value_draw_ellipse_background.c \
objet_courant_draw_ellipse_backgroung.c objet_courant_aff_data_camera.c \
malloc2d.c rgba_to_hexa.c \
objet_courant_draw_title_background.c ft_init_value_draw_title_background.c \
ft_init_value_aff_data_camera.c objet_courant_aff_data_sphere.c \
objet_courant_aff_data_plan.c objet_courant_aff_data_light.c \
objet_courant_aff_data_cylindre.c objet_courant_aff_data_cone.c \
ft_init_value_aff_data_sphere.c ft_init_value_aff_data_plan.c \
ft_init_value_aff_data_light.c ft_init_value_aff_data_cylindre.c \
ft_init_value_aff_data_cone.c save_scene.c save_scene_draw_ellipse_background.c\
 matrice_draw_ellipse_background.c matrice_draw_title_background.c \
 save_scene_draw_title_background.c ft_init_value_draw_settings.c \
save_scene_create_save.c ft_tabint.c fill_tab_color.c fill_tab_color_sd.c \
fill_tab_color_td.c check_existing_save_dir.c save_scene_load_save.c \
save_scene_load_save_draw_ellipse_background.c \
save_scene_load_save_draw_title_background.c save_scene_fill_save.c \
save_scene_parsing_save.c save_scene_parsing_sphere.c  \
save_scene_parsing_plan.c save_scene_parsing_light.c \
save_scene_parsing_cylindre.c save_scene_parsing_cone.c save_scene_erase_save.c\
 exit_interface.c settings_color.c freetabint.c mouse_hook_objet_courant.c \
mouse_hook_matrice.c mouse_hook_matrice_save.c mouse_hook_save_scene.c \
mouse_hook_load_scene.c shortcuts.c shortcuts_black_n_white.c \
shortcuts_cartoon.c shortcuts_blur.c shortcuts_cubespheres.c \
shortcuts_pyraspheres.c shortcuts_pixelisation.c shortcuts_antialiasing.c \
interface_filtres.c mouse_hook_shortcuts.c shortcuts_damier.c multiobj_create.c\
 save_scene_parsing_fill_list.c terminal_end_aff_multiobj_cubesphere.c \
terminal_aff_new_multiobj_cubesphere.c reboot_multiobj_value.c \
shortcuts_screenshot.c shortcuts_perlin.c shortcuts_reflexion.c \
shortcuts_refraction.c deplacement_matriciel_camera.c \
deplacement_matriciel_camera_sd.c shortcuts_wave.c ft_mydtoa.c screenshots.c \
apercu_courant_fill_value.c apercu_courant_aff_apercu.c \
create_obj_init_value_color.c shortcuts_skybox.c shortcuts_negatif.c \
ft_init_value_aff_data_cylindre_sd.c ft_init_value_aff_data_cone_sd.c \
ft_init_value_aff_data_plan_sd.c del_sphere_tools.c \
ft_init_value_draw_ellipse_background_sih.c init_struct_interface.c \
init_struct_interface_sd.c matrice_interface_redraw_ellipse.c \
terminal_end_aff_perlin.c terminal_end_aff_save.c \
terminal_end_aff_screenshots.c terminal_end_aff_damier.c \
terminal_end_aff_matrice.c terminal_end_aff_multiobj.c terminal_aff_damier.c \
terminal_aff_save.c terminal_aff_angle_value.c terminal_end_aff_newobj.c \
terminal_aff_newobj.c terminal_aff_perlin.c terminal_aff_screenshots.c \
terminal_aff_tab.c terminal_end_aff_new_sphere_sd.c \
terminal_end_aff_new_plan_sd.c terminal_end_aff_new_light_sd.c \
terminal_end_aff_new_cylindre_sd.c terminal_end_aff_new_cone_sd.c \
terminal_end_aff_multiobj_cubesphere_sd.c shortcuts_sd.c \
shortcuts_draw_shortcuts_refraction.c shortcuts_draw_shortcuts_reflexion.c \
shortcuts_draw_bier_shortcuts.c settings_color_fill_tab_pix.c \
settings_color_init_value.c settings_color_tools.c \
save_scene_del_excessed_mail.c save_scene_set_to_zero_list.c \
save_scene_parsing_format.c save_scene_parsing_fill_list_sphere.c \
save_scene_parsing_fill_list_plan.c save_scene_parsing_fill_list_light.c \
save_scene_parsing_fill_list_cylindre.c save_scene_load_scene_fh.c \
save_scene_load_scene_td.c save_scene_load_scene_sd.c \
save_scene_init_value_draw_title_background.c save_scene_fill_save_sphere.c \
save_scene_fill_save_plan.c save_scene_fill_save_light.c \
save_scene_fill_save_cylindre.c ft_init_value_objet_courant_color.c \
objet_courant_fill_value_current.c objet_courant_tools.c \
objet_courant_draw_ellipse_backgroung_sd.c multiobj_create_cubesphere.c \
multiobj_create_pyrasphere.c mouse_move_save_scene.c \
mouse_hook_shortcuts_filtres.c mouse_hook_shortcuts_divers.c \
mouse_hook_shortcuts_multiobj.c mouse_hook_shortcuts_multiobj_sd.c \
mouse_hook_newobj_tools.c mouse_hook_matrice_sd.c \
mouse_hook_matrice_save_color.c mouse_hook_matrice_save_select_color.c \
key_hook_chiffre_interface.c key_hook_lettres_interface.c \
interface_filtres_blur.c interface_filtres_blur_td.c

SRC_NAME_LIB_LETTER = aa.c bb.c cc.c \
dd.c ee.c ff.c gg.c hh.c ii.c jj.c kk.c ll.c mm.c nn.c oo.c pp.c qq.c rr.c \
ss.c tt.c uu.c vv.c ww.c xx.c yy.c zz.c ft_segment.c ft_arc.c \
awklm_string_put.c ft_ellipse.c zero.c one.c two.c three.c four.c five.c six.c \
seven.c eight.c nine.c dot.c minus.c colons.c slash.c settings.c full_box.c \
empty_box.c hashtag.c exclamation.c ft_full_ellipse.c ft_full_arc.c \
init_segment_a.c init_segment_b.c init_segment_e.c draw_high_letter.c \
ft_ellipse_select_part.c ft_arc_sd.c ft_init_value_settings.c \
ft_init_value_two.c

OBJ_NAME = $(SRC_NAME:.c=.o)

OBJ_SRC_INTERFACE = $(SRC_NAME_INTERFACE:.c=.o)

OBJ_SRC_LIB_LETTER = $(SRC_NAME_LIB_LETTER:.c=.o)

CPPFLAGS = -Iincludes

NAME = RT

CC = clang

CFLAGS = -Wall -Wextra -Werror

FDFFLAGS = -framework OpenGL -framework Appkit -lpthread -D_REENTRANT

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

SRC_INTERFACE = $(addprefix $(PATH_INTERFACE)/,$(SRC_NAME_INTERFACE))

SRC_LIB_LETTER = $(addprefix $(PATH_LIB_LETTER)/,$(SRC_NAME_LIB_LETTER))

OBJ = $(addprefix $(SRC_PATH)/,$(OBJ_NAME))

OBJ_INTERFACE = $(addprefix $(PATH_INTERFACE)/,$(OBJ_SRC_INTERFACE))

OBJ_LIB_LETTER = $(addprefix $(PATH_LIB_LETTER)/,$(OBJ_SRC_LIB_LETTER))

all: $(NAME)

$(NAME): $(OBJ) $(OBJ_INTERFACE) $(OBJ_LIB_LETTER)
	@cd libft ; make re ; make clean ; cd ..
	@cd mlx ; make re ; cd ..
	$(CC) $(CCFLAGS) $(FDFFLAGS) $(CPPFLAGS) libft/libft.a mlx/libmlx.a $^ -o $@

clean:
	cd $(SRC_PATH) ; rm -rf $(OBJ_NAME) ; cd -
	cd $(PATH_INTERFACE) ; rm -rf $(OBJ_SRC_INTERFACE) ; cd -
	cd $(PATH_LIB_LETTER) ; rm -rf $(OBJ_SRC_LIB_LETTER) ; cd -

fclean: clean
	rm -rf libft/libft.a
	rm -rf mlx/libmlx.a
	rm -rf $(NAME)

re: fclean all

.PHONY: all, clean, fclean
