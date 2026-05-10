/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bonus_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 13:40:09 by thaperei          #+#    #+#             */
/*   Updated: 2026/05/10 12:30:20 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include "libft.h"
#include "test_validation_bonus.h"
#include "test_parser_bonus.h"
#include <stdio.h>
#include <string.h>

static int	run_bonus_validation_tests(void)
{
	const struct CMUnitTest tests[] = {

		/* =========================================================
		   CONE unit tests
		   ========================================================= */
		cmocka_unit_test(test_valid_cone_valid),
		cmocka_unit_test(test_valid_cone_invalid_coordinates),
		cmocka_unit_test(test_valid_cone_invalid_angle),
		cmocka_unit_test(test_valid_cone_invalid_color),
		cmocka_unit_test(test_valid_cone_negative_angle),
		cmocka_unit_test(test_valid_cone_zero_angle),
		cmocka_unit_test(test_valid_cone_null_coordinates),
		cmocka_unit_test(test_valid_cone_null_angle),
		cmocka_unit_test(test_valid_cone_null_color),

		/* =========================================================
		   HYPERBOLOID unit tests
		   ========================================================= */
		cmocka_unit_test(test_valid_hyperboloid_valid),
		cmocka_unit_test(test_valid_hyperboloid_invalid_coordinates),
		cmocka_unit_test(test_valid_hyperboloid_invalid_vector),
		cmocka_unit_test(test_valid_hyperboloid_invalid_color),
		cmocka_unit_test(test_valid_hyperboloid_null_coordinates),
		cmocka_unit_test(test_valid_hyperboloid_null_vector),
		cmocka_unit_test(test_valid_hyperboloid_null_color),
		cmocka_unit_test(test_valid_hyperboloid_vector_out_of_range),
		cmocka_unit_test(test_valid_hyperboloid_vector_wrong_count),

		/* =========================================================
		   PARABOLOID unit tests
		   ========================================================= */
		cmocka_unit_test(test_valid_paraboloid_valid),
		cmocka_unit_test(test_valid_paraboloid_invalid_coordinates),
		cmocka_unit_test(test_valid_paraboloid_invalid_vector),
		cmocka_unit_test(test_valid_paraboloid_invalid_color),
		cmocka_unit_test(test_valid_paraboloid_null_coordinates),
		cmocka_unit_test(test_valid_paraboloid_null_vector),
		cmocka_unit_test(test_valid_paraboloid_null_color),
		cmocka_unit_test(test_valid_paraboloid_vector_out_of_range),
		cmocka_unit_test(test_valid_paraboloid_vector_wrong_count),

		/* =========================================================
		   SPHERE property tests
		   ========================================================= */
		cmocka_unit_test(test_sphere_spec_valid_min),
		cmocka_unit_test(test_sphere_spec_valid_max),
		cmocka_unit_test(test_sphere_spec_valid_mid),
		cmocka_unit_test(test_sphere_spec_invalid_zero),
		cmocka_unit_test(test_sphere_spec_invalid_negative),
		cmocka_unit_test(test_sphere_spec_invalid_over_one),
		cmocka_unit_test(test_sphere_spec_invalid_not_float),

		cmocka_unit_test(test_sphere_refl_valid_min),
		cmocka_unit_test(test_sphere_refl_valid_max),
		cmocka_unit_test(test_sphere_refl_invalid_zero),
		cmocka_unit_test(test_sphere_refl_invalid_negative),
		cmocka_unit_test(test_sphere_refl_invalid_over_one),
		cmocka_unit_test(test_sphere_refl_invalid_not_float),

		cmocka_unit_test(test_sphere_check_valid_zero),
		cmocka_unit_test(test_sphere_check_invalid_with_value),

		cmocka_unit_test(test_sphere_texture_valid),
		cmocka_unit_test(test_sphere_texture_invalid_path),

		cmocka_unit_test(test_sphere_spec_and_refl_valid),
		cmocka_unit_test(test_sphere_check_and_spec_valid),
		cmocka_unit_test(test_sphere_check_and_refl_valid),
		cmocka_unit_test(test_sphere_all_properties_valid),
		cmocka_unit_test(test_sphere_check_and_texture_exclusive_both_present),

		/* =========================================================
		   PLANE property tests
		   ========================================================= */
		cmocka_unit_test(test_plane_spec_valid),
		cmocka_unit_test(test_plane_spec_invalid_zero),
		cmocka_unit_test(test_plane_spec_invalid_over_one),
		cmocka_unit_test(test_plane_refl_valid),
		cmocka_unit_test(test_plane_refl_invalid_zero),
		cmocka_unit_test(test_plane_refl_invalid_over_one),
		cmocka_unit_test(test_plane_check_valid_zero),
		cmocka_unit_test(test_plane_texture_valid),
		cmocka_unit_test(test_plane_spec_refl_and_check),
		cmocka_unit_test(test_plane_check_and_texture_exclusive_both_present),

		/* =========================================================
		   CYLINDER property tests
		   ========================================================= */
		cmocka_unit_test(test_cylinder_spec_valid),
		cmocka_unit_test(test_cylinder_spec_invalid_zero),
		cmocka_unit_test(test_cylinder_spec_invalid_over_one),
		cmocka_unit_test(test_cylinder_refl_valid),
		cmocka_unit_test(test_cylinder_refl_invalid_zero),
		cmocka_unit_test(test_cylinder_refl_invalid_over_one),
		cmocka_unit_test(test_cylinder_check_valid_zero),
		cmocka_unit_test(test_cylinder_texture_valid),
		cmocka_unit_test(test_cylinder_all_properties),
		cmocka_unit_test(test_cylinder_check_and_texture_exclusive_both_present),

		/* =========================================================
		   CONE property tests
		   ========================================================= */
		cmocka_unit_test(test_cone_spec_valid),
		cmocka_unit_test(test_cone_spec_invalid_zero),
		cmocka_unit_test(test_cone_spec_invalid_negative),
		cmocka_unit_test(test_cone_spec_invalid_over_one),
		cmocka_unit_test(test_cone_refl_valid),
		cmocka_unit_test(test_cone_refl_invalid_zero),
		cmocka_unit_test(test_cone_refl_invalid_over_one),
		cmocka_unit_test(test_cone_check_valid_zero),
		cmocka_unit_test(test_cone_texture_valid),
		cmocka_unit_test(test_cone_all_properties),
		cmocka_unit_test(test_cone_check_and_texture_exclusive_both_present),

		/* =========================================================
		   HYPERBOLOID property tests
		   ========================================================= */
		cmocka_unit_test(test_hyperboloid_spec_valid),
		cmocka_unit_test(test_hyperboloid_spec_invalid_zero),
		cmocka_unit_test(test_hyperboloid_spec_invalid_over_one),
		cmocka_unit_test(test_hyperboloid_refl_valid),
		cmocka_unit_test(test_hyperboloid_refl_invalid_zero),
		cmocka_unit_test(test_hyperboloid_refl_invalid_over_one),
		cmocka_unit_test(test_hyperboloid_check_valid_zero),
		cmocka_unit_test(test_hyperboloid_texture_valid),
		cmocka_unit_test(test_hyperboloid_all_properties),
		cmocka_unit_test(test_hyperboloid_check_and_texture_exclusive_both_present),

		/* =========================================================
		   PARABOLOID property tests
		   ========================================================= */
		cmocka_unit_test(test_paraboloid_spec_valid),
		cmocka_unit_test(test_paraboloid_spec_invalid_zero),
		cmocka_unit_test(test_paraboloid_spec_invalid_negative),
		cmocka_unit_test(test_paraboloid_spec_invalid_over_one),
		cmocka_unit_test(test_paraboloid_refl_valid),
		cmocka_unit_test(test_paraboloid_refl_invalid_zero),
		cmocka_unit_test(test_paraboloid_refl_invalid_over_one),
		cmocka_unit_test(test_paraboloid_check_valid_zero),
		cmocka_unit_test(test_paraboloid_texture_valid),
		cmocka_unit_test(test_paraboloid_all_properties),
		cmocka_unit_test(test_paraboloid_check_and_texture_exclusive_both_present),

		/* =========================================================
		   Edge case tests
		   ========================================================= */
		cmocka_unit_test(test_sphere_only_check_no_other_optional),
		cmocka_unit_test(test_sphere_only_spec_no_other_optional),
		cmocka_unit_test(test_plane_only_check_no_spec_refl),
		cmocka_unit_test(test_cylinder_only_texture_no_check_spec_refl),
		cmocka_unit_test(test_cone_no_optional_properties),
		cmocka_unit_test(test_hyperboloid_only_spec_refl_no_check_texture),
		cmocka_unit_test(test_paraboloid_all_optional_properties_valid),

		/* =========================================================
		   Boundary tests
		   ========================================================= */
		cmocka_unit_test(test_sphere_spec_boundary_almost_zero),
		cmocka_unit_test(test_sphere_spec_boundary_almost_one),
		cmocka_unit_test(test_sphere_refl_boundary_almost_zero),
		cmocka_unit_test(test_sphere_refl_boundary_almost_one),
		cmocka_unit_test(test_plane_spec_boundary_one),
		cmocka_unit_test(test_plane_refl_boundary_one),

		/* =========================================================
		   Negative combination tests
		   ========================================================= */
		cmocka_unit_test(test_sphere_spec_negative_with_valid_refl),
		cmocka_unit_test(test_plane_valid_spec_with_invalid_refl_negative),
		cmocka_unit_test(test_cylinder_spec_over_max_with_valid_refl),
		cmocka_unit_test(test_cone_valid_spec_with_refl_over_max),
		cmocka_unit_test(test_hyperboloid_both_spec_refl_invalid),
		cmocka_unit_test(test_paraboloid_spec_zero_refl_valid),
	};

	printf("\n--- Bonus Validation Tests ---\n");
	return (cmocka_run_group_tests(tests, NULL, NULL));
}

static int  run_bonus_parser_tests(void)
{
    const struct CMUnitTest tests[] = {
        /* parse_cone tests */
        cmocka_unit_test(test_parse_cone_basic),
        cmocka_unit_test(test_parse_cone_offset_position),
        cmocka_unit_test(test_parse_cone_diameter_variations),
        cmocka_unit_test(test_parse_cone_red_color),
        cmocka_unit_test(test_parse_cone_black_color),
        cmocka_unit_test(test_parse_cone_negative_coordinates),
        cmocka_unit_test(test_parse_cone_decimal_coordinates),
        cmocka_unit_test(test_parse_cone_unbounded),
        cmocka_unit_test(test_parse_cone_multiple_cones),
        /* parse_hyperboloid tests */
        cmocka_unit_test(test_parse_hyperboloid_basic),
        cmocka_unit_test(test_parse_hyperboloid_offset_position),
        cmocka_unit_test(test_parse_hyperboloid_different_orientations),
        cmocka_unit_test(test_parse_hyperboloid_red_color),
        cmocka_unit_test(test_parse_hyperboloid_negative_coordinates),
        cmocka_unit_test(test_parse_hyperboloid_diagonal_orientation),
        cmocka_unit_test(test_parse_hyperboloid_unbounded),
        cmocka_unit_test(test_parse_hyperboloid_multiple_hyperboloids),
        /* parse_paraboloid tests */
        cmocka_unit_test(test_parse_paraboloid_basic),
        cmocka_unit_test(test_parse_paraboloid_offset_position),
        cmocka_unit_test(test_parse_paraboloid_different_orientations),
        cmocka_unit_test(test_parse_paraboloid_green_color),
        cmocka_unit_test(test_parse_paraboloid_negative_coordinates),
        cmocka_unit_test(test_parse_paraboloid_z_axis_orientation),
        cmocka_unit_test(test_parse_paraboloid_unbounded),
        cmocka_unit_test(test_parse_paraboloid_multiple_paraboloids),
        cmocka_unit_test(test_parse_paraboloid_blue_color),
        /* mixed bonus objects tests */
        cmocka_unit_test(test_parse_mixed_bonus_objects),
        cmocka_unit_test(test_parse_bonus_objects_color_variation),
    };
    printf("\n--- Bonus Parser Tests ---\n");
    return (cmocka_run_group_tests(tests, NULL, NULL));
}

static int run_parse_elements_integration_tests(void)
{
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_parse_elements_single_ambient),
        cmocka_unit_test(test_parse_elements_single_camera),
        cmocka_unit_test(test_parse_elements_single_light),
        cmocka_unit_test(test_parse_elements_single_sphere),
        cmocka_unit_test(test_parse_elements_single_plane),
        cmocka_unit_test(test_parse_elements_single_cylinder),
        cmocka_unit_test(test_parse_elements_complete_basic_scene),
        cmocka_unit_test(test_parse_elements_all_bonus_objects),
        cmocka_unit_test(test_parse_elements_multiple_lights),
        cmocka_unit_test(test_parse_elements_multiple_spheres),
        cmocka_unit_test(test_parse_elements_mixed_objects),
        cmocka_unit_test(test_parse_elements_decimal_values),
        cmocka_unit_test(test_parse_elements_large_values),
        cmocka_unit_test(test_parse_elements_zero_values),
        cmocka_unit_test(test_parse_elements_scene_ordering),
        cmocka_unit_test(test_parse_elements_initializes_light_array),
        cmocka_unit_test(test_parse_elements_initializes_surfaces_array),
        cmocka_unit_test(test_parse_elements_realistic_scene),
        cmocka_unit_test(test_parse_elements_all_types_mixed),
        cmocka_unit_test(test_parse_elements_color_preservation),
    };
    printf("\n--- Bonus Integration parser Tests ---\n");
    return (cmocka_run_group_tests(tests, NULL, NULL));
}

static void	print_usage(void)
{
	printf("Usage: ./run_tests_bonus [OPTIONS]\n");
	printf("Options:\n");
	printf("  (no args)              Run all tests\n");
	printf("  validation             Run validation tests only\n");
	printf("  parser                 Run parser tests only\n");
	printf("  integration            Run parse_elements integration tests only\n");
	printf("  -h, --help             Show this help message\n");
}

int	main(int argc, char *argv[])
{
	int	result;
	int	failed;

	if (argc > 1)
	{
		if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0)
		{
			print_usage();
			return (0);
		}
		if (strcmp(argv[1], "validation") == 0)
		{
			printf("\n=== Running bonus validation Tests ===\n");
			return (run_bonus_validation_tests());
		}
		if (strcmp(argv[1], "parser") == 0)
		{
			printf("\n=== Running bonus parser Tests ===\n");
			return (run_bonus_parser_tests());
		}
		if (strcmp(argv[1], "integration") == 0)
		{
			printf("\n=== Running parse_elements Integration Tests ===\n");
			return (run_parse_elements_integration_tests());
		}
		printf("Unknown option: %s\n", argv[1]);
		print_usage();
		return (1);
	}
	printf("\n=== Running MiniRT Bonus Tests ===\n");
	failed = 0;
	result = run_bonus_validation_tests();
	if (result != 0)
		failed += result;
	result = run_bonus_parser_tests();
	if (result != 0)
		failed += result;
	result = run_parse_elements_integration_tests();
	if (result != 0)
		failed += result;
	printf("\n=== Test Suite Complete ===\n");
	if (failed > 0)
		printf("Total failures: %d\n", failed);
	else
		printf("All tests passed!\n");
	return (failed);
}
