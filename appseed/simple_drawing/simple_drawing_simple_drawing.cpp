#include "framework.h"
#include <math.h>

CLASS_DECL_AURA COLORREF dk_red(); // <3 tbs

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

      if(m_iDrawing <= 3)
      {

         _001OnDraw1Through3(pgraphics);

      }
      else if(m_iDrawing == 4)
      {

         _001OnDrawArcs(pgraphics, false);

      }
      else
      {

         _001OnDrawArcs(pgraphics, true);

      }

   }


   void simple_drawing::_001OnDraw1Through3(::draw2d::graphics * pgraphics)
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

      if(m_iDrawing == 3)
      {

         brush->CreatePatternBrush(Application.dib("matter://pat1.jpg"));

      }
      else
      {

         brush->CreateLinearGradientBrush(rect.top_left(), rect.bottom_right(), ARGB(255, 255, 255, 200), ARGB(255, 255, 125, 100));

      }

      pgraphics->SelectObject(pen);

      pgraphics->SelectObject(brush);

      pgraphics->Ellipse(rect);

      if(m_iDrawing >= 2)
      {

         ::rect rectText(rect);

         rectText.inflate(100, 100);

         pgraphics->set_alpha_mode(::draw2d::alpha_mode_blend);

         if(m_iDrawing == 3)
         {

            if(m_dibmap["pat1grayed"].is_null())
            {

               auto dib = Application.dib("matter://pat1.jpg");

               ::draw2d::dib_sp dibClone = dib->clone()->cast < ::draw2d::dib >();

               m_dibmap["pat1grayed"] = dibClone;

               m_dibmap["pat1grayed"]->saturation(0.0);

            }

            brush->CreatePatternBrush(m_dibmap["pat1grayed"]);

         }
         else
         {

            brush->CreateLinearGradientBrush(rectText.top_left(), rectText.bottom_right(), ARGB(255, 55, 210, 120), ARGB(255, 255, 255, 200));

         }

         pgraphics->SelectObject(brush);

         pgraphics->draw_text("Simple Drawing", rectText, DT_CENTER | DT_VCENTER);

      }

   }


   void simple_drawing::_001OnDrawArcs(::draw2d::graphics * pgraphics, bool bPath)
   {

      pgraphics->set_alpha_mode(::draw2d::alpha_mode_blend);

      double_array daStart;

      double_array daAngle;

      daStart.add(0.0);
      daAngle.add(100.0);

      daStart.add(90.0);
      daAngle.add(100.0);

      daStart.add(180.0);
      daAngle.add(100.0);

      daStart.add(270.0);
      daAngle.add(100.0);

      daStart.add(-90.0);
      daAngle.add(100.0);

      daStart.add(-180.0);
      daAngle.add(100.0);

      daStart.add(-270.0);
      daAngle.add(100.0);

      daStart.add(45.0);
      daAngle.add(100.0);


      daStart.add(0.0);
      daAngle.add(-100.0);

      daStart.add(90.0);
      daAngle.add(-100.0);

      daStart.add(180.0);
      daAngle.add(-100.0);

      daStart.add(270.0);
      daAngle.add(-100.0);

      daStart.add(-90.0);
      daAngle.add(-100.0);

      daStart.add(-180.0);
      daAngle.add(-100.0);

      daStart.add(-270.0);
      daAngle.add(-100.0);

      daStart.add(45.0);
      daAngle.add(-100.0);

      ::rect rClient(m_rect);

      pgraphics->fill_solid_rect(rClient, ARGB(255, 192, 192, 185));

      int iColumnCount = 8;

      rect r;

      r.top = 0;

      r.left = 0;

      r.bottom = rClient.center().y;

      int i = 0;

      int iColumnWidth = rClient.width() / iColumnCount;

      for (i = 0; i < iColumnCount && i < daStart.get_size(); i++)
      {

         r.right = r.left + iColumnWidth;

         draw_arc(pgraphics, r, daStart[i], daAngle[i], bPath);

         r.left = r.right;

      }

      r.top = r.bottom;

      r.left = 0;

      r.bottom = rClient.bottom;

      for (; i < iColumnCount * 2 && i < daStart.get_size(); i++)
      {

         r.right = r.left + iColumnWidth;

         draw_arc(pgraphics, r, daStart[i], daAngle[i], bPath);

         r.left = r.right;

      }

   }


   void simple_drawing::draw_arc(::draw2d::graphics * pgraphics, rect & r, double dStart, double dAngle, bool bPath)
   {


      ::draw2d::font_sp font(allocer());

      font->create_point_font(FONT_SANS, 14.0, FW_LIGHT);

      pgraphics->set_text_color(ARGB(255, 0, 0, 0));

      pgraphics->SelectObject(font);

      string str;

      str.Format("Start: %d", dStart);

      pgraphics->text_out(r.left, r.top, str);

      str.Format("Angle: %d", dAngle);

      pgraphics->text_out(r.left, r.top + 20, str);

      ::draw2d::pen_sp pen(allocer());

      if (dAngle < 0.0)
      {

         if (bPath)
         {

            pen->create_solid(4.0, dk_red());

         }
         else
         {

            pen->create_solid(4.0, ARGB(255, 255, 230, 155));


         }

      }
      else
      {

         if (bPath)
         {

            pen->create_solid(4.0, ARGB(255, 255, 255, 255));

         }
         else
         {

            pen->create_solid(4.0, ARGB(255, 50, 180, 255));

         }

      }

      pgraphics->SelectObject(pen);

      pgraphics->Arc(r, dStart, dAngle);


   }



} // namespace simple_drawing


