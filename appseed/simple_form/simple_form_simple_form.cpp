#include "framework.h"
#include <math.h>


namespace simple_form
{


   simple_form::simple_form(::aura::application * papp) :
      object(papp)
   {

   }


   simple_form::~simple_form()
   {

   }


   void simple_form::assert_valid() const
   {

      ::user::form_view::assert_valid();

   }


   void simple_form::dump(dump_context & dumpcontext) const
   {

      ::user::form_view::dump(dumpcontext);

   }


   void simple_form::install_message_routing(::message::sender * psender)
   {

      ::user::form_view::install_message_routing(psender);

      IGUI_MSG_LINK(WM_CREATE, psender, this, &simple_form::_001OnCreate);

   }


   void simple_form::_001OnCreate(::message::message * pobj)
   {

      SCAST_PTR(::message::create, pcreate, pobj);

      pcreate->previous();

      if (pcreate->m_bRet)
      {

         return;

      }

   }


   void simple_form::on_layout()
   {

      ::user::form_view::on_layout();

   }


} // namespace simple_form



