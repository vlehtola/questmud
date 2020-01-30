inherit "obj/armour";
  start() {
 
   set_class(1);
   set_name("medal");
   set_alias("metal");
   set_short("Yang, one half of the amulet");
   set_long("You hold in your hand one part of the sacred ying-yang amulet.\n"+
            "Alone, it seems to have little power, but you still get a tingling\n"+
            "feeling in your fingers, suggesting hidden powers.\n");
}
 
set_id(arg) { return name == arg; }
query_no_save() { return 1; }
 
