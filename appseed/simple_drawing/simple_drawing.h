#pragma once


#include "sphere/sphere/sphere.h"
#include "core/filesystem/filemanager/filemanager.h"
#include "core/user/userex/userex.h"
#include "core/user/html/html/html.h"
#include "app-core/appseed/gcom/gcom/gcom.h"

#ifdef _APP_SIMPLE_SIMPLE_DRAWING_LIBRARY
#define CLASS_DECL_APP_SIMPLE_SIMPLE_DRAWING  CLASS_DECL_EXPORT
#else
#define CLASS_DECL_APP_SIMPLE_SIMPLE_DRAWING  CLASS_DECL_IMPORT
#endif


namespace user
{

   typedef ::user::show < ::user::button > button_view;

} // namespace user


namespace simple_drawing
{

   class application;
   class main_view;
   class document;
   class view;

} // namespace flag


#undef App
#define App(papp) (*papp->cast < ::simple_drawing::application > ())


#include "simple_drawing_simple_drawing.h"


#include "simple_drawing_document.h"
#include "simple_drawing_view.h"
#include "simple_drawing_main_view.h"
#include "simple_drawing_frame.h"
#include "simple_drawing_main_frame.h"
#include "simple_drawing_pane_view_update_hint.h"
#include "simple_drawing_pane_view.h"


#include "simple_drawing_application.h"



