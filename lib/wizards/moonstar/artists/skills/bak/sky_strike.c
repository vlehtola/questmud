#define MASTERY_D "/daemons/mastery_d"
get_time() {
 return random(3)+3;
}
query_type() { return "offensive"; }

ep_cost() { return 7; }

resolve_skill(str, object ob) {
    int dama, weapon_skill;
    object limb,target;
    string slot;
    if(!ob)ob=this_player();

    if(!ob->query_right_weapon() || !ob->query_left_weapon()) {
        write("You need to wield knuckles in your right and left hand to use sky strike.\n");
        return 1;
    }

    if( ob->query_right_weapon()->query_type() != "knuckles" ||
        ob->query_left_weapon()->query_type() != "knuckles") {
        write("You need to wield knuckles in your right and left hand to use sky strike.\n");
        return 1;
    }


     if(!str && ob->query_attack()) {
        str = lower_case(ob->query_attack()->query_name());
     }
     if (!str) {
        tell_object(ob,"Use sky strike at whom?\n");
        return 1;
}
     target = present(str, environment(ob));
     if(!target || !living(target) || target == ob) {
        tell_object(ob,capitalize(str)+" is not a valid target.\n");
        return 1;
     }

  dama = (this_player()->query_str()+this_player()->query_dex());
  dama = (this_player()->query_skills("sky strike") + this_player()->query_skills("claws storm") + this_player()->query_skills("dragon blow") + this_player()->query_skills("advanced martial arts") + this_player()->query_skills("martial arts") + dama/4*3 + this_player()->query_skills("body anatomy")*2 + this_player()->query_skill("focused sky strike")*2);
    if(ob->query_wiz()) tell_object(ob,"Skill: "+weapon_skill+" Dam: "+dama+"\n");
if(dama > 1600) { dama = 1600; }
    if(this_player()->query_skills("focused sky strike") > random(500)) {
    write("You breath deeply and focus your sky strike.\n");
    dama = dama + (random(600)+500);
  }
dama += MASTERY_D->mastery("Mastery of body focusing",this_player(),target)*10;
     switch(dama) {
        case 0..100:
        tell_object(ob,"You try to jump in the air and sky strike "+target->query_name()+" but you just weakly slap "+target->query_name()+" face!.\n");
        tell_object(target, ob->query_name()+" tries to strike you with knuckles but it's only a weak slap!\n");
        tell_room(environment(ob), ob->query_name()+" tries to strike"+target->query_name()+"'s face with knuckles but it just a weak slap!\n", ({ ob, target, }));
    break;
    case 101..250:
    tell_object(ob, "You strike your knuckles in the "+target->query_name()+"'s exposed chest.\n");
    tell_object(target, ob->query_name()+" strikes "+ob->query_objective()+" knuckles in your exposed chest.\n");
    tell_room(environment(ob), ob->query_name()+" strikes "+ob->query_objective()+" knuckles in the chest of "+target->query_name()+".\n", ({ ob, target}));
    break;
    case 251..450:
    tell_object(ob, "You jump in the air smash your sonkal directly at the neck of "+target->query_name()+".\n");
    tell_object(target, ob->query_name()+" jumps in the air and smashes "+ob->query_objective()+" sonkal directly at your neck.\n");
    tell_room(environment(ob), ob->query_name()+" jumps in the air and smashes "+ob->query_objective()+" sonkal directly at the neck of "+target->query_name()+".\n", ({ ob, target}));
    break;
    case 451..700:
    tell_object(ob, "You WHIRL towards "+target->query_name()+" and kick bandae dolloy chagi directly at the nose of "+target->query_name()+"!\n");
    tell_object(target, ob->query_name()+" WHIRLS towards you and kicks bandae doloy chagi directly at your nose!\n");
        tell_room(environment(ob), ob->query_name()+" WHIRLS towards "+target->query_name()+" and kicks bandae dolloy chagi directly at the nose "+target->query_name()+"!\n", ({ ob, target}));
    break;
    case 701..1000:
    tell_object(ob, "You rush towards "+target->query_name()+" and SMACK your knuckles directly at the nose of "+target->query_name()+"!\n");
    tell_object(target, ob->query_name()+" rushes towards you and SMACKS "+ob->query_objective()+" knuckles directly at your nose!\n");
    tell_room(environment(ob), ob->query_name()+" rushes towards "+target->query_name()+" and SMACKS "+target->query_name()+"'s head!\n", ({ ob, target}));
    break;
    case 1001..1400:
    tell_object(ob, "You whirl with amazing speed towards the "+target->query_name()+" and scream 'HETCHOO'!\n");
    tell_object(ob, "Suddenly "+target->query_name()+" doesn't move anymore and your knuckles PENETRATES his face!\n");
    tell_object(target, ob->query_name()+" screams 'HETCHOO' and vanishes.\n");
    tell_object(target, ob->query_name()+" comes visible and STRIKES your face with amazing FORCE making your nose to start bleed!\n");
    tell_room(environment(ob), ob->query_name()+" STRIKES "+target->query_name()+" with amazing FORCE straight to face!\n", ({ ob, target}));
    break;
    case 1401..1800:
    tell_object(ob, "You close your eyes and jump in the air while whirling trought the air.\n");
    tell_object(ob, "Suddenly your knuckles flashes and sends a ball of lightning directly at "+target->query_name()+" making him SCREAM in pain!\n");
    tell_object(target, ob->query_name()+" jumps in the air and screams 'SANTZENSO ELECS'.\n");
    tell_object(target, "Suddenly a ball of lightning strikes directly at your chest making you fall back!\n");
    tell_room(environment(ob), ob->query_name()+" knuckles flashes and a ball of lightning strikes "+target->query_name()+" body!\n", ({ ob, target}));
    break;
    case 1801..9999:
    tell_object(ob, "You focus all your strength and scream 'SASENZOR ZAROR DI'\n");
    tell_object(ob, "You rush towards "+target->query_name()+" and PENETRATE "+target->query_name()+" chest with CRUSHING sound making "+target->query_name()+" scream in PAIN!\n");
    tell_object(target, ob->query_name()+" screams 'SASENZOR ZAROR DI' and PENETRATES your chest with CRUSHING soung making you scream in PAIN!\n");
    tell_room(environment(ob), ob->query_name()+" screams 'SASENZOR ZAROR DI' and PENETRATES "+target->query_name()+" chest with CRUSHING sound making "+target->query_name()+" scream in PAIN!\n", ({ ob, target}));
    break;
    }
    ob->attack_object(target, 1);
    target->hit_with_spell(dama, "physical", ob);
}

fail_skill(str, ob) {
    object target;
     if(!ob)ob=this_player();
    if (!str) { tell_object(ob,"You fail the skill.\n"); return; }
    target = present(str, environment(ob));
    if (!target) { tell_object(ob,"You fail the skill.\n"); return; }
    tell_object(ob,"You try to sky strike "+str+".\n");
    tell_object(target, ob->query_name() + " tries to sky strike you!\n");
    tell_room(environment(ob), capitalize(ob->query_name()) + " tries to sky strike " + capitalize(target->query_name()) + " but fails.\n", ({ target, ob }));
    target->attack_object(ob);
}
