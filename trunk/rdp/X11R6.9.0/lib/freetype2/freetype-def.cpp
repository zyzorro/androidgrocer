LIBRARY libfreetype
VERSION LIBRARY_VERSION

EXPORTS
ah_arctan
autohint_module_class
;autohinter_interface
cff_driver_class
;FT_Access_Frame
#ifndef __UNIXOS2__
FT_Add64
#endif
FT_Add_Module
FT_Alloc
FT_Attach_File
FT_Attach_Stream
#ifndef __UNIXOS2__
FT_Create_Extensions
FT_Destroy_Extensions
FT_Div64by32
#endif
FT_DivFix
#ifndef __UNIXOS2__
FT_Done_Extensions
#endif
FT_Done_Face
FT_Done_GlyphSlot
FT_Done_Library
FT_Done_Size
#ifndef __UNIXOS2__
FT_Done_Stream
FT_Extract_Frame
FT_Forget_Frame
#endif
FT_Free
#ifndef __UNIXOS2__
FT_Get_Char
#endif
FT_Get_Char_Index
#ifndef __UNIXOS2__
FT_Get_Extension
#endif
FT_Get_Glyph_Name
FT_Get_Kerning
#ifndef __UNIXOS2__
FT_Get_Long
FT_Get_LongLE
#endif
FT_Get_Module
FT_Get_Module_Interface
#ifndef __UNIXOS2__
FT_Get_Offset
#endif
FT_Get_Renderer
FT_Get_Sfnt_Name
FT_Get_Sfnt_Name_Count
FT_Get_Sfnt_Table
#ifndef __UNIXOS2__
FT_Get_Short
FT_Get_ShortLE
#endif
FT_GlyphLoader_Add
#ifndef __UNIXOS2__
FT_GlyphLoader_Check_Points
FT_GlyphLoader_Check_Subglyphs
FT_GlyphLoader_Copy_Points
FT_GlyphLoader_Create_Extra
#endif
FT_GlyphLoader_Done
FT_GlyphLoader_New
FT_GlyphLoader_Prepare
FT_GlyphLoader_Reset
FT_GlyphLoader_Rewind
#ifndef __UNIXOS2__
FT_Init_Extensions
#endif
FT_List_Add
FT_List_Finalize
FT_List_Find
FT_List_Insert
FT_List_Iterate
FT_List_Remove
FT_List_Up
FT_Load_Char
FT_Load_Glyph
FT_Lookup_Renderer
FT_MulDiv
FT_MulFix
#ifndef __UNIXOS2__
FT_MulTo64
#endif
FT_New_Face
FT_New_GlyphSlot
FT_New_Library
FT_New_Memory_Face
#ifndef __UNIXOS2__
FT_New_Memory_Stream
#endif
FT_New_Size
FT_Open_Face
FT_Outline_Copy
FT_Outline_Decompose
FT_Outline_Done
FT_Outline_Done_Internal
FT_Outline_Get_Bitmap
FT_Outline_Get_CBox
FT_Outline_New
FT_Outline_New_Internal
FT_Outline_Render
FT_Outline_Reverse
FT_Outline_Transform
FT_Outline_Translate
#ifndef __UNIXOS2__
FT_Read_Char
FT_Read_Fields
FT_Read_Long
FT_Read_LongLE
FT_Read_Offset
FT_Read_Short
FT_Read_ShortLE
FT_Read_Stream
FT_Read_Stream_At
#endif
FT_Realloc
#ifndef __UNIXOS2__
FT_Register_Extension
FT_Release_Frame
#endif
FT_Remove_Module
FT_Render_Glyph
FT_Render_Glyph_Internal
#ifndef __UNIXOS2__
FT_Seek_Stream
#endif
FT_Select_Charmap
FT_Set_Char_Size
FT_Set_Charmap
FT_Set_Debug_Hook
FT_Set_Pixel_Sizes
FT_Set_Renderer
FT_Set_Transform
#ifndef __UNIXOS2__
FT_Skip_Stream
FT_Sqrt64
#endif
FT_SqrtFixed
FT_Stream_Pos
FT_Vector_Transform
FT_Outline_Get_BBox
FT_Done_Glyph
FT_Get_Glyph
FT_Glyph_Copy
FT_Glyph_Get_CBox
FT_Glyph_To_Bitmap
FT_Glyph_Transform
FT_Matrix_Invert
FT_Matrix_Multiply
ft_bitmap_glyph_class
ft_outline_glyph_class
FT_Add_Default_Modules
FT_Done_FreeType
FT_Init_FreeType
FT_Get_Multi_Master
FT_Set_MM_Blend_Coordinates
FT_Set_MM_Design_Coordinates
FT_Done_Memory
FT_New_Memory
#ifndef __UNIXOS2__
FT_New_Stream
_cygwin_dll_entry@12
_cygwin_noncygwin_dll_entry@12
dll_main@12
#endif
ps_table_funcs
psaux_module_class
t1_builder_funcs
t1_decoder_funcs
#ifndef __UNIXOS2__
t1_parser_funcs
#endif
psnames_module_class
ft_raster1_renderer_class
ft_raster5_renderer_class
ft_standard_raster
sbit_metrics_fields
sfnt_module_class
ft_grays_raster
ft_smooth_renderer_class
#ifndef __UNIXOS2__
TT_New_Context
TT_RunIns
tt_default_graphics_state
#endif
tt_driver_class
t1_driver_class
t1cid_driver_class
winfnt_driver_class
#ifdef __UNIXOS2__
FT_Get_First_Char
FT_Get_Next_Char
FT_Get_PS_Font_Info
FT_Has_PS_Glyph_Names
FT_Get_Name_Index
FT_Get_BDF_Property
FT_Activate_Size
FT_Get_X11_Font_Format
FT_Get_BDF_Charset_ID
FT_Get_Postscript_Name
#endif

/* $XFree86: xc/lib/freetype2/freetype-def.cpp,v 1.6 2003/11/06 03:25:41 dawes Exp $ */
