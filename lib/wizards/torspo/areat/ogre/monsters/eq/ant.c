inherit "obj/food";

reset(arg) {
::reset(arg);
if (arg) { return; }
set_name("ant");
set_short("Small dead ant <rotting>");
set_long("Small ant which appears to be very dead. Rumours tell that ants are the favourite\n"+
         "meal of some salmons\n");
set_weight(2);
set_value(0);
set_strength(5000);
}

set_id(arg) { return name == arg; }
query_no_save() { return 1; }
