inherit "obj/armour";
start() {
  set_class(3);
  set_sub_type("leather armour");
  set_name("robes");
  set_short("Jet black robes");
  set_long("This loose piece of black clothing has sweet smell of some kind of a\n" +
           "cologne or perfume in it. It feels soft to the touch. Like most clothes,\n" +
           "this one has no significant protective value");
  
  set_stats("con", 2);
  set_resists("fire", 5);
  set_resists("electric", 5);
  set_resists("cold", 5);
}
