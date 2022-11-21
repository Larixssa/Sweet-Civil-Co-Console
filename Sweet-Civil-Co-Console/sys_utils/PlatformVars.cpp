#include "PlatformVars.h"
#include "Platform.h"
#include "../scclib/Strutils.h"

#include<string>

std::string PLATFORM_VARS::CURRENT_PLATFORM = Platform::get_platform();
bool PLATFORM_VARS::__IS_WINDOWS__ = (STRING_UTILS::strcmpr(Platform::get_platform(), "Windows"));
bool PLATFORM_VARS::__IS_LINUX__ = (STRING_UTILS::strcmpr(Platform::get_platform(), "Linux"));
bool PLATFORM_VARS::__IS_DEFAULT__ = (!STRING_UTILS::strcmpr(Platform::get_platform(), "Linux") || !STRING_UTILS::strcmpr(Platform::get_platform(), "Windows"));