//summon
resolve(bonus, target, caster_ob) {
    object ob,vine;
    int force_vine;
    force_vine = 0;
    ob = find_player(target);
    if(!caster_ob)caster_ob=this_player();
    if (!ob) {
        tell_object(caster_ob, "No such a player.\n");
        return 1;
    }
    if(ob->query_wiz()) {
        tell_object(caster_ob, "Oops. Maybe you shouldn't have tried that.\n");
        clone_object("/guilds/spell_obj/hunter")->start_hunt(lower_case(this_player()->query_name()));
        return 1;
    }
    if (environment(ob)->query_not_out() && !caster_ob->query_npc()) {
     tell_object(caster_ob, "You can't locate "+ob->query_name()+".\n");
        if(caster_ob->query_skills("navigation mastery") > random(120)) {
                tell_object(caster_ob, "...but due to your supreme knowledge of navigation you succeed.\n");
                force_vine = 1;
        } else {
                return 1;
        }
    }
    if(environment(ob)->query_property("no_summon") || environment(caster_ob)->query_property("no_summon")) {
      tell_object(caster_ob, "A planar aura prevents you from completing your spell.\n");
      return 1;
    }
    if (present("teleport lock", ob)) {
    tell_object(caster_ob, "You locate "+ob->query_name()+" but "+ob->query_pronoun()+" is locked beyond your reach.\n");
      return 1;
    }
    vine = present("vine",ob);
    if(vine) {
      if(vine->query_target() == caster_ob) {
        tell_object(caster_ob, "You already tried to summon "+ob->query_name()+".\n");
        return 1;
      }
    }
    if(caster_ob->query_skills("navigation mastery") < random(110) ||
        ob->query_clan() && caster_ob->query_clan() &&
        ob->query_clan() != caster_ob->query_clan() || force_vine) {
      /* pull vine hommeli */
      tell_room(environment(caster_ob), caster_ob->query_name()+" throws a vine to "+ob->query_name()+".\n");
      tell_room(environment(ob), caster_ob->query_name()+" throws a vine to "+ob->query_name()+".\n");
      vine = clone_object("/guilds/spell_obj/vine");
      vine->set_target(caster_ob);
      move_object(vine, ob);
      return 1;
    }
    tell_object(ob, caster_ob->query_name()+" summons you.\n");
    tell_object(caster_ob, "You summon "+ob->query_name()+".\n");
    ob->move_player("XX",environment(caster_ob));
}

wand_summon(bonus, target, caster_ob) {
      object vine,ob;
      ob = find_player(target);
    if(!caster_ob)caster_ob=this_player();
    if (!ob) {
        tell_object(caster_ob, "No such a player.\n");
        return 1;
    }
    if(ob->query_wiz()) {
        tell_object(caster_ob, "Oops. Maybe you shouldn't have tried that.\n");
        clone_object("/guilds/spell_obj/hunter")->start_hunt(lower_case(this_player()->query_name()));
        return 1;
    }
    if (present("teleport lock", ob)) {
    tell_object(caster_ob, "You locate "+ob->query_name()+" but "+ob->query_pronoun()+" is locked beyond your reach.\n");
      return 1;
    }
    if(environment(ob)->query_property("no_summon") || environment(caster_ob)->query_property("no_summon")) {
      tell_object(caster_ob, "A planar aura prevents you from completing your spell.\n");
      return 1;
    }
    vine = present("vine",ob);
    if(vine) {
      if(vine->query_target() == caster_ob) {
        tell_object(caster_ob, "You already tried to summon "+ob->query_name()+".\n");
        return 1;
      }
    }
      vine = clone_object("/guilds/spell_obj/vine");
      tell_room(environment(caster_ob), caster_ob->query_name()+" throws a vine to "+ob->query_name()+".\n");
      tell_room(environment(ob), caster_ob->query_name()+" throws a vine to "+ob->query_name()+".\n");
      vine = clone_object("/guilds/spell_obj/vine");
      vine->set_target(caster_ob);
      move_object(vine, ob);
      return 1;
    }
