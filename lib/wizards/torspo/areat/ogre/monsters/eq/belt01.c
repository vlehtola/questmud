inherit "obj/armour";

start() {
set_slot("belt");
set_class(1);
  set_name("belt");
  set_short("Coral belt");
  set_long("A belt made of fragile looking coral. It has been probably constructed with\n"+
           "some natural magic. It somehow fits you perfectly");
  set_stats("str", 5);
  set_stats("con", 1);
  set_stats("dex", -2);
  set_stats("wis", -2);
}
