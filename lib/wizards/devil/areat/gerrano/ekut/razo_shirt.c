inherit "obj/armour";
start() {
  set_class(6);
  set_sub_type("leather armour");
  set_name("shirt");
  set_alias("shirt");
  set_short("Ragged leather shirt of the Master Brawler");
  set_long("Decaying but still sturdy looking leather shirt, you're\n"+
           "not quite sure what this piece of armour have been put through,\n"+
           "but you can definitely recognize the large scorchmarks all over\n"+
           "of it. Small holes have been burned in various places\n"+
           "as well. All in all, this piece of leather look like it have\n"+
           "received a lot of use throughout the years");

  set_value(5000);
  set_weight(50);
  set_stats("str", 15);
  set_stats("dex", 9);
  set_stats("con", 5);

}
