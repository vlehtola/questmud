inherit "obj/base_object";
 
reset(arg) {
::reset(arg);
if (arg) { return; }
set_name("flag");
set_short("A flag, flying the colours of Razindukhta");
set_long("The flag of Razindukhta consists of an anvil and a sickle on top of a\n"+
         "hooded figure.\n");
set_weight(1);
set_value(1);
set_no_get(1);
}
 
set_id(arg) {
    return name == arg;
}
