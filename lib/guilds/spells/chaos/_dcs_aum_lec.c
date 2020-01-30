#define WARLOCK_D "/daemons/warlock_d"

//Aura of protection from chaos
resolve(bonus) {
object ob;
int time;
if(this_player()->query_chaos_aura()) {
write("You are already surrounded by aura of chaos!\n");
return 1;
}
if(WARLOCK_D->query_souls(this_player()->query_real_name()) < 50) {
write("You don't have enough souls sacrificed to cast this spell.\n");
return 1;
}

time = bonus+30+this_player()->query_level();
write("You draw aura of raw chaos to surround you!\n");
say(this_player()->query_name()+" is suddenly surrounded by aura of chaos.\n");
ob = clone_object("/guilds/warlock/obj/chaos_aura");
ob->start(this_player(), time);
WARLOCK_D->reduce_souls(this_player()->query_real_name(), 50);
return 1;
}
