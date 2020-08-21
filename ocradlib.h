/*  Ocradlib - Optical Character Recognition library
    Copyright (C) 2009-2019 Antonio Diaz Diaz.

    This library is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 2 of the License, or
    (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this library.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef ocradlib_h
#define ocradlib_h

#include <climits>
#include <cstdio>
#include <cstring>
#include <stdint.h>
#include <string>
#include <vector>

#include "bitmap.h"
#include "blob.h"
#include "character.h"
#include "common.h"
#include "page_image.h"
#include "rectangle.h"
#include "textblock.h"
#include "textline.h"
#include "textpage.h"
#include "track.h"
#include "ucs.h"

#ifdef __cplusplus
extern "C" {
#endif

DllExport extern const char *const OCRAD_version_string;

/* OCRAD_Pixmap.data is a pointer to image data formed by "height" rows
   of "width" pixels each.
   The format for each pixel depends on mode like this:
   OCRAD_bitmap   --> 1 byte  per pixel;  0 = white, 1 = black
   OCRAD_greymap  --> 1 byte  per pixel;  256 level greymap (0 = black)
   OCRAD_colormap --> 3 bytes per pixel;  16777216 colors RGB (0,0,0 = black) */

enum OCRAD_Pixmap_Mode {
  OCRAD_bitmap,
  OCRAD_greymap,
  OCRAD_colormap
};

struct OCRAD_Pixmap {
  const unsigned char *data;
  int height;
  int width;
  enum OCRAD_Pixmap_Mode mode;
};

enum OCRAD_Errno {
  OCRAD_ok = 0,
  OCRAD_bad_argument,
  OCRAD_mem_error,
  OCRAD_sequence_error,
  OCRAD_library_error
};

struct OCRAD_Descriptor {
  Page_image *page_image;
  Textpage *textpage;
  OCRAD_Errno ocr_errno;
  Control control;
  std::string text;

  OCRAD_Descriptor() : page_image(0), textpage(0), ocr_errno(OCRAD_ok) {
    control.outfile = 0;
  }
};

DllExport const char *OCRAD_version(void);

/*--------------------- Functions ---------------------*/

DllExport struct OCRAD_Descriptor *OCRAD_open(void);

DllExport int OCRAD_close(struct OCRAD_Descriptor *const ocrdes);

DllExport enum OCRAD_Errno
OCRAD_get_errno(struct OCRAD_Descriptor *const ocrdes);

DllExport int OCRAD_set_image(struct OCRAD_Descriptor *const ocrdes,
                              const struct OCRAD_Pixmap *const image,
                              const bool invert);

DllExport int OCRAD_set_image_from_file(struct OCRAD_Descriptor *const ocrdes,
                                        const char *const filename,
                                        const bool invert);

DllExport int OCRAD_set_utf8_format(struct OCRAD_Descriptor *const ocrdes,
                                    const bool utf8); // 0 = byte, 1 = utf8

DllExport int OCRAD_set_threshold(struct OCRAD_Descriptor *const ocrdes,
                                  const int threshold); // 0..255, -1 = auto

DllExport int OCRAD_scale(struct OCRAD_Descriptor *const ocrdes,
                          const int value);

DllExport int OCRAD_recognize(struct OCRAD_Descriptor *const ocrdes,
                              const bool layout);

DllExport int OCRAD_result_blocks(struct OCRAD_Descriptor *const ocrdes);

DllExport int OCRAD_result_lines(struct OCRAD_Descriptor *const ocrdes,
                                 const int blocknum); // 0..blocks-1

DllExport int OCRAD_result_chars_total(struct OCRAD_Descriptor *const ocrdes);

DllExport int OCRAD_result_chars_block(struct OCRAD_Descriptor *const ocrdes,
                                       const int blocknum); // 0..blocks-1

DllExport int OCRAD_result_chars_line(struct OCRAD_Descriptor *const ocrdes,
                                      const int blocknum, // 0..blocks-1
                                      const int linenum); // 0..lines(block)-1

DllExport const char *OCRAD_result_line(struct OCRAD_Descriptor *const ocrdes,
                                        const int blocknum, // 0..blocks-1
                                        const int linenum); // 0..lines(block)-1

DllExport int
OCRAD_result_first_character(struct OCRAD_Descriptor *const ocrdes);

#ifdef __cplusplus
}
#endif
#endif // ocradlib_h
