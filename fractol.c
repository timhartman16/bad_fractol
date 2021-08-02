#include "fractol.h"

void	ft_init_julia_params(int argc, char **argv, t_fractol *fract)
{
	if (argc == 4)
	{
		fract->params = 1;
		fract->c_x = ft_atof(argv[2]);
		fract->c_y = ft_atof(argv[3]);
	}
}

int	main(int argc, char **argv)
{
	t_fractol	fract;

	if (argc == 2 || argc == 4)
	{
		if (ft_fractol_name_check(&fract, argv) == 0)
		{
			ft_wrong_parameters();
			return (0);
		}
		ft_init_fractol(&fract);
		ft_init_julia_params(argc, argv, &fract);
		ft_draw(&fract);
		mlx_hook(fract.win, 2, 0, key_press, &fract);
		mlx_hook(fract.win, 4, 0, ft_mouse_zoom, &fract);
		mlx_hook(fract.win, 17, 0, ft_close, &fract);
		mlx_loop(fract.mlx);
	}
	else
		ft_wrong_parameters();
	return (0);
}
