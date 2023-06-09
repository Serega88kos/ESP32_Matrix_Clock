const uint8_t asm_10x6b_Bitmaps[] PROGMEM = {
  0x00, 0x30, 0x00, 0x31, 0xEF, 0xF3, 0xCF, 0x3C, 0xFF, 0x78, 0xC0, 0x3D, 
  0xBC, 0xE3, 0x0C, 0x30, 0xC3, 0x0C, 0x30, 0x7B, 0xF0, 0xC3, 0x7F, 0xEC, 
  0x30, 0xFF, 0xF0, 0x7B, 0xF8, 0xC3, 0x38, 0xE0, 0xE3, 0xFD, 0xE0, 0xCF, 
  0x3C, 0xF3, 0xFD, 0xF0, 0xC3, 0x0C, 0x30, 0xFF, 0xFC, 0x30, 0xFB, 0xF0, 
  0xC3, 0xFF, 0xE0, 0x7B, 0xFC, 0x30, 0xFB, 0xFC, 0xF3, 0xFD, 0xE0, 0x7F, 
  0xFC, 0xF3, 0x0C, 0x30, 0xC3, 0x0C, 0x30, 0x7B, 0xFC, 0xF3, 0x79, 0xEC, 
  0xF3, 0xFD, 0xE0, 0x7B, 0xFC, 0xF3, 0xFD, 0xF0, 0xC3, 0xFD, 0xE0
};

const GFXglyph asm_10x6b_Glyphs[] PROGMEM = {
  {     0,   2,  10,   4,    1,   -9 },   // 0x2D '-'
  {     0,   0,   0,   0,    0,    0 },   // 0x2E '.'
  {     0,   0,   0,   0,    0,    0 },   // 0x2F '/'
  {     3,   6,  10,   7,    0,   -9 },   // 0x30 '0'
  {    11,   6,  10,   7,    0,   -9 },   // 0x31 '1'
  {    19,   6,  10,   7,    0,   -9 },   // 0x32 '2'
  {    27,   6,  10,   7,    0,   -9 },   // 0x33 '3'
  {    35,   6,  10,   7,    0,   -9 },   // 0x34 '4'
  {    43,   6,  10,   7,    0,   -9 },   // 0x35 '5'
  {    51,   6,  10,   7,    0,   -9 },   // 0x36 '6'
  {    59,   6,  10,   7,    0,   -9 },   // 0x37 '7'
  {    67,   6,  10,   7,    0,   -9 },   // 0x38 '8'
  {    75,   6,  10,   7,    0,   -9 }    // 0x39 '9'
};

const GFXfont asm_10x6b PROGMEM = {(uint8_t *) asm_10x6b_Bitmaps,          (GFXglyph *)asm_10x6b_Glyphs, 0x2D, 0x39,          6};