#include"Window.h"
SDL_Window* SDL2_Window;
SDL_Renderer* SDL2_Renderer;
SDL_Event SDL2_Event;
extern lua_State* Lua_State;
luaL_Reg SDL2_Event_Lib[] = {

};
void InitWindowLuaFuncs(){
    lua_register(Lua_State,"CreateWindow",CreateWindow);
    //lua_register(Lua_State, "GetEventType", GetEventType);
    lua_register(Lua_State, "OpenEventLibrary", PollEvent);
    lua_register(Lua_State, "SetRenderLoop", SetRenderLoop);
}
int CreateWindow(lua_State* L){
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0){
        luaL_error(L,"SDL 2 Failed To INIT! SDL_Error:%s",SDL_GetError());
    }
    //printf("%i", lua_tointeger(L, -2));
    int SDL2_WinError = SDL_CreateWindowAndRenderer(luaL_checkinteger(L,-2), luaL_checkinteger(L,-3), luaL_checkinteger(L,-1),&SDL2_Window,&SDL2_Renderer);
    //printf("%i", (int)luaL_checknumber(L, -2));
    if(SDL2_WinError != 0){
        luaL_error(L,"SDL 2 Failed To Create The Window And Renderer! SDL_Error:%s",SDL_GetError());
    }
    luaL_dostring(L, "Test()");
    //lua_pcall(L, 0, 0, 0);
}
int GetEventType(lua_State* L) {
    //lua_pushinteger(L, SDL2_Event.type);
    lua_newtable(L);
    lua_setglobal(L, "TableTest");
   // lua_pushstring(L, "Test");
    //lua_rawset(L, -2);
   // lua_pushcfunction(L, CreateWindow);
    //luaL_pushresult
   // lua_rawset(L, 0);
    //lua_pop(L, 0);
    return 0;
    //lua_setglobal(L, "Event_Type");
}
int PollEvent(lua_State* L) {
    lua_pushinteger(L, SDL_PollEvent(&SDL2_Event));
        
    return 1;
}
int SetRenderLoop(lua_State* L) {
    lua_pop(L, 0);
    lua_setglobal(L, "Test");
    

}
