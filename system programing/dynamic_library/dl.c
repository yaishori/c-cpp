#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <gnu/lib-names.h>

int main(int argc, char** argv){
	int (*libfunc)();
	void* handle = dlopen("./libN.so", RTLD_LAZY);
	*(void **) (&libfunc) = dlsym(handle, "lib1func");
	libfunc();
	dlclose(handle);
}