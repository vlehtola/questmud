inherit "obj/armour";

start() {
set_class(6);
  set_slot("hands");
    set_name("gloves");
    set_alias("gloves");
    set_short("Gloves of divine protection");
    set_long("The gloves in your hands seem to be made of the finest materials\n" +
             "imaginable. The gloves have an unearthly aura around them, and\n" +
             "as you wear them, you feel at peace with everyone.");
    set_value(5000);
    set_stats("wis",14);
    set_stats("int",10);
    set_stats("spr",16);
  
    set_weight(3);

}

