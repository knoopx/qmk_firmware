#define LED_FLAG_CUSTOM 0x10

#define LEDMAP_RGB_COLOR(layer, index) pgm_read_byte(&ledmaps[layer][index][0]), pgm_read_byte(&ledmaps[layer][index][1]), pgm_read_byte(&ledmaps[layer][index][2])
#define LEDMAP_RGB_COLOR_IS_TRANS(layer, index) (uint8_t[]){ LEDMAP_RGB_COLOR(layer, index) } == (uint8_t[]){ RGB_OFF }
#define LEDMAP_RGB_COLOR_IS_CUSTOM(layer, index) !(LEDMAP_RGB_COLOR_IS_TRANS(layer, index))

typedef uint8_t ledmap[DRIVER_LED_TOTAL][DYNAMIC_KEYMAP_LAYER_COUNT];

extern const ledmap ledmaps[];
