#include "main.h"
/** _printf
* _printf-handles the  conversion specifiers c ,s ,%
*
*Return:length of 
*/
int C(const char *format, ...)
{
	int len = 0;

	va_list args;

	va_start(args, format);

	len = _vprintf(format, args);

	va_end(args);

	return (len);
}
