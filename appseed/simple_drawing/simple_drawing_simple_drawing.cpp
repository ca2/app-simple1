#include "framework.h"
#include <math.h>


namespace simple_drawing
{



   simple_drawing::simple_drawing(::aura::application * papp) :
      object(papp)
   {


      m_rect.null();


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

      pen->create_solid(4.0, ARGB(255, 50, 180, 255));

      rect rect;

      int iSize = MIN(m_rect.width(), m_rect.height());

      iSize = iSize * 3 / 4;

      rect.set_size(iSize, iSize);

      rect.Align(align_center, m_rect);

      brush->CreateLinearGradientBrush(rect.top_left(), rect.bottom_right(), ARGB(255, 255, 255, 200), ARGB(255, 255, 125, 100));

      pgraphics->SelectObject(pen);

      pgraphics->SelectObject(brush);

      pgraphics->Ellipse(rect);

   }


} // namespace simple_drawing


