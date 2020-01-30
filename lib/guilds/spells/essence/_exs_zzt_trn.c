resolve(bonus, target, caster_ob) {
    if (present("teleport lock", caster_ob )) {
      tell_object(caster_ob, "Your teleport lock prevents you from teleporting.\n");
      return 1;
    }
    if ( target && lower_case(target) == "asgroth" ) {
        caster_ob->move_player("XX#/wizards/moonstar/areas/asgroth/other/teleportroom");
        return;
    }
    /* must be force teleport, inn is no_teleport //Celtron */
    caster_ob->move_player("X#world/city/inn");
}
