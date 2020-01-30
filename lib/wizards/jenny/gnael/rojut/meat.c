inherit "obj/food";

reset(arg) {
::reset(arg);
if (arg) { return; }
set_name("meat");
set_short("A piece of rotten meat");
set_long("An old piece of meat that has been rotten for\n"+
         "some time now.\n");
set_weight(1);
set_value(0);
set_strength(10000);
}

set_id(arg) {
    return name == arg;
}
