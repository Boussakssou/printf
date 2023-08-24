#include "main.h"
/**
 * _printf -  produces output according to a format
 * @format: character string
 * Return: the total number of characters to print
 */
int _printf(const char *format, ...)
{
	va_list para;
	int i = 0;

	va_start(para, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				putchar(va_arg(para, int));
				i++;
			}
			else if (*format == 's')
			{
				const char *stri = va_arg(para, const char *);

				while (*stri != '\0')
				{
					putchar(*stri);
					stri++;
					i++;
				}
			}
			else if (*format == '%')
			{
				putchar('%');
				i++;
			}
		}
		else
		{
			putchar(*format);
			i++;
		}
		format++;
	}
	va_end(para);
	return (i);
}
