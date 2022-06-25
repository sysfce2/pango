/*
 * Copyright 2022 Red Hat, Inc.
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

#include "pango-language-set-private.h"
#include <fontconfig/fontconfig.h>


#define PANGO2_TYPE_FC_LANGUAGE_SET (pango2_fc_language_set_get_type ())

G_DECLARE_FINAL_TYPE (Pango2FcLanguageSet, pango2_fc_language_set, PANGO2, FC_LANGUAGE_SET, Pango2LanguageSet)

struct _Pango2FcLanguageSet
{
  Pango2LanguageSet parent_instance;

  FcLangSet *langs;
};

struct _Pango2FcLanguageSetClass
{
  Pango2LanguageSetClass parent_class;
};

Pango2FcLanguageSet *   pango2_fc_language_set_new       (FcLangSet                      *langs);

guint                   pango2_fc_language_set_hash      (const Pango2FcLanguageSet      *self);
gboolean                pango2_fc_language_set_equal     (const Pango2FcLanguageSet      *a,
                                                          const Pango2FcLanguageSet      *b);
