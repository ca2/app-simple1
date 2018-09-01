#pragma once


namespace simple_form
{


   class CLASS_DECL_APP_SIMPLE_SIMPLE_FORM main_frame :
      virtual public ::sphere::main_frame
   {
   public:


      bool                       m_bExplicitTranslucency;


      main_frame(::aura::application * papp);
      virtual ~main_frame();


      virtual void assert_valid() const override;
      virtual void dump(dump_context & dumpcontext) const override;


      using ::sphere::main_frame::get_translucency;
      virtual bool get_translucency(::user::e_translucency & etranslucency, ::user::e_element eelement, ::user::style_context * pui) override;
      virtual sp(::user::wndfrm::frame::frame) create_frame_schema() override;

      virtual bool has_pending_graphical_update() override;

   };


} // namespace simple_form












