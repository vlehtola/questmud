string owner;
string dir;
int x,y;
init() {
add_action("_enter","enter");
if (!owner) { owner=="nobody"; }
}


id(str) {
return str == "car";
}


short() {
if(!owner) { return "A car, nobody sits inside it"; }
return("A car, " + owner + " is driving it");
}

long() {
if(present(this_player(),this_object())) {
write("You are sitting inside a car!\n");
write("There is a window here, where you can look out.\n");
write("There is one obvious exit: leave.\n");
return 1;}
write("A fancy looking car!\n");
}

_cs() {
move_object(this_object(),"/world/city/cs");
}

_north() {
 owner = this_player()->query_name();
 dir = environment(this_object())->query_valid_dir("north");
 if(!dir) { write("What?\n"); return 1; }
check_outw();
 tell_room(environment(this_object()),"A car drives to north.\n");

if(this_player()->query_wiz()) {
write(dir + "\n");
}

 move_object(this_object(),dir);
 write("You drive wildly!\n");
 write(environment(this_object())->short());
 tell_room(dir,"A car arrives from north.\n");
return 1;
}
_east() {
owner = this_player()->query_name();
dir = environment(this_object())->query_valid_dir("east");
 if(!dir) { write("What?\n"); return 1; }
check_outw();
tell_room(environment(this_object()),"A car drives to east.\n");

if(this_player()->query_wiz()) {
write(dir + "\n");
}

move_object(this_object(),dir);
write("You drive wildly!\n");
write(environment(this_object())->short());
tell_room(dir,"A car arrives from east.\n");
return 1;

}
_south() {
owner = this_player()->query_name();
dir = environment(this_object())->query_valid_dir("south");
 if(!dir) { write("What?\n"); return 1; }
check_outw();
tell_room(environment(this_object()),"A car drives to south.\n");

if(this_player()->query_wiz()) {
write(dir + "\n");
}


move_object(this_object(),dir);
write("You drive wildly!\n");
write(environment(this_object())->short());
tell_room(dir,"A car arrives from north.\n");
return 1;
}
_west() {
owner = this_player()->query_name();
dir = environment(this_object())->query_valid_dir("west");
 if(!dir) { write("What?\n"); return 1; }
check_outw();
tell_room(environment(this_object()),"A car drives to west.\n");

if(this_player()->query_wiz()) {
write(dir + "\n");
}


move_object(this_object(),dir);
write("You drive wildly!\n");
write(environment(this_object())->short());

tell_room(dir,"A car arrives from west.\n");
return 1;
}

_enter() {
owner = this_player()->query_name();
write("You enter the car\n");
tell_room(environment(this_object()),this_player()->query_name() + " enters the car.\n");
move_object(this_player(),this_object());
add_action("_leave","leave");
add_action("_north","north");
add_action("_west","west");
add_action("_east","east");
add_action("_south","south");
add_action("_look","look");
add_action("_cs","cs");
remove_action("enter");
return 1;
}
_leave() {
owner ="nobody";
write("You step out from the car.\n");
move_object(this_player(),environment(this_object()));
tell_room(environment(this_object()),this_player()->query_name() + " steps out from the car.\n");
return 1;
}

_look(str) {
if(str == "at window") {
write("You look out from the car's window and see:\n");
write(environment(this_object())->long());
	return 1;
	}
return 0;
}

check_outw() {
if (sscanf(dir,"out: %d %d", x, y)) {
move_object(this_object(),"out: " + x + " " + y);
return 1;
	}
}
