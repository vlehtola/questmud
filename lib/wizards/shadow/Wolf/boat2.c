inherit "room/room";

reset(arg) {
  set_not_out(1);
  set_light(3);
  short_desc = "A rowing-boat";
  long_desc =
"You are in a wonderful little rowing-boat, speeding steadily\n"+
"across the sea. The waves make it rock from side to side\n"+
"and you try do your best not to think about your breakfast.\n";
  property = allocate(4);
   property[0] = "no_skill";
   property[1] = "no_spell";
   property[2] = "no_summon";
}
