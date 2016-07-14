#include "g2o_cli_api.h"

#include "callbackstreaminterceptor.h"

typedef void(*StringCallbackFuncType)(const char* message);

extern "C" {
	G2O_CLI_API void setCoutListener(StringCallbackFuncType callbackFunc);
	G2O_CLI_API void setCerrListener(StringCallbackFuncType callbackFunc);
		
	G2O_CLI_API int optimise(const char* input, char** outputPointerReference, int argc, char** argv);
	G2O_CLI_API void cleanup(char* pointer);
};