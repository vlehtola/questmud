inherit "obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) { return; }
  set_level(50);
  set_name("dwarf");
  set_alias("guard");
  set_gender(1);
  set_short("Dwarf guard");
  set_long("The sturdy-looking, hairy pony is perfect work animal for gnomes because of its\n"+
           "relatively small size and patient nature. Despite of its pudgy appearance\n"+
           "a mountain pony is almost as strong as a working horse.\n");
  set_al(6);
  set_aggressive(0);
}
