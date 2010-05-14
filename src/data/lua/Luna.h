/*****************************************************************************
 *     .:: Luna ::.                                                          *
 *                                                                *   , *    *
 *  C++ library for binding classes into Lua.     By nornagon.       ((   *  *
 *                                                               *    `      *
 *  Example:                                                                 *
 *****************************************************************************

    class Foo {
      public:
        Foo(lua_State *L) {
          printf("in constructor\n");
        }

        int foo(lua_State *L) {
          printf("in foo\n");
        }

        ~Foo() {
          printf("in destructor\n");
        }

        static const char className[];
        static const Luna<Foo>::RegType Register[];
    };

    const char Foo::className[] = "Foo";
    const Luna<Foo>::RegType Foo::Register[] = {
      { "foo", &Foo::foo },
      { 0 }
    };

 *****************************************************************************
 * Then:                                                                     *
 *****************************************************************************

    Luna<Foo>::Register(L);

 *****************************************************************************
 * From Lua:                                                                 *
 *****************************************************************************

    local foo = Foo()
    foo:foo()

 *****************************************************************************
 * Clean up:                                                                 *
 *****************************************************************************

    lua_close(L);

 *****************************************************************************
 * Output:                                                                   *
 *****************************************************************************

    in constructor
    in foo
    in destructor

 *****************************************************************************
 * This program is free software. It comes without any warranty, to          *
 * the extent permitted by applicable law. You can redistribute it           *
 * and/or modify it under the terms of the Do What The Fuck You Want         *
 * To Public License, Version 2, as published by Sam Hocevar. See            *
 * http://sam.zoy.org/wtfpl/COPYING for more details.                        *
 ****************************************************************************/
 
#ifndef LUNA_H
#define LUNA_H

// convenience macros
#define luna_register(L, klass) (Luna<klass>::Register((L)))
#define luna_registermetatable(L, klass) (Luna<klass>::RegisterMetatable((L)))
#define luna_inject(L, klass, t) (Luna<klass>::inject((L), (t)))

extern "C" 
{
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}

template<class T> class Luna 
{
  public:
    static void Register(lua_State *L) 
    {
      lua_pushcfunction(L, &Luna<T>::constructor);
      lua_setglobal(L, T::className); // T() in lua will make a new instance.

      RegisterMetatable(L);
    }

    // register the metatable without registering the class constructor
    static void RegisterMetatable(lua_State *L) 
    {
      luaL_newmetatable(L, T::className); // create a metatable in the registry
      lua_pushstring(L, "__gc");
      lua_pushcfunction(L, &Luna<T>::gc_obj);
      lua_settable(L, -3); // metatable["__gc"] = Luna<T>::gc_obj
      lua_pop(L, 1);
    }

    static int constructor(lua_State *L) 
    {
      return inject(L, new T(L));
    }

    static int inject(lua_State *L, T* obj) 
    {
      lua_newtable(L); // create a new table for the class object ('self')

      lua_pushnumber(L, 0);

      T** a = static_cast<T**>(lua_newuserdata(L, sizeof(T*))); // store a ptr to the ptr
      *a = obj; // set the ptr to the ptr to point to the ptr... >.>
      luaL_newmetatable(L, T::className); // get (or create) the unique metatable
      lua_setmetatable(L, -2); // self.metatable = uniqe_metatable

      lua_settable(L, -3); // self[0] = obj;

      for (int i = 0; T::Register[i].name; i++) 
      {
	// register the functions
        lua_pushstring(L, T::Register[i].name);
        lua_pushnumber(L, i); // let the thunk know which method we mean
        lua_pushcclosure(L, &Luna<T>::thunk, 1);
        lua_settable(L, -3); // self["function"] = thunk("function")
      }
      return 1;
    }

    static int thunk(lua_State *L) 
    {
      // redirect method call to the real thing
      int i = (int)lua_tonumber(L, lua_upvalueindex(1)); // which function?
      lua_pushnumber(L, 0);
      lua_gettable(L, 1); // get the class table (i.e, self)

      T** obj = static_cast<T**>(luaL_checkudata(L, -1, T::className));
      lua_remove(L, -1); // remove the userdata from the stack

      return ((*obj)->*(T::Register[i].mfunc))(L); // execute the thunk
    }

    static int gc_obj(lua_State *L) 
    {
      // clean up
      //printf("GC called: %s\n", T::className);
      T** obj = static_cast<T**>(luaL_checkudata(L, -1, T::className));
      delete (*obj);
      return 0;
    }

    struct RegType
    {
      const char *name;
      int(T::*mfunc)(lua_State*);
    };
};

/**
* A simple class pointer store
*/
template<class T> class Lun 
{
  private:
    static const char storeName[]; 
    
  public:
    static T* Get(lua_State* state)
    {
      	T* obj = 0;
	
	//access table
	lua_getglobal(state, Lun<T>::storeName);
	if (!lua_istable(state, -1))
	{
	    //not exist create new one
	    lua_newtable(state);
	    
	    //if not exist theres still no pointer create new one and got out
	    obj = new T(state);
	    
	    lua_pushstring(state, T::className);
	    //push ptr here
	    lua_pushlightuserdata(state, obj);
	    //T** a = static_cast<T**>(lua_newuserdata(state, sizeof(T*))); // store a ptr to the ptr
	    //*a = obj;
	    lua_settable(state, -3);

	    //set global store table
	    lua_setglobal(state, Lun<T>::storeName);	    
	    return obj;
	}
	
	
	//get field here
	lua_pushstring(state, T::className);
	//lua_gettable(state, -2);
	lua_rawget(state,-2);
	//no field create new one
	if(!lua_islightuserdata(state, -1))
	{
	    obj = new T(state);
	    lua_pushstring(state, T::className);
	    lua_pushlightuserdata(state, obj);
	    lua_settable(state, -3);
	    
	    return obj;
	}
	
	//lua_rawget(state,-2);
	obj = static_cast<T*>(lua_touserdata(state,-1));
	
	lua_pop(state, -1);
	
	//return obj
	return obj;
    }
    
};

template<class T> const char Lun<T>::storeName[] = "LunStore";



template<class T> class WrapClassFunction
{
  public:
    static void Register(lua_State* state, T* obj)
    {
	//TODO Check for Table
	
	for (int i = 0; T::Register[i].name; i++) 
	{
	  // register the functions
	  lua_pushstring(state, T::Register[i].name);
	  lua_pushlightuserdata(state, obj);
	  lua_pushnumber(state, i); // let the thunk know which method we mean
	  lua_pushcclosure(state, &WrapClassFunction<T>::dispatch, 2);
	  lua_settable(state, -3); // self["function"] = thunk("function")
	} 
    }
    
    /**
    * Dispatch to object
    */
    static int dispatch(lua_State *state) 
    {
	//get parameter 
	T* obj = static_cast<T*>(lua_touserdata(state, -2));
	int no = lua_tonumber(state, -1);
	
	//Execute Function
	return (obj->*(T::Register[no].mfunc))(state); 
    }
};

#endif // LUNA_H
