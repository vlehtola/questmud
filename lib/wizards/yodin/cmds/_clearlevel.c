#define TP this_player()


status cmd_clearlevel() {
 TP->clear_level_advance();
  write("Level advance removed.\n");
  return 1;
}
