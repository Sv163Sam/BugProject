#pragma once

#ifndef _WIN32_WINNT
#define _WIN32_WINNT _WIN32_WINNT_WIN7
#endif

#ifndef WINVER
#define WINVER _WIN32_WINNT
#endif

#ifndef _WIN32_WINDOWS
#define _WIN32_WINDOWS _WIN32_WINNT
#endif

#ifndef _WIN32_IE
#define _WIN32_IE _WIN32_IE_IE110
#endif

#include <afxwin.h>

#include <vector>
#include <filesystem>
#include <fstream>
#include <map>
#include <ranges>

#include "load.h"
#include "save.h"