#pragma once

// C/C++
#include <new>
#include <memory>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cwchar>
#include <cwctype>
#include <cctype>
#include <cmath>
#include <cstdarg>
#include <ctime>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
#include <list>
#include <set>
#include <stack>
#include <map>
#include <queue>
#include <algorithm>
#include <limits>
#include <functional>
#include <bitset>
#include <typeinfo>
#include <thread>
#include <mutex>
#include <chrono>
//#include "Logger.h"

//GL

#include "glload/gl_4_0.h"
#include "glload/gl_load.hpp"
#include "GL/freeglut.h"

// Bring common functions from C into global namespace
using std::memcpy;
using std::fabs;
using std::sqrt;
using std::cos;
using std::sin;
using std::tan;
using std::isspace;
using std::isdigit;
using std::toupper;
using std::tolower;
using std::size_t;
using std::min;
using std::max;
using std::modf;
using std::atoi;
using namespace std;
// Common
#ifndef NULL
#define NULL     0
#endif



namespace FMango
{
// Assert macros.
#ifdef _DEBUG
#define FM_ASSERT(expression) assert(expression)
#else
#define FM_ASSERT(expression)
#endif



	// Error macro.
#ifdef FM_ERRORS_AS_WARNINGS
#define FM_ERROR GP_WARN
#else
#define FM_ERROR(...) do \
	{ \
		assert(0); \
		std::exit(-1); \
} while (0)
#endif

// Warning macro.
#define FM_WARN(...) do \
{ \
	printf("");\
} while (0)

// Array deletion macro
#define SAFE_DELETE_ARRAY(x) \
{ \
	delete[] x; \
	x = NULL; \
}

#define  SAFE_DELETE(x) \
{\
	delete x;\
	x = NULL;\
}

}
