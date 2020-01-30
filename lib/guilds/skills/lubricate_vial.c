query_type() { return "witchcraft"; }

get_time() {
    return 12-(this_player()->query_skills("speedcrafting")/12);
}
ep_cost() { return 10-(this_player()->query_skills("speedcrafting")/20); }

resolve_skill(str) {
        object armour,potion,effect;
        int i;
        i = this_player()->query_skills("herbalist knowledge");
        if(!str) { write("Use at what?\n");
        return 1;
}
potion = present("vial", this_player());
armour = present(str, this_player());
if(!potion) {
        write("You don't have vial.\n");
        return 1;
}
if(!potion->query_potion() && !potion->query_prepared() && !potion->query_full()) {
        write("Is not valid vial.\n");
        return 1;
}
if(!potion->query_effect() == ({ "armour_strength", "armour_dexterity", "armour_wisdom", "armour_intelligence", "armour_fire", "armour_electric", "armour_poison", "armour_cold", "armour_constitution", })) {
        write("You can't lubricate that vial.\n");
        return 1;
}
if(!armour) {
        write("You dont have such thing.\n");
        return 1;
}
if(!armour->query_armour() && armour->query_worn()) {
        write(str+" is not valid target.\n");
        return 1;
}
if(armour->query_slot() != "torso") {
        write("Only torso armours can be enchanted.\n");
        return 1;
}

write("You lubricate some liquid on the "+armour->query_name()+".\n");
potion->get_lubricate(armour);
}
fail_skill() {
    write("You fail to lubricate the vial.\n");
    say(capitalize(this_player()->query_name()) + " fails to lubricate the vial.\n");
}

