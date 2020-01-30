inherit "obj/armour";
 
start() {
    set_class(8);
    set_sub_type("cloak");
    set_name("cloak");
    set_alias("hoovee");
    set_short("A cloak with the emblem of HV on it");
    set_long("hoovee cloak.\n");
    set_resists("cold", 10);
}
 
init() {
  add_action("rip","rip");
}
 
int rip(string str) {
if(str!="cloak") return 0;
 
write("You rip up the cloak, and only the emblem and a torn cloak is left.\n");
move_object(clone_object("/wizards/walla/northern/stuph/rag"),
                this_player());
move_object(clone_object("/wizards/walla/northern/stuph/holecloak"),
                this_player());
destruct(this_object());
return 1;
}
