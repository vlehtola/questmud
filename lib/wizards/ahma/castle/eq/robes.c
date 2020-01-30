inherit "obj/armour";

start() {
  set_name("robes");
  set_slot("cloak");
  set_short("Wizard's blue robes");
  set_long("An ordinary dark blue mage robes with white edging. Because these kind of robes\n" + 
           "are also used often among different kingdoms' kings, they are sometimes called\n" + 
           "'The Royal Robes'. The surface of the robe feel comfortably soft and pure to\n" + 
           "touch. A weak cold-blue aura can be seen surrounding the robes and also soft\n" + 
           "orange glow pulsates from somewhere inside the robe");
  set_value(125);
  set_weight(125);
  set_stats("int", 3);
  set_resists("fire", 5);
  set_resists("cold", 5);
}
