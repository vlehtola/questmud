inherit "obj/armour";
start() {
  set_class(10);
  set_sub_type("leggings");
  set_name("leggings");
  set_short("Flaming platinum leggings <unique>");
  set_long("You really should not be holding these leggings");
  set_stats("str", 20);
  set_stats("dex", 20);
  set_stats("con", 20);
  set_stats("int", 20);
  set_stats("wiz", 20);
  set_stats("spr", 20);
}

long() {
  destruct(this_object());
}
