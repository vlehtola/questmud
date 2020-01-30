inherit "obj/armour";

start() {
  set_slot("cloak");
  set_name("robes");
  set_short("Red robes of Nehelam's salesmen");
  set_long("Long robes made of some ordinary cloth. These robes are used to indicate\n" + 
           "that their wearer is a salesman in village Nehelam. Robes are coloured\n" +
           "in bright red and they are lined with bold, golden line. Robes can be\n" + 
           "attached into any torso armour with the chain mechanism located in neck-\n" + 
           "part of the robes");
  
  set_value(100);
  set_weight(125);
  set_resists("fire", 5);
}
