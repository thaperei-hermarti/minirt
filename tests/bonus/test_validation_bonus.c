/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_validation_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 13:40:48 by thaperei          #+#    #+#             */
/*   Updated: 2026/05/11 21:06:03 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "test_validation_bonus.h"
#include "validation_bonus.h"
#include "parser_bonus.h"
#include "scene_bonus.h"
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* =========================================================
   HELPERS
   ========================================================= */

static t_scene  *make_scene(void)
{
	return (calloc(1, sizeof(t_scene)));
}

static void free_scene(t_scene *scene)
{
	t_list  *node;
	t_list  *next;

	node = scene->objs;
	while (node)
	{
		next = node->next;
		free(node->content);
		free(node);
		node = next;
	}
	free(scene);
}

static void write_rt(const char *path, const char *content)
{
	FILE    *f;

	f = fopen(path, "w");
	fputs(content, f);
	fclose(f);
}

#define MANDATORY \
	"A 0.5 255,255,255\n" \
	"C 0,0,0 0.0,0.0,1.0 90\n" \
	"L 0,5,0 0.8 255,255,255\n"

/* =========================================================
   CONE unit tests (mandatory: coords, dir, angle, height, color)
   ========================================================= */

void	test_valid_cone_valid(void **state)
{
	(void)state;
	char *arr[] = {"co", "0,0,0", "0,1,0", "30.0", "4.0", "255,0,0", NULL};
	assert_int_equal(is_valid_cone(arr), 1);
}

void	test_valid_cone_invalid_coordinates(void **state)
{
	(void)state;
	char *arr[] = {"co", "abc,def,ghi", "0,1,0", "30.0", "4.0", "255,0,0", NULL};
	assert_int_equal(is_valid_cone(arr), 0);
}

void	test_valid_cone_invalid_angle(void **state)
{
	(void)state;
	char *arr[] = {"co", "0,0,0", "0,1,0", "abc", "4.0", "255,0,0", NULL};
	assert_int_equal(is_valid_cone(arr), 0);
}

void	test_valid_cone_invalid_color(void **state)
{
	(void)state;
	char *arr[] = {"co", "0,0,0", "0,1,0", "30.0", "4.0", "256,0,0", NULL};
	assert_int_equal(is_valid_cone(arr), 0);
}

void	test_valid_cone_negative_angle(void **state)
{
	(void)state;
	char *arr[] = {"co", "0,0,0", "0,1,0", "-30.0", "4.0", "255,0,0", NULL};
	assert_int_equal(is_valid_cone(arr), 0);
}

void	test_valid_cone_zero_angle(void **state)
{
	(void)state;
	char *arr[] = {"co", "0,0,0", "0,1,0", "0.0", "4.0", "255,0,0", NULL};
	assert_int_equal(is_valid_cone(arr), 0);
}

void	test_valid_cone_null_coordinates(void **state)
{
	(void)state;
	char *arr[] = {"co", NULL, "0,1,0", "30.0", "4.0", "255,0,0", NULL};
	assert_int_equal(is_valid_cone(arr), 0);
}

void	test_valid_cone_null_angle(void **state)
{
	(void)state;
	char *arr[] = {"co", "0,0,0", "0,1,0", NULL, "4.0", "255,0,0", NULL};
	assert_int_equal(is_valid_cone(arr), 0);
}

void	test_valid_cone_null_color(void **state)
{
	(void)state;
	char *arr[] = {"co", "0,0,0", "0,1,0", "30.0", "4.0", NULL, NULL};
	assert_int_equal(is_valid_cone(arr), 0);
}

/* =========================================================
   HYPERBOLOID unit tests (mandatory: coords, dir, a, b, c, height, color)
   ========================================================= */

void	test_valid_hyperboloid_valid(void **state)
{
	(void)state;
	char *arr[] = {"hy", "0,0,0", "0,1,0", "1.0", "1.0", "1.0", "4.0", "255,255,255", NULL};
	assert_int_equal(is_valid_hyperboloid(arr), 1);
}

void	test_valid_hyperboloid_invalid_coordinates(void **state)
{
	(void)state;
	char *arr[] = {"hy", "abc,def,ghi", "0,1,0", "1.0", "1.0", "1.0", "4.0", "255,255,255", NULL};
	assert_int_equal(is_valid_hyperboloid(arr), 0);
}

void	test_valid_hyperboloid_invalid_vector(void **state)
{
	(void)state;
	char *arr[] = {"hy", "0,0,0", "abc,def,ghi", "1.0", "1.0", "1.0", "4.0", "255,255,255", NULL};
	assert_int_equal(is_valid_hyperboloid(arr), 0);
}

void	test_valid_hyperboloid_invalid_color(void **state)
{
	(void)state;
	char *arr[] = {"hy", "0,0,0", "0,1,0", "1.0", "1.0", "1.0", "4.0", "256,255,255", NULL};
	assert_int_equal(is_valid_hyperboloid(arr), 0);
}

void	test_valid_hyperboloid_null_coordinates(void **state)
{
	(void)state;
	char *arr[] = {"hy", NULL, "0,1,0", "1.0", "1.0", "1.0", "4.0", "255,255,255", NULL};
	assert_int_equal(is_valid_hyperboloid(arr), 0);
}

void	test_valid_hyperboloid_null_vector(void **state)
{
	(void)state;
	char *arr[] = {"hy", "0,0,0", NULL, "1.0", "1.0", "1.0", "4.0", "255,255,255", NULL};
	assert_int_equal(is_valid_hyperboloid(arr), 0);
}

void	test_valid_hyperboloid_null_color(void **state)
{
	(void)state;
	char *arr[] = {"hy", "0,0,0", "0,1,0", "1.0", "1.0", "1.0", "4.0", NULL, NULL};
	assert_int_equal(is_valid_hyperboloid(arr), 0);
}

void	test_valid_hyperboloid_vector_out_of_range(void **state)
{
	(void)state;
	char *arr[] = {"hy", "0,0,0", "2,1,0", "1.0", "1.0", "1.0", "4.0", "255,255,255", NULL};
	assert_int_equal(is_valid_hyperboloid(arr), 0);
}

void	test_valid_hyperboloid_vector_wrong_count(void **state)
{
	(void)state;
	char *arr[] = {"hy", "0,0,0", "0,1", "1.0", "1.0", "1.0", "4.0", "255,255,255", NULL};
	assert_int_equal(is_valid_hyperboloid(arr), 0);
}

/* =========================================================
   PARABOLOID unit tests (mandatory: coords, dir, k, height, color)
   ========================================================= */

void	test_valid_paraboloid_valid(void **state)
{
	(void)state;
	char *arr[] = {"pa", "0,0,0", "0,1,0", "0.5", "4.0", "255,255,255", NULL};
	assert_int_equal(is_valid_paraboloid(arr), 1);
}

void	test_valid_paraboloid_invalid_coordinates(void **state)
{
	(void)state;
	char *arr[] = {"pa", "abc,def,ghi", "0,1,0", "0.5", "4.0", "255,255,255", NULL};
	assert_int_equal(is_valid_paraboloid(arr), 0);
}

void	test_valid_paraboloid_invalid_vector(void **state)
{
	(void)state;
	char *arr[] = {"pa", "0,0,0", "abc,def,ghi", "0.5", "4.0", "255,255,255", NULL};
	assert_int_equal(is_valid_paraboloid(arr), 0);
}

void	test_valid_paraboloid_invalid_color(void **state)
{
	(void)state;
	char *arr[] = {"pa", "0,0,0", "0,1,0", "0.5", "4.0", "256,255,255", NULL};
	assert_int_equal(is_valid_paraboloid(arr), 0);
}

void	test_valid_paraboloid_null_coordinates(void **state)
{
	(void)state;
	char *arr[] = {"pa", NULL, "0,1,0", "0.5", "4.0", "255,255,255", NULL};
	assert_int_equal(is_valid_paraboloid(arr), 0);
}

void	test_valid_paraboloid_null_vector(void **state)
{
	(void)state;
	char *arr[] = {"pa", "0,0,0", NULL, "0.5", "4.0", "255,255,255", NULL};
	assert_int_equal(is_valid_paraboloid(arr), 0);
}

void	test_valid_paraboloid_null_color(void **state)
{
	(void)state;
	char *arr[] = {"pa", "0,0,0", "0,1,0", "0.5", "4.0", NULL, NULL};
	assert_int_equal(is_valid_paraboloid(arr), 0);
}

void	test_valid_paraboloid_vector_out_of_range(void **state)
{
	(void)state;
	char *arr[] = {"pa", "0,0,0", "2,1,0", "0.5", "4.0", "255,255,255", NULL};
	assert_int_equal(is_valid_paraboloid(arr), 0);
}

void	test_valid_paraboloid_vector_wrong_count(void **state)
{
	(void)state;
	char *arr[] = {"pa", "0,0,0", "0,1", "0.5", "4.0", "255,255,255", NULL};
	assert_int_equal(is_valid_paraboloid(arr), 0);
}

/* =========================================================
   SPHERE - SPEC property tests (spec=0.0 < x <= 1.0)
   ========================================================= */

void	test_sphere_spec_valid_min(void **state)
{
	(void)state;
	char *arr[] = {"sp", "0,0,0", "2.0", "255,0,0", "spec=0.001", NULL};
	assert_int_equal(is_valid_sphere(arr), 1);
}

void	test_sphere_spec_valid_max(void **state)
{
	(void)state;
	char *arr[] = {"sp", "0,0,0", "2.0", "255,0,0", "spec=1.0", NULL};
	assert_int_equal(is_valid_sphere(arr), 1);
}

void	test_sphere_spec_valid_mid(void **state)
{
	(void)state;
	char *arr[] = {"sp", "0,0,0", "2.0", "255,0,0", "spec=0.5", NULL};
	assert_int_equal(is_valid_sphere(arr), 1);
}

void	test_sphere_spec_invalid_zero(void **state)
{
	(void)state;
	char *arr[] = {"sp", "0,0,0", "2.0", "255,0,0", "spec=0.0", NULL};
	assert_int_equal(is_valid_sphere(arr), 0);
}

void	test_sphere_spec_invalid_negative(void **state)
{
	(void)state;
	char *arr[] = {"sp", "0,0,0", "2.0", "255,0,0", "spec=-0.5", NULL};
	assert_int_equal(is_valid_sphere(arr), 0);
}

void	test_sphere_spec_invalid_over_one(void **state)
{
	(void)state;
	char *arr[] = {"sp", "0,0,0", "2.0", "255,0,0", "spec=1.5", NULL};
	assert_int_equal(is_valid_sphere(arr), 0);
}

void	test_sphere_spec_invalid_not_float(void **state)
{
	(void)state;
	char *arr[] = {"sp", "0,0,0", "2.0", "255,0,0", "spec=abc", NULL};
	assert_int_equal(is_valid_sphere(arr), 0);
}

/* =========================================================
   SPHERE - REFL property tests (refl=0.0 < x <= 1.0)
   ========================================================= */

void	test_sphere_refl_valid_min(void **state)
{
	(void)state;
	char *arr[] = {"sp", "0,0,0", "2.0", "255,0,0", "refl=0.001", NULL};
	assert_int_equal(is_valid_sphere(arr), 1);
}

void	test_sphere_refl_valid_max(void **state)
{
	(void)state;
	char *arr[] = {"sp", "0,0,0", "2.0", "255,0,0", "refl=1.0", NULL};
	assert_int_equal(is_valid_sphere(arr), 1);
}

void	test_sphere_refl_invalid_zero(void **state)
{
	(void)state;
	char *arr[] = {"sp", "0,0,0", "2.0", "255,0,0", "refl=0.0", NULL};
	assert_int_equal(is_valid_sphere(arr), 0);
}

void	test_sphere_refl_invalid_negative(void **state)
{
	(void)state;
	char *arr[] = {"sp", "0,0,0", "2.0", "255,0,0", "refl=-0.5", NULL};
	assert_int_equal(is_valid_sphere(arr), 0);
}

void	test_sphere_refl_invalid_over_one(void **state)
{
	(void)state;
	char *arr[] = {"sp", "0,0,0", "2.0", "255,0,0", "refl=1.5", NULL};
	assert_int_equal(is_valid_sphere(arr), 0);
}

void	test_sphere_refl_invalid_not_float(void **state)
{
	(void)state;
	char *arr[] = {"sp", "0,0,0", "2.0", "255,0,0", "refl=abc", NULL};
	assert_int_equal(is_valid_sphere(arr), 0);
}

/* =========================================================
   SPHERE - CHECK property tests (check flag, no value)
   ========================================================= */

void	test_sphere_check_valid_zero(void **state)
{
	(void)state;
	char *arr[] = {"sp", "0,0,0", "2.0", "255,0,0", "check", NULL};
	assert_int_equal(is_valid_sphere(arr), 1);
}

void	test_sphere_check_invalid_with_value(void **state)
{
	(void)state;
	char *arr[] = {"sp", "0,0,0", "2.0", "255,0,0", "check=0", NULL};
	assert_int_equal(is_valid_sphere(arr), 0);
}

/* =========================================================
   SPHERE - TEXTURE property tests (texture=/path/to/file)
   ========================================================= */

void	test_sphere_texture_valid(void **state)
{
	(void)state;
	write_rt("/tmp/test_texture.xpm", "P3\n1 1\n255\n255 0 0\n");
	char *arr[] = {"sp", "0,0,0", "2.0", "255,0,0", "texture=/tmp/test_texture.xpm", NULL};
	assert_int_equal(is_valid_sphere(arr), 1);
	unlink("/tmp/test_texture.xpm");
}

void	test_sphere_texture_invalid_path(void **state)
{
	(void)state;
	char *arr[] = {"sp", "0,0,0", "2.0", "255,0,0", "texture=/nonexistent/path.xpm", NULL};
	assert_int_equal(is_valid_sphere(arr), 0);
}

/* =========================================================
   SPHERE - Combined properties tests
   ========================================================= */

void	test_sphere_spec_and_refl_valid(void **state)
{
	(void)state;
	char *arr[] = {"sp", "0,0,0", "2.0", "255,0,0", "spec=0.5", "refl=0.3", NULL};
	assert_int_equal(is_valid_sphere(arr), 1);
}

void	test_sphere_check_and_spec_valid(void **state)
{
	(void)state;
	char *arr[] = {"sp", "0,0,0", "2.0", "255,0,0", "check", "spec=0.5", NULL};
	assert_int_equal(is_valid_sphere(arr), 1);
}

void	test_sphere_check_and_refl_valid(void **state)
{
	(void)state;
	char *arr[] = {"sp", "0,0,0", "2.0", "255,0,0", "check", "refl=0.5", NULL};
	assert_int_equal(is_valid_sphere(arr), 1);
}

void	test_sphere_all_properties_valid(void **state)
{
	(void)state;
	char *arr[] = {"sp", "0,0,0", "2.0", "255,0,0", "spec=0.5", "refl=0.3", "check", NULL};
	assert_int_equal(is_valid_sphere(arr), 1);
}

void	test_sphere_check_and_texture_exclusive_both_present(void **state)
{
	(void)state;
	write_rt("/tmp/test_texture2.xpm", "P3\n1 1\n255\n255 0 0\n");
	char *arr[] = {"sp", "0,0,0", "2.0", "255,0,0", "spec=0.5", "check", "texture=/tmp/test_texture2.xpm", NULL};
	assert_int_equal(is_valid_sphere(arr), 0);
	unlink("/tmp/test_texture2.xpm");
}

/* =========================================================
   PLANE - SPEC and REFL property tests
   ========================================================= */

void	test_plane_spec_valid(void **state)
{
	(void)state;
	char *arr[] = {"pl", "0,0,0", "0,1,0", "255,255,255", "spec=0.5", NULL};
	assert_int_equal(is_valid_plane(arr), 1);
}

void	test_plane_spec_invalid_zero(void **state)
{
	(void)state;
	char *arr[] = {"pl", "0,0,0", "0,1,0", "255,255,255", "spec=0.0", NULL};
	assert_int_equal(is_valid_plane(arr), 0);
}

void	test_plane_spec_invalid_over_one(void **state)
{
	(void)state;
	char *arr[] = {"pl", "0,0,0", "0,1,0", "255,255,255", "spec=1.5", NULL};
	assert_int_equal(is_valid_plane(arr), 0);
}

void	test_plane_refl_valid(void **state)
{
	(void)state;
	char *arr[] = {"pl", "0,0,0", "0,1,0", "255,255,255", "refl=0.3", NULL};
	assert_int_equal(is_valid_plane(arr), 1);
}

void	test_plane_refl_invalid_zero(void **state)
{
	(void)state;
	char *arr[] = {"pl", "0,0,0", "0,1,0", "255,255,255", "refl=0.0", NULL};
	assert_int_equal(is_valid_plane(arr), 0);
}

void	test_plane_refl_invalid_over_one(void **state)
{
	(void)state;
	char *arr[] = {"pl", "0,0,0", "0,1,0", "255,255,255", "refl=1.5", NULL};
	assert_int_equal(is_valid_plane(arr), 0);
}

void	test_plane_check_valid_zero(void **state)
{
	(void)state;
	char *arr[] = {"pl", "0,0,0", "0,1,0", "255,255,255", "check", NULL};
	assert_int_equal(is_valid_plane(arr), 1);
}

void	test_plane_texture_valid(void **state)
{
	(void)state;
	write_rt("/tmp/test_texture3.xpm", "P3\n1 1\n255\n255 0 0\n");
	char *arr[] = {"pl", "0,0,0", "0,1,0", "255,255,255", "texture=/tmp/test_texture3.xpm", NULL};
	assert_int_equal(is_valid_plane(arr), 1);
	unlink("/tmp/test_texture3.xpm");
}

void	test_plane_spec_refl_and_check(void **state)
{
	(void)state;
	char *arr[] = {"pl", "0,0,0", "0,1,0", "255,255,255", "spec=0.5", "refl=0.3", "check", NULL};
	assert_int_equal(is_valid_plane(arr), 1);
}

void	test_plane_check_and_texture_exclusive_both_present(void **state)
{
	(void)state;
	write_rt("/tmp/test_texture4.xpm", "P3\n1 1\n255\n255 0 0\n");
	char *arr[] = {"pl", "0,0,0", "0,1,0", "255,255,255", "check", "texture=/tmp/test_texture4.xpm", NULL};
	assert_int_equal(is_valid_plane(arr), 0);
	unlink("/tmp/test_texture4.xpm");
}

/* =========================================================
   CYLINDER - SPEC and REFL property tests
   ========================================================= */

void	test_cylinder_spec_valid(void **state)
{
	(void)state;
	char *arr[] = {"cy", "0,0,0", "0,1,0", "2.0", "4.0", "255,255,255", "spec=0.5", NULL};
	assert_int_equal(is_valid_cylinder(arr), 1);
}

void	test_cylinder_spec_invalid_zero(void **state)
{
	(void)state;
	char *arr[] = {"cy", "0,0,0", "0,1,0", "2.0", "4.0", "255,255,255", "spec=0.0", NULL};
	assert_int_equal(is_valid_cylinder(arr), 0);
}

void	test_cylinder_spec_invalid_over_one(void **state)
{
	(void)state;
	char *arr[] = {"cy", "0,0,0", "0,1,0", "2.0", "4.0", "255,255,255", "spec=1.5", NULL};
	assert_int_equal(is_valid_cylinder(arr), 0);
}

void	test_cylinder_refl_valid(void **state)
{
	(void)state;
	char *arr[] = {"cy", "0,0,0", "0,1,0", "2.0", "4.0", "255,255,255", "refl=0.3", NULL};
	assert_int_equal(is_valid_cylinder(arr), 1);
}

void	test_cylinder_refl_invalid_zero(void **state)
{
	(void)state;
	char *arr[] = {"cy", "0,0,0", "0,1,0", "2.0", "4.0", "255,255,255", "refl=0.0", NULL};
	assert_int_equal(is_valid_cylinder(arr), 0);
}

void	test_cylinder_refl_invalid_over_one(void **state)
{
	(void)state;
	char *arr[] = {"cy", "0,0,0", "0,1,0", "2.0", "4.0", "255,255,255", "refl=1.5", NULL};
	assert_int_equal(is_valid_cylinder(arr), 0);
}

void	test_cylinder_check_valid_zero(void **state)
{
	(void)state;
	char *arr[] = {"cy", "0,0,0", "0,1,0", "2.0", "4.0", "255,255,255", "check", NULL};
	assert_int_equal(is_valid_cylinder(arr), 1);
}

void	test_cylinder_texture_valid(void **state)
{
	(void)state;
	write_rt("/tmp/test_texture5.xpm", "P3\n1 1\n255\n255 0 0\n");
	char *arr[] = {"cy", "0,0,0", "0,1,0", "2.0", "4.0", "255,255,255", "texture=/tmp/test_texture5.xpm", NULL};
	assert_int_equal(is_valid_cylinder(arr), 1);
	unlink("/tmp/test_texture5.xpm");
}

void	test_cylinder_all_properties(void **state)
{
	(void)state;
	char *arr[] = {"cy", "0,0,0", "0,1,0", "2.0", "4.0", "255,255,255", "spec=0.5", "refl=0.3", "check", NULL};
	assert_int_equal(is_valid_cylinder(arr), 1);
}

void	test_cylinder_check_and_texture_exclusive_both_present(void **state)
{
	(void)state;
	write_rt("/tmp/test_texture6.xpm", "P3\n1 1\n255\n255 0 0\n");
	char *arr[] = {"cy", "0,0,0", "0,1,0", "2.0", "4.0", "255,255,255", "check", "texture=/tmp/test_texture6.xpm", NULL};
	assert_int_equal(is_valid_cylinder(arr), 0);
	unlink("/tmp/test_texture6.xpm");
}

/* =========================================================
   CONE - SPEC and REFL property tests
   ========================================================= */

void	test_cone_spec_valid(void **state)
{
	(void)state;
	char *arr[] = {"co", "0,0,0", "0,1,0", "30.0", "4.0", "255,0,0", "spec=0.5", NULL};
	assert_int_equal(is_valid_cone(arr), 1);
}

void	test_cone_spec_invalid_zero(void **state)
{
	(void)state;
	char *arr[] = {"co", "0,0,0", "0,1,0", "30.0", "4.0", "255,0,0", "spec=0.0", NULL};
	assert_int_equal(is_valid_cone(arr), 0);
}

void	test_cone_spec_invalid_negative(void **state)
{
	(void)state;
	char *arr[] = {"co", "0,0,0", "0,1,0", "30.0", "4.0", "255,0,0", "spec=-0.5", NULL};
	assert_int_equal(is_valid_cone(arr), 0);
}

void	test_cone_spec_invalid_over_one(void **state)
{
	(void)state;
	char *arr[] = {"co", "0,0,0", "0,1,0", "30.0", "4.0", "255,0,0", "spec=1.5", NULL};
	assert_int_equal(is_valid_cone(arr), 0);
}

void	test_cone_refl_valid(void **state)
{
	(void)state;
	char *arr[] = {"co", "0,0,0", "0,1,0", "30.0", "4.0", "255,0,0", "refl=0.3", NULL};
	assert_int_equal(is_valid_cone(arr), 1);
}

void	test_cone_refl_invalid_zero(void **state)
{
	(void)state;
	char *arr[] = {"co", "0,0,0", "0,1,0", "30.0", "4.0", "255,0,0", "refl=0.0", NULL};
	assert_int_equal(is_valid_cone(arr), 0);
}

void	test_cone_refl_invalid_over_one(void **state)
{
	(void)state;
	char *arr[] = {"co", "0,0,0", "0,1,0", "30.0", "4.0", "255,0,0", "refl=1.5", NULL};
	assert_int_equal(is_valid_cone(arr), 0);
}

void	test_cone_check_valid_zero(void **state)
{
	(void)state;
	char *arr[] = {"co", "0,0,0", "0,1,0", "30.0", "4.0", "255,0,0", "check", NULL};
	assert_int_equal(is_valid_cone(arr), 1);
}

void	test_cone_texture_valid(void **state)
{
	(void)state;
	write_rt("/tmp/test_texture7.xpm", "P3\n1 1\n255\n255 0 0\n");
	char *arr[] = {"co", "0,0,0", "0,1,0", "30.0", "4.0", "255,0,0", "texture=/tmp/test_texture7.xpm", NULL};
	assert_int_equal(is_valid_cone(arr), 1);
	unlink("/tmp/test_texture7.xpm");
}

void	test_cone_all_properties(void **state)
{
	(void)state;
	char *arr[] = {"co", "0,0,0", "0,1,0", "30.0", "4.0", "255,0,0", "spec=0.5", "refl=0.3", "check", NULL};
	assert_int_equal(is_valid_cone(arr), 1);
}

void	test_cone_check_and_texture_exclusive_both_present(void **state)
{
	(void)state;
	write_rt("/tmp/test_texture8.xpm", "P3\n1 1\n255\n255 0 0\n");
	char *arr[] = {"co", "0,0,0", "0,1,0", "30.0", "4.0", "255,0,0", "check", "texture=/tmp/test_texture8.xpm", NULL};
	assert_int_equal(is_valid_cone(arr), 0);
	unlink("/tmp/test_texture8.xpm");
}

/* =========================================================
   HYPERBOLOID - SPEC and REFL property tests
   ========================================================= */

void	test_hyperboloid_spec_valid(void **state)
{
	(void)state;
	char *arr[] = {"hy", "0,0,0", "0,1,0", "1.0", "1.0", "1.0", "4.0", "255,255,255", "spec=0.5", NULL};
	assert_int_equal(is_valid_hyperboloid(arr), 1);
}

void	test_hyperboloid_spec_invalid_zero(void **state)
{
	(void)state;
	char *arr[] = {"hy", "0,0,0", "0,1,0", "1.0", "1.0", "1.0", "4.0", "255,255,255", "spec=0.0", NULL};
	assert_int_equal(is_valid_hyperboloid(arr), 0);
}

void	test_hyperboloid_spec_invalid_over_one(void **state)
{
	(void)state;
	char *arr[] = {"hy", "0,0,0", "0,1,0", "1.0", "1.0", "1.0", "4.0", "255,255,255", "spec=1.5", NULL};
	assert_int_equal(is_valid_hyperboloid(arr), 0);
}

void	test_hyperboloid_refl_valid(void **state)
{
	(void)state;
	char *arr[] = {"hy", "0,0,0", "0,1,0", "1.0", "1.0", "1.0", "4.0", "255,255,255", "refl=0.3", NULL};
	assert_int_equal(is_valid_hyperboloid(arr), 1);
}

void	test_hyperboloid_refl_invalid_zero(void **state)
{
	(void)state;
	char *arr[] = {"hy", "0,0,0", "0,1,0", "1.0", "1.0", "1.0", "4.0", "255,255,255", "refl=0.0", NULL};
	assert_int_equal(is_valid_hyperboloid(arr), 0);
}

void	test_hyperboloid_refl_invalid_over_one(void **state)
{
	(void)state;
	char *arr[] = {"hy", "0,0,0", "0,1,0", "1.0", "1.0", "1.0", "4.0", "255,255,255", "refl=1.5", NULL};
	assert_int_equal(is_valid_hyperboloid(arr), 0);
}

void	test_hyperboloid_check_valid_zero(void **state)
{
	(void)state;
	char *arr[] = {"hy", "0,0,0", "0,1,0", "1.0", "1.0", "1.0", "4.0", "255,255,255", "check", NULL};
	assert_int_equal(is_valid_hyperboloid(arr), 1);
}

void	test_hyperboloid_texture_valid(void **state)
{
	(void)state;
	write_rt("/tmp/test_texture9.xpm", "P3\n1 1\n255\n255 0 0\n");
	char *arr[] = {"hy", "0,0,0", "0,1,0", "1.0", "1.0", "1.0", "4.0", "255,255,255", "texture=/tmp/test_texture9.xpm", NULL};
	assert_int_equal(is_valid_hyperboloid(arr), 1);
	unlink("/tmp/test_texture9.xpm");
}

void	test_hyperboloid_all_properties(void **state)
{
	(void)state;
	char *arr[] = {"hy", "0,0,0", "0,1,0", "1.0", "1.0", "1.0", "4.0", "255,255,255", "spec=0.5", "refl=0.3", "check", NULL};
	assert_int_equal(is_valid_hyperboloid(arr), 1);
}

void	test_hyperboloid_check_and_texture_exclusive_both_present(void **state)
{
	(void)state;
	write_rt("/tmp/test_texture10.xpm", "P3\n1 1\n255\n255 0 0\n");
	char *arr[] = {"hy", "0,0,0", "0,1,0", "1.0", "1.0", "1.0", "4.0", "255,255,255", "check", "texture=/tmp/test_texture10.xpm", NULL};
	assert_int_equal(is_valid_hyperboloid(arr), 0);
	unlink("/tmp/test_texture10.xpm");
}

/* =========================================================
   PARABOLOID - SPEC and REFL property tests
   ========================================================= */

void	test_paraboloid_spec_valid(void **state)
{
	(void)state;
	char *arr[] = {"pa", "0,0,0", "0,1,0", "0.5", "4.0", "255,255,255", "spec=0.5", NULL};
	assert_int_equal(is_valid_paraboloid(arr), 1);
}

void	test_paraboloid_spec_invalid_zero(void **state)
{
	(void)state;
	char *arr[] = {"pa", "0,0,0", "0,1,0", "0.5", "4.0", "255,255,255", "spec=0.0", NULL};
	assert_int_equal(is_valid_paraboloid(arr), 0);
}

void	test_paraboloid_spec_invalid_negative(void **state)
{
	(void)state;
	char *arr[] = {"pa", "0,0,0", "0,1,0", "0.5", "4.0", "255,255,255", "spec=-0.5", NULL};
	assert_int_equal(is_valid_paraboloid(arr), 0);
}

void	test_paraboloid_spec_invalid_over_one(void **state)
{
	(void)state;
	char *arr[] = {"pa", "0,0,0", "0,1,0", "0.5", "4.0", "255,255,255", "spec=1.5", NULL};
	assert_int_equal(is_valid_paraboloid(arr), 0);
}

void	test_paraboloid_refl_valid(void **state)
{
	(void)state;
	char *arr[] = {"pa", "0,0,0", "0,1,0", "0.5", "4.0", "255,255,255", "refl=0.3", NULL};
	assert_int_equal(is_valid_paraboloid(arr), 1);
}

void	test_paraboloid_refl_invalid_zero(void **state)
{
	(void)state;
	char *arr[] = {"pa", "0,0,0", "0,1,0", "0.5", "4.0", "255,255,255", "refl=0.0", NULL};
	assert_int_equal(is_valid_paraboloid(arr), 0);
}

void	test_paraboloid_refl_invalid_over_one(void **state)
{
	(void)state;
	char *arr[] = {"pa", "0,0,0", "0,1,0", "0.5", "4.0", "255,255,255", "refl=1.5", NULL};
	assert_int_equal(is_valid_paraboloid(arr), 0);
}

void	test_paraboloid_check_valid_zero(void **state)
{
	(void)state;
	char *arr[] = {"pa", "0,0,0", "0,1,0", "0.5", "4.0", "255,255,255", "check", NULL};
	assert_int_equal(is_valid_paraboloid(arr), 1);
}

void	test_paraboloid_texture_valid(void **state)
{
	(void)state;
	write_rt("/tmp/test_texture11.xpm", "P3\n1 1\n255\n255 0 0\n");
	char *arr[] = {"pa", "0,0,0", "0,1,0", "0.5", "4.0", "255,255,255", "texture=/tmp/test_texture11.xpm", NULL};
	assert_int_equal(is_valid_paraboloid(arr), 1);
	unlink("/tmp/test_texture11.xpm");
}

void	test_paraboloid_all_properties(void **state)
{
	(void)state;
	char *arr[] = {"pa", "0,0,0", "0,1,0", "0.5", "4.0", "255,255,255", "spec=0.5", "refl=0.3", "check", NULL};
	assert_int_equal(is_valid_paraboloid(arr), 1);
}

void	test_paraboloid_check_and_texture_exclusive_both_present(void **state)
{
	(void)state;
	write_rt("/tmp/test_texture12.xpm", "P3\n1 1\n255\n255 0 0\n");
	char *arr[] = {"pa", "0,0,0", "0,1,0", "0.5", "4.0", "255,255,255", "check", "texture=/tmp/test_texture12.xpm", NULL};
	assert_int_equal(is_valid_paraboloid(arr), 0);
	unlink("/tmp/test_texture12.xpm");
}

/* =========================================================
   Edge case tests - optional properties only
   ========================================================= */

void	test_sphere_only_check_no_other_optional(void **state)
{
	(void)state;
	char *arr[] = {"sp", "0,0,0", "2.0", "255,0,0", "check", NULL};
	assert_int_equal(is_valid_sphere(arr), 1);
}

void	test_sphere_only_spec_no_other_optional(void **state)
{
	(void)state;
	char *arr[] = {"sp", "0,0,0", "2.0", "255,0,0", "spec=0.5", NULL};
	assert_int_equal(is_valid_sphere(arr), 1);
}

void	test_plane_only_check_no_spec_refl(void **state)
{
	(void)state;
	char *arr[] = {"pl", "0,0,0", "0,1,0", "255,255,255", "check", NULL};
	assert_int_equal(is_valid_plane(arr), 1);
}

void	test_cylinder_only_texture_no_check_spec_refl(void **state)
{
	(void)state;
	write_rt("/tmp/test_texture13.xpm", "P3\n1 1\n255\n255 0 0\n");
	char *arr[] = {"cy", "0,0,0", "0,1,0", "2.0", "4.0", "255,255,255", "texture=/tmp/test_texture13.xpm", NULL};
	assert_int_equal(is_valid_cylinder(arr), 1);
	unlink("/tmp/test_texture13.xpm");
}

void	test_cone_no_optional_properties(void **state)
{
	(void)state;
	char *arr[] = {"co", "0,0,0", "0,1,0", "30.0", "4.0", "255,0,0", NULL};
	assert_int_equal(is_valid_cone(arr), 1);
}

void	test_hyperboloid_only_spec_refl_no_check_texture(void **state)
{
	(void)state;
	char *arr[] = {"hy", "0,0,0", "0,1,0", "1.0", "1.0", "1.0", "4.0", "255,255,255", "spec=0.5", "refl=0.3", "check", NULL};
	assert_int_equal(is_valid_hyperboloid(arr), 1);
}

void	test_paraboloid_all_optional_properties_valid(void **state)
{
	(void)state;
	char *arr[] = {"pa", "0,0,0", "0,1,0", "0.5", "4.0", "255,255,255", "spec=0.5", "refl=0.3", "check", NULL};
	assert_int_equal(is_valid_paraboloid(arr), 1);
}

/* =========================================================
   Boundary tests - min/max values for spec and refl
   ========================================================= */

void	test_sphere_spec_boundary_almost_zero(void **state)
{
	(void)state;
	char *arr[] = {"sp", "0,0,0", "2.0", "255,0,0", "spec=0.00001", NULL};
	assert_int_equal(is_valid_sphere(arr), 1);
}

void	test_sphere_spec_boundary_almost_one(void **state)
{
	(void)state;
	char *arr[] = {"sp", "0,0,0", "2.0", "255,0,0", "spec=0.99999", NULL};
	assert_int_equal(is_valid_sphere(arr), 1);
}

void	test_sphere_refl_boundary_almost_zero(void **state)
{
	(void)state;
	char *arr[] = {"sp", "0,0,0", "2.0", "255,0,0", "refl=0.00001", NULL};
	assert_int_equal(is_valid_sphere(arr), 1);
}

void	test_sphere_refl_boundary_almost_one(void **state)
{
	(void)state;
	char *arr[] = {"sp", "0,0,0", "2.0", "255,0,0", "refl=0.99999", NULL};
	assert_int_equal(is_valid_sphere(arr), 1);
}

void	test_plane_spec_boundary_one(void **state)
{
	(void)state;
	char *arr[] = {"pl", "0,0,0", "0,1,0", "255,255,255", "spec=1.0", NULL};
	assert_int_equal(is_valid_plane(arr), 1);
}

void	test_plane_refl_boundary_one(void **state)
{
	(void)state;
	char *arr[] = {"pl", "0,0,0", "0,1,0", "255,255,255", "refl=1.0", NULL};
	assert_int_equal(is_valid_plane(arr), 1);
}

/* =========================================================
   Negative tests - invalid spec/refl combinations
   ========================================================= */

void	test_sphere_spec_negative_with_valid_refl(void **state)
{
	(void)state;
	char *arr[] = {"sp", "0,0,0", "2.0", "255,0,0", "spec=-0.5", "refl=0.5", NULL};
	assert_int_equal(is_valid_sphere(arr), 0);
}

void	test_plane_valid_spec_with_invalid_refl_negative(void **state)
{
	(void)state;
	char *arr[] = {"pl", "0,0,0", "0,1,0", "255,255,255", "spec=0.5", "refl=-0.5", NULL};
	assert_int_equal(is_valid_plane(arr), 0);
}

void	test_cylinder_spec_over_max_with_valid_refl(void **state)
{
	(void)state;
	char *arr[] = {"cy", "0,0,0", "0,1,0", "2.0", "4.0", "255,255,255", "spec=1.5", "refl=0.5", NULL};
	assert_int_equal(is_valid_cylinder(arr), 0);
}

void	test_cone_valid_spec_with_refl_over_max(void **state)
{
	(void)state;
	char *arr[] = {"co", "0,0,0", "0,1,0", "30.0", "4.0", "255,0,0", "spec=0.5", "refl=1.5", NULL};
	assert_int_equal(is_valid_cone(arr), 0);
}

void	test_hyperboloid_both_spec_refl_invalid(void **state)
{
	(void)state;
	char *arr[] = {"hy", "0,0,0", "0,1,0", "1.0", "1.0", "1.0", "4.0", "255,255,255", "spec=0.0", "refl=2.0", NULL};
	assert_int_equal(is_valid_hyperboloid(arr), 0);
}

void	test_paraboloid_spec_zero_refl_valid(void **state)
{
	(void)state;
	char *arr[] = {"pa", "0,0,0", "0,1,0", "0.5", "4.0", "255,255,255", "spec=0.0", "refl=0.5", NULL};
	assert_int_equal(is_valid_paraboloid(arr), 0);
}
