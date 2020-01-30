inherit "obj/armour";

start() {
  set_class(4);
  set_sub_type("leather leggings");
  set_name("pants");
  set_short("Brown leather pants");
  set_long("Pants made of thick, brown leather of some animal. The pants are of great\n" +
           "quality, but a bit short of their size. They would cover your legs only\n" +
           "from waist to shin and, therefore, offer only lesser protection against\n" +
           "cold. The pants seem firm and durable and, for that very fact, have\n" +
           "probably some material value");

  set_resists("cold", 6);
  set_value(180);
  set_weight(250);
}