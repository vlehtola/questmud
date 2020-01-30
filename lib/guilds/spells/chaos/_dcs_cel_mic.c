#define WARLOCK_D "/daemons/warlock_d"

//Shield of chaos
resolve(bonus, string target) {
object ob;
string str;
int boost;
int souls;
int amount;
if(!target) {
write("Usage: cast dcs cel mic at <target> boost <amount>\n");
	return 1;
}
if(sscanf(target, "%s boost %d",str, boost) != 2) {
write("Usage: cast dcs cel mic at <target> boost <amount>\n");
return 1;
}

if(lower_case(str) == lower_case(this_player()->query_real_name())) {
ob = this_player();
} else if(lower_case(str) == "demon") { ob = present("demon", environment(this_player())); }

if(!ob) { write("Cast at what?\n"); return 1; }

souls = boost+50;
amount = souls+this_player()->query_skills("knowledge of chaos")+bonus+100/2;

if(WARLOCK_D->query_souls(this_player()->query_real_name()) < souls) {
write("You don't have enough souls sacrificed to cast this spell.\n");
return 1;
}

write("You cure some of the "+ob->query_name()+" wounds.\n");
say(this_player()->query_name()+" cures some of the "+ob->query_name()+" wounds.\n");
ob->heal_hp(amount);
WARLOCK_D->reduce_souls(this_player()->query_real_name(), souls);
return 1;
}
