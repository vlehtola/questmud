inherit "obj/armour";

start() {
  set_class(7);
  set_value(1000);
  set_sub_type("breastplate");
  set_name("breastplate");
  set_slot("torso");
  set_alias("plate");
  set_short("A stained bronze breastplate");
  set_long("The bronze breastplate seems to be of great quality. It is a common-\n" +
           "looking breastplate with three bronze, maybe golden, chains hanging\n" +
           "horizontally in the front. The plate does not offer any protection\n" +
           "to its wearer's arms and neck, but otherwise it seems to be very\n" +
           "hard and protective. Numerous dark brown drops and rivers stain the\n" +
           "breastplate's surface. It must be blood");

  set_stats("str", 3);
  set_stats("con", 2);
  set_stats("spr", -5);
  set_weight(500);
}
