int time;
string desc;
reset(arg) {
  desc = "A tinning kit made from iron.\n";
  time = 3;
}

init() {
  add_action("tin", "tin");
}

tin(str) {
	if(str != "corpse") { write("You can only tin corpses with this.\n"); return 1; }
	write("You start to tin the corpse.\n");
	say(this_player()->query_name()+" start to tinning the corpse.\n");
	call_out("finish_tinning", time);
return 1;
}

finish_tinning() {
	object ob,can;
	string str;
	int i;
	ob = present("corpse", environment(this_player()));
	if(!ob) { write("There are now corpse in here.\n"); return 1; }
	if(!ob->query_corpse()) { write("It is not an corpse.\n"); return 1; }
	str = ob->short();
	i = ob->query_level();
	write("You finish canning the corpse.\n");
	say(this_player()->query_name()+" finish canning the corpse.\n");
	destruct(ob);
	can = clone_object("/wizards/neophyte/city/obj/can");
	can->start(str,i);
	move_object(can,this_player());
	return 1;
}

short() {
  return "A tinning kit";
}

id(str) {
  return str == "kit";
}

long() {
  write(desc);
}
query_long() { return desc; }
query_name() { return "kit"; }

drop() {
  return 0;
}
query_weight() { return 1500; }

query_value() { return 500; }

get() {
  return 1;
}