#define BANK_D "/room/bank_d"
#define MONEY  "/obj/new_money"
inherit "room/room";
object monster;
object prisoner;
mapping warnings;

reset(arg) {
  if(!present("displayer",this_object())) {
    move_object(clone_object("/room/money_list"), this_object());
   }

  if(!monster) {
    monster = clone_object("/wizards/jenny/city/guards/jailguard.c");
    move_object(monster, this_object());
   }

  if(arg) return;
  property = allocate(4);
  property[0] = "no_kill";
  property[1] = "no_skill";
  property[2] = "no_spell";
  property[3] = "no_summon";
  set_not_out(1);
  set_light(3);
  short_desc = "You are in jail";
  long_desc = "This is the jail of Duranghom. All kind of\n"+
              "criminals are brought here to go through their\n"+
              "punishments. There is only a small toilet here\n"+
              "and you can see guard's room behind iron bars.\n"+
              "There is a small automat which you can use as a\n"+
              "bank here. You can 'check' when next prisoner will\n"+
              "be released. Available commands:\n"+
              "  withdraw <amount> <type>\n"+
              "  balance\n";

  warnings = ([]);
}

jail(ob) {
  int time;
  time = ob->query_level()*40;
  //log_file("JAIL", ctime(time())+" "+ob->query_name()+" jailed for "+time+" seconds\n");
  call_out("sentence", time, ob->query_name());
  return 1;
}

sentence(name) {
  object player;
  player = find_player(lower_case(name));
  if(file_name(environment(player)) == "/wizards/jenny/city/jail/jailroom") {
    tell_object(player,"You have now completed your sentence, you are free to go\n");
    player->move_player("city#/world/city/cs.c");
      prisoner = "/guilds/skill_obj/meditate_ob";
      this_player()->vapaudu();
  }
  if(file_name(environment(player)) == "/world/special/ldroom") {
    player->set_ld_location("/world/city/cs");
      prisoner = "/guilds/skill_obj/meditate_ob";   
      this_player()->vapaudu();
  }
}

time_left() {
  int sek, min, h;
  string str;
  min = 0;
  h = 0;
  sek = find_call_out("sentence");

  while(sek > 60) {
        sek -= 60;
        min++;
  }

  while(min > 60) {
        min -= 60;
        h++;
  }

  if(min > 0 && h > 0) {
        str = h+" hours, "+min+" minutes and "+sek+" seconds";
  } else if (min > 0){
        str = min+" minutes and "+sek+" seconds";
  } else if (h > 0 && !min) {
        str = h+" hours and "+sek+" seconds";
  } else {
        str = sek+" seconds";
  }

write("The next prisoner will be released after "+str+"\n");
return 1;
}

add_warning(str) {
	if(!warnings[str]) {
		warnings += ([ str: 1]);
	} else {
		warnings[str]++;
	}
}

get_warning(str) {
	return warnings[str];
}

funktio() { return 1; }

action_history() {
  string *str;
  int i;

  str = explode(BANK_D->query_action_history(), ":");
  write("Displaying action history for your bank account:\n");
  for(i=0; i < sizeof(str); i++) {
    write(str[i]+"\n");
  }
  return 1;
}

init() {
  ::init();
  add_action("withdraw", "withdraw");
  add_action("saldo", "balance");
  add_action("action_history", "actions");
  add_action("time_left", "check");
  add_action("funktio","quit");

}

saldo() {
  int temp;
  temp = query_money_in_bank(1) / 100;
  write("You have "+temp+" bronze coins in your account.\n");
  return 1;
}

transfer(arg) {
  int num;
  string who;
  object ob;
  if(!arg || sscanf(arg, "%d to %s", num,who) != 2) {
    write("Usage: transfer <amount> to <player>\n");
    return 1;
  }
  if(this_player()->query_wiz() && this_player()->query_wiz() < 3) {
    write("Low level wizards cannot make transfers.\n");
    return 1;
  }
  if(num < 100) {
    write("The minimum transfer amount is 100 bronzes.\n");
    return 1;
  }
  if(query_money_in_bank(3) < num) {
    write("You don't have that much money in your account.\n");
    return 1;
  }
  ob = find_player(who);
  if(!ob && file_size("/players/"+who+".o") == -1) {
    write("No such a player.\n");
    return 1;
  }
  write("You transferred "+num+" bronzes to "+capitalize(who)+"'s account.\n");
  if(ob && ob != this_player()) {
    tell_object(ob, this_player()->query_name()+
        " transferred "+num+" bronzes to your account.\n");
  }
  add_bank_money(-num,3);
  add_bank_money(num,3,who);
  log_file("BANK_TRANSFER", ctime(time())+" "+this_player()->query_name()+" (lv "+this_player()->query_level()+") "+
        "transfered "+num+" bronze to "+capitalize(who)+".\n");
  return 1;
}

deposit(arg) {
   int num,tmp,type,temp;
   string str;
   if (!arg) {
     write("Deposit how much?\n");
     return 1;
   }
   
   if (arg == "all") {
        num = this_player()->total_money();
        if (query_money_in_bank(1) + num > 1000000000) {
           write("You can't have more than 10m bronze on your bank account.\n");
           return 1;
        }
        this_player()->total_money(1);
        num -= num / 20;
        add_bank_money(num,1);
        temp = num / 100;
        write("You deposit money worth "+temp+" bronze coins. (After taxing)\n");
        return 1;
   }
   if(sscanf(arg,"all %s",str) == 1) {
     type = call_other(MONEY, "type_nums",str);
     num = this_player()->query_money(type, 1);
   }
   if (sscanf(arg,"%d %s",num,str) == 2 || num) {
     type = call_other(MONEY, "type_nums",str);
     tmp = this_player()->query_money(type, 1);
     if (tmp < num) { num = 0; }
   }
   if (!str) {
     write("No such a money type.\n");
     return 1;
   }
   if(!num) {
     write("You don't have any "+str+" coins.\n");
     return 1;
   }
   if(num<0) {
     write("You cannot deposit negative amounts.\n");
     return 1;
   }
   if(!str) str = "";
   else str = " "+str;
   if(this_player()->query_wiz())
     write("Type:"+str+" ("+type+") "+num+"\n");
   if (this_player()->query_money(type,1) >= num) {
       if (query_money_in_bank(1) + num > 1000000000) {
          write("You can't have more than 10m bronze on your bank account.\n");
          return 1;
       }
       this_player()->reduce_part_money(num,type);
       num -= num / 20;
       add_bank_money(num,type);
       write("You deposit " + num +str+" coins. (After taxing)\n");
        temp = query_money_in_bank(1) / 100;
       write("You now have " +temp+
         " bronze on your bank account.\n");
       return 1;
   } else {
       write("You don't have that much"+str+" coins on you.\n");
       return 1;
   }
   write("Usages:\n");
   write("  deposit all <type>\n");
   write("  deposit <amount> <type>\n");
   return 1;
}
query_money_in_bank(type) {
  return BANK_D -> query_money(type);
}

add_bank_money(int num, int type, string who) {
  if(!who) return BANK_D -> add_money(num,type);
  who = lower_case(who);
  return BANK_D -> add_other_money(num,type,who);
}

withdraw(arg) {
   int num,type,temp;
   string str;
   if (!arg) {
        write("Usage: withdraw <amount> <type>\n");
        return 1;
   }
   if (sscanf(arg,"%d %s", num,str) == 2) {
     type = call_other(MONEY, "type_nums", str);
     if (!type) { write("No such money type.\n"); return 1; }
     if(num<1) {
       write("You cannot withdraw negative amounts.\n");
       return 1;
     }
     if (query_money_in_bank(type) >= num) {
       this_player()->add_money(num,type);
       add_bank_money(-num,type);
       write("You withdraw " + num + " "+str+" coins.\n");
       temp = query_money_in_bank(1) / 100;
       write("You now have " +temp+ " bronze on your bank account.\n");
       return 1;
     }
     else {
       write("You don't have that much "+str+" coins on your account.\n");
       return 1;
     }
   }
   write("Usage: withdraw <amount> <type>\n");
   return 1;
}
