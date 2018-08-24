#include "framework.h"
#include <math.h>


namespace simple_drawing
{



   simple_drawing::simple_drawing(::aura::application * papp) :
      object(papp)
   {


      m_rect.null();
      
      m_iDrawing = 1;


   }

   simple_drawing::~simple_drawing()
   {

   }



   void simple_drawing::on_layout()
   {


   }


   void simple_drawing::_001OnDraw(::draw2d::graphics * pgraphics)
   {

      ::draw2d::pen_sp pen(allocer());

      ::draw2d::brush_sp brush(allocer());
      
      ::draw2d::font_sp font(allocer());
      
      font->create_pixel_font(FONT_SANS_EX, 100.0, 800);
      
      pgraphics->selectFont(font);

      pen->create_solid(4.0, ARGB(255, 50, 180, 255));

      rect rect;

      int iSize = MIN(m_rect.width(), m_rect.height());

      iSize = iSize * 3 / 4;

      rect.set_size(iSize, iSize);

      rect.Align(align_center, m_rect);

      brush->CreateLinearGradientBrush(rect.top_left(), rect.bottom_right(), ARGB(255, 255, 255, 200), ARGB(255, 255, 125, 100));

      //auto & dib1 = Application.dib("/Users/camilo/Pictures/pat1.jpg");
      
      //pgraphics->set_text_color(ARGB(255, 55, 210, 120));
      
      //brush->CreatePatternBrush(dib1);

      pgraphics->SelectObject(pen);

      pgraphics->SelectObject(brush);

      pgraphics->Ellipse(rect);
      
      if(m_iDrawing >= 2)
      {
      
      ::rect rectText(rect);
      
      rectText.inflate(100, 100);
      
      brush->CreateLinearGradientBrush(rectText.top_left(), rectText.bottom_right(), ARGB(255, 55, 210, 120), ARGB(255, 230, 210, 100));
      
      pgraphics->SelectObject(brush);
      
      
      //auto & dib = Application.dib("/Users/camilo/Pictures/pat1.jpg");
      
      //pgraphics->set_text_color(ARGB(255, 55, 210, 120));
      
      //brush->CreatePatternBrush(dib);

      pgraphics->draw_text("Simple Drawing", rectText, DT_CENTER | DT_VCENTER);
         
      }

   }


} // namespace simple_drawing


