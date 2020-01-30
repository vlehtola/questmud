inherit "obj/armour";

start() {
set_sub_type("helm");
set_class(7);
  set_slot("head");
  set_name("crown");
  set_short("Red crown");
  set_long("Crown made of red ruby. It has amazingly smooth surface and is probably hundreds\n"+
           "of years old. There's a huge amethyst embedded in front of the crown. It shimmers\n"+
           "in rainbow colours as light reflects from it\n");
  set_stats("str",4);
  set_stats("dex",5);
  set_stats("con",-2);
  set_stats("int",-15);
  set_resists("fire", 33);
}
