/*
 * Copyright (C) 1999 Red Hat Software
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

#include <glib.h>
#include <glib-object.h>

#include <pango/pango-types.h>
#include <pango/pango-version-macros.h>
#include <pango/pango-script.h>

G_BEGIN_DECLS

#define PANGO2_TYPE_LANGUAGE (pango2_language_get_type ())

PANGO2_AVAILABLE_IN_ALL
GType                   pango2_language_get_type                 (void) G_GNUC_CONST;

PANGO2_AVAILABLE_IN_ALL
Pango2Language *        pango2_language_get_default              (void) G_GNUC_CONST;

PANGO2_AVAILABLE_IN_ALL
Pango2Language **       pango2_language_get_preferred            (void) G_GNUC_CONST;

PANGO2_AVAILABLE_IN_ALL
Pango2Language *        pango2_language_from_string              (const char      *language);

PANGO2_AVAILABLE_IN_ALL
const char *            pango2_language_to_string                (Pango2Language  *language) G_GNUC_CONST;

/* For back compat.  Will have to keep indefinitely. */
#define pango2_language_to_string(language) ((const char *)language)

PANGO2_AVAILABLE_IN_ALL
const char *            pango2_language_get_sample_string        (Pango2Language  *language) G_GNUC_CONST;

PANGO2_AVAILABLE_IN_ALL
gboolean                pango2_language_matches                  (Pango2Language  *language,
                                                                  const char      *range_list) G_GNUC_PURE;

PANGO2_AVAILABLE_IN_ALL
gboolean                pango2_language_includes_script          (Pango2Language  *language,
                                                                  GUnicodeScript   script) G_GNUC_PURE;
PANGO2_AVAILABLE_IN_ALL
const GUnicodeScript *  pango2_language_get_scripts              (Pango2Language  *language,
                                                                  int             *num_scripts);

G_END_DECLS
