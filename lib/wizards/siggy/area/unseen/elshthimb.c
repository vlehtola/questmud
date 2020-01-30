inherit"obj/armour";

start(arg) {
  set_name("thimble");
  set_alias("ring"); 
  set_sub_type("ring");
  set_short("A little thimble");
  set_long("A little silver thimble that is covering almost your whole finger. It\n"
         + "feels cold, but strangely your finger doesn't seem to freeze, actually it\n"
         + "makes you feel better.\n");
  set_weight(120);
  set_class(5);
  set_stats("spr", 5);
  set_stats("hpr", 5);
  set_slot("finger");
  set_value("2000");
}
