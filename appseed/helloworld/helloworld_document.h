#pragma once

namespace helloworld
{

   class CLASS_DECL_APP_SIMPLE_HELLOWORLD document :
      public ::user::document
   {
   public:


      document(::aura::application * papp);
	   virtual ~document();

      
   #ifdef DEBUG
	   virtual void assert_valid() const;
	   virtual void dump(dump_context & dumpcontext) const;
   #endif

      virtual bool on_new_document();
      virtual bool on_open_document(var varFile);

   };

} // namespace helloworld