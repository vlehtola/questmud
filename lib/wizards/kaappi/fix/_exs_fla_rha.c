#define MASTERY_D "/daemons/mastery_d"
object tp;
status disc_filter(object ob) {
        if(ob->query_disc_owner() == tp->query_name()) return 1;
        return 0;
}

resolve(int bonus,string str, caster_ob) {
        object ob;
        object *obs;

        int i;

if(!caster_ob)caster_ob=this_player();
tp=caster_ob;
        obs = all_inventory(environment(caster_ob));
        obs = filter(obs,"disc_filter");

        bonus += caster_ob->query_int()/2;

        if(sizeof(obs) == 0) {
                ob = clone_object("/guilds/spell_obj/floating_disc");
                move_object(ob, environment(caster_ob));
                ob->set_power(bonus+MASTERY_D->query_mastery("Dangerous Fire",caster_ob), caster_ob);
                write("You summon your floating disc.\n");
                tell_room(environment(caster_ob), caster_ob->query_name()+" summons a floating disc.\n", ({caster_ob }));
                return 1;
                }

        else {
                ob = obs[0];
                ob->set_power(bonus, caster_ob,1);
        tell_object(caster_ob, "You refresh your floating disc.\n");
        tell_room(environment(caster_ob), caster_ob->query_name()+" refreshes "+caster_ob->query_possessive()+" floating disc.\n");
                return 1;
        }
}
