#define max_damage 1000
object weapon,target,explode;
string str;

get_time() {
  return random(3)+4;
}

query_type() { return "offensive"; }
ep_cost() { return 7; }

resolve_skill(string str) {
        int damage, weapon_skill;
        if(!this_player()->query_right_weapon()) { tell_object(this_player(), "You need a weapon to use this skill.\n"); return 1; }
        if(!str && this_player()->query_attack()) {
                str = lower_case(this_player()->query_attack()->query_name());
        }
        if(!str) {
                tell_object(this_player(), "Use strike at whom?\n");
                return 1;
        }
        target = present(str, environment(this_player()));
        if(!target || !living(target) || target == this_player()) {
                tell_object(this_player(), str+" is not valid target.\n");
                return 1;
        }
        weapon = this_player()->query_right_weapon();
        damage = (this_player()->query_str()/2) + (this_player()->query_dex()/2) + weapon->query_wc()/2;
        weapon_skill = this_player()->query_skills(lower_case(weapon->query_type()+"s"));
        damage = damage + weapon_skill;
             if(random(1000) == 0) {
             if(!this_player()->query_npc()) { this_player()->set_mastery("Offensive maneuvers",(this_player()->query_mastery()["Offensive maneuvers"] + 1)); }
           }
            if(!this_player()->query_npc()) { damage += this_player()->query_mastery()["Offensive maneuvers"]; }
        if(this_player()->query_berserk() && this_player()->query_attack()) {
    tell_object(this_player(), "The taste of blood fills your mouth as you focus your fury to the blod.\n");
    damage += 50;
}
    if(damage > 700) damage = 700;
        get_words(damage);
        if(this_player()->query_skills("double strike") > random(130)) {
                tell_object(this_player(), "You quickly strike again!\n");
                tell_object(target, this_player()->query_name()+" quickly strikes again!\n");
                damage = damage + 50;
        }
        if(this_player()->query_skills("tremendous blow") > random(150)) { damage = damage * 2; }
        if(damage > max_damage) damage = max_damage;
        if(this_player()->query_wiz())  tell_object(this_player(), "Skill: "+weapon_skill+" Damage: "+damage+"\n");
        target->attack_object(this_player());
        target->hit_with_spell(damage, "physical");
}

fail_skill() {
        tell_object(this_player(), "You fail the skill.\n");
        say(this_player()->query_name()+" fails the skill.\n");
}

get_words(int damage) {
        switch(damage) {
case 0..150:
     tell_object(this_player(), "Your weak strike just bounces of the "+target->query_name()+"'s body.\n");
         tell_object(target, this_player()->query_name()+" weak strike just bounche's of your body.\n");
         say(this_player()->query_name()+" weak strike just bounche of the "+target->query_name()+"'s body.\n",target);
     break;
case 151..250:
     tell_object(this_player(), "You move swiftly and skillfully strike "+target->query_name()+".\n");
     tell_object(target, this_player()->query_name()+" moves swiftly and skillfully strikes you.\n");
     say(this_player()->query_name()+" moves swiftly and skillfully strikes "+target->query_name()+".\n",target);
     break;
case 251..350:
     tell_object(this_player(), "You step forward and BRUTALLY strike "+target->query_name()+" with your "+weapon->query_name()+".\n");
     tell_object(target, this_player()->query_name()+" steps forward and BRUTALLY strike you with "+this_player()->query_possessive()+" "+weapon->query_name()+".\n");
     say(this_player()->query_name()+" steps forward and BRUTALLY strikes "+target->query_name()+" with "+this_player()->query_possessive()+" "+weapon->query_name()+".\n",target);
     break;
case 351..450:
     tell_object(this_player(), "You hear CRACKING sound from "+target->query_name()+" bones as you make MASSIVE strike.\n");
     tell_object(target, this_player()->query_name()+" makes your bones CRACK as "+this_player()->query_possessive()+" hits you with "+weapon->query_name()+".\n");
     say("Cracking sound is comfing from target BONES as "+this_player()->query_name()+" makes a MASSIVE strike.\n",target);
     break;
case 451..550:
     tell_object(this_player(), "You send out MIGHTY strike and "+target->query_name()+" SCREAMS in PAIN.\n");
     tell_object(target, this_player()->query_name()+" sends out a MIGHTY strike and you SCREAM in PAIN.\n");
     say(this_player()->query_name()+" sends out a MIGHTY strike and "+target->query_name()+" SCREAMS in PAIN.\n",target);
     break;
case 551..650:
     tell_object(this_player(), target->query_name()+" SHRIEKS in PAIN as you STRIKE your "+weapon->query_name()+" into "+target->query_possessive()+" head.\n");
     tell_object(target, "You SHRIEK in PAIN as "+this_player()->query_name()+" STRIKES "+this_player()->query_possessive()+" "+weapon->query_name()+" into your head.\n");
     say(target->query_name()+" SHRIEKS in PAIN as "+this_player()->query_name()+" STRIKES "+this_player()->query_possessive()+" "+weapon->query_name()+" into "+target->query_possessive()+" head.\n",target);
     break;
        }
}
