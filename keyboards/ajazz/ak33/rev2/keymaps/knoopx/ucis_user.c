#include QMK_KEYBOARD_H

#ifdef UCIS_ENABLE
const qk_ucis_symbol_t ucis_symbol_table[] = UCIS_TABLE(UCIS_SYM("wat", 0x00AF, 0x005C, 0x005F, 0x0028, 0x30C4, 0x0029, 0x005F, 0x002F, 0x00AF),                          // ¯\_(ツ)_/¯
                                                        UCIS_SYM("tflip", 0x0028, 0x256f, 0x00b0, 0x25a1, 0x00b0, 0xff09, 0x256f, 0xfe35, 0x0020, 0x253b, 0x2501, 0x253b),  // (╯°□°）╯︵ ┻━┻
                                                        UCIS_SYM("boss", 0x0028, 0x2310, 0x25a0, 0x005f, 0x25a0, 0x0029)                                                    // (⌐■_■)
);
#endif
