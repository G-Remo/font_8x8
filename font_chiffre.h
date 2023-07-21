const uint8_t rial4pt8bBitmaps[] PROGMEM = {
  0xD6, 0xD6, 0x00, 0x04, 0x92, 0x00, 0xC7, 0xC6, 0x00, 0xC5, 0x96, 0x00, 
  0x97, 0x92, 0x00, 0xD3, 0x96, 0x00, 0xD3, 0xD6, 0x00, 0xC4, 0xA4, 0x00, 
  0xD5, 0x56, 0x00, 0xD7, 0x96, 0x00, 0x00
};

const GFXglyph rial4pt8bGlyphs[] PROGMEM = {
  {     0,   3,   5,   4,    0,   -4 },   // 0x30 '0'
  {     3,   3,   5,   4,    0,   -4 },   // 0x31 '1'
  {     6,   3,   5,   4,    0,   -4 },   // 0x32 '2'
  {     9,   3,   5,   4,    0,   -4 },   // 0x33 '3'
  {    12,   3,   5,   4,    0,   -4 },   // 0x34 '4'
  {    15,   3,   5,   4,    0,   -4 },   // 0x35 '5'
  {    18,   3,   5,   4,    0,   -4 },   // 0x36 '6'
  {    21,   3,   5,   4,    0,   -4 },   // 0x37 '7'
  {    24,   3,   5,   4,    0,   -4 },   // 0x38 '8'
  {    27,   3,   5,   4,    0,   -4 },   // 0x39 '9'
  {    30,   1,   3,   1,    0,   -3 }    // 0x3A ':'
};

const GFXfont rial4pt8b PROGMEM = {
  (uint8_t  *)rial4pt8bBitmaps,    
  (GFXglyph *)rial4pt8bGlyphs, 0x30, 0x3A,     9 };

