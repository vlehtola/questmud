inherit "obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) { return; }
  set_level(22);
  set_name("lover");
  set_race("dark elf");
  set_short("A crazy lover");
  set_long("This is one of the young dark elfs that has been seduced by the\n"+
           "chemical unbalance called, love.\n");
  set_al(500);
  set_aggressive(0);

}
