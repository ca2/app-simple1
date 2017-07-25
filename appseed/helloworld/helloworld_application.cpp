#include "framework.h"


namespace helloworld
{


   application::application()
   {

      m_strAppName                     = "app-simple/helloworld";
      m_strBaseSupportId               = "app-simple/helloworld";
      m_bLicense                       = false;
      m_pdocumenttemplate    = NULL;

   }


   application::~application()
   {

   }


   bool application::initialize_application()
   {

      System.factory().creatable_small < ::helloworld::document >();
      System.factory().creatable_small < ::helloworld::frame >();
      System.factory().creatable_small < ::helloworld::view >();

      if(!::core::application::initialize_application())
         return false;

      m_dataid += ".local://";

	   ::user::single_document_template* pdocumenttemplate;

      pdocumenttemplate = new ::user::single_document_template(
         this,
		   "main",
         System.type_info < ::helloworld::document > (),
		   System.type_info < ::helloworld::frame > (),
		   System.type_info < ::helloworld::view > ());

      add_document_template(pdocumenttemplate);

      m_pdocumenttemplate = pdocumenttemplate;

      return true;

   }


   int32_t application::exit_application()
   {

      return ::core::application::exit_application();

   }


   void application::on_request(::create * pcreate)
   {

      m_pdocumenttemplate->request_create(pcreate);

   }


} // namespace helloworld




extern "C"
::aura::library * app_simple_helloworld_get_new_library(::aura::application * papp)
{

   return new ::aura::single_application_library < ::helloworld::application >(papp, "app-simple/helloworld");

}


