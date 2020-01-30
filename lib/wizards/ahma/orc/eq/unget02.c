inherit "obj/armour";
start() {
  set_class(10);
  set_sub_type("great helm");
  set_name("helm");
  set_short("A silvered unicorn helm <unique>");
  set_long("You really should not be holding this helm");
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
