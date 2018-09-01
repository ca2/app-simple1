#include "framework.h"
#include <math.h>


namespace simple_form
{



   simple_form_001::simple_form_001(::aura::application * papp) :
      object(papp),
      simple_form(papp),
      m_still(papp),
      m_edit(papp),
      m_button(papp)
   {

   }


   simple_form_001::~simple_form_001()
   {

   }


   void simple_form_001::assert_valid() const
   {

      simple_form::assert_valid();

   }


   void simple_form_001::dump(dump_context & dumpcontext) const
   {

      simple_form::dump(dumpcontext);

   }


   void simple_form_001::install_message_routing(::message::sender * psender)
   {

      simple_form::install_message_routing(psender);

      IGUI_MSG_LINK(WM_CREATE, psender, this, &simple_form_001::_001OnCreate);

   }


   void simple_form_001::_001OnCreate(::message::message * pobj)
   {

      SCAST_PTR(::message::create, pcreate, pobj);

      pcreate->previous();

      if (pcreate->m_bRet)
      {

         return;

      }

      m_still.create_window(null_rect(), this, "still");

      m_edit.create_window(null_rect(), this, "edit");

      m_button.create_window(null_rect(), this, "send_button");


      m_still.set_window_text("Enter new text:");

      m_edit.m_strEmtpyText = "Enter New Text Here";


      m_button.set_window_text("Send");


   }


   void simple_form_001::on_layout()
   {

      ::user::form_view::on_layout();

      int iLeft = 100;

      int y = 100;

      int iHeight = 25;

      m_still.SetWindowPos(ZORDER_TOP, iLeft, y, 200, iHeight, SWP_SHOWWINDOW);

      y += 30;

      m_edit.SetWindowPos(ZORDER_TOP, iLeft, y, 200, iHeight, SWP_SHOWWINDOW);

      y += 30;

      m_button.SetWindowPos(ZORDER_TOP, iLeft, y, 200, iHeight, SWP_SHOWWINDOW);

   }


   void simple_form_001::on_control_event(::user::control_event * pevent)
   {

      if (pevent->m_eevent == ::user::event_button_clicked)
      {

         if (pevent->m_id == "send_button")
         {

            string strText;

            m_edit._001GetText(strText);

            Application.simple_message_box(GetTopLevelFrame(), "send_button clicked\nText: " + strText);

         }

      }

   }


} // namespace simple_form



