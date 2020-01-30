inherit "obj/base_object";
 
reset(arg) {
::reset(arg);
if (arg) { return; }
set_name("rag");
set_alias("hv0700123123");
set_short("A ripped and torn rag from a cloak");
set_long("This is a rag, ripped of Khilarbhunaz's cloak. You can see the old symbol\n"+
         "of the anvil on it.\n");
set_weight(1);
set_value(1);
set_no_get(1);
}
 
set_id(arg) {
    return name == arg;
}
