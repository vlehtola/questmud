inherit "obj/armour";

start() {
  set_class(4);
  set_sub_type("cap");
  set_name("cap");
  set_short("A brown leather cap");
  set_long("The cap has been made of rough, warm leather of some animal. The leather\n" +
           "is very soft material and, therefore, offers only a minor protection to\n" +
           "cap's wearer. Few strings hang from the cap for decorative purposes. The\n" +
           "cap seems to have been made by sewing many pieces of leather together");

  set_resists("cold", 10);
  set_value(100);
  set_weight(40);
}