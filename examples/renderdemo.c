/* Pango
 * pangoft2topgm.c: Example program to view a UTF-8 encoding file
 *                  using Pango to render result.
 *
 * Copyright (C) 1999 Red Hat Software
 * Copyright (C) 2001 Sun Microsystems
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

#define BUFSIZE 1024
#define MALLOCSIZE 1024
#define DEFAULT_FONT_FAMILY "Sans"
#define DEFAULT_FONT_SIZE 36

#include <pango/pango.h>
#include <pango/pangoft2.h>

#include <errno.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static char *prog_name;
static PangoContext *context;

static gboolean opt_display = FALSE;
static int opt_dpi = 96;

#define _MAKE_FONT_NAME(family, size) family " " #size
#define MAKE_FONT_NAME(family, size) _MAKE_FONT_NAME(family, size)
static char *opt_font = MAKE_FONT_NAME (DEFAULT_FONT_FAMILY, DEFAULT_FONT_SIZE);

static  PangoDirection opt_dir = PANGO_DIRECTION_LTR;
static char *outfile_name;
static char *opt_output = NULL;
static int opt_margin = 10;
static int opt_markup = FALSE;
static  gboolean opt_waterfall = FALSE;

static void fail (const char *format, ...)  G_GNUC_PRINTF (1, 2);

static void
fail (const char *format, ...)
{
  const char *msg;
  
  va_list vap;
  va_start (vap, format);
  msg = g_strdup_vprintf (format, vap);
  g_printerr ("%s: %s\n", prog_name, msg);

  if (outfile_name && !opt_output)
    remove (outfile_name);
  
  exit (1);
}

static PangoLayout *
make_layout(PangoContext *context,
	    const char   *text,
	    double        size)
{
  static PangoFontDescription *font_description;
  PangoDirection base_dir;
  PangoLayout *layout;

  layout = pango_layout_new (context);
  if (opt_markup)
    pango_layout_set_markup (layout, text, -1);
  else
    pango_layout_set_text (layout, text, -1);

  font_description = pango_font_description_from_string (opt_font);

  if ((pango_font_description_get_set_fields (font_description) & PANGO_FONT_MASK_FAMILY) == 0)
    pango_font_description_set_family (font_description, DEFAULT_FONT_FAMILY);

  if (size > 0)
    pango_font_description_set_size (font_description, size * PANGO_SCALE);
  else if ((pango_font_description_get_set_fields (font_description) & PANGO_FONT_MASK_SIZE) == 0)
    pango_font_description_set_size (font_description, DEFAULT_FONT_SIZE * PANGO_SCALE);
    
  base_dir = pango_context_get_base_dir (context);
  pango_layout_set_alignment (layout,
			      base_dir == PANGO_DIRECTION_LTR ? PANGO_ALIGN_LEFT : PANGO_ALIGN_RIGHT);
  
  pango_layout_set_font_description (layout, font_description);
  pango_font_description_free (font_description);

  return layout;
}

static void
do_output (PangoContext *context,
	   const char   *text,
	   FT_Bitmap    *bitmap,
	   int          *width,
	   int          *height)
{
  PangoLayout *layout;
  PangoRectangle logical_rect;
  int x = opt_margin;
  int y = opt_margin;
  int size, start_size, end_size, increment;
  
  *width = 0;
  *height = 0;

  if (opt_waterfall)
    {
      start_size = 8;
      end_size = 48;
      increment = 4;
    }
  else
    {
      start_size = end_size = -1;
      increment = 1;
    }

  for (size = start_size; size <= end_size; size += increment)
    {
      layout = make_layout (context, text, size);
      pango_layout_get_extents (layout, NULL, &logical_rect);
      
      *width = MAX (*width, PANGO_PIXELS (logical_rect.width));
      *height += PANGO_PIXELS (logical_rect.height);
      
      if (bitmap)
	pango_ft2_render_layout (bitmap, layout, x, y);
      
      y += PANGO_PIXELS (logical_rect.height);

      g_object_unref (layout);
    }
  
  *width += 2 * opt_margin;
  *height += 2 * opt_margin;
}

int int_arg (const char *arg_name, const char *arg)
{
  char *end;
  long result = strtol (arg, &end, 0);
  if (*arg == '\0' || *end != '\0')
    {
      fail ("Cannot parse integer value '%s' for %s.",
	    arg, arg_name);
    }

  return result;
}

int main(int argc, char *argv[])
{
  FILE *outfile;
  char *text;
  size_t len;
  char *p;
  int argp;
  PangoFontMap *fontmap;
  GError *error = NULL;

  prog_name = g_path_get_basename (argv[0]);
  
  g_type_init();

  if (g_file_test ("./pangorc", G_FILE_TEST_EXISTS))
    putenv ("PANGO_RC_FILE=./pangorc");
  
  /* Parse command line */
  argp=1;
  while(argp < argc && argv[argp][0] == '-')
    {
      char *opt = argv[argp++];
      if (strcmp(opt, "--help") == 0)
	{
	  printf("%s - An example viewer for the pango ft2 extension\n"
		 "\n"
		 "Syntax:\n"
		 "    %s [options] FILE\n"
		 "\n"
		 "Options:\n"
 		 "    --display    Show output using ImageMagick rather than writing to a file.\n"
		 "    --dpi d      Set the dpi.Default is '%d'.\n"
		 "    --font       Set the font name. Default is '%s'.\n"
		 "    --margin m   Set the margin on the output in pixels. Default is %d.\n"
		 "    --markup     Interpret contents as Pango markup.\n"
 		 "    --output f   Name of output file [short form, -o].\n"
		 "    --rtl        Set base dir to RTL. Default is LTR.\n"
		 "    --waterfall  Create a waterfall display."
		 "    --width      Width of drawing window. Default is 500.\n",
		 prog_name, prog_name, opt_dpi, opt_font, opt_margin);
	  exit(0);
	}
      if (strcmp(opt, "--display") == 0)
	{
	  opt_display = TRUE;
	  continue;
	}
      if (strcmp(opt, "--dpi") == 0)
	{
	  opt_dpi = int_arg("--dpi", argv[argp++]);
	  continue;
	}
      if (strcmp(opt, "--font") == 0)
	{
	  opt_font = argv[argp++];
	  continue;
	}
      if (strcmp(opt, "--margin") == 0)
	{
	  opt_margin = int_arg("--margin", argv[argp++]);
	  continue;
	}
      if (strcmp(opt, "--markup") == 0)
	{
	  opt_markup = TRUE;
	  continue;
	}
      if (strcmp(opt, "--output") == 0 ||
	  strcmp(opt, "-o") == 0)
	{
	  opt_output = argv[argp++];
	  continue;
	}
      if (strcmp(opt, "--waterfall") == 0)
	{
	  opt_waterfall = TRUE;
	  continue;
	}
      if (strcmp(opt, "--rtl") == 0)
	{
	  opt_dir = PANGO_DIRECTION_RTL;
	  continue;
	}
      fail ("Unknown option %s!\n", opt);
    }
  if (!opt_display && !opt_output)
    {
      g_printerr ("%s: --output not specified, assuming --display\n", prog_name);
      opt_display = TRUE;
    }

  if (argp + 1 != argc)
    {
      g_printerr ("Usage: %s [options] FILE\n", prog_name);
      exit (1);
    }

  /* Get the text in the supplied file
   */
  if (!g_file_get_contents (argv[argp++], &text, &len, &error))
    fail ("%s\n", error->message);
  if (!g_utf8_validate (text, len, NULL))
    fail ("Text is not valid UTF-8");

  /* Strip trailing whitespace
   */
  p = text + len;
  while (p > text)
    {
      gunichar ch;
      p = g_utf8_prev_char (p);
      ch = g_utf8_get_char (p);
      if (!g_unichar_isspace (ch))
	break;
      else
	*p = '\0';
    }

  /* Make sure we have valid markup
   */
  if (opt_markup &&
      !pango_parse_markup (text, -1, 0, NULL, NULL, NULL, &error))
    fail ("Cannot parse input as markup: %s", error->message);

  if (opt_output)
    {
      outfile_name = opt_output;
      outfile = fopen (opt_output, "wb");

      if (!outfile)
	fail ("Cannot open output file %s: %s\n",
	      opt_output, g_strerror (errno));
    }
  else				/* --display */
    {
      /* This may need to be G_OS_UNIX guarded for fdopen */
      int fd = g_file_open_tmp ("pangoft2pgmXXXXXX", &outfile_name, &error);
      if (fd == 1)
	fail ("Cannot open temporary file: %s\n", error->message);
      outfile = fdopen (fd, "wb");
      if (!outfile)
	fail ("Cannot open temporary file: %s\n", g_strerror (errno));
    }

  fontmap = pango_ft2_font_map_new ();
  pango_ft2_font_map_set_resolution (PANGO_FT2_FONT_MAP (fontmap), opt_dpi, opt_dpi);
  context = pango_ft2_font_map_create_context (PANGO_FT2_FONT_MAP (fontmap));

  pango_context_set_language (context, pango_language_from_string ("en_US"));
  pango_context_set_base_dir (context, opt_dir);

  /* Write contents as pgm file */
  {
      FT_Bitmap bitmap;
      guchar *buf;
      int row;
      int width, height;

      do_output (context, text, NULL, &width, &height);
      
      bitmap.width = width;
      bitmap.pitch = (bitmap.width + 3) & ~3;
      bitmap.rows = height;
      buf = bitmap.buffer = g_malloc (bitmap.pitch * bitmap.rows);
      bitmap.num_grays = 256;
      bitmap.pixel_mode = ft_pixel_mode_grays;
      memset (buf, 0x00, bitmap.pitch * bitmap.rows);
	  
      do_output (context, text, &bitmap, &width, &height);
      
      /* Invert bitmap to get black text on white background */
      {
	int pix_idx;
	for (pix_idx=0; pix_idx<bitmap.pitch * bitmap.rows; pix_idx++)
	  {
	    buf[pix_idx] = 255-buf[pix_idx];
	  }
      }
      
      /* Write it as pgm to output */
      fprintf(outfile,
	      "P5\n"
	      "%d %d\n"
	      "255\n", bitmap.width, bitmap.rows);
      for (row = 0; row < bitmap.rows; row++)
	fwrite(bitmap.buffer + row * bitmap.pitch,
	       1, bitmap.width,
	       outfile);
      g_free (buf);
      if (fclose(outfile) == EOF)
	fail ("Error writing output file: %s\n", g_strerror (errno));

      if (opt_display)
	{
	  int exit_status;
	  gchar *command = g_strdup_printf ("display %s", outfile_name);
	  if (!g_spawn_command_line_sync (command, NULL, NULL, &exit_status, &error))
	    fail ("When running ImageMagick 'display' command: %s\n",
		  error->message);

	  g_free (command);
	  if (!opt_output)
	    remove (outfile_name);
	  
	  if (exit_status)
	    exit (1);
	}
    }

  return 0;
}
