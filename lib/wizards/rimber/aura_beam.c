get_time() {
  if(this_player()->query_npc()) return 5;
return random(3)+3;
}
query_type() { return "offensive"; }

ep_cost() { return 2; }

resolve_skill(str, object ob) {
    int dama, weapon_skill;
    object limb,target;
    string slot;
    if(!ob)ob=this_player();
    if(!ob->query_right_weapon()) {
        write("You need to wield sorcerers staff in your right to use aurabeam.\n");
        return 1;
    }
    if (this_player()->query_attack()) {
        write("You cannot use aurabeam while in combat.\n");
        return 1;
    }
    if( ob->query_right_weapon()->query_name() != "club") {
        write("You need to wield your staff in your right to use aurabeam.\n");
        return 1;
    }


     if(!str && ob->query_attack()) {
        str = lower_case(ob->query_attack()->query_name());
     }
     if (!str) {
        tell_object(ob,"Use aurabeam at whom?\n");
        return 1;
     }
     target = present(str, environment(ob));
     if(!target || !living(target) || target == ob) {
        tell_object(ob,capitalize(str)+" is not a valid target.\n");
        return 1;
     }

  dama = (this_player()->query_int()*2+this_player()->query_wis()*2)*3;
  dama += (this_player()->query_skills("powered will")*3 +
this_player()->query_skills("focused will")*2 +
this_player()->query_skills("mind link")*2 +this_player()->query_skills("faith of izyldran")*5);
    if(ob->query_wiz()) tell_object(ob,"Skill: "+weapon_skill+" Dam: "+dama+"\n");
if(dama > 9000) { dama = 9000; }
    if(this_player()->query_skills("mind critical") > random(600)) {
    write("You focus your mind on POWER.\n");
    dama = dama + (random(800)+1000);
  }


    switch(dama) {
        case 0..9000:
        tell_object(ob,"You point your staff at "+target->query_name()+" and focus your will!.\n");
        tell_object(ob,"A huge aurabeam comes out from the staff and hits "+target->query_name()+" with amazing POWER\n");
        tell_object(target, ob->query_name()+" points his staff at you and a huge aurabeam hits you making your head almost explode!\n");
        tell_room(environment(ob), ob->query_name()+" points staff at "+target->query_name()+" and a huge aurabeam hits "+target->query_name()+" with FORCE'\n", ({ ob, target, }));
    }
    ob->attack_object(target, 1);
    target->hit_with_spell(dama, "fire", ob);
    target->set_stunned(random(4) + 2);
    this_player()->set_sp( ( this_player()->query_sp() - (100 + dama/14)));
}

 fail_skill(str, ob) {
    object target;
     if(!ob)ob=this_player();
    if (!str) { tell_object(ob,"You fail the skill.\n"); return; }
    target = present(str, environment(ob));
    if (!target) { tell_object(ob,"You fail the skill.\n"); return; }
    tell_object(ob,"You point your staff at "+str+" but nothing happends.\n");
     tell_object(target, ob->query_name() + " tries to cast a aurabeam at you!\n");
    tell_room(environment(ob), capitalize(ob->query_name()) + " points his staff at " + capitalize(target->query_name()) + " but northing happends.\n", ({ target, ob}));
    target->attack_object(ob);
}

