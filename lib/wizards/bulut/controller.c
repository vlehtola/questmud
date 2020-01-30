object ob;
string dir;

init() {
add_action("control","control");
add_action("move","move");
add_action("rl","rl");
add_action("stop","stop");
}

control(str) {
if(!present(str,environment(this_player()))) { write("No such thing.\n"); return 1; }
ob = present(str,environment(this_player()));
write("Controlling" + ob->short() + "\n");
}

move(str) {
dir = environment(this_object())->query_valid_dir(str);
 if(!dir) { write("No such dir.\n"); return 1; }
move_object(ob,dir);
write("Moved " + ob->short() + " to " + str + "\n");
write(environment(this_object())->short());
return 1;
}

rl() {
write(environment(ob))->long();
}
stop() {
write("okke\n");
ob = 0;
}

