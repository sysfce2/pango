/* == Start of generated table == */
/*
 * The following tables are generated by running:
 *
 *   ./gen-break-table.py SentenceBreakProperty.txt IndicSyllabicCategory.txt EastAsianWidth.txt | indent
 *
 * on files with these headers:
 *
 * # SentenceBreakProperty-14.0.0.txt
 * # Date: 2021-08-12, 23:13:21 GMT
 * # © 2021 Unicode®, Inc.
 * # Unicode and the Unicode Logo are registered trademarks of Unicode, Inc. in the U.S. and other countries.
 * # For terms of use, see http://www.unicode.org/terms_of_use.html
 * #
 * # Unicode Character Database
 * #   For documentation, see http://www.unicode.org/reports/tr44/
 * # IndicSyllabicCategory-14.0.0.txt
 * # Date: 2021-05-22, 01:01:00 GMT [KW, RP]
 * # © 2021 Unicode®, Inc.
 * # Unicode and the Unicode Logo are registered trademarks of Unicode, Inc. in the U.S. and other countries.
 * # For terms of use, see http://www.unicode.org/terms_of_use.html
 * #
 * # For documentation, see UAX #44: Unicode Character Database,
 * # at http://www.unicode.org/reports/tr44/
 * #
 * # This file defines the following property:
 * #
 * #    Indic_Syllabic_Category     enumerated property
 * #
 * # Scope: This property is aimed at two general problem
 * # areas involving the analysis and processing of Indic scripts:
 * #
 * #   1. Specification of syllabic structure.
 * #   2. Specification of segmentation rules.
 * #
 * # Both of these problem areas may benefit from having defined subtypes
 * # of Indic script characters which are relevant to how Indic
 * # syllables (or aksaras) are constructed. Note that rules for
 * # syllabic structure in Indic scripts may differ significantly
 * # from how phonological syllables are defined.
 * #
 * # Format:
 * #    Field 0  Unicode code point value or range of code point values
 * #    Field 1  Indic_Syllabic_Category property value
 * #
 * # Field 1 is followed by a comment field, starting with the number sign '#',
 * # which shows the General_Category property value, the Unicode character name
 * # or names, and, in lines with ranges of code points, the code point count in
 * # square brackets.
 * #
 * # The scripts assessed as Indic in the structural sense used for the
 * # Indic_Syllabic_Category are the following:
 * #
 * # Ahom, Balinese, Batak, Bengali, Bhaiksuki, Brahmi, Buginese, Buhid,
 * # Chakma, Cham, Devanagari, Dives Akuru, Dogra, Grantha, Gujarati,
 * # Gunjala Gondi, Gurmukhi, Hanunoo, Javanese, Kaithi, Kannada,
 * # Kayah Li, Kharoshthi, Khmer, Khojki, Khudawadi, Lao, Lepcha, Limbu,
 * # Mahajani, Makasar, Malayalam, Marchen, Masaram Gondi, Meetei Mayek,
 * # Modi, Multani, Myanmar, Nandinagari, Newa, New Tai Lue, Oriya,
 * # Phags-pa, Rejang, Saurashtra, Sharada, Siddham, Sinhala, Soyombo,
 * # Sundanese, Syloti Nagri, Tagalog, Tagbanwa, Tai Le, Tai Tham,
 * # Tai Viet, Takri, Tamil, Telugu, Thai, Tibetan, Tirhuta, and
 * # Zanabazar Square.
 * #
 * # All characters for all other scripts not in that list
 * # take the default value for this property, unless they
 * # are individually listed in this data file.
 * #
 * # EastAsianWidth-14.0.0.txt
 * # Date: 2021-07-06, 09:58:53 GMT [KW, LI]
 * # © 2021 Unicode®, Inc.
 * # Unicode and the Unicode Logo are registered trademarks of Unicode, Inc. in the U.S. and other countries.
 * # For terms of use, see https://www.unicode.org/terms_of_use.html
 * #
 * # Unicode Character Database
 * # For documentation, see https://www.unicode.org/reports/tr44/
 * #
 * # East_Asian_Width Property
 * #
 * # This file is a normative contributory data file in the
 * # Unicode Character Database.
 * #
 * # The format is two fields separated by a semicolon.
 * # Field 0: Unicode code point value or range of code point values
 * # Field 1: East_Asian_Width property, consisting of one of the following values:
 * #         "A", "F", "H", "N", "Na", "W"
 * #  - All code points, assigned or unassigned, that are not listed
 * #      explicitly are given the value "N".
 * #  - The unassigned code points in the following blocks default to "W":
 * #         CJK Unified Ideographs Extension A: U+3400..U+4DBF
 * #         CJK Unified Ideographs:             U+4E00..U+9FFF
 * #         CJK Compatibility Ideographs:       U+F900..U+FAFF
 * #  - All undesignated code points in Planes 2 and 3, whether inside or
 * #      outside of allocated blocks, default to "W":
 * #         Plane 2:                            U+20000..U+2FFFD
 * #         Plane 3:                            U+30000..U+3FFFD
 * #
 * # Character ranges are specified as for other property files in the
 * # Unicode Character Database.
 * #
 * # For legacy reasons, there are no spaces before or after the semicolon
 * # which separates the two fields. The comments following the number sign
 * # "#" list the General_Category property value or the L& alias of the
 * # derived value LC, the Unicode character name or names, and, in lines
 * # with ranges of code points, the code point count in square brackets.
 * #
 * # For more information, see UAX #11: East Asian Width,
 * # at https://www.unicode.org/reports/tr11/
 * #
 * # @missing: 0000..10FFFF; N
 */

#ifndef PANGO2_BREAK_TABLE_H
#define PANGO2_BREAK_TABLE_H

#include <glib.h>


static inline gboolean
_pango2_is_STerm (gunichar wc)
{
  if ((wc >= 0x0021 && wc <= 0x1945))
    {
      if (wc == 0x0021 ||
	  wc == 0x003F || wc == 0x0589 || (wc >= 0x061D && wc <= 0x061F))
	return TRUE;
      if ((wc >= 0x06D4 && wc <= 0x0839))
	{
	  if (wc == 0x06D4)
	    return TRUE;
	  if ((wc >= 0x0700 && wc <= 0x0702))
	    return TRUE;
	  if (wc == 0x07F9)
	    return TRUE;
	  if (wc == 0x0837 || wc == 0x0839)
	    return TRUE;
	  return FALSE;
	}
      if ((wc >= 0x083D && wc <= 0x083E) ||
	  (wc >= 0x0964 && wc <= 0x0965) ||
	  (wc >= 0x104A && wc <= 0x104B) || wc == 0x1362)
	return TRUE;
      if ((wc >= 0x1367 && wc <= 0x1945))
	{
	  if ((wc >= 0x1367 && wc <= 0x1368))
	    return TRUE;
	  if (wc == 0x166E || (wc >= 0x1735 && wc <= 0x1736))
	    return TRUE;
	  if (wc == 0x1803)
	    return TRUE;
	  if (wc == 0x1809 || (wc >= 0x1944 && wc <= 0x1945))
	    return TRUE;
	  return FALSE;
	}
      return FALSE;
    }
  if ((wc >= 0x1AA8 && wc <= 0xA92F))
    {
      if ((wc >= 0x1AA8 && wc <= 0x1AAB) ||
	  (wc >= 0x1B5A && wc <= 0x1B5B) ||
	  (wc >= 0x1B5E && wc <= 0x1B5F) || (wc >= 0x1B7D && wc <= 0x1B7E))
	return TRUE;
      if ((wc >= 0x1C3B && wc <= 0x2E2E))
	{
	  if ((wc >= 0x1C3B && wc <= 0x1C3C))
	    return TRUE;
	  if ((wc >= 0x1C7E && wc <= 0x1C7F))
	    return TRUE;
	  if ((wc >= 0x203C && wc <= 0x203D))
	    return TRUE;
	  if ((wc >= 0x2047 && wc <= 0x2049) || wc == 0x2E2E)
	    return TRUE;
	  return FALSE;
	}
      if (wc == 0x2E3C ||
	  (wc >= 0x2E53 && wc <= 0x2E54) || wc == 0x3002 || wc == 0xA4FF)
	return TRUE;
      if ((wc >= 0xA60E && wc <= 0xA92F))
	{
	  if ((wc >= 0xA60E && wc <= 0xA60F))
	    return TRUE;
	  if (wc == 0xA6F3 || wc == 0xA6F7)
	    return TRUE;
	  if ((wc >= 0xA876 && wc <= 0xA877))
	    return TRUE;
	  if ((wc >= 0xA8CE && wc <= 0xA8CF) || wc == 0xA92F)
	    return TRUE;
	  return FALSE;
	}
      return FALSE;
    }
  if ((wc >= 0xA9C8 && wc <= 0x1123C))
    {
      if ((wc >= 0xA9C8 && wc <= 0xA9C9) ||
	  (wc >= 0xAA5D && wc <= 0xAA5F) ||
	  (wc >= 0xAAF0 && wc <= 0xAAF1) || wc == 0xABEB)
	return TRUE;
      if ((wc >= 0xFE56 && wc <= 0x10A57))
	{
	  if ((wc >= 0xFE56 && wc <= 0xFE57))
	    return TRUE;
	  if (wc == 0xFF01)
	    return TRUE;
	  if (wc == 0xFF1F)
	    return TRUE;
	  if (wc == 0xFF61 || (wc >= 0x10A56 && wc <= 0x10A57))
	    return TRUE;
	  return FALSE;
	}
      if ((wc >= 0x10F55 && wc <= 0x10F59) ||
	  (wc >= 0x10F86 && wc <= 0x10F89) ||
	  (wc >= 0x11047 && wc <= 0x11048) ||
	  (wc >= 0x110BE && wc <= 0x110C1))
	return TRUE;
      if ((wc >= 0x11141 && wc <= 0x1123C))
	{
	  if ((wc >= 0x11141 && wc <= 0x11143))
	    return TRUE;
	  if ((wc >= 0x111C5 && wc <= 0x111C6) || wc == 0x111CD)
	    return TRUE;
	  if ((wc >= 0x111DE && wc <= 0x111DF))
	    return TRUE;
	  if ((wc >= 0x11238 && wc <= 0x11239) ||
	      (wc >= 0x1123B && wc <= 0x1123C))
	    return TRUE;
	  return FALSE;
	}
      return FALSE;
    }
  if ((wc >= 0x112A9 && wc <= 0x1DA88))
    {
      if (wc == 0x112A9 ||
	  (wc >= 0x1144B && wc <= 0x1144C) ||
	  (wc >= 0x115C2 && wc <= 0x115C3) ||
	  (wc >= 0x115C9 && wc <= 0x115D7))
	return TRUE;
      if ((wc >= 0x11641 && wc <= 0x11A43))
	{
	  if ((wc >= 0x11641 && wc <= 0x11642))
	    return TRUE;
	  if ((wc >= 0x1173C && wc <= 0x1173E))
	    return TRUE;
	  if (wc == 0x11944)
	    return TRUE;
	  if (wc == 0x11946 || (wc >= 0x11A42 && wc <= 0x11A43))
	    return TRUE;
	  return FALSE;
	}
      if ((wc >= 0x11A9B && wc <= 0x11A9C) ||
	  (wc >= 0x11C41 && wc <= 0x11C42) ||
	  (wc >= 0x11EF7 && wc <= 0x11EF8) ||
	  (wc >= 0x16A6E && wc <= 0x16A6F))
	return TRUE;
      if ((wc >= 0x16AF5 && wc <= 0x1DA88))
	{
	  if (wc == 0x16AF5)
	    return TRUE;
	  if ((wc >= 0x16B37 && wc <= 0x16B38) || wc == 0x16B44)
	    return TRUE;
	  if (wc == 0x16E98)
	    return TRUE;
	  if (wc == 0x1BC9F || wc == 0x1DA88)
	    return TRUE;
	  return FALSE;
	}
      return FALSE;
    }
  return FALSE;
}

static inline gboolean
_pango2_is_Virama (gunichar wc)
{
  if ((wc >= 0x094D && wc <= 0x0BCD))
    {
      if (wc == 0x094D)
	return TRUE;
      if (wc == 0x09CD || wc == 0x0A4D)
	return TRUE;
      if (wc == 0x0ACD)
	return TRUE;
      if (wc == 0x0B4D || wc == 0x0BCD)
	return TRUE;
      return FALSE;
    }
  if ((wc >= 0x0C4D && wc <= 0xA8C4))
    {
      if (wc == 0x0C4D)
	return TRUE;
      if (wc == 0x0CCD || wc == 0x0D4D)
	return TRUE;
      if (wc == 0x0DCA)
	return TRUE;
      if (wc == 0x1B44 || wc == 0xA806 || wc == 0xA8C4)
	return TRUE;
      return FALSE;
    }
  if ((wc >= 0xA9C0 && wc <= 0x1134D))
    {
      if (wc == 0xA9C0)
	return TRUE;
      if (wc == 0x11046 || wc == 0x110B9)
	return TRUE;
      if (wc == 0x111C0)
	return TRUE;
      if (wc == 0x11235 || wc == 0x1134D)
	return TRUE;
      return FALSE;
    }
  if ((wc >= 0x11442 && wc <= 0x11C3F))
    {
      if (wc == 0x11442 || wc == 0x114C2)
	return TRUE;
      if (wc == 0x115BF || wc == 0x1163F)
	return TRUE;
      if (wc == 0x116B6 || wc == 0x11839)
	return TRUE;
      if (wc == 0x119E0 || wc == 0x11C3F)
	return TRUE;
      return FALSE;
    }
  return FALSE;
}

static inline gboolean
_pango2_is_Vowel_Dependent (gunichar wc)
{
  if ((wc >= 0x093A && wc <= 0x0CC8))
    {
      if ((wc >= 0x093A && wc <= 0x09CC))
	{
	  if ((wc >= 0x093A && wc <= 0x093B) ||
	      (wc >= 0x093E && wc <= 0x094C))
	    return TRUE;
	  if ((wc >= 0x094E && wc <= 0x094F) ||
	      (wc >= 0x0955 && wc <= 0x0957))
	    return TRUE;
	  if ((wc >= 0x0962 && wc <= 0x0963) ||
	      (wc >= 0x09BE && wc <= 0x09C4))
	    return TRUE;
	  if ((wc >= 0x09C7 && wc <= 0x09C8) ||
	      (wc >= 0x09CB && wc <= 0x09CC))
	    return TRUE;
	  return FALSE;
	}
      if ((wc >= 0x09D7 && wc <= 0x0ACC))
	{
	  if (wc == 0x09D7 || (wc >= 0x09E2 && wc <= 0x09E3))
	    return TRUE;
	  if ((wc >= 0x0A3E && wc <= 0x0A42) ||
	      (wc >= 0x0A47 && wc <= 0x0A48))
	    return TRUE;
	  if ((wc >= 0x0A4B && wc <= 0x0A4C) ||
	      (wc >= 0x0ABE && wc <= 0x0AC5))
	    return TRUE;
	  if ((wc >= 0x0AC7 && wc <= 0x0AC9) ||
	      (wc >= 0x0ACB && wc <= 0x0ACC))
	    return TRUE;
	  return FALSE;
	}
      if ((wc >= 0x0AE2 && wc <= 0x0BC8))
	{
	  if ((wc >= 0x0AE2 && wc <= 0x0AE3) ||
	      (wc >= 0x0B3E && wc <= 0x0B44))
	    return TRUE;
	  if ((wc >= 0x0B47 && wc <= 0x0B48) ||
	      (wc >= 0x0B4B && wc <= 0x0B4C))
	    return TRUE;
	  if ((wc >= 0x0B55 && wc <= 0x0B57) ||
	      (wc >= 0x0B62 && wc <= 0x0B63))
	    return TRUE;
	  if ((wc >= 0x0BBE && wc <= 0x0BC2) ||
	      (wc >= 0x0BC6 && wc <= 0x0BC8))
	    return TRUE;
	  return FALSE;
	}
      if ((wc >= 0x0BCA && wc <= 0x0CC8))
	{
	  if ((wc >= 0x0BCA && wc <= 0x0BCC) || wc == 0x0BD7)
	    return TRUE;
	  if ((wc >= 0x0C3E && wc <= 0x0C44) ||
	      (wc >= 0x0C46 && wc <= 0x0C48))
	    return TRUE;
	  if ((wc >= 0x0C4A && wc <= 0x0C4C) ||
	      (wc >= 0x0C55 && wc <= 0x0C56))
	    return TRUE;
	  if ((wc >= 0x0C62 && wc <= 0x0C63) ||
	      (wc >= 0x0CBE && wc <= 0x0CC4) ||
	      (wc >= 0x0CC6 && wc <= 0x0CC8))
	    return TRUE;
	  return FALSE;
	}
      return FALSE;
    }
  if ((wc >= 0x0CCA && wc <= 0x1928))
    {
      if ((wc >= 0x0CCA && wc <= 0x0D63))
	{
	  if ((wc >= 0x0CCA && wc <= 0x0CCC) ||
	      (wc >= 0x0CD5 && wc <= 0x0CD6))
	    return TRUE;
	  if ((wc >= 0x0CE2 && wc <= 0x0CE3) ||
	      (wc >= 0x0D3E && wc <= 0x0D44))
	    return TRUE;
	  if ((wc >= 0x0D46 && wc <= 0x0D48) ||
	      (wc >= 0x0D4A && wc <= 0x0D4C))
	    return TRUE;
	  if (wc == 0x0D57 || (wc >= 0x0D62 && wc <= 0x0D63))
	    return TRUE;
	  return FALSE;
	}
      if ((wc >= 0x0DCF && wc <= 0x0EBB))
	{
	  if ((wc >= 0x0DCF && wc <= 0x0DD4) || wc == 0x0DD6)
	    return TRUE;
	  if ((wc >= 0x0DD8 && wc <= 0x0DDF) ||
	      (wc >= 0x0DF2 && wc <= 0x0DF3))
	    return TRUE;
	  if ((wc >= 0x0E30 && wc <= 0x0E39) ||
	      (wc >= 0x0E40 && wc <= 0x0E45))
	    return TRUE;
	  if (wc == 0x0E47 || (wc >= 0x0EB0 && wc <= 0x0EB9) || wc == 0x0EBB)
	    return TRUE;
	  return FALSE;
	}
      if ((wc >= 0x0EC0 && wc <= 0x1074))
	{
	  if ((wc >= 0x0EC0 && wc <= 0x0EC4) ||
	      (wc >= 0x0F71 && wc <= 0x0F7D))
	    return TRUE;
	  if ((wc >= 0x0F80 && wc <= 0x0F81) ||
	      (wc >= 0x102B && wc <= 0x1035))
	    return TRUE;
	  if ((wc >= 0x1056 && wc <= 0x1059) || wc == 0x1062)
	    return TRUE;
	  if ((wc >= 0x1067 && wc <= 0x1068) ||
	      (wc >= 0x1071 && wc <= 0x1074))
	    return TRUE;
	  return FALSE;
	}
      if ((wc >= 0x1083 && wc <= 0x1928))
	{
	  if ((wc >= 0x1083 && wc <= 0x1086) ||
	      (wc >= 0x109C && wc <= 0x109D))
	    return TRUE;
	  if ((wc >= 0x1712 && wc <= 0x1713) ||
	      (wc >= 0x1732 && wc <= 0x1733))
	    return TRUE;
	  if ((wc >= 0x1752 && wc <= 0x1753) ||
	      (wc >= 0x1772 && wc <= 0x1773))
	    return TRUE;
	  if ((wc >= 0x17B6 && wc <= 0x17C5) ||
	      wc == 0x17C8 || (wc >= 0x1920 && wc <= 0x1928))
	    return TRUE;
	  return FALSE;
	}
      return FALSE;
    }
  if ((wc >= 0x193A && wc <= 0x112E8))
    {
      if ((wc >= 0x193A && wc <= 0x1C2C))
	{
	  if (wc == 0x193A || (wc >= 0x19B0 && wc <= 0x19C0))
	    return TRUE;
	  if ((wc >= 0x1A17 && wc <= 0x1A1B) ||
	      (wc >= 0x1A61 && wc <= 0x1A73))
	    return TRUE;
	  if ((wc >= 0x1B35 && wc <= 0x1B43) ||
	      (wc >= 0x1BA4 && wc <= 0x1BA9))
	    return TRUE;
	  if ((wc >= 0x1BE7 && wc <= 0x1BEF) ||
	      (wc >= 0x1C26 && wc <= 0x1C2C))
	    return TRUE;
	  return FALSE;
	}
      if ((wc >= 0xA802 && wc <= 0xAA32))
	{
	  if (wc == 0xA802 || (wc >= 0xA823 && wc <= 0xA827))
	    return TRUE;
	  if ((wc >= 0xA8B5 && wc <= 0xA8C3) || wc == 0xA8FF)
	    return TRUE;
	  if ((wc >= 0xA947 && wc <= 0xA94E) ||
	      (wc >= 0xA9B4 && wc <= 0xA9BC))
	    return TRUE;
	  if (wc == 0xA9E5 || (wc >= 0xAA29 && wc <= 0xAA32))
	    return TRUE;
	  return FALSE;
	}
      if ((wc >= 0xAAB0 && wc <= 0x11074))
	{
	  if ((wc >= 0xAAB0 && wc <= 0xAABE) ||
	      (wc >= 0xAAEB && wc <= 0xAAEF))
	    return TRUE;
	  if ((wc >= 0xABE3 && wc <= 0xABEA) ||
	      (wc >= 0x10A01 && wc <= 0x10A03))
	    return TRUE;
	  if ((wc >= 0x10A05 && wc <= 0x10A06) ||
	      (wc >= 0x10A0C && wc <= 0x10A0D))
	    return TRUE;
	  if ((wc >= 0x11038 && wc <= 0x11045) ||
	      (wc >= 0x11073 && wc <= 0x11074))
	    return TRUE;
	  return FALSE;
	}
      if ((wc >= 0x110B0 && wc <= 0x112E8))
	{
	  if ((wc >= 0x110B0 && wc <= 0x110B8) || wc == 0x110C2)
	    return TRUE;
	  if ((wc >= 0x11127 && wc <= 0x11132) ||
	      (wc >= 0x11145 && wc <= 0x11146))
	    return TRUE;
	  if ((wc >= 0x111B3 && wc <= 0x111BF) ||
	      (wc >= 0x111CB && wc <= 0x111CC))
	    return TRUE;
	  if (wc == 0x111CE ||
	      (wc >= 0x1122C && wc <= 0x11233) ||
	      (wc >= 0x112E0 && wc <= 0x112E8))
	    return TRUE;
	  return FALSE;
	}
      return FALSE;
    }
  if ((wc >= 0x1133E && wc <= 0x11EF6))
    {
      if ((wc >= 0x1133E && wc <= 0x115B5))
	{
	  if ((wc >= 0x1133E && wc <= 0x11344) ||
	      (wc >= 0x11347 && wc <= 0x11348))
	    return TRUE;
	  if ((wc >= 0x1134B && wc <= 0x1134C) || wc == 0x11357)
	    return TRUE;
	  if ((wc >= 0x11362 && wc <= 0x11363) ||
	      (wc >= 0x11435 && wc <= 0x11441))
	    return TRUE;
	  if ((wc >= 0x114B0 && wc <= 0x114BE) ||
	      (wc >= 0x115AF && wc <= 0x115B5))
	    return TRUE;
	  return FALSE;
	}
      if ((wc >= 0x115B8 && wc <= 0x11938))
	{
	  if ((wc >= 0x115B8 && wc <= 0x115BB) ||
	      (wc >= 0x115DC && wc <= 0x115DD))
	    return TRUE;
	  if ((wc >= 0x11630 && wc <= 0x1163C) || wc == 0x11640)
	    return TRUE;
	  if ((wc >= 0x116AD && wc <= 0x116B5) ||
	      (wc >= 0x11720 && wc <= 0x1172A))
	    return TRUE;
	  if ((wc >= 0x1182C && wc <= 0x11836) ||
	      (wc >= 0x11930 && wc <= 0x11935) ||
	      (wc >= 0x11937 && wc <= 0x11938))
	    return TRUE;
	  return FALSE;
	}
      if ((wc >= 0x119D1 && wc <= 0x11CB4))
	{
	  if ((wc >= 0x119D1 && wc <= 0x119D7) ||
	      (wc >= 0x119DA && wc <= 0x119DD))
	    return TRUE;
	  if (wc == 0x119E4 || (wc >= 0x11A01 && wc <= 0x11A0A))
	    return TRUE;
	  if ((wc >= 0x11A51 && wc <= 0x11A5B) ||
	      (wc >= 0x11C2F && wc <= 0x11C36))
	    return TRUE;
	  if ((wc >= 0x11C38 && wc <= 0x11C3B) ||
	      (wc >= 0x11CB0 && wc <= 0x11CB4))
	    return TRUE;
	  return FALSE;
	}
      if ((wc >= 0x11D31 && wc <= 0x11EF6))
	{
	  if ((wc >= 0x11D31 && wc <= 0x11D36) || wc == 0x11D3A)
	    return TRUE;
	  if ((wc >= 0x11D3C && wc <= 0x11D3D) || wc == 0x11D3F)
	    return TRUE;
	  if (wc == 0x11D43 || (wc >= 0x11D8A && wc <= 0x11D8E))
	    return TRUE;
	  if ((wc >= 0x11D90 && wc <= 0x11D91) ||
	      (wc >= 0x11D93 && wc <= 0x11D94) ||
	      (wc >= 0x11EF3 && wc <= 0x11EF6))
	    return TRUE;
	  return FALSE;
	}
      return FALSE;
    }
  return FALSE;
}

static inline gboolean
_pango2_is_Consonant_Prefixed (gunichar wc)
{
  if ((wc >= 0x111C2 && wc <= 0x111C3) ||
      wc == 0x1193F || wc == 0x11A3A || (wc >= 0x11A84 && wc <= 0x11A89))
    return TRUE;
  return FALSE;
}

static inline gboolean
_pango2_is_Consonant_Preceding_Repha (gunichar wc)
{
  if (wc == 0x0D4E || wc == 0x11941 || wc == 0x11D46)
    return TRUE;
  return FALSE;
}

static inline gboolean
_pango2_is_EastAsianWide (gunichar wc)
{
  if ((wc >= 0x1100 && wc <= 0x27B0))
    {
      if ((wc >= 0x1100 && wc <= 0x25FE))
	{
	  if ((wc >= 0x1100 && wc <= 0x115F) || wc == 0x20A9)
	    return TRUE;
	  if ((wc >= 0x231A && wc <= 0x231B) ||
	      (wc >= 0x2329 && wc <= 0x232A))
	    return TRUE;
	  if ((wc >= 0x23E9 && wc <= 0x23EC) || wc == 0x23F0)
	    return TRUE;
	  if (wc == 0x23F3 || (wc >= 0x25FD && wc <= 0x25FE))
	    return TRUE;
	  return FALSE;
	}
      if ((wc >= 0x2614 && wc <= 0x26C5))
	{
	  if ((wc >= 0x2614 && wc <= 0x2615) ||
	      (wc >= 0x2648 && wc <= 0x2653))
	    return TRUE;
	  if (wc == 0x267F || wc == 0x2693)
	    return TRUE;
	  if (wc == 0x26A1 || (wc >= 0x26AA && wc <= 0x26AB))
	    return TRUE;
	  if ((wc >= 0x26BD && wc <= 0x26BE) ||
	      (wc >= 0x26C4 && wc <= 0x26C5))
	    return TRUE;
	  return FALSE;
	}
      if ((wc >= 0x26CE && wc <= 0x2705))
	{
	  if (wc == 0x26CE || wc == 0x26D4)
	    return TRUE;
	  if (wc == 0x26EA || (wc >= 0x26F2 && wc <= 0x26F3))
	    return TRUE;
	  if (wc == 0x26F5 || wc == 0x26FA)
	    return TRUE;
	  if (wc == 0x26FD || wc == 0x2705)
	    return TRUE;
	  return FALSE;
	}
      if ((wc >= 0x270A && wc <= 0x27B0))
	{
	  if ((wc >= 0x270A && wc <= 0x270B) || wc == 0x2728)
	    return TRUE;
	  if (wc == 0x274C || wc == 0x274E)
	    return TRUE;
	  if ((wc >= 0x2753 && wc <= 0x2755) || wc == 0x2757)
	    return TRUE;
	  if ((wc >= 0x2795 && wc <= 0x2797) || wc == 0x27B0)
	    return TRUE;
	  return FALSE;
	}
      return FALSE;
    }
  if ((wc >= 0x27BF && wc <= 0xFFD7))
    {
      if ((wc >= 0x27BF && wc <= 0x2FFB))
	{
	  if (wc == 0x27BF || (wc >= 0x2B1B && wc <= 0x2B1C))
	    return TRUE;
	  if (wc == 0x2B50 || wc == 0x2B55)
	    return TRUE;
	  if ((wc >= 0x2E80 && wc <= 0x2E99) ||
	      (wc >= 0x2E9B && wc <= 0x2EF3))
	    return TRUE;
	  if ((wc >= 0x2F00 && wc <= 0x2FD5) ||
	      (wc >= 0x2FF0 && wc <= 0x2FFB))
	    return TRUE;
	  return FALSE;
	}
      if ((wc >= 0x3000 && wc <= 0x321E))
	{
	  if (wc == 0x3000 || (wc >= 0x3001 && wc <= 0x303E))
	    return TRUE;
	  if ((wc >= 0x3041 && wc <= 0x3096) ||
	      (wc >= 0x3099 && wc <= 0x30FF))
	    return TRUE;
	  if ((wc >= 0x3105 && wc <= 0x312F) ||
	      (wc >= 0x3131 && wc <= 0x318E))
	    return TRUE;
	  if ((wc >= 0x3190 && wc <= 0x31E3) ||
	      (wc >= 0x31F0 && wc <= 0x321E))
	    return TRUE;
	  return FALSE;
	}
      if ((wc >= 0x3220 && wc <= 0xFE19))
	{
	  if ((wc >= 0x3220 && wc <= 0x3247) ||
	      (wc >= 0x3250 && wc <= 0x4DBF))
	    return TRUE;
	  if ((wc >= 0x4E00 && wc <= 0xA48C) ||
	      (wc >= 0xA490 && wc <= 0xA4C6))
	    return TRUE;
	  if ((wc >= 0xA960 && wc <= 0xA97C) ||
	      (wc >= 0xAC00 && wc <= 0xD7A3))
	    return TRUE;
	  if ((wc >= 0xF900 && wc <= 0xFAFF) ||
	      (wc >= 0xFE10 && wc <= 0xFE19))
	    return TRUE;
	  return FALSE;
	}
      if ((wc >= 0xFE30 && wc <= 0xFFD7))
	{
	  if ((wc >= 0xFE30 && wc <= 0xFE52) ||
	      (wc >= 0xFE54 && wc <= 0xFE66))
	    return TRUE;
	  if ((wc >= 0xFE68 && wc <= 0xFE6B) ||
	      (wc >= 0xFF01 && wc <= 0xFF60))
	    return TRUE;
	  if ((wc >= 0xFF61 && wc <= 0xFFBE) ||
	      (wc >= 0xFFC2 && wc <= 0xFFC7))
	    return TRUE;
	  if ((wc >= 0xFFCA && wc <= 0xFFCF) ||
	      (wc >= 0xFFD2 && wc <= 0xFFD7))
	    return TRUE;
	  return FALSE;
	}
      return FALSE;
    }
  if ((wc >= 0xFFDA && wc <= 0x1F3F4))
    {
      if ((wc >= 0xFFDA && wc <= 0x18D08))
	{
	  if ((wc >= 0xFFDA && wc <= 0xFFDC) ||
	      (wc >= 0xFFE0 && wc <= 0xFFE6))
	    return TRUE;
	  if ((wc >= 0xFFE8 && wc <= 0xFFEE) ||
	      (wc >= 0x16FE0 && wc <= 0x16FE4))
	    return TRUE;
	  if ((wc >= 0x16FF0 && wc <= 0x16FF1) ||
	      (wc >= 0x17000 && wc <= 0x187F7))
	    return TRUE;
	  if ((wc >= 0x18800 && wc <= 0x18CD5) ||
	      (wc >= 0x18D00 && wc <= 0x18D08))
	    return TRUE;
	  return FALSE;
	}
      if ((wc >= 0x1AFF0 && wc <= 0x1F004))
	{
	  if ((wc >= 0x1AFF0 && wc <= 0x1AFF3) ||
	      (wc >= 0x1AFF5 && wc <= 0x1AFFB))
	    return TRUE;
	  if ((wc >= 0x1AFFD && wc <= 0x1AFFE) ||
	      (wc >= 0x1B000 && wc <= 0x1B122))
	    return TRUE;
	  if ((wc >= 0x1B150 && wc <= 0x1B152) ||
	      (wc >= 0x1B164 && wc <= 0x1B167))
	    return TRUE;
	  if ((wc >= 0x1B170 && wc <= 0x1B2FB) || wc == 0x1F004)
	    return TRUE;
	  return FALSE;
	}
      if ((wc >= 0x1F0CF && wc <= 0x1F265))
	{
	  if (wc == 0x1F0CF || wc == 0x1F18E)
	    return TRUE;
	  if ((wc >= 0x1F191 && wc <= 0x1F19A) ||
	      (wc >= 0x1F200 && wc <= 0x1F202))
	    return TRUE;
	  if ((wc >= 0x1F210 && wc <= 0x1F23B) ||
	      (wc >= 0x1F240 && wc <= 0x1F248))
	    return TRUE;
	  if ((wc >= 0x1F250 && wc <= 0x1F251) ||
	      (wc >= 0x1F260 && wc <= 0x1F265))
	    return TRUE;
	  return FALSE;
	}
      if ((wc >= 0x1F300 && wc <= 0x1F3F4))
	{
	  if ((wc >= 0x1F300 && wc <= 0x1F320) ||
	      (wc >= 0x1F32D && wc <= 0x1F335))
	    return TRUE;
	  if ((wc >= 0x1F337 && wc <= 0x1F37C) ||
	      (wc >= 0x1F37E && wc <= 0x1F393))
	    return TRUE;
	  if ((wc >= 0x1F3A0 && wc <= 0x1F3CA) ||
	      (wc >= 0x1F3CF && wc <= 0x1F3D3))
	    return TRUE;
	  if ((wc >= 0x1F3E0 && wc <= 0x1F3F0) || wc == 0x1F3F4)
	    return TRUE;
	  return FALSE;
	}
      return FALSE;
    }
  if ((wc >= 0x1F3F8 && wc <= 0x3FFFD))
    {
      if ((wc >= 0x1F3F8 && wc <= 0x1F596))
	{
	  if ((wc >= 0x1F3F8 && wc <= 0x1F43E) || wc == 0x1F440)
	    return TRUE;
	  if ((wc >= 0x1F442 && wc <= 0x1F4FC) ||
	      (wc >= 0x1F4FF && wc <= 0x1F53D))
	    return TRUE;
	  if ((wc >= 0x1F54B && wc <= 0x1F54E) ||
	      (wc >= 0x1F550 && wc <= 0x1F567))
	    return TRUE;
	  if (wc == 0x1F57A || (wc >= 0x1F595 && wc <= 0x1F596))
	    return TRUE;
	  return FALSE;
	}
      if ((wc >= 0x1F5A4 && wc <= 0x1F6EC))
	{
	  if (wc == 0x1F5A4 || (wc >= 0x1F5FB && wc <= 0x1F64F))
	    return TRUE;
	  if ((wc >= 0x1F680 && wc <= 0x1F6C5) || wc == 0x1F6CC)
	    return TRUE;
	  if ((wc >= 0x1F6D0 && wc <= 0x1F6D2) ||
	      (wc >= 0x1F6D5 && wc <= 0x1F6D7))
	    return TRUE;
	  if ((wc >= 0x1F6DD && wc <= 0x1F6DF) ||
	      (wc >= 0x1F6EB && wc <= 0x1F6EC))
	    return TRUE;
	  return FALSE;
	}
      if ((wc >= 0x1F6F4 && wc <= 0x1FA7C))
	{
	  if ((wc >= 0x1F6F4 && wc <= 0x1F6FC) ||
	      (wc >= 0x1F7E0 && wc <= 0x1F7EB))
	    return TRUE;
	  if (wc == 0x1F7F0 || (wc >= 0x1F90C && wc <= 0x1F93A))
	    return TRUE;
	  if ((wc >= 0x1F93C && wc <= 0x1F945) ||
	      (wc >= 0x1F947 && wc <= 0x1F9FF))
	    return TRUE;
	  if ((wc >= 0x1FA70 && wc <= 0x1FA74) ||
	      (wc >= 0x1FA78 && wc <= 0x1FA7C))
	    return TRUE;
	  return FALSE;
	}
      if ((wc >= 0x1FA80 && wc <= 0x3FFFD))
	{
	  if ((wc >= 0x1FA80 && wc <= 0x1FA86) ||
	      (wc >= 0x1FA90 && wc <= 0x1FAAC))
	    return TRUE;
	  if ((wc >= 0x1FAB0 && wc <= 0x1FABA) ||
	      (wc >= 0x1FAC0 && wc <= 0x1FAC5))
	    return TRUE;
	  if ((wc >= 0x1FAD0 && wc <= 0x1FAD9) ||
	      (wc >= 0x1FAE0 && wc <= 0x1FAE7))
	    return TRUE;
	  if ((wc >= 0x1FAF0 && wc <= 0x1FAF6) ||
	      (wc >= 0x20000 && wc <= 0x2FFFD) ||
	      (wc >= 0x30000 && wc <= 0x3FFFD))
	    return TRUE;
	  return FALSE;
	}
      return FALSE;
    }
  return FALSE;
}

#endif /* PANGO2_BREAK_TABLE_H */

/* == End of generated table == */
