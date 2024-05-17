#include "stdafx.h"

int wmain(int argc, wchar_t * argv[])
{
	if (argc < 3)
		return 1;

	save_to_file(argv[2], load_from_file(argv[1]));

	return 0;
}