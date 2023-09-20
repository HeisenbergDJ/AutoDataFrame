#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(AUTODATAFRAME_LIB)
#  define AUTODATAFRAME_EXPORT Q_DECL_EXPORT
# else
#  define AUTODATAFRAME_EXPORT Q_DECL_IMPORT
# endif
#else
# define AUTODATAFRAME_EXPORT
#endif
