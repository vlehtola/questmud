inherit "obj/food";

reset(arg) {
::reset(arg);
if (arg) { return; }
set_name("salmon");
set_alias("fish");
set_short("Small dead salmon");
set_long("Small salmon. It appears to be dead.\n");
set_weight(150);
set_value(0);
set_strength(10000);
}

set_id(arg) { return name == arg; }
query_no_save() { return 1; }
