﻿#pragma once


namespace simple_drawing
{


   class CLASS_DECL_APP_SIMPLE_SIMPLE_DRAWING view :
      virtual public ::user::impact
   {
   public:


      sp(simple_drawing)       m_psimple_drawing;


      view(::aura::application * papp);
      virtual ~view();

      virtual void assert_valid() const;
      virtual void dump(dump_context & dumpcontext) const;

      virtual int64_t add_ref()
      {
         return ::object::add_ref();
      }
      virtual int64_t dec_ref()
      {
         return ::object::dec_ref();
      }

      virtual void install_message_routing(::message::sender * psender);

      virtual void _001OnDraw(::draw2d::graphics * pgraphics);

      virtual void on_update(::user::impact * pSender, LPARAM lHint, object* pHint);

      ::user::document * get_document();

      virtual void on_layout();

      DECL_GEN_SIGNAL(_001OnCreate);
      DECL_GEN_SIGNAL(_001OnDestroy);

   };


} // namespace simple_drawing


