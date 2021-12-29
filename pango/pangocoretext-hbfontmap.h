/* Pango
 * pangocoretext-hbfontmap.h: Fontmap using coretext
 *
 * Copyright (C) 2021 Red Hat, Inc
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	 See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

#pragma once

#include <pango/pango.h>

G_BEGIN_DECLS

#define PANGO_TYPE_CORE_TEXT_HB_FONT_MAP      (pango_core_text_hb_font_map_get_type ())

PANGO_AVAILABLE_IN_1_52
PANGO_DECLARE_INTERNAL_TYPE (PangoCoreTextHbFontMap, pango_core_text_hb_font_map, PANGO, CORE_TEXT_HB_FONT_MAP, PangoHbFontMap)

PANGO_AVAILABLE_IN_1_52
PangoCoreTextHbFontMap * pango_core_text_hb_font_map_new (void);


G_END_DECLS
