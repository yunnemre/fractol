/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_palete.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydinler <ydinler@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 02:37:58 by ydinler           #+#    #+#             */
/*   Updated: 2025/10/13 19:10:04 by ydinler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

int	create_rgb3(t_rgb rgb)
{
	double	t = rgb.t;
	rgb.r = (int)(9 * (1 - t) * t * t * t * 255);
	rgb.g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	rgb.b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	return (((rgb.r & 0xFF )<< 16) | ((rgb.g & 0xFF) << 8) | (rgb.b & 0xFF));
}
int create_rgb1(t_rgb rgb)
{
    double t = sqrt(rgb.t);
   	rgb.r = (int)(9 * (1 - t) * t * t * t * 255);
	rgb.g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	rgb.b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);

    return (((rgb.r & 0xFF )<< 16) | ((rgb.g & 0xFF) << 8) | (rgb.b & 0xFF));
}

int create_rgb2(t_rgb rgb)
{
    double t = pow(rgb.t, 0.3);
    int r = (int)(9 * (1 - t) * t * t * t * 255);
    int g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
    int b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
    return ((0 << 24) | (r << 16) | (g << 8) | b);
}

// int	*create_pallette(int max_iter)
// {
// 	static int	mod = 0;
// 	t_rgb		rgb;
// 	int			*palette;
// 	int			i;

// 	i = -1;
// 	palette = malloc(sizeof(int) * (max_iter + 1));
// 	if (!palette)
// 		return (0);
// 	while (++i < max_iter)
// 	{
// 		rgb.t = (double)i / (double)max_iter;
// 		if (mod == 0)
// 			palette[i] = create_rgb1(rgb);
// 		else if (mod == 1)
// 			palette[i] = create_rgb2(rgb);
// 		else if (mod == 2)
// 			palette[i] = create_rgb3(rgb);
// 	}
// 	mod = (mod + 1) % 3;
// 	return (palette);
// }
// 

// int	create_rgb1(t_rgb rgb)
// {
// 	double	t = rgb.t;

// 	// t = pow(t, 0.7); // istersen ufak yumuşatma ekleyebilirsin (isteğe bağlı)

// 	rgb.r = (int)(255 * (1.0 - t) * t * t * t);
// 	rgb.g = (int)(255 * (1.0 - t) * (1.0 - t) * t * t);
// 	rgb.b = (int)(255 * (1.0 - t) * (1.0 - t) * (1.0 - t) * t);

// 	return ((rgb.r << 16) | (rgb.g << 8) | rgb.b);
// }

int	create_rgb(t_rgb rgb)
{
	return (((rgb.r & 0xFF)) | ((rgb.g & 0xFF) << 8) | (rgb.b & 0xFF) << 16);
}

int	*create_pallette(int max_iter)
{
	t_rgb	rgb;
	int		*palette;
	int		i;

	palette = malloc(sizeof(int) * (max_iter + 1));
	if (!palette)
		return (0);
	i = -1;
	while (++i < max_iter)
	{
		rgb.t = (double)i / (double)max_iter;
		double t = rgb.t;
		rgb.r = (int)(2 * (1 - t) * t * t * t * 255);
		rgb.g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
		rgb.b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);

		palette[i] = create_rgb(rgb);
	}
	return (palette);
}
// static int	hsl_to_rgb(double h, double s, double l)
// {
// 	double	r, g, b, c, x, m;

// 	c = (1 - fabs(2 * l - 1)) * s;
// 	x = c * (1 - fabs(fmod(h / 60.0, 2) - 1));
// 	m = l - c / 2;

// 	if (h < 60) { r = c; g = x; b = 0; }
// 	else if (h < 120) { r = x; g = c; b = 0; }
// 	else if (h < 180) { r = 0; g = c; b = x; }
// 	else if (h < 240) { r = 0; g = x; b = c; }
// 	else if (h < 300) { r = x; g = 0; b = c; }
// 	else { r = c; g = 0; b = x; }

// 	return ((int)((r + m) * 255) | ((int)((g + m) * 255) << 8) | ((int)((b + m) * 255) << 16));
// }



// int	lerp_rgb(int c1, int c2, double t)
// {
// 	int	r1 = c1 & 0xFF;
// 	int	g1 = (c1 >> 8) & 0xFF;
// 	int	b1 = (c1 >> 16) & 0xFF;
// 	int	r2 = c2 & 0xFF;
// 	int	g2 = (c2 >> 8) & 0xFF;
// 	int	b2 = (c2 >> 16) & 0xFF;

// 	int	r = r1 + (r2 - r1) * t;
// 	int	g = g1 + (g2 - g1) * t;
// 	int	b = b1 + (b2 - b1) * t;

// 	return (r | (g << 8) | (b << 16));
// }

// int	get_ocean_color(double t)
// {
// 	if (t < 0.25)
// 		return lerp_rgb(0x000022, 0x003366, t / 0.25); // lacivert → koyu mavi
// 	else if (t < 0.5)
// 		return lerp_rgb(0x003366, 0x0088FF, (t - 0.25) / 0.25); // koyu mavi → mavi
// 	else if (t < 0.75)
// 		return lerp_rgb(0x0088FF, 0x00FFD0, (t - 0.5) / 0.25); // mavi → turkuaz
// 	else
// 		return lerp_rgb(0x00FFD0, 0xFFFFFF, (t - 0.75) / 0.25); // turkuaz → beyaz
// }
// int	get_sunset_color(double t)
// {
// 	if (t < 0.17)
// 		return lerp_rgb(0xFF0000, 0xFF7F00, t / 0.17);
// 	else if (t < 0.20)
// 		return lerp_rgb(0x1A0033, 0x660066, t / 0.20);
// 	else if (t < 0.25)
// 		return lerp_rgb(0x000022, 0x003366, t / 0.25);
// 	else if (t < 0.34)
// 		return lerp_rgb(0xFF7F00, 0xFFFF00, (t - 0.17) / 0.17);
// 	else if (t < 0.40)
// 		return lerp_rgb(0x660066, 0xFF0099, (t - 0.20) / 0.20); // mor → pembe
// 	// else if (t < 0.5)
// 	// 	return lerp_rgb(0x003366, 0x0088FF, (t - 0.25) / 0.25); // koyu mavi → mavi
// 	// else if (t < 0.51)
// 	// 	return lerp_rgb(0xFFFF00, 0x00FF00, (t - 0.34) / 0.17); // sarı → yeşil
// 	else if (t < 0.60)
// 		return lerp_rgb(0xFF0099, 0xFF6600, (t - 0.40) / 0.20); // pembe → turuncu
// 	// else if (t < 0.68)
// 	// 	return lerp_rgb(0x00FF00, 0x0000FF, (t - 0.51) / 0.17); // yeşil → mavi
// 	// else if (t < 0.75)
// 	// 	return lerp_rgb(0x0088FF, 0x00FFD0, (t - 0.5) / 0.25); // mavi → turkuaz
// 	else if (t < 0.80)
// 		return lerp_rgb(0xFF6600, 0xFFFF00, (t - 0.60) / 0.20); // turuncu → sarı
// 	else if (t < 0.85)
// 		return lerp_rgb(0x0000FF, 0x8B00FF, (t - 0.68) / 0.17); // mavi → mor
// 	else
// 		return lerp_rgb(0x8B00FF, 0xFFFFFF, (t - 0.85) / 0.15); // mor → beyaz
// }

// int	get_rainbow_color(double t)
// {
// 	if (t < 0.17)
// 		return lerp_rgb(0xFF0000, 0xFF7F00, t / 0.17); // kırmızı → turuncu
// 	else if (t < 0.34)
// 		return lerp_rgb(0xFF7F00, 0xFFFF00, (t - 0.17) / 0.17); // turuncu → sarı
// 	else if (t < 0.51)
// 		return lerp_rgb(0xFFFF00, 0x00FF00, (t - 0.34) / 0.17); // sarı → yeşil
// 	else if (t < 0.68)
// 		return lerp_rgb(0x00FF00, 0x0000FF, (t - 0.51) / 0.17); // yeşil → mavi
// 	else if (t < 0.85)
// 		return lerp_rgb(0x0000FF, 0x8B00FF, (t - 0.68) / 0.17); // mavi → mor
// 	else
// 		return lerp_rgb(0x8B00FF, 0xFFFFFF, (t - 0.85) / 0.15); // mor → beyaz
// }
// int	*create_pallette(int max_iter)
// {
// 	int	*palette = malloc(sizeof(int) * max_iter);
// 	int i = 0;
// 	while(++i < max_iter)
// 		palette[i] = get_sunset_color((double)i / max_iter);
// 	// i--;
// 	// while (++i < 300)
// 	// 	palette[i] = get_ocean_color((double)i / max_iter);
// 	// i--;
// 	// while (++i < 513)
// 	// 	palette[i] = get_sunset_color((double)i / max_iter);
// 	return (palette);

// }
// // static char	*ft_itoa_hex(long long nbr, char *base)
// {
// 	int					len;
// 	size_t				base_len;
// 	char				*res;
// 	char				*sub;

// 	base_len = ft_strlen(base);
// 	len = base_len;
// 	res = ft_calloc(sizeof(char), (base_len + 1));
// 	if (!res)
// 		return (0);
// 	if (nbr == 0)
// 		res[--len] = '0';
// 	while (nbr)
// 	{
// 		res[--len] = base[nbr % base_len];
// 		nbr /= base_len;
// 	}
// 	sub = ft_substr(&res[len], 0, base_len - len);
// 	free(res);
// 	return (sub);
// }

// void	crte_color_txt(void)
// {
// 	int fd; 
// 	char *str;
// 	int		*palette;
// 	int i;
	
// 	fd = open("/home/ynn/fractol/src/colors_palet.txt",  O_CREAT | O_RDWR | O_TRUNC, 0644);
//     if (fd < 0)
//     {
//         perror("open");
//         return ;
//     }
// 	palette = create_pallette(256,255,255,255);
// 	i = 1;
// 	while(++i < 256)
// 	{
// 		str = ft_itoa_hex((long long)(palette[i]), "0123456789abcdef");
// 		ft_putstr_fd("0x",fd);
// 		ft_putstr_fd(str,fd);
// 		if(i !=255)
// 			ft_putstr_fd("\n",fd);
// 	}
	
// }
// int *load_palette_from_file(const char *filename, int *size)
// {
//     int fd = open(filename, O_RDONLY,0644);
//     if (fd < 0)
//     {
//         perror("open");
//         return NULL;
//     }

// 	int capacity = 520	;
//     int *palette = malloc(sizeof(int) * capacity);
//     if (!palette)
//     {
//         close(fd);
//         return NULL;
//     }

//     int count = 0;
//     char *line;
//     while ((line = get_next_line(fd)))
//     {
//         if (count >= capacity)
//         {
//             capacity *= 2;
//             int *tmp = realloc(palette, sizeof(int) * capacity);
//             if (!tmp)
//             {
//                 free(palette);
//                 free(line);
//                 close(fd);
//                 return NULL;
//             }
//             palette = tmp;
//         }

//         palette[count++] = (int)strtol(line, NULL, 16);
//         free(line);
//     }

//     close(fd);
//     *size = count;
//     return palette;
// }

// int main (void)
// {
// 	int *ss =create_pallette(768);
// 	int i = 0;
// 	while(++i < 256)
//  	{
// 			printf("%p\n",ss[i]);
// 	}
// 	return (0);
// }