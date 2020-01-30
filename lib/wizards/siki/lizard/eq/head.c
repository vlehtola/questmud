inherit "obj/armour";
  start() {

   set_class(6);
   set_name("head");
   set_alias("I_can_see_it_all");
   set_slot("head");
   set_short("Head of the sea monster");
   set_long("Green head of the huge sea monster. The red glow in the\n"+
            "eyes is slowly fading");
   set_stats("str", 5);
   set_stats("wis", -15);
 
 }

set_id(arg) { return name == arg; }
query_no_save() { return 0; } /*Modified by Ahma due to the illusion abuse.*/
