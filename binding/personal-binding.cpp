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

//=============================================================================
// Personal Binding Init
//-----------------------------------------------------------------------------
//
//=============================================================================
void personalBindingInit(){
}
