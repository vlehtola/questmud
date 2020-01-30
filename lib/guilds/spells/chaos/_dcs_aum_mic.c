#define WARLOCK_D "/daemons/warlock_d"

//Shield of chaos
resolve(bonus, string target) {
object ob;
int time;
string str;
int boost;
int souls;
if(!target) {
write("Usage: cast dcs aum mic at <target> boost <amount>\n");
	return 1;
}
if(sscanf(target, "%s boost %d",str, boost) != 2) {
write("Usage: cast dcs aum mic at <target> boost <amount>\n");
return 1;
}


ob = present(str, environment(this_player()));
if(!ob) {
write("No "+str+" here.\n");
return 1;
}
if(!ob->query_demon()) {
write("This spell can only be casted at demon's.\n");
return 1;
}
if(ob->query_controller() != this_player()->query_real_name()) {
write("You can only cast this spell demons that are summoned by you!\n");
return 1;
}
souls = boost+100+this_player()->query_level();

if(ob->query_chaos_shield()) {
write(str+" is already shielded.\n");
return 1;
}

if(WARLOCK_D->query_souls(this_player()->query_real_name()) < souls) {
write("You don't have enough souls sacrificed to cast this spell.\n");
return 1;
}
time = souls+boost+bonus;
time +=600;

write("You create shield of chaos around "+str+"!\n");
say(this_player()->query_name()+" creates shield of chaos around "+str+".\n");
ob->set_chaos_shield(time);
WARLOCK_D->reduce_souls(this_player()->query_real_name(), souls);
return 1;
}