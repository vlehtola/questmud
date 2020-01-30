status cmd_static(string what) {
        string stat, target_name, skill, resist, reason, cap_name;
        int num, passed, much, i, i2, Wiza,level;
        object ob, obje;
        if(!query_ip_number(this_player())) return 0;
        if(this_player()->query_npc()) return 0;
        if(!what) {
          write("Syntax: static <argument>\n");
          write("See: static help\n");
          return 1;
        }
        if (what == "help" ) {
                cat("/doc/wiz_help/static");
                return 1;
        }
        Wiza = this_player()->query_wiz();
        level = this_player()->query_level();
        cap_name = capitalize(this_player()->query_real_name());
        log_file("WIZ_CALLS", cap_name+" ("+level+") Wiz("+Wiza+"): "+what+"\n", 1);
        if (sscanf(what, "award %s with %d for %s", target_name, num, reason) == 3 &&
            Wiza == 5) {
          ob = find_player(target_name);
          if (!ob) {
            write("Usage: wiz award <name> with <num> for <reason>.\n");
            return 1;
          }
          write_file("/log/awards", "\n"+this_player()->query_name()+" awarded "+
                     target_name+" with "+num+" levels for doing: "+reason+"\n");
          call_other(find_object("/obj/wizlist"), "update_list",target_name, num);
          write(capitalize(target_name)+" has now been awarded with "+num+" levels.\n");
         tell_object(ob, cap_name+" awarded you for "+reason+" with "+num+" levels.\n");
          ob->set_level(ob->query_level()+num);
          return 1;
        }
        if (sscanf(what, "zap %s", target_name) == 1) {
          if(Wiza < 2) { return 0; }
          ob = find_player(target_name);
          shout(capitalize(target_name)+" suffers from " + cap_name + "'s wrath, as lightning strikes on "+
                 ob->query_objective() + " turning "+ob->query_objective() + " into a small pile of dust.\n");
          write(capitalize(target_name) + " whines in agony as " + ob->query_pronoun()+ " dies.\n");
          ob->death();
          return 1;
        }
        if ((sscanf(what,"identify %s", target_name) == 1) && Wiza) {
                if (!present(target_name, this_player())) {
                        write("You don't have a '" + target_name + "'.\n");
                        return 1;
                }
                ob = present(target_name, this_player());
                if (ob->query_type()) {
                        write("Weapon_type: " + ob->query_type() + ".\n");
                        write("Weapon_weight: " + ob->query_weight() + ".\n");
                        write("Weapon_class: " + ob->query_wc() + ".\n");
                        write("Armour_class: " + ob->query_ac() + ".\n");
                        write("Value: " + ob->query_value() + ".\n");
                        return 1;
                }
                write("No such eq: " + target_name + ".\n");
                return 1;
        }
        if ((sscanf(what,"idlestop %s", target_name) == 1) && Wiza == 5) {
          sscanf(target_name, "%s %d %d", target_name, i, i2);
          ob = find_player(target_name);
          if (!ob) {
            write("No such player.\n");
            return 1;
          }
          if (ob->query_wiz() == 5) { return 0; }
          obje = clone_object("obj/idlestop");
          move_object(obje, ob);
          obje->start(ob,i,i2);
          write(capitalize(ob->query_name())+" is now on idlestop-mode<tm>.\n");
          return 1;
        }
        if ((sscanf(what,"set stun to %d %s", num, target_name) == 2) && Wiza > 1) {
                ob = present(target_name);
                if(!ob) { ob = find_living(target_name); }
                if (!ob) {
                    write("Stun whom?\n");
                    return 1;
                }
                if (num < 0) { num = 0; }
                if (num > 0) {
                    write("You stun " + target_name + " with your force for " + num + " rounds!\n");
                    tell_object(ob, "You are STUNNED by some amazing force!\n");
                }
                else {
                    write("You release " + target_name + " from stun.\n");
                    tell_object(ob, this_player()->query_name() + " releases your stun!\n");
                }
                ob->set_stunned(num);
                return 1;
        }
        if ((sscanf(what,"ress %s", target_name) == 1) && Wiza >= 2) {
                ob = find_living(target_name);
                if (!ob) {
                    write("Ress whom?\n");
                    return 1;
                }
                ob->remove_ghost(100);
                write("Ressed.\n");
                return 1;
        }
        if ((sscanf(what,"heal %s", target_name) == 1) && Wiza > 1) {
                ob = find_player(target_name);
                if(!ob) {
                  write("No such player.\n");
                  return 1;
                }
                ob->heal_self(1000000000);
                return 1;
        }
        if ((sscanf(what,"set skill %s to %d %s", skill, much,target_name) == 3) && Wiza) {
                ob = present(target_name);
                if(!ob) { ob = find_living(target_name); }
                if (!ob) {
                    write("Set skill to whom?\n");
                    return 1;
                }
                if (ob != this_player() && Wiza < 4) {
                    write("You can only set your own skills.\n");
                    return 1;
                }
                ob->set_skill(skill, much);
                write(capitalize(ob->query_name()) + "'s skill " + skill + " is now " + much + ".\n");
                tell_object(ob, capitalize(this_player()->query_name()) + " just modified your skills.\n");
                return 1;
        }
        if ((sscanf(what,"set resist %s to %d %s", resist, much,target_name) == 3) && Wiza == 5) {
                ob = find_living(target_name);
                if (!ob) {
                    write("Set skill to whom?\n");
                    return 1;
                }
                if (call_other("obj/resfun", "resist_nums", resist)) {
                    ob->set_resists(call_other("obj/resfun", "resist_nums", resist), much);
                    write(capitalize(ob->query_name()) + "'s resist " + resist + " is now " + much +".\n");
                    tell_object(ob, capitalize(this_player()->query_name()) + " just modified your resistances.\n");
                    return 1;
                }
                write("No such a skill.\n");
                return 1;
        }
        if ((sscanf(what,"set %s to %d %s", stat, num, target_name) == 3) && Wiza) {
                ob = present(target_name);
                if(!ob) { ob = find_living(target_name); }
                if (!ob) {
                    write("Set to whom?\n");
                    return 1;

                }
                if (ob != this_player() && Wiza < 3 && !ob->query_tester()) {
                    write("You can only set your own stats.\n");
                    return 1;
                }
                if (stat == "str") {
                    ob->set_str(num);
                    passed = 1;
                }
                if (stat == "dex") {
                    ob->set_dex(num);
                    passed = 1;
                }
                if(stat=="alignment") {
                  ob->set_al(num);
                  passed = 1;
                }
                if (stat == "con") {
                    ob->set_con(num);
                    passed = 1;
                }
                if (stat == "int") {
                    ob->set_int(num);
                    passed = 1;
                }
                if (stat == "wis") {
                    ob->set_wis(num);
                    passed = 1;
                }
                if (stat == "level" && Wiza == 5) {
                    ob->set_level(num);
                    passed = 1;
                }
                if (stat == "exp") {
                    num = ob->add_skill_exps(num, 1);
                    ob->reset_free_exp();
                    ob->add_free_exp(num);
                    passed = 1;
                }
                if (stat == "hp") {
                    ob->set_hp(num);
                    passed = 1;
                }
                if (stat == "sp") {
                    ob->set_sp(num);
                    passed = 1;
                }
                if (stat == "ep") {
                    ob->set_ep(num);
                    passed = 1;
                }
                if (stat == "maxhp") {
                    ob->set_max_hp(num);
                    passed = 1;
                }
                if (stat == "maxsp") {
                    ob->set_max_sp(num);
                    passed = 1;
                }
                if (stat == "maxep") {
                    ob->set_max_ep(num);
                    passed = 1;
                }
                if (stat == "silver") {
                    ob->add_money(num,4);
                    passed = 1;
                }
                if (stat == "wiz" && Wiza == 5 && level == 1000) {
                    ob->set_wiz(num);
                    passed = 1;
                }
                if (passed == 1) {
                    write(capitalize(ob->query_name()) + "'s " +
                                stat + " is now " + num + ".\n");
                    return 1;
                }
        write("Set what?\n");
        return 1;
        }
}

