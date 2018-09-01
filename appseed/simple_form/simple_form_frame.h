﻿#pragma once


namespace simple_form
{


   class CLASS_DECL_APP_SIMPLE_SIMPLE_FORM frame :
      virtual public simple_frame_window
   {
   public:


      frame(::aura::application * papp);
      virtual ~frame();


	   virtual void assert_valid() const;
	   virtual void dump(dump_context & dumpcontext) const;


      virtual bool get_translucency(::user::e_translucency & etranslucency);


   };


} // namespace simple_form












