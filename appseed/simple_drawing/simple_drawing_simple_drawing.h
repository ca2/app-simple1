#pragma once


namespace simple_drawing
{


   class CLASS_DECL_APP_SIMPLE_SIMPLE_DRAWING simple_drawing :
      virtual public ::object
   {
   public:


      rect                                m_rect;
      ::user::impact *                    m_pview;
      string                              m_strFont;
      int                                 m_iDrawing;
      string_map < ::visual::dib_sp >     m_dibmap;


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

      virtual void _001OnDraw(::draw2d::graphics * pgraphics);

      virtual void _001OnDraw1Through3(::draw2d::graphics * pgraphics);

      virtual void _001OnDrawArcs(::draw2d::graphics * pgraphics, bool bPath);

      virtual void draw_arc(::draw2d::graphics * pgraphics, rect & r, double dStart, double dAngle, bool bPath);

      virtual void on_layout();

   };


} // namespace simple_drawing


