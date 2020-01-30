inherit "obj/armour";

start() {
  set_slot("cloak");
  set_name("shoulder cloth");
  set_alias("cloth");
  set_short("A blood-red shoulder cloth");
  set_long("The original colour of this shoulder cloth would be impossible to tell\n" +
           "due to the huge amount of blood soaked into the cloth's innermosts. The\n" +
           "shoulder cloth is supposed to be attached around the neck, letting the\n" +
           "actual cloth lie on its wearer's right or left shoulder. The cloth feels\n" +
           "somehow very powerful, but in the same time, dirty");
  
  set_stats("int", 6);
  set_stats("wis", 4);
  set_stats("spr", 7);
  set_value(2000);
  set_weight(50);
}