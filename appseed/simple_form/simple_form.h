#pragma once


#include "sphere/sphere/sphere.h"
#include "core/filesystem/filemanager/filemanager.h"
#include "core/user/userex/userex.h"
#include "core/user/html/html/html.h"
#include "app-core/appseed/gcom/gcom/gcom.h"

#ifdef _APP_SIMPLE_SIMPLE_FORM_LIBRARY
#define CLASS_DECL_APP_SIMPLE_SIMPLE_FORM  CLASS_DECL_EXPORT
#else
#define CLASS_DECL_APP_SIMPLE_SIMPLE_FORM  CLASS_DECL_IMPORT
#endif


namespace user
{

   typedef ::user::show < ::user::button > button_view;

} // namespace user


namespace simple_form
{

   class application;
   class main_view;
   class document;
   class view;
   class pane_view;

} // namespace flag


#undef App
#define App(papp) (*papp->cast < ::simple_form::application > ())


#include "simple_form_simple_form.h"
#include "simple_form_simple_form_001.h"


#include "simple_form_document.h"
#include "simple_form_view.h"
#include "simple_form_main_view.h"
#include "simple_form_frame.h"
#include "simple_form_main_frame.h"
#include "simple_form_pane_view_update_hint.h"
#include "simple_form_pane_view.h"


#include "simple_form_application.h"



