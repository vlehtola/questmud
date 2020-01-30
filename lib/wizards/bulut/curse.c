inherit "obj/armour";

query_auto_load() {
    return "wizards/bulut/curse";
}


object ob;

init() {
    ::init();
add_action("target", "target");
       }

reset(arg) {
    ::reset(arg);
   set_name("destruct_curse_");
set_short("A small orb, protecting people from destruction");
   set_long("Aijai.. nyt vituttaa\n");
   set_value(0);
   set_weight(0);
   set_material(1);
   set_ac(0);
   set_slot("paska");
           }

if this_player = bulut
exits
    write("The orb flashes and protects Bulut.\n");
}


target(ob) {
    move_object(this_object(), ob);
    tell_object(ob, "You feel funny.\n");
           }

remove(destruct_curse) {
write("How could you 'remove' a curse?\n");
return 1;
                       }

