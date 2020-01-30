#define WARLOCK_D "/daemons/warlock_d"

//stat boost for demon
resolve(bonus, string target) {
object ob;
int time;
string str;
int boost;
int power;
if(!target) {
write("Usage: cast dcs cab mic at <target> boost <amount>\n");
return 1;
}
if(sscanf(target, "%s boost %d", str, boost) != 2) {
write("Usage: cast dcs cab mic at <target> boost <amount>\n");
return 1;
}
ob = present(str, environment(this_player()));
if(!ob) {
write("No "+str+" here.\n");
return 1;
}
if(!ob->query_demon()) {
write("This spell can only be casted at demons.\n");
return 1;
}
if(ob->query_chaos_stat()) {
write("This boost is already casted at that\n");
return 1;
}
if(WARLOCK_D->query_souls(this_player()->query_real_name()) < 50+boost+this_player()->query_level()) {
write("You don't have enough souls sacrificed to cast this spell.\n");
return 1;
}

time = bonus*6+boost;
power = time/200;

write("You draw powers of chaos to bless the demon!\n");
say(this_player()->query_name()+" draws powers of chaos to bless the demon.\n");
ob->start_chaos_stat(time, power);
WARLOCK_D->reduce_souls(this_player()->query_real_name(), 50+boost);
return 1;
}
