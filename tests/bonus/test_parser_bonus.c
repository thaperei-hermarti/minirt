/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_parser_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 10:00:00 by thaperei          #+#    #+#             */
/*   Updated: 2026/05/11 18:57:08 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>
#include <setjmp.h>
#include <cmocka.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#include "parser_bonus.h"
#include "objects_bonus.h"
#include "scene_bonus.h"
#include "libft.h"

/* ========================================================= */
/* HELPER FUNCTIONS */
/* ========================================================= */

static t_scene	*make_scene(void)
{
	t_scene	*scene;

	scene = (t_scene *)calloc(1, sizeof(t_scene));
	scene->light = (t_light *)calloc(1, sizeof(t_light));
	scene->surfaces = (t_surface *)calloc(1000, sizeof(t_surface));
	scene->idx_obj = 0;
	scene->num_objs = 0;
	return (scene);
}

static void	free_scene(t_scene *scene)
{
	if (scene)
	{
		free(scene->light);
		free(scene->surfaces);
		free(scene);
	}
}

/* Helper to create token array */

static char	**make_arr(const char *str1, const char *str2, const char *str3,
		const char *str4)
{
	char	**arr;

	arr = (char **)malloc(sizeof(char *) * 5);
	arr[0] = (char *)str1;
	arr[1] = (char *)str2;
	arr[2] = (char *)str3;
	arr[3] = (char *)str4;
	arr[4] = NULL;
	return (arr);
}

static char	**make_arr_5(const char *str1, const char *str2,
		const char *str3, const char *str4, const char *str5)
{
	char	**arr;

	arr = (char **)malloc(sizeof(char *) * 6);
	arr[0] = (char *)str1;
	arr[1] = (char *)str2;
	arr[2] = (char *)str3;
	arr[3] = (char *)str4;
	arr[4] = (char *)str5;
	arr[5] = NULL;
	return (arr);
}

static char	**make_arr_6(const char *str1, const char *str2,
		const char *str3, const char *str4, const char *str5,
		const char *str6)
{
	char	**arr;

	arr = (char **)malloc(sizeof(char *) * 7);
	arr[0] = (char *)str1;
	arr[1] = (char *)str2;
	arr[2] = (char *)str3;
	arr[3] = (char *)str4;
	arr[4] = (char *)str5;
	arr[5] = (char *)str6;
	arr[6] = NULL;
	return (arr);
}

static char	**make_arr_7(const char *str1, const char *str2,
		const char *str3, const char *str4, const char *str5,
		const char *str6, const char *str7)
{
	char	**arr;

	arr = (char **)malloc(sizeof(char *) * 8);
	arr[0] = (char *)str1;
	arr[1] = (char *)str2;
	arr[2] = (char *)str3;
	arr[3] = (char *)str4;
	arr[4] = (char *)str5;
	arr[5] = (char *)str6;
	arr[6] = (char *)str7;
	arr[7] = NULL;
	return (arr);
}

static char	**make_arr_8(const char *str1, const char *str2,
		const char *str3, const char *str4, const char *str5,
		const char *str6, const char *str7, const char *str8)
{
	char	**arr;

	arr = (char **)malloc(sizeof(char *) * 9);
	arr[0] = (char *)str1;
	arr[1] = (char *)str2;
	arr[2] = (char *)str3;
	arr[3] = (char *)str4;
	arr[4] = (char *)str5;
	arr[5] = (char *)str6;
	arr[6] = (char *)str7;
	arr[7] = (char *)str8;
	arr[8] = NULL;
	return (arr);
}

/* ========================================================= */
/* PARSE_CONE TESTS (using parse_cone function) */
/* ========================================================= */

void	test_parse_cone_basic(void **state)
{
	(void)state;
	t_scene	*scene = make_scene();
	char	**arr = make_arr_6("co", "0,0,0", "0.0,1.0,0.0", "30.0",
		"4.0", "255,255,255");

	parse_cone(arr, scene);
	assert_int_equal(scene->surfaces[0].type, CONE);
	assert_true(fabs(scene->surfaces[0].obj.coordinate.x) < 0.0001);
	assert_true(fabs(scene->surfaces[0].obj.coordinate.y) < 0.0001);
	assert_true(fabs(scene->surfaces[0].obj.coordinate.z) < 0.0001);
	assert_int_equal(scene->surfaces[0].obj.material.color.x, 255);
	assert_int_equal(scene->surfaces[0].obj.material.color.y, 255);
	assert_int_equal(scene->surfaces[0].obj.material.color.z, 255);
	assert_int_equal(scene->idx_obj, 1);

	free(arr);
	free_scene(scene);
}

void	test_parse_cone_offset_position(void **state)
{
	(void)state;
	t_scene	*scene = make_scene();
	char	**arr = make_arr_6("co", "10.5,20.3,-15.7", "0.0,1.0,0.0",
		"20.0", "5.0", "128,64,32");

	parse_cone(arr, scene);
	assert_int_equal(scene->surfaces[0].type, CONE);
	assert_true(fabs(scene->surfaces[0].obj.coordinate.x - 10.5) < 0.0001);
	assert_true(fabs(scene->surfaces[0].obj.coordinate.y - 20.3) < 0.0001);
	assert_true(fabs(scene->surfaces[0].obj.coordinate.z + 15.7) < 0.0001);
	assert_int_equal(scene->surfaces[0].obj.material.color.x, 128);
	assert_int_equal(scene->surfaces[0].obj.material.color.y, 64);
	assert_int_equal(scene->surfaces[0].obj.material.color.z, 32);

	free(arr);
	free_scene(scene);
}

void	test_parse_cone_angle_variations(void **state)
{
	(void)state;
	t_scene	*scene = make_scene();
	char	**arr = make_arr_6("co", "5,5,5", "0.0,1.0,0.0", "15.0",
		"2.0", "100,100,100");

	parse_cone(arr, scene);
	assert_int_equal(scene->surfaces[0].type, CONE);

	free(arr);
	free_scene(scene);
}

void	test_parse_cone_diameter_variations(void **state)
{
	(void)state;
	t_scene	*scene = make_scene();
	char	**arr1 = make_arr_6("co", "0,0,0", "0.0,1.0,0.0",
		"25.0", "3.0", "200,200,200");
	char	**arr2 = make_arr_6("co", "1,2,3", "0.0,1.0,0.0",
		"45.0", "6.0", "100,100,100");

	parse_cone(arr1, scene);
	parse_cone(arr2, scene);
	assert_int_equal(scene->surfaces[0].type, CONE);
	assert_int_equal(scene->surfaces[1].type, CONE);
	assert_int_equal(scene->surfaces[0].is_bounded, 1);
	assert_int_equal(scene->surfaces[1].is_bounded, 1);
	assert_int_equal(scene->idx_obj, 2);

	free(arr1);
	free(arr2);
	free_scene(scene);
}

void	test_parse_cone_red_color(void **state)
{
	(void)state;
	t_scene	*scene = make_scene();
	char	**arr = make_arr_6("co", "0,0,0", "0.0,1.0,0.0", "20.0",
		"4.0", "255,0,0");

	parse_cone(arr, scene);
	assert_int_equal(scene->surfaces[0].obj.material.color.x, 255);
	assert_int_equal(scene->surfaces[0].obj.material.color.y, 0);
	assert_int_equal(scene->surfaces[0].obj.material.color.z, 0);

	free(arr);
	free_scene(scene);
}

void	test_parse_cone_black_color(void **state)
{
	(void)state;
	t_scene	*scene = make_scene();
	char	**arr = make_arr_6("co", "0,0,0", "0.0,1.0,0.0", "20.0",
		"4.0", "0,0,0");

	parse_cone(arr, scene);
	assert_int_equal(scene->surfaces[0].obj.material.color.x, 0);
	assert_int_equal(scene->surfaces[0].obj.material.color.y, 0);
	assert_int_equal(scene->surfaces[0].obj.material.color.z, 0);

	free(arr);
	free_scene(scene);
}

void	test_parse_cone_negative_coordinates(void **state)
{
	(void)state;
	t_scene	*scene = make_scene();
	char	**arr = make_arr_6("co", "-50,-100,-150", "0.0,1.0,0.0",
		"20.0", "4.0", "75,75,75");

	parse_cone(arr, scene);
	assert_true(fabs(scene->surfaces[0].obj.coordinate.x + 50.0) < 0.0001);
	assert_true(fabs(scene->surfaces[0].obj.coordinate.y + 100.0) < 0.0001);
	assert_true(fabs(scene->surfaces[0].obj.coordinate.z + 150.0) < 0.0001);

	free(arr);
	free_scene(scene);
}

void	test_parse_cone_decimal_coordinates(void **state)
{
	(void)state;
	t_scene	*scene = make_scene();
	char	**arr = make_arr_6("co", "1.5,2.7,3.9", "0.0,1.0,0.0",
		"10.0", "2.0", "150,150,150");

	parse_cone(arr, scene);
	assert_true(fabs(scene->surfaces[0].obj.coordinate.x - 1.5) < 0.0001);
	assert_true(fabs(scene->surfaces[0].obj.coordinate.y - 2.7) < 0.0001);
	assert_true(fabs(scene->surfaces[0].obj.coordinate.z - 3.9) < 0.0001);

	free(arr);
	free_scene(scene);
}

void	test_parse_cone_bounded(void **state)
{
	(void)state;
	t_scene	*scene = make_scene();
	char	**arr = make_arr_6("co", "0,0,0", "0.0,1.0,0.0", "30.0",
		"4.0", "255,255,255");

	parse_cone(arr, scene);
	/* Cones are bounded */
	assert_int_equal(scene->surfaces[0].is_bounded, 1);

	free(arr);
	free_scene(scene);
}

void	test_parse_cone_unbounded(void **state)
{
	(void)state;
	t_scene	*scene = make_scene();
	char	**arr = make_arr_6("co", "0,0,0", "0.0,1.0,0.0", "30.0",
		"4.0", "255,255,255");

	parse_cone(arr, scene);
	assert_int_equal(scene->surfaces[0].is_bounded, 1);

	free(arr);
	free_scene(scene);
}

void	test_parse_cone_multiple_cones(void **state)
{
	(void)state;
	t_scene	*scene = make_scene();
	char	**arr1 = make_arr_6("co", "0,0,0", "0.0,1.0,0.0", "30.0",
		"4.0", "255,0,0");
	char	**arr2 = make_arr_6("co", "10,10,10", "0.0,1.0,0.0", "45.0",
		"6.0", "0,255,0");

	parse_cone(arr1, scene);
	parse_cone(arr2, scene);

	assert_int_equal(scene->surfaces[0].type, CONE);
	assert_int_equal(scene->surfaces[1].type, CONE);
	assert_int_equal(scene->surfaces[0].obj.material.color.x, 255);
	assert_int_equal(scene->surfaces[1].obj.material.color.y, 255);
	assert_int_equal(scene->idx_obj, 2);

	free(arr1);
	free(arr2);
	free_scene(scene);
}

void	test_parse_cone_with_spec_property(void **state)
{
	(void)state;
	t_scene	*scene = make_scene();
	char	**arr = make_arr_7("co", "0,0,0", "0.0,1.0,0.0", "30.0",
		"4.0", "255,0,0", "spec=0.5");

	parse_cone(arr, scene);
	assert_int_equal(scene->surfaces[0].type, CONE);
	assert_double_equal(scene->surfaces[0].obj.reflectivity, 0.5, 0.0001);

	free(arr);
	free_scene(scene);
}

void	test_parse_cone_with_refl_property(void **state)
{
	(void)state;
	t_scene	*scene = make_scene();
	char	**arr = make_arr_7("co", "0,0,0", "0.0,1.0,0.0", "30.0",
		"4.0", "255,0,0", "refl=0.8");

	parse_cone(arr, scene);
	assert_int_equal(scene->surfaces[0].type, CONE);
	assert_double_equal(scene->surfaces[0].obj.reflectivity, 0.8, 0.0001);

	free(arr);
	free_scene(scene);
}

void	test_parse_cone_with_check_property(void **state)
{
	(void)state;
	t_scene	*scene = make_scene();
	char	**arr = make_arr_7("co", "0,0,0", "0.0,1.0,0.0", "30.0",
		"4.0", "255,0,0", "check");

	parse_cone(arr, scene);
	assert_int_equal(scene->surfaces[0].type, CONE);
	assert_int_equal(scene->surfaces[0].is_checked, 1);

	free(arr);
	free_scene(scene);
}

/* ========================================================= */
/* PARSE_HYPERBOLOID TESTS (using parse_hyperboloid function) */
/* ========================================================= */

void	test_parse_hyperboloid_basic(void **state)
{
	(void)state;
	t_scene	*scene = make_scene();
	char	**arr = make_arr_8("hy", "0,0,0", "0.0,1.0,0.0", "1.0",
		"1.0", "1.0", "4.0", "255,255,255");

	parse_hyperboloid(arr, scene);
	assert_int_equal(scene->surfaces[0].type, HYPERBOLOID);
	assert_true(fabs(scene->surfaces[0].obj.coordinate.x) < 0.0001);
	assert_true(fabs(scene->surfaces[0].obj.coordinate.y) < 0.0001);
	assert_true(fabs(scene->surfaces[0].obj.coordinate.z) < 0.0001);
	assert_true(fabs(scene->surfaces[0].obj.orientation.y - 1.0) < 0.0001);
	assert_int_equal(scene->idx_obj, 1);

	free(arr);
	free_scene(scene);
}

void	test_parse_hyperboloid_offset_position(void **state)
{
	(void)state;
	t_scene	*scene = make_scene();
	char	**arr = make_arr_8("hy", "5.5,10.3,-8.7", "1.0,0.0,0.0",
		"1.5", "2.0", "0.8", "3.0", "255,255,255");

	parse_hyperboloid(arr, scene);
	assert_int_equal(scene->surfaces[0].type, HYPERBOLOID);
	assert_true(fabs(scene->surfaces[0].obj.coordinate.x - 5.5) < 0.0001);
	assert_true(fabs(scene->surfaces[0].obj.coordinate.y - 10.3) < 0.0001);
	assert_true(fabs(scene->surfaces[0].obj.coordinate.z + 8.7) < 0.0001);
	assert_true(fabs(scene->surfaces[0].obj.orientation.x - 1.0) < 0.0001);

	free(arr);
	free_scene(scene);
}

void	test_parse_hyperboloid_different_orientations(void **state)
{
	(void)state;
	t_scene	*scene = make_scene();
	char	**arr = make_arr_8("hy", "0,0,0", "0.0,0.0,1.0", "1.0",
		"1.0", "1.0", "4.0", "255,255,255");

	parse_hyperboloid(arr, scene);
	assert_true(fabs(scene->surfaces[0].obj.orientation.z - 1.0) < 0.0001);

	free(arr);
	free_scene(scene);
}

void	test_parse_hyperboloid_red_color(void **state)
{
	(void)state;
	t_scene	*scene = make_scene();
	char	**arr = make_arr_8("hy", "0,0,0", "0.0,1.0,0.0", "1.0",
		"1.0", "1.0", "4.0", "255,0,0");

	parse_hyperboloid(arr, scene);
	/* Color is the 8th parameter in parse_hyperboloid */
	assert_int_equal(scene->surfaces[0].type, HYPERBOLOID);

	free(arr);
	free_scene(scene);
}

void	test_parse_hyperboloid_negative_coordinates(void **state)
{
	(void)state;
	t_scene	*scene = make_scene();
	char	**arr = make_arr_8("hy", "-25,-50,-75", "0.0,1.0,0.0",
		"1.0", "1.0", "1.0", "4.0", "255,255,255");

	parse_hyperboloid(arr, scene);
	assert_true(fabs(scene->surfaces[0].obj.coordinate.x + 25.0) < 0.0001);
	assert_true(fabs(scene->surfaces[0].obj.coordinate.y + 50.0) < 0.0001);
	assert_true(fabs(scene->surfaces[0].obj.coordinate.z + 75.0) < 0.0001);

	free(arr);
	free_scene(scene);
}

void	test_parse_hyperboloid_diagonal_orientation(void **state)
{
	(void)state;
	t_scene	*scene = make_scene();
	char	**arr = make_arr_8("hy", "0,0,0", "-1.0,-1.0,-1.0", "1.0",
		"1.0", "1.0", "4.0", "255,255,255");

	parse_hyperboloid(arr, scene);
	assert_int_equal(scene->surfaces[0].type, HYPERBOLOID);

	free(arr);
	free_scene(scene);
}

void	test_parse_hyperboloid_bounded(void **state)
{
	(void)state;
	t_scene	*scene = make_scene();
	char	**arr = make_arr_8("hy", "0,0,0", "0.0,1.0,0.0", "1.0",
		"1.0", "1.0", "4.0", "255,255,255");

	parse_hyperboloid(arr, scene);
	/* Hyperboloids are bounded */
	assert_int_equal(scene->surfaces[0].is_bounded, 1);

	free(arr);
	free_scene(scene);
}

void	test_parse_hyperboloid_unbounded(void **state)
{
	(void)state;
	t_scene	*scene = make_scene();
	char	**arr = make_arr_8("hy", "0,0,0", "0.0,1.0,0.0", "1.0",
		"1.0", "1.0", "4.0", "255,255,255");

	parse_hyperboloid(arr, scene);
	assert_int_equal(scene->surfaces[0].is_bounded, 1);

	free(arr);
	free_scene(scene);
}

void	test_parse_hyperboloid_multiple_hyperboloids(void **state)
{
	(void)state;
	t_scene	*scene = make_scene();
	char	**arr1 = make_arr_8("hy", "0,0,0", "0.0,1.0,0.0", "1.0",
		"1.0", "1.0", "4.0", "255,255,255");
	char	**arr2 = make_arr_8("hy", "20,20,20", "1.0,0.0,0.0", "2.0",
		"1.5", "0.8", "6.0", "200,200,200");

	parse_hyperboloid(arr1, scene);
	parse_hyperboloid(arr2, scene);

	assert_int_equal(scene->surfaces[0].type, HYPERBOLOID);
	assert_int_equal(scene->surfaces[1].type, HYPERBOLOID);
	assert_int_equal(scene->idx_obj, 2);

	free(arr1);
	free(arr2);
	free_scene(scene);
}

/* ========================================================= */
/* PARSE_PARABOLOID TESTS (using parse_paraboloid function) */
/* ========================================================= */

void	test_parse_paraboloid_basic(void **state)
{
	(void)state;
	t_scene	*scene = make_scene();
	char	**arr = make_arr_6("pa", "0,0,0", "0.0,1.0,0.0", "0.5",
		"4.0", "255,255,255");

	parse_paraboloid(arr, scene);
	assert_int_equal(scene->surfaces[0].type, PARABOLOID);
	assert_true(fabs(scene->surfaces[0].obj.coordinate.x) < 0.0001);
	assert_true(fabs(scene->surfaces[0].obj.coordinate.y) < 0.0001);
	assert_true(fabs(scene->surfaces[0].obj.coordinate.z) < 0.0001);
	assert_true(fabs(scene->surfaces[0].obj.orientation.y - 1.0) < 0.0001);
	assert_int_equal(scene->surfaces[0].obj.material.color.x, 255);
	assert_int_equal(scene->surfaces[0].obj.material.color.y, 255);
	assert_int_equal(scene->surfaces[0].obj.material.color.z, 255);
	assert_int_equal(scene->idx_obj, 1);

	free(arr);
	free_scene(scene);
}

void	test_parse_paraboloid_offset_position(void **state)
{
	(void)state;
	t_scene	*scene = make_scene();
	char	**arr = make_arr_6("pa", "3.2,7.1,-9.4", "0.0,1.0,0.0",
		"0.5", "4.0", "50,100,200");

	parse_paraboloid(arr, scene);
	assert_int_equal(scene->surfaces[0].type, PARABOLOID);
	assert_true(fabs(scene->surfaces[0].obj.coordinate.x - 3.2) < 0.0001);
	assert_true(fabs(scene->surfaces[0].obj.coordinate.y - 7.1) < 0.0001);
	assert_true(fabs(scene->surfaces[0].obj.coordinate.z + 9.4) < 0.0001);
	assert_int_equal(scene->surfaces[0].obj.material.color.x, 50);
	assert_int_equal(scene->surfaces[0].obj.material.color.y, 100);
	assert_int_equal(scene->surfaces[0].obj.material.color.z, 200);

	free(arr);
	free_scene(scene);
}

void	test_parse_paraboloid_different_orientations(void **state)
{
	(void)state;
	t_scene	*scene = make_scene();
	char	**arr = make_arr_6("pa", "0,0,0", "1.0,0.0,0.0", "0.5",
		"4.0", "128,64,32");

	parse_paraboloid(arr, scene);
	assert_true(fabs(scene->surfaces[0].obj.orientation.x - 1.0) < 0.0001);
	assert_true(fabs(scene->surfaces[0].obj.orientation.y) < 0.0001);
	assert_true(fabs(scene->surfaces[0].obj.orientation.z) < 0.0001);

	free(arr);
	free_scene(scene);
}

void	test_parse_paraboloid_green_color(void **state)
{
	(void)state;
	t_scene	*scene = make_scene();
	char	**arr = make_arr_6("pa", "0,0,0", "0.0,1.0,0.0", "0.5",
		"4.0", "0,255,0");

	parse_paraboloid(arr, scene);
	assert_int_equal(scene->surfaces[0].obj.material.color.x, 0);
	assert_int_equal(scene->surfaces[0].obj.material.color.y, 255);
	assert_int_equal(scene->surfaces[0].obj.material.color.z, 0);

	free(arr);
	free_scene(scene);
}

void	test_parse_paraboloid_negative_coordinates(void **state)
{
	(void)state;
	t_scene	*scene = make_scene();
	char	**arr = make_arr_6("pa", "-100,-200,-300", "0.0,1.0,0.0",
		"0.5", "4.0", "200,200,200");

	parse_paraboloid(arr, scene);
	assert_true(fabs(scene->surfaces[0].obj.coordinate.x + 100.0) < 0.0001);
	assert_true(fabs(scene->surfaces[0].obj.coordinate.y + 200.0) < 0.0001);
	assert_true(fabs(scene->surfaces[0].obj.coordinate.z + 300.0) < 0.0001);

	free(arr);
	free_scene(scene);
}

void	test_parse_paraboloid_z_axis_orientation(void **state)
{
	(void)state;
	t_scene	*scene = make_scene();
	char	**arr = make_arr_6("pa", "0,0,0", "0.0,0.0,1.0", "0.5",
		"4.0", "100,150,200");

	parse_paraboloid(arr, scene);
	assert_true(fabs(scene->surfaces[0].obj.orientation.z - 1.0) < 0.0001);
	assert_true(fabs(scene->surfaces[0].obj.orientation.x) < 0.0001);
	assert_true(fabs(scene->surfaces[0].obj.orientation.y) < 0.0001);

	free(arr);
	free_scene(scene);
}

void	test_parse_paraboloid_bounded(void **state)
{
	(void)state;
	t_scene	*scene = make_scene();
	char	**arr = make_arr_6("pa", "0,0,0", "0.0,1.0,0.0", "0.5",
		"4.0", "255,255,255");

	parse_paraboloid(arr, scene);
	/* Paraboloids are bounded */
	assert_int_equal(scene->surfaces[0].is_bounded, 1);

	free(arr);
	free_scene(scene);
}

void	test_parse_paraboloid_unbounded(void **state)
{
	(void)state;
	t_scene	*scene = make_scene();
	char	**arr = make_arr_6("pa", "0,0,0", "0.0,1.0,0.0", "0.5",
		"4.0", "255,255,255");

	parse_paraboloid(arr, scene);
	assert_int_equal(scene->surfaces[0].is_bounded, 1);

	free(arr);
	free_scene(scene);
}

void	test_parse_paraboloid_multiple_paraboloids(void **state)
{
	(void)state;
	t_scene	*scene = make_scene();
	char	**arr1 = make_arr_6("pa", "0,0,0", "0.0,1.0,0.0", "0.5",
		"4.0", "255,0,0");
	char	**arr2 = make_arr_6("pa", "15,15,15", "0.0,0.0,1.0", "0.5",
		"4.0", "0,0,255");

	parse_paraboloid(arr1, scene);
	parse_paraboloid(arr2, scene);

	assert_int_equal(scene->surfaces[0].type, PARABOLOID);
	assert_int_equal(scene->surfaces[1].type, PARABOLOID);
	assert_int_equal(scene->surfaces[0].obj.material.color.x, 255);
	assert_int_equal(scene->surfaces[1].obj.material.color.z, 255);
	assert_int_equal(scene->idx_obj, 2);

	free(arr1);
	free(arr2);
	free_scene(scene);
}

void	test_parse_paraboloid_blue_color(void **state)
{
	(void)state;
	t_scene	*scene = make_scene();
	char	**arr = make_arr_6("pa", "0,0,0", "0.0,1.0,0.0", "0.5",
		"4.0", "0,0,255");

	parse_paraboloid(arr, scene);
	assert_int_equal(scene->surfaces[0].obj.material.color.x, 0);
	assert_int_equal(scene->surfaces[0].obj.material.color.y, 0);
	assert_int_equal(scene->surfaces[0].obj.material.color.z, 255);

	free(arr);
	free_scene(scene);
}

/* ========================================================= */
/* MIXED BONUS OBJECTS TESTS */
/* ========================================================= */

void	test_parse_mixed_bonus_objects(void **state)
{
	(void)state;
	t_scene	*scene = make_scene();
	char	**arr_cone = make_arr_6("co", "0,0,0", "0.0,1.0,0.0",
		"30.0", "4.0", "255,0,0");
	char	**arr_hy = make_arr_8("hy", "10,10,10", "0.0,1.0,0.0", "1.0",
		"1.0", "1.0", "4.0", "255,255,255");
	char	**arr_pa = make_arr_6("pa", "20,20,20", "0.0,1.0,0.0", "0.5",
		"4.0", "0,0,255");

	parse_cone(arr_cone, scene);
	parse_hyperboloid(arr_hy, scene);
	parse_paraboloid(arr_pa, scene);

	assert_int_equal(scene->surfaces[0].type, CONE);
	assert_int_equal(scene->surfaces[1].type, HYPERBOLOID);
	assert_int_equal(scene->surfaces[2].type, PARABOLOID);
	assert_int_equal(scene->idx_obj, 3);
	assert_int_equal(scene->surfaces[0].obj.material.color.x, 255);
	assert_int_equal(scene->surfaces[2].obj.material.color.z, 255);

	free(arr_cone);
	free(arr_hy);
	free(arr_pa);
	free_scene(scene);
}

void	test_parse_bonus_objects_color_variation(void **state)
{
	(void)state;
	t_scene	*scene = make_scene();
	char	**arr1 = make_arr_6("co", "0,0,0", "0.0,1.0,0.0", "25.0",
		"4.0", "100,100,100");
	char	**arr2 = make_arr_8("hy", "5,5,5", "0.0,1.0,0.0", "1.0",
		"1.0", "1.0", "4.0", "255,255,255");
	char	**arr3 = make_arr_6("pa", "10,10,10", "0.0,1.0,0.0", "0.5",
		"4.0", "200,200,200");

	parse_cone(arr1, scene);
	parse_hyperboloid(arr2, scene);
	parse_paraboloid(arr3, scene);

	assert_int_equal(scene->surfaces[0].obj.material.color.x, 100);
	assert_int_equal(scene->surfaces[2].obj.material.color.z, 200);

	free(arr1);
	free(arr2);
	free(arr3);
	free_scene(scene);
}

/* ========================================================= */
/* OPTIONAL PROPERTIES TESTS (key=value format) */
/* ========================================================= */

void	test_parse_sphere_with_spec_property(void **state)
{
	(void)state;
	t_scene	*scene = make_scene();
	char	**arr = make_arr_5("sp", "0,0,0", "2.0", "255,0,0", "spec=0.5");

	parse_sphere(arr, scene);
	assert_int_equal(scene->surfaces[0].type, SPHERE);
	assert_double_equal(scene->surfaces[0].obj.material.specular.strenght,
		0.5, 0.0001);

	free(arr);
	free_scene(scene);
}

void	test_parse_sphere_with_refl_property(void **state)
{
	(void)state;
	t_scene	*scene = make_scene();
	char	**arr = make_arr_5("sp", "0,0,0", "2.0", "255,0,0", "refl=0.8");

	parse_sphere(arr, scene);
	assert_int_equal(scene->surfaces[0].type, SPHERE);
	assert_double_equal(scene->surfaces[0].obj.reflectivity, 0.8, 0.0001);

	free(arr);
	free_scene(scene);
}

void	test_parse_sphere_with_check_property(void **state)
{
	(void)state;
	t_scene	*scene = make_scene();
	char	**arr = make_arr_5("sp", "0,0,0", "2.0", "255,0,0", "check");

	parse_sphere(arr, scene);
	assert_int_equal(scene->surfaces[0].type, SPHERE);
	assert_int_equal(scene->surfaces[0].is_checked, 1);

	free(arr);
	free_scene(scene);
}

void	test_parse_plane_with_multiple_properties(void **state)
{
	(void)state;
	t_scene	*scene = make_scene();
	char	**arr = (char **)malloc(sizeof(char *) * 7);
	arr[0] = "pl";
	arr[1] = "0,0,0";
	arr[2] = "0.0,1.0,0.0";
	arr[3] = "200,200,200";
	arr[4] = "spec=0.3";
	arr[5] = "refl=0.6";
	arr[6] = NULL;

	parse_plane(arr, scene);
	assert_int_equal(scene->surfaces[0].type, PLANE);
	assert_double_equal(scene->surfaces[0].obj.material.specular.strenght,
		0.3, 0.0001);
	assert_double_equal(scene->surfaces[0].obj.reflectivity, 0.6, 0.0001);

	free(arr);
	free_scene(scene);
}

void	test_parse_cylinder_with_spec_refl_and_check(void **state)
{
	(void)state;
	t_scene	*scene = make_scene();
	char	**arr = (char **)malloc(sizeof(char *) * 8);
	arr[0] = "cy";
	arr[1] = "0,0,0";
	arr[2] = "0.0,1.0,0.0";
	arr[3] = "2.0";
	arr[4] = "4.0";
	arr[5] = "100,100,100";
	arr[6] = "spec=0.4";
	arr[7] = NULL;

	parse_cylinder(arr, scene);
	assert_int_equal(scene->surfaces[0].type, CYLINDER);
	assert_double_equal(scene->surfaces[0].obj.material.specular.strenght,
		0.4, 0.0001);

	free(arr);
	free_scene(scene);
}
