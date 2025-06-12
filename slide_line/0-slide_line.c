#include "slide_line.h"

int slide_line(int *line, size_t size, int direction)
{
	size_t i, pos;

	if (!line || (direction != SLIDE_LEFT && direction != SLIDE_RIGHT))
		return (0);

	if (direction == SLIDE_LEFT)
	{
		pos = 0;
		for (i = 0; i < size; i++)
			if (line[i] != 0)
				line[pos++] = line[i];
		while (pos < size)
			line[pos++] = 0;

		for (i = 0; i < size - 1; i++)
		{
			if (line[i] != 0 && line[i] == line[i + 1])
			{
				line[i] *= 2;
				line[i + 1] = 0;
			}
		}

		pos = 0;
		for (i = 0; i < size; i++)
			if (line[i] != 0)
				line[pos++] = line[i];
		while (pos < size)
			line[pos++] = 0;
	}
	else if (direction == SLIDE_RIGHT)
	{
		pos = size - 1;
		for (i = size; i-- > 0;)
			if (line[i] != 0)
				line[pos--] = line[i];
		while (pos < size)
			line[pos--] = 0;

		for (i = size - 1; i > 0; i--)
		{
			if (line[i] != 0 && line[i] == line[i - 1])
			{
				line[i] *= 2;
				line[i - 1] = 0;
			}
		}

		pos = size - 1;
		for (i = size; i-- > 0;)
			if (line[i] != 0)
				line[pos--] = line[i];
		while (pos < size)
			line[pos--] = 0;
	}
	return (1);
}

