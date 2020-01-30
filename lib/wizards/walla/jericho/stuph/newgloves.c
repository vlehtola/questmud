inherit "obj/armour";

start() {
set_class(6);
  set_slot("hands");
    set_name("knuckles");
    set_alias("gloves");
    set_short("Spiked steel knuckles");
    set_long("The knuckles you hold in your hand are made of the strongest\n" +
             "steel imaginable. They seem to fit your hands perfectly, and they\n" +
             "start glowing as you wear them.");
    set_value(5000);
    set_stats("str",4);
    set_stats("con",1);
    set_stats("hpr",6);
    set_stats("dex",7);
    set_resists("fire", 5);
    set_resists("cold", 3);
    set_resists("electric", 1);
    set_weight(3);

}
