inherit"obj/armour";

reset(arg) {
  set_name("book");
  set_alias("spellbook");
  set_sub_type("gloves");
  set_short("A dark yellow spellbook");
  set_long("A dark yellow spellbook. Some ancient writing is embedded in the book.\n"
         + "You can't learn any spell from the spellbook, because you can't undestand\n"
         + "the text.\n");
  set_weight(180);
/*  set_stats("int", 2);
  set_stats("wis", 2);
  set_stats("spr", 3); */
  set_slot("held");
  set_value("4500");
}
