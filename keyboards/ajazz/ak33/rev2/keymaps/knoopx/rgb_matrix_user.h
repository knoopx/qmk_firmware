#define LED_FLAG_CUSTOM 0x10

typedef uint8_t rgb_matrix_led_map_t[DRIVER_LED_TOTAL]
#ifdef DYNAMIC_KEYMAP_ENABLE
                                    [DYNAMIC_KEYMAP_LAYER_COUNT];
#else
                                    [5];
#endif

extern const rgb_matrix_led_map_t rgb_matrix_led_map[];

#define RGB_LED_MAP_COLOR(layer, index)                                        \
  {                                                                            \
    pgm_read_byte(&rgb_matrix_led_map[layer][index][0]),                       \
        pgm_read_byte(&rgb_matrix_led_map[layer][index][1]),                   \
        pgm_read_byte(&rgb_matrix_led_map[layer][index][2])                    \
  }
