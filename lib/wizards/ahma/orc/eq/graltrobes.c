inherit "obj/armour";
start() {
  set_slot("cloak");
  set_name("robes");
  set_short("G'ralt's worn red robes");
  set_long("Made of worn and rough red cloth, smelling bad and looking dirty. A few\n" +
           "darker red stains, maybe blood, can be seen in it. A few worn runes are\n" +
           "decorating the edges of the sleeves, but none of them can be identified");
  
  set_value(150);
  set_weight(100);
  set_stats("con", 2);
  set_resists("fire", 5);
  set_resists("electric", 5);
  set_resists("cold", 5);
}
