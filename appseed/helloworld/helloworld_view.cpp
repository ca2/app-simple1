﻿#include "framework.h"
#include <math.h>


namespace helloworld
{


   view::view(::aura::application * papp) :
      ::object(papp)
   {


   }


   view::~view()
   {

   }


   void view::assert_valid() const
   {

      ::user::impact::assert_valid();

   }


   void view::dump(dump_context & dumpcontext) const
   {

      ::user::impact::dump(dumpcontext);

   }


   void view::install_message_handling(::message::dispatch * pdispatch)
   {

      ::user::impact::install_message_handling(pdispatch);

      IGUI_WIN_MSG_LINK(WM_CREATE,pdispatch,this,&view::_001OnCreate);

   }

   
   void view::_001OnCreate(signal_details * pobj)
   {

      SCAST_PTR(::message::create,pcreate,pobj);

      pcreate->previous();

      if(pcreate->m_bRet)
         return;

   }


   void view::on_update(::user::impact * pSender, LPARAM lHint, object* phint)
   {

      UNREFERENCED_PARAMETER(pSender);
      UNREFERENCED_PARAMETER(lHint);
      UNREFERENCED_PARAMETER(phint);

   }


   void view::_001OnDraw(::draw2d::graphics * pgraphics)
   {

      rect rectClient;

      GetClientRect(rectClient);

      ::draw2d::font_sp font(allocer());

      font->create_point_font(FONT_SANS, MIN(rectClient.height() / 5.0, rectClient.width() / 10.0), 800);

      pgraphics->SelectObject(font);

      pgraphics->draw_text("Hello World!!", rectClient, DT_CENTER | DT_VCENTER);

   }



} // namespace helloworld



