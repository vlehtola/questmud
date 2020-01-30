inherit "obj/base_object";
 
reset(arg) {
::reset(arg);
if (arg) { return; }
set_name("railing");
set_alias("pala0503246921");
set_short("A part of a railing");
set_long("This is a piece of a railing, that has come loose from a wall, it is carefully\n"+
         "carved out of bronze, and looks like a snake.\n");
set_weight(1);
set_value(1);
set_no_get(1);
}
 
set_id(arg) {
    return name == arg;
}
