
//circle of chaos
resolve(bonus) {
object ob;
int time;
ob = present("corpse", environment(this_player()));
if(!ob) {
write("There are no corpses here.\n");
return 1;
}
time = bonus+30+this_player()->query_level();
write("You sacrifice the corpse to dark gods\n");
say(this_player()->query_name()+" sacrifices the corpse to dark gods.\n");
destruct(ob);
this_player()->add_alignment(-10);
return 1;
}
