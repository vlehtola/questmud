get_combat_texts(ob,tmp, name_of_weapon) {
    string what, what2, how, how2, where, causing, causing2, slot_text,seko, seko2;
    string name_of_attack, name_of_defender;
    object attacker_ob;
    int is_light;
    string weapon_type;
    attacker_ob = ob->query_attack();
    if(!attacker_ob) return;
    weapon_type = "bare hands";
    if (name_of_weapon) { weapon_type = name_of_weapon->query_type(); }
    if(!name_of_weapon && ob->query_npc()) weapon_type = "bludgeon";
    if (ob->query_animal()) { weapon_type = "animal"; }
    if(tmp == 0) {
      how = "hit";
      how2 = "hits";
      seko = ", but your blow bounces off from "+
        attacker_ob->query_possessive()+" armour";
      seko2 = ", but "+ob->query_possessive()+" blow bounces off"+
        " from your armour";
    }
    if (weapon_type == "bare hands") {
        if (tmp < 5) {
             how = "weakly pat";
             how2 = "weakly pats";
        }
        if (tmp > 4) {
             how = "pat";
             how2 = "pats";
        }
        if (tmp > 10) {
             how = "bump";
             how2 = "bumps";
        }
        if (tmp > 20) {
             how = "smack";
             how2 = "smacks";
        }
        if (tmp > 45) {
             how = "deliver";
             how2 = "delivers";
             seko = " a nasty punch";
             seko2 = seko;
        }
        if (tmp > 80) {
             how = "swing your fist with amazing quickness and it hits";
             how2 = "swings " + attacker_ob->query_possessive() +
                " fist with amazing quickeness and it hits";
             seko = "";
             seko2 = "";
        }
        if (tmp > 140) {
            how = "thrust your fist and hear an unpleasant sound as it impacts";
            how2 = "thrusts " +attacker_ob->query_possessive() +
                " fist and it sorely impacts";
            seko = "";
            seko2 = "";
        }
        if (tmp > 200) {
             how = "let out a mighty roar as your crushing fist hits";
             how2 = "roars mightily as " + attacker_ob->query_possessive() +
                    " crushing fist hits";
            seko = "";
            seko2 = "";
        }
        if (tmp > 300) {
             how = "summon all your strength and BRUTALLY hit";
             how2 = "summons all " + attacker_ob->query_possessive() +
        " strength and brutally HITS";
            seko = "";
            seko2 = "";
        }
    }
    if (weapon_type == "bludgeon") {
        if (tmp < 6) {
            how = "weakly bump";
            how2 = "weakly bumps";
        }
        if (tmp > 5) {
            how = "bump";
            how2 = "bumps";
        }
        if (tmp > 15) {
            how = "pummel";
            how2 = "pummels";
        }
        if (tmp > 40) {
            how = "bash";
            how2 = "bashes";
        }
        if (tmp > 80) {
            how = "cruelly bash";
            how2 = "cruelly bashes";
        }
        if (tmp > 140) {
            how = "pound";
            how2 = "pounds";
        }
        if (tmp > 200) {
            how = "barbalically pound";
            how2 = "barbalically pounds";
        }
        if (tmp > 400) {
            how = "make a quick turn and skillfully smash";
            how2 = "makes a quick turn and skillfully smashes";
            seko = "";
            seko2 = "";
        }
        if (tmp > 700) {
            how = "focus your strength and HAMMER";
            how2 = "HAMMERS with amazing force";
            seko = "";
            seko2 = "";
        }
        if (tmp > 1000) {
            how = "rush forward and BRUTALLY HAMMER";
            how2 = "rushes forward and BRUTALLY HAMMERS";
            seko = "";
            seko2 = "";
        }
    }
    if (weapon_type == "axe") {
        if (tmp < 6) {
             how = "weakly scratch";
             how2 = "weakly scratches";
        }
        if (tmp > 5) {
             how = "barely hit";
             how2 = "barely hits";
        }
        if (tmp > 15) {
             how = "weakly hit";
             how2 = "weakly hits";
        }
        if (tmp > 40) {
             how = "swing and hit";
             how2 = "swings and hits";
        }
        if (tmp > 80) {
             how = "whack";
             how2 = "whacks";
        }
        if (tmp > 140) {
             how = "hack";
             how2 = "hacks";
        }
        if (tmp > 200) {
             how = "furiously whack";
             how2 = "furiously whacks";
        }
        if (tmp > 300) {
             how = "advance and hack";
             how2 = "advances and hacks";
             seko = " furiously";
             seko2 = " furiously";
        }
        if (tmp > 500) {
             how = "focus your strength and brutally hack";
             how2 = "focuses " + ob->query_possessive() + " and brutally hacks";
        }
        if (tmp > 800) {
             how = "you swing your " + name_of_weapon->query_name() +
                " with full strength and hit";
             how2 = "swings " + ob->query_possessive() + " " +
                name_of_weapon->query_name() + " and hits";
             seko = " with a RENDING force";
             seko2 = " with a RENDING force";
        }
        if (tmp > 1000) {
             how = "swing your " + name_of_weapon->query_name() +
                " in a huge arc and SMASH it right in to";
             how2 = "swings " + ob->query_possessive() + " " +
                name_of_weapon->query_name() +
                " in a huge arc and SMASHES it right in to";
             seko = "'s chest with a RENDING force";
             seko2 = "r chest with a RENDING force";
        }
    }
    if (weapon_type == "blade") {
        if (tmp < 6) {
             how = "weakly scratch";
             how2 = "weakly scratches";
        }
        if (tmp > 5) {
             how = "slightly graze";
             how2 = "slightly grazes";
        }
        if (tmp > 15) {
             how = "carelessly swipe";
             how2 = "carelessly swipes";
        }
        if (tmp > 40) {
             how = "cut";
             how2 = "cuts";
        }
        if (tmp > 80) {
             how = "hastily slash";
             how2 = "hastily slashes";
        }
        if (tmp > 140) {
             how = "thrust and hit";
             how2 = "thrusts and hits";
        }
        if (tmp > 200) {
             how = "swipe and hit";
             how2 = "swipes and hits";
        }
        if (tmp > 300) {
             how = "severely cut";
             how2 = "severely cuts";
        }
        if (tmp > 500) {
             how = "quickly and skillfully slash";
             how2 = "quickly and skillfully slashes";
        }
        if (tmp > 800) {
             how = "skillfully thrust your "+name_of_weapon->query_name() + " at";
             how2 = "skillfully thrusts " + ob->query_pronoun() +
                        " " + name_of_weapon->query_name() + " at";
             seko = " and PIERCE "+ob->query_possessive();
             seko2 = " and PIERCES you";
        }
        if (tmp > 1000) {
             how = "swing your "+name_of_weapon->query_name()+" with FULL strength"+
                " and extremely accurately at";
             how2 = "swings " + ob->query_possessive()+" "+name_of_weapon->query_name() +
                " with FULL strength and extremely accurately at";
             seko = " with a RENDING force";
             seko2 = " with a RENDING force";
        }
    }
    if (weapon_type == "animal") {
        if (tmp < 5) {
             how = "pitifully scratch";
             how2 = "pitifully scratches";
        }
        if (tmp > 4) {
             how = "slightly graze";
             how2 = "slightly grazes";
        }
        if (tmp > 10) {
             how = "graze";
             how2 = "grazes";
        }
        if (tmp > 30) {
             how = "claw";
             how2 = "claws";
        }
        if (tmp > 70) {
             how = "bite";
             how2 = "bites";
        }
        if (tmp > 200) {
             how = "severely claw";
             how2 = "severely claws";
        }
        if (tmp > 300) {
             how = "powerfully bites";
             how2 = "powerfully bites";
        }
        if (tmp > 500) {
             how = "jump forward and CLAW";
             how2 = "jumps forward and CLAWS";
        }
        if (tmp > 800) {
             how = "LEAP forward and get a good grip on";
             how2 = "LEAPS forward and gets a good grip on";
             seko = " with your teeth";
             seko2 = " with "+ob->query_possessive()+" teeth";
        }
    }

    if (weapon_type == "knuckles") {
        if (tmp < 6) {
             how = "weakly punch";
             how2 = "weakly punches";
        }
        if (tmp > 5) {
             how = "barely smack";
             how2 = "barely smacks";
        }
        if (tmp > 15) {
             how = "weakly strike";
             how2 = "weakly strikes";
        }
        if (tmp > 40) {
             how = "whirl and hit";
             how2 = "whirls and hits";
        }
        if (tmp > 80) {
             how = "strike";
             how2 = "strikes";
        }
        if (tmp > 140) {
             how = "smack";
             how2 = "smacks";
        }
        if (tmp > 200) {
             how = "furiously crush";
             how2 = "furiously crushes";
        }
        if (tmp > 300) {
             how = "whirl and smack";
             how2 = "whirl and smacks";
        }
        if (tmp > 500) {
             how = "jump in the air and brutally CRUSH";
             how2 = "jumps in the air and brutally CRUSHES";
        }
        if (tmp > 800) {
             how = "you whirl your knuckles with amazing speed and smack";
             how2 = "whirls his knuckles with amazing speed and smacks";
             seko = " with a CRUSHING sound";
             seko2 = " with a CRUSHING sound";
        }
        if (tmp > 1000) {
             how = "jump in the air and with a flash you STRIKE your knuckles right in to";
             how2 = "jumps in the air and with a flash he STRIKES his knuckles right in to";
             seko = "'s face with a CRUSHING sound";
             seko2 = "r face with a CRUSHING sound";
        }
    }

    if (!seko) { seko = ""; }
    if (!seko2) { seko2 = ""; }
    if (tmp < attacker_ob->query_max_hp() / 80) {
        what = "causing just light scratches";
        what2 = "causing just light scratches";
    }
    if (tmp >= attacker_ob->query_max_hp() / 80) {
        what = "causing scratches";
        what2 = "causing scratches";
    }
    if (tmp > attacker_ob->query_max_hp() / 50) {
        what = "opening small wounds";
        what2 = "opening small wounds";
    }
    if (tmp > attacker_ob->query_max_hp() / 30) {
        what = "causing nasty scrapes";
        what2 = "causing nasty scrapes";
    }
    if (tmp > attacker_ob->query_max_hp() / 20) {
        what = "rupturing skin";
        what2 = "rupturing skin";
    }
    if (tmp > attacker_ob->query_max_hp() / 15) {
        what = "leaving large wounds";
        what2 = "leaving large wounds";
    }
    if (tmp > attacker_ob->query_max_hp() / 10) {
        what = "causing nasty large wounds";
        what2 = "causing nasty large wounds";
    }
    if (tmp > attacker_ob->query_max_hp() / 6) {
        what = "harming muscles badly";
        what2 = "harming muscles badly";
    }
    if (tmp > attacker_ob->query_max_hp() / 4) {
        if (name_of_weapon) {
           what = "with your " + name_of_weapon->query_name() +
                " opening severe wounds";
            what2 = "with " + ob->query_possessive() + " " +
                name_of_weapon->query_name() + " opening severe wounds";
        } else {
            what = "opening severe wounds";
            what2 = "opening severe wounds";
        }
    }
    if (tmp > attacker_ob->query_max_hp() / 3) {
        what = "smashing bones";
        what2 = "smashing bones";
    }
    if (tmp > attacker_ob->query_max_hp() / 2) {
        what = "devastating flesh and bones";
        what2 = "devastating flesh and bones";
    }
    if (tmp > attacker_ob->query_max_hp()) {
        what = "crushing and mutilating " + attacker_ob->query_objective();
        what2 = "crushing and mutilating you";
    }
    name_of_defender = "something";
    name_of_attack = "Something";
    is_light = ob->test_dark();
    if (is_light > 1) {
        name_of_defender = call_other(ob->query_attack(),"query_name");
    }
    is_light = attacker_ob->test_dark();
    if (is_light > 1) {
        name_of_attack = capitalize(ob->query_name());
    }
    tell_object(ob, "You " + how + " " + name_of_defender +
           seko + " " + what + ".\n");
    tell_object(attacker_ob, name_of_attack + " " + how2 + " you" +
           seko2 + " " + what2 + ".\n");
}

