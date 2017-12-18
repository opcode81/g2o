#include "g2o_dll_api.h"

#include "callbackstreaminterceptor.h"

typedef void(*StringCallbackFuncType)(const char* message);

extern "C" {
	G2O_DLL_API void setCoutListener(StringCallbackFuncType callbackFunc);
	G2O_DLL_API void setCerrListener(StringCallbackFuncType callbackFunc);
		
	G2O_DLL_API int optimise(const char* input, char** outputPointerReference, int argc, char** argv);
	G2O_DLL_API void cleanup(char* pointer);
};