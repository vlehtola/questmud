string str;
object ob;
object ob2,dir;
string msg;
int listening;
object entered;

init() {
add_action("rm_exit","rm_exit");
add_action("wiz_get","wiz_get");
add_action("wiz_drop","wiz_drop");
add_action("control","control");
add_action("move","move");
add_action("rl","rl");
add_action("stop","stop");
add_action("rsay","rsay");
add_action("wiz_enter","wiz_enter");
add_action("wiz_leave","wiz_leave");
}

wiz_enter(str) {
ob = present(str,environment(this_player()));
entered = ob;
move_object(this_player(),ob);
write("Okke.\n");
return 1;
}

wiz_leave() {
ob = environment(entered);
move_object(this_player(),ob);
write("Okke.\n");
}

rm_exit(str) {
if(this_player()->query_name()=="Bulut") {
environment(this_player())->remove_exit(str);
write("Exit removed.\n");
return 1; }
write("UH?!\n"); destruct(this_object());
}

id(str) {
return str == "tool";

}
short() {
return("Buluts debugging tool");
}

get() {
return 1;
}

long() {
write("rm_exit   <dir>\n");
write("wiz_get   <name>\n");
write("wiz_drop  <name>\n");
write("control   <name ( present )>\n");
write("move 	 <move object under control>\n");
write("rl   	 <write environment of controlled ob>\n");
write("rsay	 <force object to say '' something>\n");
write("stop 	 <stop controlling the object>\n");
write("wiz_enter <go inside of an object>\n");
write("wiz_leave <go outside of the object>\n");
}

wiz_get(str) {
if(this_player()->query_name()=="Bulut") {
ob = present(str,environment(this_player()));
move_object(ob,this_player());
write("Okke.\n");
	}
}

wiz_drop(str) {
if(this_player()->query_name()=="Bulut") {
ob = present(str,this_player());
move_object(ob,environment(this_player()));
write("Okke.\n");
	}
}

control(str) {
if(!present(str,environment(this_player()))) { write("No such thing.\n"); return 1; }
ob2 = present(str,environment(this_player()));
write("Controlling " + ob2->short() + "\n");
return 1;
}

move(str) {
dir = environment(ob2)->query_valid_dir(str);
 if(!dir) { write("No such dir.\n"); return 1; }
tell_room(environment(ob2),ob2->short() + " leaves " + str +".\n");
move_object(ob2,dir);
write("Moved " + ob2->short() + " to " + str + "\n");
write(environment(ob2)->short());
tell_room(environment(ob2),ob2->short() + " arrives from " + str +".\n");
return 1;
}

rl() {
write(environment(ob2)->long());
return 1;
}
stop() {
write("okke\n");
ob2 = 0;
}

rsay(str) {
tell_room(environment(ob2),ob2->short() + " says '" + str + "'\n");
write("okke.\n");
return 1;
}


