/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydinler <ydinler@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 00:53:03 by ydinler           #+#    #+#             */
/*   Updated: 2025/10/13 18:58:33 by ydinler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	malloc_error(void)
{
	perror("Problems with Malloc");
	exit(EXIT_FAILURE);
}

void	start_helper(void)
{
	ft_printf("/**********************************************************/\n");
	ft_printf("/*                                                        */\n");
	ft_printf("/*                - How to Start Program -                */\n");
	ft_printf("/*                                                        */\n");
	ft_printf("/*  For Mandelbrot set  :                                 */\n");
	ft_printf("/*               ./fractol mandelbrot                     */\n");
	ft_printf("/*                                                        */\n");
	ft_printf("/*  For Multibrot set   :                                 */\n");
	ft_printf("/*               ./fractol multibrot                      */\n");
	ft_printf("/*                                                        */\n");
	ft_printf("/*  For Julia set       :                                 */\n");
	ft_printf("/*               ./fractol julia <value_1> <value_2>      */\n");
	ft_printf("/*  Example :    ./fractol julia -0.7269 0.1889           */\n");
	ft_printf("/*                                                        */\n");
	ft_printf("/*  For MultiJulia set  :                                 */\n");
	ft_printf("/*               ./fractol multijul <value_1> <value_2>   */\n");
	ft_printf("/*  Example :    ./fractol multijul -0.7269 0.1889        */\n");
	ft_printf("/*                                                        */\n");
	ft_printf("/**********************************************************/\n");
	exit(EXIT_FAILURE);
}

static void	menu_helper_c(void)
{
	ft_printf("/**********************************************************/\n");
	ft_printf("/*                                                        */\n");
	ft_printf("/*                 - Mouse Shortcuts -                    */\n");
	ft_printf("/*                                                        */\n");
	ft_printf("/*  Scroll Down  -> Zoom in                               */\n");
	ft_printf("/*  Scroll Up    -> Zoom out                              */\n");
	ft_printf("/*  Left Click   -> Double zoom in                        */\n");
	ft_printf("/*  Right Click  -> For Mandelbrot or Multibort -         */\n");
	ft_printf("/*                         Open the mini Julia window     */\n");
	ft_printf("/*                                                        */\n");
	ft_printf("/**********************************************************/\n");
	ft_printf("/**********************************************************/\n");
	ft_printf("/*                                                        */\n");
	ft_printf("/*              - Mini Julia Window Controls -            */\n");
	ft_printf("/*                                                        */\n");
	ft_printf("/*  Right Click   -> Zoom in                              */\n");
	ft_printf("/*  Middle Click  -> Zoom out                             */\n");
	ft_printf("/*  [1]           -> Increase iteration count             */\n");
	ft_printf("/*  [-]           -> Decrease iteration count             */\n");
	ft_printf("/*  [3]           -> Reset zoom and shifts                */\n");
	ft_printf("/*                                                        */\n");
	ft_printf("/**********************************************************/\n");
}

void	menu_helper(void)
{
	ft_printf("/**********************************************************/\n");
	ft_printf("/*                                                        */\n");
	ft_printf("/*                - Keyboard Shortcuts -                  */\n");
	ft_printf("/*                                                        */\n");
	ft_printf("/*  [1]  -> Increase iteration count                      */\n");
	ft_printf("/*  [-]  -> Decrease iteration count                      */\n");
	ft_printf("/*  [2]  -> (Julia only) Toggle motion lock               */\n");
	ft_printf("/*  [3]  -> Reset fractal view                            */\n");
	ft_printf("/*  [d]  -> (Multibrot or multijul only) change power     */\n");
	ft_printf("/*  [c]  -> Change palette                                */\n");
	ft_printf("/*  ←  (Left Arrow)   -> Move fractal to the left         */\n");
	ft_printf("/*  →  (Right Arrow)  -> Move fractal to the right        */\n");
	ft_printf("/*  ↑  (Up Arrow)     -> Move fractal upward              */\n");
	ft_printf("/*  ↓  (Down Arrow)   -> Move fractal downward            */\n");
	ft_printf("/*                                                        */\n");
	ft_printf("/**********************************************************/\n");
	menu_helper_c();
}
