object nuuh, elain;

id(str) { return str == "probe_tame_ob"; }

start(ob, ani) {
 nuuh = ob;
 elain = ani;
}

init() {
    add_action("quit", "quit");
}

quit() {
 write("You feel like your tamed animal is no longer under your control.\n"); 
 if (nuuh) { destruct(nuuh); }
 destruct(this_object());
}

safe_quit() {
 if (nuuh) { destruct(nuuh); }
 if(elain) {
   tell_room(environment(elain), elain->short()+" leaves back into the wilderness.\n");
   move_object(elain, "/world/special/dump");
   destruct(elain);
 }
 destruct(this_object());
}

get() { return 1; }
drop() { return 1; }
