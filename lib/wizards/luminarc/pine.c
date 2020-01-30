
inherit "obj/food";

reset(arg) {
::reset(arg);
if (arg) { return; }
set_name("pineapple");
set_alias("fruit");
set_short("Beautiful yellow pineapple");
set_long("Big pineapple with beautiful colors \n");
set_weight(20);
set_value(0);
set_strength(0);
}
query_no_save() { return 1; }

