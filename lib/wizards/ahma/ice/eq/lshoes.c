inherit "obj/armour";

start() {
  set_class(4);
  set_sub_type("leather boots");
  set_name("slippers");
  set_short("Brown leather slippers");
  set_long("Soft, brown slippers have been made of some animal's skin. The slippers\n" +
           "are thoroughly very soft, including the bottom. The only holes, which\n" +
           "allow the slipper to be worn, are very small, thus preventing the cold-\n" +
           "ness from entering them. The slippers are quite funny-looking, but very\n" +
           "comfortable and warm to wear");

  set_resists("cold", 12);
  set_value(120);
  set_weight(80);
}