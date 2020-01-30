inherit "obj/armour";

start() {
  set_class(3);
  set_slot("cloak");
  set_name("ranger cloak");
  set_alias("cloak");
  set_short("A ranger cloak");
  set_long("The cloak is so dirty you can barely see that it was once green,\n"+
           "and yet you feel like you are drawn to the cloak somehow.");
  set_value(2000);
  set_weight(500);
  set_stats("str", 2);
  set_stats("dex", 2);
}
