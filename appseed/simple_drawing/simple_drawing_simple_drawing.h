#pragma once


namespace simple_drawing
{


   class CLASS_DECL_APP_SIMPLE_SIMPLE_DRAWING simple_drawing :
      virtual public ::object
   {
   public:


      rect                    m_rect;
      ::user::impact *        m_pview;
      string                  m_strFont;


      simple_drawing(::aura::application * papp);
      virtual ~simple_drawing();


      virtual int64_t add_ref()
      {
         return ::object::add_ref();
      }
      virtual int64_t dec_ref()
      {
         return ::object::dec_ref();
      }

      virtual void _001OnBeatMapperDraw(::draw2d::graphics * pgraphics);

      virtual void on_layout();

   };


} // namespace simple_drawing


