/*=============================================================================
Personal Bindings
-------------------------------------------------------------------------------
  All my OC bindings will be lazily thrown here to keep the original files as
 clean as possible

  Since this means I'll have to snatch modules after they're created, I'll need
 to figure out how to do that without relying on rb_define_module

  Maybe rb_const_get(rb_cObject, rb_intern(name)) will work, time to try
=============================================================================*/
#include "audio.h"
#include "sharedstate.h"
#include "binding-util.h"
#include "exception.h"

#include "graphics.h"

#include "font.h"

//=============================================================================
//=============================================================================
//=============================================================================

//=============================================================================
// Get Window Size
//=============================================================================
RB_METHOD(graphicsGetWindowWidth){
    RB_UNUSED_PARAM;
    return rb_fix_new(shState->graphics().windowWidth());
}
RB_METHOD(graphicsGetWindowHeight){
    RB_UNUSED_PARAM;
    return rb_fix_new(shState->graphics().windowHeight());
}
//=============================================================================
// Resize Binding Init
//=============================================================================
void resizeBindingInit(){
  VALUE module = rb_const_get(rb_cObject, rb_intern("Graphics"));
  //=================================================================
  // Window Size
  //-----------------------------------------------------------------
  //  Gets the physical size of the display window (?) (DPI???)
  //=================================================================
  _rb_define_module_function(module, "window_width", graphicsGetWindowWidth);
  _rb_define_module_function(module, "window_height", graphicsGetWindowHeight);
}

//=============================================================================
//=============================================================================
//=============================================================================

//=============================================================================
// Font Get/Set Solid
//-----------------------------------------------------------------------------
//  font-binding.cpp and font.cpp in general uses really complicated looking
// defines that my powerlevel isn't high enough to understand so I won't use
// those
//=============================================================================
RB_METHOD(fontGetSolid){
    RB_UNUSED_PARAM;
    Font *f = getPrivateData<Font>(self);
    return f->isSolid() ? Qtrue : Qfalse;
}
RB_METHOD(fontSetSolid){
    RB_UNUSED_PARAM;
    Font *f = getPrivateData<Font>(self);
    bool set = 0;
    rb_get_args(argc, argv, "b", &set RB_ARG_END);
    f->setSolid(set);
    return Qnil;
}
//=============================================================================
// Fonts Binding Init
//=============================================================================
void fontsBindingInit(){
  VALUE klass = rb_const_get(rb_cObject, rb_intern("Font"));
  //=================================================================
  // Solid Accessor
  //-----------------------------------------------------------------
  //  Enables/Disables font anti-aliasing
  //
  //  Works sometimes
  //
  //  Defaults to false
  //=================================================================
  _rb_define_method(klass, "solid", fontGetSolid);
  _rb_define_method(klass, "solid=", fontSetSolid);
}

//=============================================================================
// Personal Binding Init
//=============================================================================
void personalBindingInit(){
  resizeBindingInit();
  fontsBindingInit();
}
