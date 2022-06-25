/* Pango2
 *
 * Copyright (C) 2021 Red Hat, Inc.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

#include "config.h"

#include <gio/gio.h>

#include "pango-language-set-simple-private.h"

struct _Pango2LanguageSetSimple
{
  Pango2LanguageSet parent_instance;

  GHashTable *languages;
  Pango2Language **list;
};

G_DEFINE_TYPE (Pango2LanguageSetSimple, pango2_language_set_simple, PANGO2_TYPE_LANGUAGE_SET)

static void
pango2_language_set_simple_init (Pango2LanguageSetSimple *self)
{
  self->languages = g_hash_table_new (g_direct_hash, g_direct_equal);
}

static void
pango2_language_set_simple_finalize (GObject *object)
{
  Pango2LanguageSetSimple *self = PANGO2_LANGUAGE_SET_SIMPLE (object);

  g_hash_table_unref (self->languages);
  g_free (self->list);

  G_OBJECT_CLASS (pango2_language_set_simple_parent_class)->finalize (object);
}

static gboolean
pango2_language_set_simple_matches_language (Pango2LanguageSet *set,
                                             Pango2Language    *language)
{
  Pango2LanguageSetSimple *self = PANGO2_LANGUAGE_SET_SIMPLE (set);
  const char *s;

  if (g_hash_table_contains (self->languages, language))
    return TRUE;

  if (language == pango2_language_from_string ("c"))
    return TRUE;

  s = pango2_language_to_string (language);
  if (strchr (s, '-'))
    {
      char buf[10];

      for (int i = 0; i < 10; i++)
        {
          buf[i] = s[i];
          if (buf[i] == '-')
            {
              buf[i] = '\0';
              break;
            }
        }
      buf[9] = '\0';

      if (g_hash_table_contains (self->languages, pango2_language_from_string (buf)))
        return TRUE;
    }

  return FALSE;
}

static Pango2Language **
pango2_language_set_simple_get_languages (Pango2LanguageSet *set)
{
  Pango2LanguageSetSimple *self = PANGO2_LANGUAGE_SET_SIMPLE (set);

  if (!self->list)
    self->list = (Pango2Language **) g_hash_table_get_keys_as_array (self->languages, NULL);

  return self->list;
}

static void
pango2_language_set_simple_class_init (Pango2LanguageSetSimpleClass *class)
{
  GObjectClass *object_class = G_OBJECT_CLASS (class);
  Pango2LanguageSetClass *language_set_class = PANGO2_LANGUAGE_SET_CLASS (class);

  object_class->finalize = pango2_language_set_simple_finalize;
  language_set_class->matches_language = pango2_language_set_simple_matches_language;
  language_set_class->get_languages = pango2_language_set_simple_get_languages;
}

Pango2LanguageSetSimple *
pango2_language_set_simple_new (void)
{
  return g_object_new (PANGO2_TYPE_LANGUAGE_SET_SIMPLE, NULL);
}

void
pango2_language_set_simple_add_language (Pango2LanguageSetSimple *self,
                                         Pango2Language          *language)
{
  g_return_if_fail (self->list == NULL);

  g_hash_table_add (self->languages, language);
}
