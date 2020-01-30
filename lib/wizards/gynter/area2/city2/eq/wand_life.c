inherit "obj/armour";

reset(arg) {
  ::reset(arg);
  set_slot("held");
  set_name("wand of life");
  set_alias("wand");
  set_short("Wand of life");
  set_long("This is one of the Wands of life. They are specialisied in the\n"+
           "wit if the caster.\n");
  set_value(10000);
  set_weight(500);
  set_stats("wis", 17);
  set_stats("int", 19);
  set_stats("spr", 28);
  set_stats("str", -20);
  set_stats("dex", -15);
  set_stats("con", 10);
}
