int percent, mastery, type, duration;
object ob, prot;
string text;

resolve(class,effect_bonus,target, caster_ob) {
    int max, max_prot, type;
    if (!target) {
        tell_object(caster_ob, "Cast at whom?\n");
        return 1;
    }
    ob = present(lower_case(target), environment(caster_ob));
    if (!ob) {
        tell_object(caster_ob, "There is no " + capitalize(target) + " here.\n");
        return 1;
    }
    mastery = 0;
    type = 1;
    if(class == "fla" && ob->query_see_invisible()) {
      tell_object(caster_ob, ob->query_name()+" already has magical vision.\n");
      return 1;
    }
    if(class == "brr" && ob->query_invisibility_level()) {
      tell_object(caster_ob, ob->query_name()+" is already invisible.\n");
      return 1;
    }
    mastery = this_player()->query_skills("mastery of invisibility");
    if(mastery > random(30)) type += 1;
    if(mastery > (30+random(40))) type += 1;
    if(mastery > (70+random(30))) type += 1;
    if(type == 1) text = "a tiny";
    if(type == 2) text = "an average";
    if(type == 3) text = "a good";
    if(type > 4) type = 4;
    if(type == 4) text = "an incredible";
    mastery += this_player()->query_skills("mastery of protection")/3;
    duration = (5 * 60) + (effect_bonus/3) + (mastery * 3);
    tell_object(caster_ob, "You feel like your spell had "+text+" effect.\n");
    if(class == "fla") {
      duration = duration * 3;
      prot = clone_object("/guilds/spell_obj/see_invisibility");
      prot->start(ob,type,duration);
      if (ob != caster_ob) {
        tell_object(caster_ob, capitalize(target)+"'s eyes glow blue for a while.\n");
      }
      tell_room(environment(caster_ob), capitalize(target) + "'s eyes flicker for a while.\n", ({ob}));
      tell_object(ob, "You feel like your vision is enhanced.\n");
      return 1;
    }
    prot = clone_object("/guilds/spell_obj/invisibility");
    prot->start(ob,type,duration);
    if (ob != this_player()) {
        tell_object(caster_ob, capitalize(target)+" turns invisible.\n");
    }
    tell_room(environment(caster_ob), capitalize(target) + " suddenly disappears!\n", ({ ob }));
    tell_object(ob, "You feel dizzy.\n");
    return 1;
}

