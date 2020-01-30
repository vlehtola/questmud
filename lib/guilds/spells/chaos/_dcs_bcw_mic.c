#define WARLOCK_D "/daemons/warlock_d"

//Bless chaos sword
resolve(bonus, string target, caster_ob) {
object ob;
object who;
int souls;
int time;
int boost;
if(!caster_ob)caster_ob=this_player();
who=this_player();
ob = present("warlock_weapon", caster_ob);
if(!target) {
tell_object(caster_ob, "Usage: cast dcs bcw mic at boost <amount>\n");
return 1;
}
if(sscanf(target, "boost %d", souls) != 1) {
tell_object(caster_ob, "Usage: cast dcs bcw mic at boost <amount>\n");
return 1;
}
if(ob->query_type() != "blade") {
tell_object(caster_ob, "You don't have the right chaos weapon.\n");
return 1;
}
if(ob->query_warlock_boost()) {
tell_object(caster_ob, "That weapon is already blessed.\n");
return 1;
}
souls = 100+boost+who->query_level();
if(WARLOCK_D->query_souls(who->query_real_name()) < souls) {
tell_object(caster_ob, "You don't have enough souls sacrificed to cast this spell.\n");
return 1;
}
time = who->query_skills("knowledge of chaos")*2+300;
time+= who->query_int()+souls+bonus;
tell_object(caster_ob, "You call blessing upon the chaos sword.\n");
tell_room(environment(caster_ob), caster_ob->query_name()+" calls blessing upon the chaos sword.\n", ({ caster_ob }));
ob->set_warlock_boost(time);
WARLOCK_D->reduce_souls(who->query_real_name(), souls);
return 1;
}
