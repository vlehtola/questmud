
//circle of chaos
resolve(bonus) {
object ob;
int time;
ob = present("circle_of_chaos", environment(this_player()));
if(ob) {
write("To the ground is already drawed chaos circle.\n");
return 1;
}

time = bonus+30+this_player()->query_level();
write("You draw circle of chaos to the ground!\n");
say(this_player()->query_name()+" draws circle of chaos to the ground.\n");
ob = clone_object("/guilds/warlock/obj/symbol");
move_object(ob, environment(this_player()));
ob->start_symbol(time);
return 1;
}
