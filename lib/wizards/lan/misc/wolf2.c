inherit "obj/monster";

string lan;
object ob;

reset(arg) {
    object money;
    ::reset(arg);
    if(arg) { return; }
    set_animal(1);
    set_level(10);
    set_exp(0);
    set_max_hp(100000);
    set_hp(query_max_hp());
    set_name("wolf");
    set_alias("wolf");
    set_short("Takke's pet Wolf ");
    set_long("You are looking at Takke's pet wolf. It looks like it could rip\n" +
    	     "your arm clean off. A good idea would be not to try and pet this\n" +
    	     "beast.\n"); 
    set_aggressive(0);
}

/* Follows leaving player. */

catch_tell(str) {
    if(sscanf(str, "%s fades", lan) == 1 || sscanf(str, "%s disappears", lan) == 1) {
        if(lan != "Lan") return;
        ob = find_player(lower_case(lan));
        if (!ob) return;
        call_out("move_to",1,ob);
}
} 


heart_beat() {
  if(find_player("lan")) return;
  say("The wolf disappears as its master leaves the realm.\n");
  destruct(this_object());
}


move_to(ob) {
        move_player("after " + ob->query_name(), environment(ob));
        say("Wolf enters the room after its master.\n", ob);
}