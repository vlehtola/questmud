
#define BANK_D "/room/bank_d"
#define MONEY  "/obj/new_money"
inherit "room/room";

reset(arg) {
  if(!present("displayer",this_object())) {
    move_object(clone_object("/room/money_list"), this_object());
  }
  if(arg) return;
  set_light(3);
  set_not_out(1);
  add_exit("south","world/city/mainstr5");
  short_desc = "The bank of Duranghom";

long_desc = "This is the bank of Duranghom.\n" +
"You can store your money in here.\n" +
"However, a small tax is taken for the bank.\n" +
"Available commands:\n" +
"  deposit [<amount> <type> | all <type> | all]\n" +
"  withdraw <amount> <type>\n" +
"  transfer <amount> to <player>\n" +
"  balance\n";
//"  actions\n";
}

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
  add_action("deposit", "deposit");
  add_action("withdraw", "withdraw");
  add_action("saldo", "balance");
  add_action("transfer", "transfer");
  add_action("action_history", "actions");
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
       if (query_money_in_bank(1) + num > 40000000000) {
          write("You can't have more than 40m bronze on your bank account.\n");
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
