#include"LuaUtils.h"
#include<stdbool.h>
lua_State* Lua_State;
bool Lua_Result;
void InitLua(){
    Lua_State = luaL_newstate();
    luaL_openlibs(Lua_State);
    InitWindowLuaFuncs();
    Lua_Result = luaL_dofile(Lua_State, "ClientInit.lua");
    printf("Lua_Result:%i", Lua_Result);
       if (Lua_Result == true) {
           SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Lua Error", lua_tostring(Lua_State, -1), NULL);
           return;
        }    
}

