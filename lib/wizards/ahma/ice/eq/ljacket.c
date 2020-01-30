inherit "obj/armour";

start() {
  set_class(4);
  set_sub_type("leather coat");
  set_name("jacket");
  set_short("A brown leather jacket, filled with fur");
  set_long("Very warm-looking leather jacket. The inside of the jacket has been\n" +
           "stuffed full of fur, which makes this piece of clothing even more\n" +
           "comfortable and warm to wear. The high quality of handicraft used\n" +
           "to create the jacket can be seen especially from its sleeves. Few\n" +
           "buttons in the front make it possible to attach the other side of\n" +
           "the jacket to the other");

  set_resists("cold", 14);
  set_value(190);
  set_weight(300);
}
