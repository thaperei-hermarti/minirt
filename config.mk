NAME = miniRT
NAME_BONUS = miniRT_bonus

INC_DIR = inc lib/libft/inc lib/minilibx-linux/
SRC_DIR = src
OBJ_DIR = obj
INC_BONUS_DIR = inc_bonus lib/libft/inc lib/minilibx-linux/
SRC_BONUS_DIR = src_bonus
OBJ_BONUS_DIR = obj_bonus

MATH_DIR = math
MINIRT_DIR = minirt
VALIDATION_DIR = validation
PARSER_DIR = parser

SRC = main.c \
	  free_memory.c \
	  $(MATH_DIR)/rt_math.c \
	  $(MATH_DIR)/rt_math2.c \
	  $(MATH_DIR)/rt_math3.c \
	  $(MATH_DIR)/rt_math4.c \
	  $(MATH_DIR)/rt_math5.c \
	  $(MATH_DIR)/rt_math_intersection.c \
	  $(MATH_DIR)/set_surface_quadrics.c \
	  $(MATH_DIR)/set_surface_params.c \
	  $(MATH_DIR)/surface.c \
	  $(MINIRT_DIR)/env.c \
	  $(MINIRT_DIR)/draw.c \
	  $(MINIRT_DIR)/window.c \
	  $(MINIRT_DIR)/img_buffer.c \
	  $(MINIRT_DIR)/key_hook.c \
	  $(MINIRT_DIR)/raytrace.c \
	  $(MINIRT_DIR)/raytrace_calc.c \
	  $(MINIRT_DIR)/raytrace_calc2.c \
	  $(MINIRT_DIR)/render.c \
	  $(VALIDATION_DIR)/input.c \
	  $(VALIDATION_DIR)/validate_objects.c \
	  $(VALIDATION_DIR)/validate_scene.c \
	  $(VALIDATION_DIR)/validate_properties.c \
	  $(VALIDATION_DIR)/validate_number_values.c \
	  $(PARSER_DIR)/parse_scene.c \
	  $(PARSER_DIR)/parse_objects.c \
	  $(PARSER_DIR)/parse_values.c \

SRC_BONUS = main_bonus.c \
	  free_memory_bonus.c \
	  $(MATH_DIR)/rt_math_bonus.c \
	  $(MATH_DIR)/rt_math2_bonus.c \
	  $(MATH_DIR)/rt_math3_bonus.c \
	  $(MATH_DIR)/rt_math4_bonus.c \
	  $(MATH_DIR)/rt_math5_bonus.c \
	  $(MATH_DIR)/rt_math_intersection_bonus.c \
	  $(MATH_DIR)/set_surface_quadrics_bonus.c \
	  $(MATH_DIR)/set_surface_quadrics2_bonus.c \
	  $(MATH_DIR)/set_surface_params_bonus.c \
	  $(MATH_DIR)/surface_bonus.c \
	  $(MATH_DIR)/surface_normal_bonus.c \
	  $(MINIRT_DIR)/env_bonus.c \
	  $(MINIRT_DIR)/draw_bonus.c \
	  $(MINIRT_DIR)/window_bonus.c \
	  $(MINIRT_DIR)/texture_bonus.c \
	  $(MINIRT_DIR)/img_buffer_bonus.c \
	  $(MINIRT_DIR)/key_hook_bonus.c \
	  $(MINIRT_DIR)/raytrace_bonus.c \
	  $(MINIRT_DIR)/raytrace_calc_bonus.c \
	  $(MINIRT_DIR)/raytrace_calc2_bonus.c \
	  $(MINIRT_DIR)/render_bonus.c \
	  $(MINIRT_DIR)/render_trace_bonus.c \
	  $(MINIRT_DIR)/render_uv_bonus.c \
	  $(MINIRT_DIR)/render_texture_bonus.c \
	  $(VALIDATION_DIR)/input_bonus.c \
	  $(VALIDATION_DIR)/validate_objects_bonus.c \
	  $(VALIDATION_DIR)/validate_objects2_bonus.c \
	  $(VALIDATION_DIR)/validate_scene_bonus.c \
	  $(VALIDATION_DIR)/validate_properties_bonus.c \
	  $(VALIDATION_DIR)/validate_properties2_bonus.c \
	  $(VALIDATION_DIR)/validate_optional_bonus.c \
	  $(VALIDATION_DIR)/validate_number_values_bonus.c \
	  $(VALIDATION_DIR)/validate_key_value_bonus.c \
	  $(PARSER_DIR)/parse_scene_bonus.c \
	  $(PARSER_DIR)/parse_objects2_bonus.c \
	  $(PARSER_DIR)/parse_objects_bonus.c \
	  $(PARSER_DIR)/parse_values_bonus.c \

