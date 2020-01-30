inherit "obj/armour";

start() {
  set_sub_type("helm");
  set_class(8);
  set_name("helmet");
  set_short("A sturdy full helmet with stones attached on it");
  set_long("Not much metal can be seen under the thick layer of flat stones which have\n" +
           "been attached on the surface of the steel full helmet. Naturally, the helmet\n" +
           "weights very much, but the stones give excellent defense against even the\n" +
           "most powerful blows aimed for the head. Inside the steel helmet there seems\n" +
           "to be some clothing, which makes it more comfortable to wear");

  set_value(9000);
  set_weight(7000);
  set_stats("dex", -3);
  set_stats("con", 10);
  set_stats("spr", -5);
  set_resists("fire", 4);
  set_resists("electric", 4);
}
