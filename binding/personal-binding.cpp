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
RB_METHOD(fontGetDefaultSolid){
    RB_UNUSED_PARAM;
    Font *f = getPrivateData<Font>(self);
    return f->getDefaultSolid() ? Qtrue : Qfalse;
}
RB_METHOD(fontSetDefaultSolid){
    RB_UNUSED_PARAM;
    Font *f = getPrivateData<Font>(self);
    const bool *set;
    rb_get_args(argc, argv, "b", &set RB_ARG_END);
    f->setDefaultSolid(set);
    return Qnil;
}
//=============================================================================
// Font Get/Set Path
//-----------------------------------------------------------------------------
//  Alternative to the family name nonsense
//=============================================================================
RB_METHOD(fontGetPath){
    RB_UNUSED_PARAM;
    Font* f = getPrivateData<Font>(self);
    return rb_str_new_cstr(f->getPath().c_str());
}
RB_METHOD(fontSetPath){
    RB_UNUSED_PARAM;
    Font* f = getPrivateData<Font>(self);
    const char* filename = "";
    rb_get_args(argc, argv, "z", &filename RB_ARG_END);
    f->setPath(filename);
    return Qnil;
}
RB_METHOD(fontGetDefaultPath){
    RB_UNUSED_PARAM;
    Font* f = getPrivateData<Font>(self);
    return rb_str_new_cstr(f->getDefaultPath().c_str());
}
RB_METHOD(fontSetDefaultPath){
    RB_UNUSED_PARAM;
    Font* f = getPrivateData<Font>(self);
    const char* filename;
    rb_get_args(argc, argv, "z", &filename RB_ARG_END);
    f->setDefaultPath(filename);
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
  //  When true, font anti-aliasing is turned off, and you can see
  // the font's pixels completely unsmoothed
  //
  //  Defaults to false
  //=================================================================
  _rb_define_method(klass, "solid", fontGetSolid);
  _rb_define_method(klass, "solid=", fontSetSolid);
  //=================================================================
  // Default Solid Accessor
  //-----------------------------------------------------------------
  //  Manages font anti-aliasing globally
  //=================================================================
  rb_define_class_method(klass, "default_solid", fontGetDefaultSolid);
  rb_define_class_method(klass, "default_solid=", fontSetDefaultSolid);
  //=================================================================
  // Path
  //-----------------------------------------------------------------
  //  Gets/Sets the direct path of a font file, used as an alternative
  // for the horrible traumatizing trash rpgm called font family name
  // selector thingies
  //
  //  Also works for selecting fonts outside of .ttf format, but no
  // clue what the total supported formats are
  //=================================================================
  _rb_define_method(klass, "path", fontGetPath);
  _rb_define_method(klass, "path=", fontSetPath);
  //=================================================================
  // Default Path
  //=================================================================
  rb_define_class_method(klass, "default_path", fontGetDefaultPath);
  rb_define_class_method(klass, "default_path=", fontSetDefaultPath);
}

//=============================================================================
// Personal Binding Init
//=============================================================================
void personalBindingInit(){
  resizeBindingInit();
  fontsBindingInit();
}
