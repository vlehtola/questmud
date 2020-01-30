inherit "obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) { return; }
  set_level(190);
  set_name("citizen");
  set_race("dark elf");
  set_short("A dark elf citizen.");
  set_long("One of the dark elfs that inhabit this city of darkness.\n"+
           "They look like any citizen would look.. but these are carved\n"+
           "out of stone by the harsh environments of this place.\n");
  set_al(-800);
  set_aggressive(0);
  set_str(1);
  set_con(1);
  set_hp(1);
}
