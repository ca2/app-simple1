﻿#pragma once


namespace simple_form
{


   class CLASS_DECL_APP_SIMPLE_SIMPLE_FORM document :
      public ::user::document
   {
   public:


      document(::aura::application * papp);
	   virtual ~document();

      
	   virtual void assert_valid() const;
	   virtual void dump(dump_context & dumpcontext) const;

      virtual bool on_new_document();
      virtual bool on_open_document(var varFile);

      virtual int64_t add_ref();

      virtual int64_t dec_ref();


   };


} // namespace simple_form















