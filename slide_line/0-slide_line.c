#include "slide_line.h"

int slide_line(int *line, size_t size, int direction)
{
	size_t i, pos;
	int temp;

	if (!line || (direction != SLIDE_LEFT && direction != SLIDE_RIGHT))
		return (0);

	if (direction == SLIDE_LEFT)
	{
		pos = 0;
		// Étape 1 : compacter vers la gauche
		for (i = 0; i < size; i++)
		{
			if (line[i] != 0)
			{
				line[pos++] = line[i];
			}
		}
		while (pos < size)
			line[pos++] = 0;

		// Étape 2 : fusion
		for (i = 0; i < size - 1; i++)
		{
			if (line[i] != 0 && line[i] == line[i + 1])
			{
				line[i] *= 2;
				line[i + 1] = 0;
			}
		}

		// Étape 3 : compacter à nouveau
		pos = 0;
		for (i = 0; i < size; i++)
		{
			if (line[i] != 0)
				line[pos++] = line[i];
		}
		while (pos < size)
			line[pos++] = 0;
	}
	else if (direction == SLIDE_RIGHT)
	{
		pos = size - 1;
		for (i = size; i-- > 0;)
		{
			if (line[i] != 0)
				line[pos--] = line[i];
		}
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
		{
			if (line[i] != 0)
				line[pos--] = line[i];
		}
		while (pos < size)
			line[pos--] = 0;
	}
	return (1);
}

