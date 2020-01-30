inherit "obj/armour";

start() {
  set_class(4);
  set_sub_type("leather gloves");
  set_name("mittens");
  set_short("Brown leather mittens");
  set_long("These funny-looking mittens seem to be very hastily made. The leather,\n" +
           "from which the mittens have been made of, seems very warm and gives\n" +
           "the mittens a lot of value when moving in the cold climate. The mittens\n" +
           "have been made by sewing many pieces of leather together");

  set_resists("cold", 8);
  set_value(140);
  set_weight(60);
}