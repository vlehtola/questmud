#define BOOST "/guilds/obj/boost.c"

offensive_resolve(type,class,category,effect_bonus,target,object caster) {
    int damage, mastery, mastery_damage, effect_damage, divider, source;
    int boost, value, skill, reflect;
    object ob, next_ob, counter,test;
    string text_word,text_word2, temp_str,dam_type;

    if (class == "sol") { text_word = "Earth";
dam_type = "physical";
mastery = caster->query_skills("mastery of earth");
    }
    if (class == "poi") { text_word = "Poison";
    dam_type = "poison";
mastery = caster->query_skills("lore of poison");
}
    if (class == "fla") { text_word = "Fire";
dam_type = "fire";
mastery = caster->query_skills("knowledge of heat");
    }
    if (class == "brr") { text_word = "Ice";
dam_type = "cold";
mastery = caster->query_skills("lore of cold");
    }
    if (class == "zzt") { text_word = "Lightning";
dam_type = "electric";
mastery = caster->query_skills("theory of electricity");
    }
    if (type == "blt") { text_word2 = "Bolt"; }
    if (type == "strm") { text_word2 = "Storm"; }
    if (type == "arr") { text_word2 = "Arrow"; }
    if (type == "grsp") { text_word2 = "Grasp"; }

    if (text_word == 0 || text_word2 == 0) { return; }
    if (!caster) { caster = this_player(); }

    /* boost [10,300+] */
    boost = caster->query_sp_boost(1);
    /* boost * 3? */
    boost = BOOST->offensive_boost(boost);

    /* effect [60,130] */
    if (effect_bonus > 100) { effect_bonus=100+(effect_bonus-100)/4; }
    effect_bonus += effect_bonus * mastery / 160;

    /* 300 * ( 130 + 40 ) / 100 => 500+ */
    damage = boost * ( effect_bonus + caster->query_int()/10 ) / 100;

    if (class == "sol") {
      damage = damage / 2;
    }
    if (type == "arr") {
		damage = damage*3/2;
	}
	if (type == "grsp") {
		damage = damage*4/2;
	}
    if (type == "strm") {
        call_other("/guilds/obj/area_resolve.c", "resolve", damage, dam_type, text_word, text_word2);
        return 1;
    }

    /* resolve spells other than storm */

    if (!target) {
        tell_object(caster, "Cast at whom?\n");
        return 1;
    }
    ob = present(lower_case(target), environment(caster));
    if (!ob || !living(ob)) {
        tell_object(caster, "There is no " + capitalize(target) + " here.\n");
        return 1;
    }
    if (ob == caster) {
        tell_object(caster, "Cast an offensive spell at yourself, huh?\n");
        return 1;
    }

    /* Reflect returns the spell in full, but 1/3 still hits the target //Celtron */
    reflect = ob->query_skills("reflect spell") - (caster->query_skills("reflect spell")*3/4);
    reflect -= caster->query_antireflect_bonus();
    if(caster->query_wiz()) write(reflect+" and "+effect_bonus+".\n");
    if (reflect > random(effect_bonus)) {
        tell_object(caster, ob->query_name()+ " reflects a part of your spell and it hits YOU!\n");
        tell_object(ob, "You manage to reflect a part of " + caster->query_name() + "'s spell on " +
                caster->query_objective() + "self!\n");
        ob->casting_sp_reduce((boost/2));
        offensive_resolve(type,class,category,effect_bonus,caster->query_name(),ob);
        damage = damage / 3;
    }
    test = ({ caster, ob, });

 // Rebirth ability to fully prevent the bolt

    if(ob->query_rebirth("absorb bolt")) {
      tell_object(caster, "Your " + text_word + " " + text_word2 + " is absorbed by "+ob->query_name()+"'s skin!\n");
      tell_object(ob, "You absorb "+caster->query_name()+"'s " + text_word + " " + text_word2 + "!\n");
      say(caster->query_name() + "'s " + text_word + " " + text_word2 + " is absorbed by " + target + "'s skin!\n", test);
      return 0;
    }

    tell_object(caster, "Your " + text_word + " " + text_word2 + " hits " + ob->query_name() + " in the torso!\n");
    say(caster->query_name() + "'s " + text_word + " " + text_word2 + " hits " + target + " in the torso!\n", test);
    tell_object(ob, caster->query_name() + "'s " + text_word + " " + text_word2 + " hits YOU in the torso!\n");
    if(!caster->query_npc() && random(50)) { this_player()->set_mastery("Offensive spellcasting",(this_player()->query_mastery()["Offensive spellcasting"] + 1));
    }

    if(!caster->query_npc() && !random(50)) { this_player()->set_mastery("Dangerous "+text_word,(this_player()->query_mastery()["Dangerous "+text_word] + 1));
    }
    if(!caster->query_npc()) {
	damage += damage * this_player()->query_mastery()["Dangerous "+text_word] / 200;
    damage += damage * this_player()->query_mastery()["Offensive spellcasting"] / 200;
    }
    /* saving throw? ym tune + randomia */
    if(random(ob->query_dex() + 500) < ob->query_dex()) {
      tell_object(caster, target+" avoids part of the blast!\n");
      tell_object(ob, "You avoid part of the blast!\n");
      if(caster->query_skills("proximity blast") > random(101)) {
        tell_object(caster, "..but the spell still hits "+ob->query_name()+"!\n");
        tell_object(ob, "..but the spell still hits you!\n");
      } else {
        damage = damage / 2;
      }
    }

// eq monsu tune & necro tune combined ++Celtron
    if(caster->query_npc())
	damage = damage / 2;

    if(caster->query_tester())
      tell_object(caster, "Damage: "+damage+"\n");
    caster->attack_object(ob, 1);
    ob->hit_with_spell(damage, dam_type, caster);
    if(!ob) return 1; /* return if npc is dead */

    if (ob->query_resists(dam_type) == 100) {
        tell_object(caster, target+ " is COMPLETELY unharmed!\n");
    }
    else if (ob->query_resists(dam_type) >= 90) {
        tell_object(caster, target + " seems unharmed!\n");
    }
    else if (ob->query_resists(dam_type) >= 70) {
        tell_object(caster, target+ " seems to shrug off the "+text_word2+"!\n");
    }
    source = caster->query_skills("invoke ethereal mana");
    source = ob->query_resists(dam_type) * boost * source / 10000;
    if(source > 0) {
      tell_object(caster, "You invoke ethereal mana and save some of your own.\n");
      caster->add_sp(source);
    }

    counter = present("blast counter", caster);
    if(!counter) {
      counter = clone_object("/guilds/obj/blast_counter");
      move_object(counter, caster);
    }
    value = caster->query_skills("stunning blast") - ob->query_skills("stunning blast")/2;

    /* ei toimi eq monsuihin //Celtron */
    if(!ob->query_kill_log() && value > 0 && counter->add_stun_count(value)) {
      ob->set_stunned(2);
      tell_object(caster, "You stun "+ob->query_name()+" with your spell!\n");
      tell_object(ob, "You are STUNNED by the spell!\n");
    }

    /* toimii vain skilleihin. counter spelli toimii spellej^D vastaan. //Celtron */
    value = caster->query_skills("distract concentration") - ob->query_skills("distract concentration")/2;
    if (ob->query_use_skill()) {
      if(value > 0 && counter->add_distract_count(value)) {
          tell_object(caster, "You break "+ob->query_name()+"'s skill concentration!\n");
          tell_object(ob, "The spell breaks your skill concentration!\n");
          if (ob->query_use_skill())
                ob->query_use_skill()->interrupt_skill();
      }
    }
    return 1;
}
