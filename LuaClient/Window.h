#include<SDL.h>
#include<lua.h>
#include<lauxlib.h>
void InitWindowLuaFuncs();
int CreateWindow(lua_State* L);
int PollEvent(lua_State* L);
int GetEventType(lua_State* L);
int SetRenderLoop(lua_State* L);
