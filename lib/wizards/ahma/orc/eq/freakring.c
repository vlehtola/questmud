inherit "obj/armour";
start() {
  set_slot("finger");
  set_name("ring");
  set_alias("freakring");
  set_short("A small stone-made ring");
  set_long("A small, simple stone ring. The ring seems to be carefully made, it probably\n" +
           "has been carved and ground from some bigger rock. The stone from which the\n" +
           "ring has been carved seems to be yellow in colour. The stony material seems\n" +
           "to glow weakly. Regardless of ring's sturdy material, it seems to fit in your\n" +
           "finger perfectly");
  
  set_value(1500);
  set_weight(65);
  set_stats("str", 2);
  set_stats("dex", -2);
  set_stats("con", 5);
}
