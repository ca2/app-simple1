﻿#pragma once


namespace simple_form
{


   enum EPaneView
   {
      PaneViewNone,
      PaneViewMenu,
      PaneViewBeatMapper
   };


   class CLASS_DECL_APP_SIMPLE_SIMPLE_FORM pane_view_update_hint :
      public object
   {
   public:


      enum e_type
      {

         TypeNone,
         TypeGetView,
         TypeSetView,
         TypeOnShowKaraoke,
         TypeOnShowView,

      };

      EPaneView m_eview;
      e_type m_etype;


      pane_view_update_hint();
      virtual ~pane_view_update_hint();


      void set_type(e_type e_type);

      bool is_type_of(e_type e_type);


   };


} // namespace simple_form















