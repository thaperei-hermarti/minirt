/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 19:34:44 by hermarti          #+#    #+#             */
/*   Updated: 2026/05/09 19:38:43 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMG_BONUS_H
# define IMG_BONUS_H

typedef struct s_img_buffer
{
	void			*img;
	char			*img_addr;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
	int				pixel_size;
}					t_img_buffer;

typedef struct s_texture
{
	t_img_buffer	img;
	int				width;
	int				height;
}					t_texture;
#endif
