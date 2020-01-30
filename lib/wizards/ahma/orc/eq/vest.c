inherit "obj/armour";
start() {
  set_class(4);
  set_sub_type("scale mail");
  set_name("vest");
  set_short("A brown furry vest");
  set_long("A brown furry vest has probably been made of bear fur. This kind of vests\n" + 
           "are widely used by hunters to give them proper camouflage when hunting.\n" + 
           "Due to the soft material from which the vest has been made of, it does not\n" + 
           "give almost at all protection against piercing attacks. The weak static\n" +
           "field which the thick hair is creating gives protection against electric,\n" +
           "though");
  
  set_stats("str", 1);
  set_stats("con", 1);
  set_resists("electric", 7);
  set_resists("cold", 7);
}
