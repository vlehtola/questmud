//Summon lesser demon
#define WARLOCK_D "/daemons/warlock_d"
resolve(bonus, string str) {
int i;
string type;
if(!str) {
write("Usage: cast dcs cad mic at boost <amount> <type>\n");
write("Type can be cleric|fighter|mage\n");
return 1;
}
if(sscanf(str, "boost %d %s", i, type) != 2) {
write("Usage: cast dcs cad mic at boost <amount> <type>\n");
write("Type can be cleric|fighter|mage\n");
return 1;
}
if(WARLOCK_D->query_souls(this_player()->query_real_name()) < i+1000) {
write("You don't have enough souls sacrificed to cast this spell.\n");
return 1;
}
WARLOCK_D->summon_demon("minor", i/5, type);
i=i+1000;
WARLOCK_D->reduce_souls(this_player()->query_real_name(), i);
return 1;
}

