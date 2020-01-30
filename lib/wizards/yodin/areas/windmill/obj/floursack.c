inherit "obj/food";

reset(arg) {
set_name("real_flour_not_fake");
set_alias("sack");
set_short("Large sack full of flour");
  set_long("This is large sack full of white flour.\n");
set_weight(10);
set_value(0);
set_strength(10000);
}
query_real_flour() { return 1; }
query_no_save() { return 1; }
