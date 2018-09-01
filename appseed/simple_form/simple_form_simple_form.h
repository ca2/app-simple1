#pragma once


namespace simple_form
{


   class CLASS_DECL_APP_SIMPLE_SIMPLE_FORM simple_form :
      virtual public ::user::form_view
   {
   public:


      pane_view *                         m_ppaneview;
      string                              m_strFont;
      int                                 m_iId;


      simple_form(::aura::application * papp);
      virtual ~simple_form();

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

      DECL_GEN_SIGNAL(_001OnCreate);

      virtual void on_layout();

   };


} // namespace simple_form


