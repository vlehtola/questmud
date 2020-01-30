#define WARLOCK_D "/daemons/warlock_d"

//Chaos armour
resolve(bonus, string target,caster_ob) {
object ob;
object who;
int souls;
int boost;
int time;
if(!caster_ob)caster_ob=this_player();
who=this_player();
if(!target) {
tell_object(caster_ob, "Usage: cast dcs car lec at boost <amount>\n");
return 1;
}
if(sscanf(target, "boost %d", boost) != 1) {
tell_object(caster_ob, "Usage: cast dcs car lec at boost <amount>\n");
return 1;
}
ob = present("warlock_armour", caster_ob);
if(ob) {
tell_object(caster_ob, "You already have warlock armour.\n");
return 1;
}
if(caster_ob->query_demon()) {
who=find_player(caster_ob->query_demon_master());
}
souls = 50+boost+who->query_level();
if(WARLOCK_D->query_souls(who->query_real_name()) < souls) {
tell_object(caster_ob, "You don't have enough souls sacrificed to cast this spell.\n");
return 1;
}
boost += who->query_skills("knowledge of chaos")+bonus;
time = souls+boost*4;
boost = boost/150; // was 100 -N
if(boost > 10)boost=10;
tell_object(caster_ob, "You call the void and receive a chaos armour.\n");
tell_room(environment(caster_ob), caster_ob->query_name()+" calls the void and receives a chaos armour.\n", ({ caster_ob }));
ob = clone_object("/guilds/warlock/obj/armour");
move_object(ob, caster_ob);
ob->set_class(who->query_skills("knowledge of chaos")/10);
//ob->set_stats("con", boost);
ob->set_stats("int", boost);
ob->set_stats("str", boost);
ob->set_stats("spr", boost);
ob->set_timer(time);
WARLOCK_D->reduce_souls(who->query_real_name(), souls);
return 1;
}
