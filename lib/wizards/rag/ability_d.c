// Daemon for handling abilities - Rag, Sep 04

#define MEGA 1000000

//Note that if you add abilities, the name of the ability must be a lower_case
//no_space version of the name for players (and of course remember to code the
//functionality of the ability :)

//name of ability, cost to 100% in M, name for players, info about the ability, 100% usage info
mapping abilities = ([ "infravision": 2000; "Infravision";
                       "This ability allows you to see in the dark."; "",
                       
                       "nohunger": 1500; "No hunger";
                       "With this ability you don't get hungry or thirsty."; "",
                       
                       "spellpiercing": 4000; "Spell piercing";
                       "This ability grants you the power to ignore targets tumble."; "",
                       
                       "banditfriend": 500; "Bandit friend";
                       "Your friend among the bandits helps you to avoid attacks in the outworld."; "",
                       
                       "noscars": 2000; "No scars";
                       "Your skin becomes so rigid with this ability that you cannot be scarred."; "",
                       
                       "quickrecovery": 3000; "Quick recovery";
                       "This ability shortens the time of death penalty."; "",
                       
                       "improvedplan": 1500; "Improved plan";
                       "This ability grants additional lines to your plan."; "",
                       
                       "movementmessages": 2000; "Movement messages";
                       "You can set your movement messages if you have this ability.";
                       "Usage: abilities setmout <leave message>, abilities setmin <enter message>\n",
                       
                       "monstersense": 500; "Monster sense";
                       "This ability allows you to sense which monsters are tougher than normal.";
                       "Usage: abilities sense\n",
                       
                       "durationsense": 4000; "Duration sense";
                       "This ability gives you insight about your skill duration."; "",
                       
                       "stabilemagic": 130; "Stabile magic";
                       "With this ability you can lower the chance for magical gaps."; "",
                    ]);


//List all abilities
void list_abilities(object ob) {
  string str = "Abilities\n";
  string *abi = m_indices(abilities);
  mapping abi_;
  int i;
  
  if ( !ob ) ob = this_player();
  abi_ = ob->query_abilities();
  
  str += "+-------------------+-------+---------+\n";
  str += "| Name              | Cost  | Current |\n";
  str += "+-------------------+-------+---------+\n";
  
  for ( i = 0; i < sizeof(abi); i++ ) {
    str += "|" + sprintf("%-19s", " "+abilities[abi[i],1]);
    str += "|" + sprintf("%-7s", " "+abilities[abi[i],0]+"M");
    str += "|" + sprintf("%-9s", " "+abi_[abi[i]]+"%");
    str += "|\n";
  }
  
  str += "+-------------------+-------+---------+\n";
  
  tell_object(ob,str);
}


//Train ability
void train_ability(string str, object ob) {
  string abi, tmp1, tmp2;
  int train_to, cost;
  if ( !ob ) ob = this_player();
  if ( !str ) return;

  abi = lower_case(str);
  while(sscanf(abi,"%s %s",tmp1,tmp2) == 2 ) {
    abi = tmp1 + tmp2;
  }

  //Check if the ability exists
  if ( !abilities[abi] ) {
    tell_object(ob, str+" is not an ability.\n");
    return;
  }
  
  //Check if the player is already training an ability
  if ( ob->query_ability_train() ) {
    tell_object(ob, "You are already training an ability.\n");
    return;
  }  

  //Check if the player already has that ability at 100%
  if ( ob->query_ability(abi) ) {
    tell_object(ob, "You already have the ability trained.\n");
    return;
  }
  
  //Training is done in 10% pieces
  train_to = ob->query_abilities()[abi] + 10;
  cost = abilities[abi,0] / 10 * MEGA;
  
  log_file("ABILITY", ctime(time())+" "+ob->query_name()+" trained "+abi+" to "+train_to+"\n",1);
  
  //If the player has safe exp
  if ( ob->query_enough_exp(cost) == cost ) {
    tell_object(ob,"Trained "+str+" to "+train_to+"%.\n");
    ob->set_ability( abi, train_to );
    ob->reduce_free_exp( cost );
    ob->add_total_worth( cost );
    return;
  }
  
  tell_object(ob,"Training "+str+" to "+train_to+"%.\n");
  ob->set_ability_train( abi, cost, train_to );
  return;
}


//Displays info on different abilities
void info(string str, object ob) {
  string abi, msg, tmp1, tmp2;
  if ( !ob ) ob = this_player();
  
  abi = lower_case(str);
  while(sscanf(abi,"%s %s",tmp1,tmp2) == 2 ) {
    abi = tmp1 + tmp2;
  }
  
  if ( !abilities[abi] ) {
    tell_object(ob, "No such ability.\n");
    return;
  }
  
  msg = "Displaying info on '"+capitalize(str)+"'\n";
  msg += "Cost: "+abilities[abi,0]+"M\n";
  msg += abilities[abi,2]+"\n";
  
  if ( ob->query_ability(abi) || ob->query_wiz() ) {
    msg += abilities[abi,3];
  }
  
  tell_object(ob,msg);
  
  return;
}

string get_ability_name(string str) {
  if ( !str ) return "";
  if ( !abilities[str] ) return "";
  return abilities[str,1];
}