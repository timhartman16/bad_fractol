#include "fractol.h"

float ft_atof(char *s)
{
	float	value;
	float	fraction;
	char	iexp;
	char	sign;

	while (isspace(*s)) s++;

	if (*s == '-')
	{
		sign = 1;
		s++;
	}
	else
	{
		sign = 0;
		if (*s == '+') s++;
	}

	for (value = 0.0; ft_isdigit(*s); s++)
	{
		value = 10.0 * value + (*s - '0');
	}

	if (*s == '.')
	{
		s++;
		for (fraction = 0.1; ft_isdigit(*s); s++)
		{
			value += (*s-'0') * fraction;
			fraction *= 0.1;
		}
	}

	if (ft_toupper(*s) == 'E')
	{
		s++;
		iexp = (char)ft_atoi(s);
		{
			while(iexp != 0)
			{
				if(iexp < 0)
				{
					value *= 0.1;
					iexp++;
				}
				else
				{
					value *= 10.0;
					iexp--;
				}
			}
		}
	}

	if(sign) value*=-1.0;
	return (value);
}