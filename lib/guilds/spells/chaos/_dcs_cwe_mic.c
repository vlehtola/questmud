#define WARLOCK_D "/daemons/warlock_d"

//Chaos bludgeon
resolve(bonus, string target, caster_ob) {
object ob;
object who;
int souls;
if(!caster_ob)caster_ob=this_player();
who = this_player();
ob = present("warlock_weapon", caster_ob);
if(ob) {
tell_object(caster_ob, "You already have warlock weapon.\n");
return 1;
}
if(caster_ob->query_demon()) {
who = find_player(caster_ob->query_demon_master());
} else

souls = 300;
if(WARLOCK_D->query_souls(who->query_real_name()) < souls) {
tell_object(caster_ob, "You don't have enough souls sacrificed to cast this spell.\n");
return 1;
}

tell_object(caster_ob, "You call the void and receive a chaos sword.\n");
tell_room(environment(caster_ob), caster_ob->query_name()+" calls the void and receives a chaos sword.\n", ({ caster_ob }));
ob = clone_object("/guilds/warlock/obj/sword");
move_object(ob, caster_ob);
ob->set_class(who->query_skills("knowledge of chaos")/10);
WARLOCK_D->reduce_souls(who->query_real_name(), souls);
return 1;
}
