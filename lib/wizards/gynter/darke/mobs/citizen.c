inherit "obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) { return; }
  set_level(25);
  set_name("citizen");
  set_race("dark elf");
  set_short("A dark elf citizen.");
  set_long("One of the dark elfs that inhabit this city of darkness.\n"+
           "They look like any citizen would look, but these looks like\n"+
           "are carved out of stone by the harsh environments of this place.\n");
  set_al(-800);
  set_aggressive(0);
}