static void	data_init(t_data *data)
{
	if (!ft_strcmp(data->name, "julia"))
		data->color = 0xF0FF0000;
	else
		data->color = 0x00050709;
	data->iterations = 100;
	data->zoom = 1.0;
	data->lock_mouse = 1;
	data->x_offset = 0.0;
	data->y_offset = 0.0;
	data->mlx = mlx_init();
	ft_error(data->mlx);
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, TITLE);
	ft_error(data->win);
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	ft_error(data->img);
	data->addr = mlx_get_data_addr(data->img,
			&data->bits_per_pixel,
			&data->size_line,
			&data->endian);
	ft_error(data->addr);
	mlx_key_hook(data->win, key_hook, data);
	mlx_hook(data->win, 6, 0, mouse_move, data);
	mlx_mouse_hook(data->win, mouse_hook, data);
	mlx_hook(data->win, CLOSE_BUTTON, 0, close_window, data);
}