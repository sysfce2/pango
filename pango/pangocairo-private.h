/*
 * Copyright (C) 2000, 2004 Red Hat, Inc.
 *
 * SPDX-License-Identifier: LGPL-2.1-or-later
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include <pango/pangocairo.h>
#include <pango/pango-renderer.h>

#define PANGO_CAIRO_FONT_GET_IFACE(obj) (G_TYPE_INSTANCE_GET_INTERFACE ((obj), PANGO_TYPE_CAIRO_FONT, PangoCairoFontIface))

typedef struct _PangoCairoFontIface                  PangoCairoFontIface;
typedef struct _PangoCairoFontPrivate                PangoCairoFontPrivate;
typedef struct _HexBoxInfo                           PangoCairoFontHexBoxInfo;
typedef struct _PangoCairoFontPrivateScaledFontData  PangoCairoFontPrivateScaledFontData;
typedef struct _PangoCairoFontGlyphExtentsCacheEntry PangoCairoFontGlyphExtentsCacheEntry;

struct _PangoCairoFontPrivateScaledFontData
{
  cairo_matrix_t font_matrix;
  cairo_matrix_t ctm;
  cairo_font_options_t *options;
};

struct _PangoCairoFontPrivate
{
  PangoCairoFont *cfont;

  PangoCairoFontPrivateScaledFontData *data;

  cairo_scaled_font_t *scaled_font;
  PangoCairoFontHexBoxInfo *hbi;

  gboolean is_hinted;
  PangoGravity gravity;

  PangoRectangle font_extents;
  PangoCairoFontGlyphExtentsCacheEntry *glyph_extents_cache;

  GSList *metrics_by_lang;
};

struct _PangoCairoFontIface
{
  GTypeInterface g_iface;

  cairo_font_face_t *(*create_font_face) (PangoCairoFont *cfont);
  PangoFontMetrics *(*create_base_metrics_for_context) (PangoCairoFont *cfont,
                                                        PangoContext   *context);

  gssize cf_priv_offset;
};

gboolean _pango_cairo_font_install (PangoFont *font,
                                    cairo_t   *cr);
PangoFontMetrics * _pango_cairo_font_get_metrics (PangoFont     *font,
                                                  PangoLanguage *language);
PangoCairoFontHexBoxInfo *_pango_cairo_font_get_hex_box_info (PangoFont *font);
PangoCairoFontPrivate    *_pango_font_get_cairo_font_private (PangoFont *font);
cairo_scaled_font_t      *_pango_font_get_scaled_font        (PangoFont *font);

void _pango_cairo_font_private_initialize (PangoCairoFontPrivate      *cf_priv,
                                           PangoCairoFont             *font,
                                           PangoGravity                gravity,
                                           const cairo_font_options_t *font_options,
                                           const PangoMatrix          *pango_ctm,
                                           const cairo_matrix_t       *font_matrix);
void _pango_cairo_font_private_finalize (PangoCairoFontPrivate *cf_priv);
cairo_scaled_font_t *_pango_cairo_font_private_get_scaled_font (PangoCairoFontPrivate *cf_priv);
gboolean _pango_cairo_font_private_is_metrics_hinted (PangoCairoFontPrivate *cf_priv);
void _pango_cairo_font_private_get_glyph_extents (PangoCairoFontPrivate *cf_priv,
                                                  PangoGlyph             glyph,
                                                  PangoRectangle        *ink_rect,
                                                  PangoRectangle        *logical_rect);

#define PANGO_TYPE_CAIRO_RENDERER            (pango_cairo_renderer_get_type())
#define PANGO_CAIRO_RENDERER(object)         (G_TYPE_CHECK_INSTANCE_CAST ((object), PANGO_TYPE_CAIRO_RENDERER, PangoCairoRenderer))
#define PANGO_IS_CAIRO_RENDERER(object)      (G_TYPE_CHECK_INSTANCE_TYPE ((object), PANGO_TYPE_CAIRO_RENDERER))

typedef struct _PangoCairoRenderer PangoCairoRenderer;

_PANGO_EXTERN
GType pango_cairo_renderer_get_type    (void) G_GNUC_CONST;


const cairo_font_options_t *_pango_cairo_context_get_merged_font_options (PangoContext *context);
