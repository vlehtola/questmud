inherit "obj/armour";

start() {
  set_class(4);
  set_slot("finger");
  set_name("Ring of spiritism");
  set_alias("ring");
  set_short("The ring of spiritism");
  set_long("This is a true ring of spiritusm.\n"+
          "There are one thousand and one souls trapped in this ring.\n"+
         "It is rumored that there are only a few real rings of spiritism.\n");
  set_weight(100);
  set_stats("int", 7);
  set_stats("wis", 6);
  set_stats("spr", 29);
}
