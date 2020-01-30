resolve(effect_bonus, target, caster_ob) {
    object ob, prot;
    int number, duration;
    if (!target) {
        tell_object(caster_ob, "You have to give a target for mirror image.\n");
        return 1;
    }
    ob = present(target, environment(caster_ob));

    if (!ob) {
        tell_object(caster_ob, "No "+capitalize(target)+" here.\n");
        return 1;
    }
// modified by Celtron 4.4.2004. can now cast mirrors only on players
    if(ob != find_player(target)) {
      tell_object(caster_ob, "You can place mirrors only on players.\n");
      return 0;
    }
    if (ob->query_mirror_image()) {
        tell_object(caster_ob, capitalize(ob->query_name()) + " already has mirror images.\n");
        return 0;
    }
    number = random(4 + effect_bonus / 30) + 3;

    if (number > 15) { number = 15; }

// Battle-tune (c) Torspo.
   if(ob->query_attack()) {
    if(number < 7) { number = 1; }
    else { number = number - (5+random(2)); }
   }

    duration = (2 * 60) + (effect_bonus / 3);
    prot = clone_object("guilds/spell_obj/mirror.c");
    prot->start(ob, number, duration);
    tell_room(environment(caster_ob),number + " images of " + capitalize(ob->query_name()) + " appear beside of him.\n", ({caster_ob}));
    tell_object(ob, number + " images of yourself appear beside of you.\n");
}
