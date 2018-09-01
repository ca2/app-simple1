#pragma once


namespace simple_form
{


   class CLASS_DECL_APP_SIMPLE_SIMPLE_FORM simple_form_001 :
      virtual public simple_form
   {
   public:


      ::user::still                 m_still;
      ::user::plain_edit            m_edit;
      ::user::button                m_button;


      simple_form_001(::aura::application * papp);
      virtual ~simple_form_001();

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

      virtual void on_control_event(::user::control_event * pevent) override;


   };


} // namespace simple_form


