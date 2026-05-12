
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_validation_bonus.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 10:00:00 by thaperei          #+#    #+#             */
/*   Updated: 2026/04/22 20:23:42 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_VALIDATION_BONUS_H
# define TEST_VALIDATION_BONUS_H

void	test_valid_cone_valid(void **state);
void	test_valid_cone_invalid_coordinates(void **state);
void	test_valid_cone_invalid_angle(void **state);
void	test_valid_cone_invalid_color(void **state);
void	test_valid_cone_negative_angle(void **state);
void	test_valid_cone_zero_angle(void **state);
void	test_valid_cone_null_coordinates(void **state);
void	test_valid_cone_null_angle(void **state);
void	test_valid_cone_null_color(void **state);

void	test_valid_hyperboloid_valid(void **state);
void	test_valid_hyperboloid_invalid_coordinates(void **state);
void	test_valid_hyperboloid_invalid_vector(void **state);
void	test_valid_hyperboloid_invalid_color(void **state);
void	test_valid_hyperboloid_null_coordinates(void **state);
void	test_valid_hyperboloid_null_vector(void **state);
void	test_valid_hyperboloid_null_color(void **state);
void	test_valid_hyperboloid_vector_out_of_range(void **state);
void	test_valid_hyperboloid_vector_wrong_count(void **state);

void	test_valid_paraboloid_valid(void **state);
void	test_valid_paraboloid_invalid_coordinates(void **state);
void	test_valid_paraboloid_invalid_vector(void **state);
void	test_valid_paraboloid_invalid_color(void **state);
void	test_valid_paraboloid_null_coordinates(void **state);
void	test_valid_paraboloid_null_vector(void **state);
void	test_valid_paraboloid_null_color(void **state);
void	test_valid_paraboloid_vector_out_of_range(void **state);
void	test_valid_paraboloid_vector_wrong_count(void **state);

void	test_sphere_spec_valid_min(void **state);
void	test_sphere_spec_valid_max(void **state);
void	test_sphere_spec_valid_mid(void **state);
void	test_sphere_spec_invalid_zero(void **state);
void	test_sphere_spec_invalid_negative(void **state);
void	test_sphere_spec_invalid_over_one(void **state);
void	test_sphere_spec_invalid_not_float(void **state);

void	test_sphere_refl_valid_min(void **state);
void	test_sphere_refl_valid_max(void **state);
void	test_sphere_refl_invalid_zero(void **state);
void	test_sphere_refl_invalid_negative(void **state);
void	test_sphere_refl_invalid_over_one(void **state);
void	test_sphere_refl_invalid_not_float(void **state);

void	test_sphere_check_valid_zero(void **state);
void	test_sphere_check_invalid_with_value(void **state);

void	test_sphere_texture_valid(void **state);
void	test_sphere_texture_invalid_path(void **state);

void	test_sphere_spec_and_refl_valid(void **state);
void	test_sphere_check_and_spec_valid(void **state);
void	test_sphere_check_and_refl_valid(void **state);
void	test_sphere_all_properties_valid(void **state);
void	test_sphere_check_and_texture_exclusive_both_present(void **state);

void	test_plane_spec_valid(void **state);
void	test_plane_spec_invalid_zero(void **state);
void	test_plane_spec_invalid_over_one(void **state);
void	test_plane_refl_valid(void **state);
void	test_plane_refl_invalid_zero(void **state);
void	test_plane_refl_invalid_over_one(void **state);
void	test_plane_check_valid_zero(void **state);
void	test_plane_texture_valid(void **state);
void	test_plane_spec_refl_and_check(void **state);
void	test_plane_check_and_texture_exclusive_both_present(void **state);

void	test_cylinder_spec_valid(void **state);
void	test_cylinder_spec_invalid_zero(void **state);
void	test_cylinder_spec_invalid_over_one(void **state);
void	test_cylinder_refl_valid(void **state);
void	test_cylinder_refl_invalid_zero(void **state);
void	test_cylinder_refl_invalid_over_one(void **state);
void	test_cylinder_check_valid_zero(void **state);
void	test_cylinder_texture_valid(void **state);
void	test_cylinder_all_properties(void **state);
void	test_cylinder_check_and_texture_exclusive_both_present(void **state);

void	test_cone_spec_valid(void **state);
void	test_cone_spec_invalid_zero(void **state);
void	test_cone_spec_invalid_negative(void **state);
void	test_cone_spec_invalid_over_one(void **state);
void	test_cone_refl_valid(void **state);
void	test_cone_refl_invalid_zero(void **state);
void	test_cone_refl_invalid_over_one(void **state);
void	test_cone_check_valid_zero(void **state);
void	test_cone_texture_valid(void **state);
void	test_cone_all_properties(void **state);
void	test_cone_check_and_texture_exclusive_both_present(void **state);

void	test_hyperboloid_spec_valid(void **state);
void	test_hyperboloid_spec_invalid_zero(void **state);
void	test_hyperboloid_spec_invalid_over_one(void **state);
void	test_hyperboloid_refl_valid(void **state);
void	test_hyperboloid_refl_invalid_zero(void **state);
void	test_hyperboloid_refl_invalid_over_one(void **state);
void	test_hyperboloid_check_valid_zero(void **state);
void	test_hyperboloid_texture_valid(void **state);
void	test_hyperboloid_all_properties(void **state);
void	test_hyperboloid_check_and_texture_exclusive_both_present(void **state);

void	test_paraboloid_spec_valid(void **state);
void	test_paraboloid_spec_invalid_zero(void **state);
void	test_paraboloid_spec_invalid_negative(void **state);
void	test_paraboloid_spec_invalid_over_one(void **state);
void	test_paraboloid_refl_valid(void **state);
void	test_paraboloid_refl_invalid_zero(void **state);
void	test_paraboloid_refl_invalid_over_one(void **state);
void	test_paraboloid_check_valid_zero(void **state);
void	test_paraboloid_texture_valid(void **state);
void	test_paraboloid_all_properties(void **state);
void	test_paraboloid_check_and_texture_exclusive_both_present(void **state);

void	test_sphere_only_check_no_other_optional(void **state);
void	test_sphere_only_spec_no_other_optional(void **state);
void	test_plane_only_check_no_spec_refl(void **state);
void	test_cylinder_only_texture_no_check_spec_refl(void **state);
void	test_cone_no_optional_properties(void **state);
void	test_hyperboloid_only_spec_refl_no_check_texture(void **state);
void	test_paraboloid_all_optional_properties_valid(void **state);

void	test_sphere_spec_boundary_almost_zero(void **state);
void	test_sphere_spec_boundary_almost_one(void **state);
void	test_sphere_refl_boundary_almost_zero(void **state);
void	test_sphere_refl_boundary_almost_one(void **state);
void	test_plane_spec_boundary_one(void **state);
void	test_plane_refl_boundary_one(void **state);

void test_sphere_spec_negative_with_valid_refl(void **state);
void test_plane_valid_spec_with_invalid_refl_negative(void **state);
void test_cylinder_spec_over_max_with_valid_refl(void **state);
void test_cone_valid_spec_with_refl_over_max(void **state);
void test_hyperboloid_both_spec_refl_invalid(void **state);
void test_paraboloid_spec_zero_refl_valid(void **state);
#endif
