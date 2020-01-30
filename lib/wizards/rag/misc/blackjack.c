#define TP this_player()
#define NAME this_player()->query_name()
#define CARD_NAME(x) "/wizards/rag/misc/bj_addon"->query_full_cardname(x,0)

inherit "room/room";

mapping bets;
mapping cards;
mapping players;
mapping splits;
int game, done, force, wins, rounds, tbets,tbetsn;

stand() {
  string c;
  if(!cards[NAME]) {
    write("You are not in the game.\n");
    return 1;
  }
  if(cards[NAME+"split"]) {
        write("You finish your first hand.\n");
        players += ([ NAME+"2": (int)get_value(NAME) ]);
        cards += ([ NAME+"2": cards[NAME] ]);
        cards -= ([ NAME ]);
        cards += ([ NAME: cards[NAME+"split"] ]);
        cards -= ([ NAME+"split" ]);
        deal_card(NAME);
        check_value(NAME);
        return 1;
  }
  if(players[NAME]) {
    write("You have already made that clear.\n");
  } else {
    write("You decide to stand.\n");
    players += ([ NAME:(int)get_value(NAME) ]);
    done++;
  }
  check_idle();
  check_finish();
  return 1;
}

double() {
        int bet;
        string *c;
        string tmp;
        check_idle();
        if(!cards[NAME]) {
                write("You are not in the game.\n");
                return 1;
        }
        if(players[NAME]) {
                write("You have already finished your hand.\n");
                return 1;
        }
        if(cards[NAME+"split"] || players[NAME+"2"]) {
                write("You can't double a splitted hand.\n");
                return 1;
        }
        c = explode(cards[NAME]," ");
        if(sizeof(c) != 2) {
                write("You can double only when you have two cards.\n");
                return 1;
        }
        bet = bets[NAME];
        if(TP->query_money(3) < bet) {
                write("You don't have enough money to double.\n");
                return 1;
        }
        write("You decide to double.\n");
        TP->reduce_money(bet,3);
        bets -= ([ NAME ]);
        bets += ([ NAME: bet*2 ]);
        tbets+=bet;
        tbetsn++;
        deal_card(NAME);
        check_value(NAME);
        if(cards[NAME] && !players[NAME]) {
                players += ([ NAME:(int)get_value(NAME) ]);
                done++;
                check_finish();
        }
        return 1;
}

split() {       
        int bet, le1, le2;
        string *c;
        string tmp1, tmp2;
        check_idle();
        if(!cards[NAME]) {
                write("You are not in the game.\n");
                return 1;
        }
        if(players[NAME]) {
                write("You have already finished your hand.\n");
                return 1;
        }
        if(splits[NAME]) {
                write("You have already splitted your hand once.\n");
                return 1;
        }
        c = explode(cards[NAME]," ");
        if(sizeof(c) != 2) {
                write("You can split only when you have two cards.\n");
                return 1;
        }
        tmp1 = c[0];
        tmp2 = c[1];
        le1 = strlen(tmp1);
        le2 = strlen(tmp2);
        if(tmp1[le1-1..le1-1] != tmp2[le2-1..le2-1] || le1 != le2) {
                write("You must have two same cards to split.\n");
                return 1;
        }
        bet = bets[NAME];
        if(TP->query_money(3) < bet) {
                write("You don't have enough money to split.\n");
                return 1;
        }
        write("You decide to split.\n");
        TP->reduce_money(bet,3);
        cards -= ([ NAME ]);
        cards += ([ NAME: c[0]]);
        cards += ([ NAME+"split": c[1]]);
        splits += ([ NAME: 1 ]);
        tbets+=bet;
        tbetsn++;
        deal_card(NAME);
        return 1;
}

check_finish() {
  int siz, i;
  if(!game) return;
  siz = sizeof(m_indices(bets));
  if(siz && siz == done) { finish(); end_round(); return 1;}
  if(siz == 0) { end_round(); }
  return 1;
}

cont_check_idle() {
        call_out("check_idle",0);
        call_out("cont_check_idle",30);
        return 1;
}       

check_idle() {
  int i, siz;
  string *us;
  if(!game) return;
  us = m_indices(bets);
  siz = sizeof(us);
  i = 0;
  while(i<siz) {
    if(query_idle( find_player(lower_case(us[i])) ) > 60 && !players[us[i]] && bets[us[i]]) {
        tell_room(this_object(),us[i]+" is kicked out of the game for idling.\n");
        cards -= ([ us[i] ]);
        bets -= ([ us[i] ]);
    }
    if(!present(find_player(lower_case(us[i])))) {
        tell_room(this_object(),us[i]+" isn't here and is kicked out of the game.\n");
        cards -= ([ us[i] ]);
        bets -= ([ us[i] ]);
    }           
    i++;
  }
  check_finish();
  return 1;
}


finish() {
  int i,o, win;
  object ob;
  string *names;
  names = m_indices(bets);
  i = get_value("dealer");
  /* teko aly */
  while (i > 0 && i <16) {
    deal_card("dealer");
    i = get_value("dealer");
    if (i == 21 && sizeof(explode(cards["dealer"]," ")) == 2) {
        tell_room(this_object(), "The dealer got blackjack!\n");
        i = 0;
        while(i<sizeof(names)) {
                tell_room(this_object(),names[i]+" lost his bet.\n");
                i++;
        }
        return 1;
    }
  }
  if(i>21) {
        tell_room(this_object(), "The dealer is out of the game. ("+i+") \n");
  }
  /* end of aly */
  tell_room(this_object(), "The dealer has: "+i+".\n");
  while(o<sizeof(names)) {
        win = bets[names[o]]*2;
        if(players[names[o]+"2"] && (players[names[o]+"2"] > i || i > 21)) {
                tell_room(this_object(), names[o]+" won "+win+" bronze.\n");
                ob = present(lower_case(names[o]), this_object());
                if(!ob) {
                tell_room(this_object(), "..but because he's not here, the casino keeps his reward.\n");
                } else {
                ob->add_money(win, 3);
                wins += win;
                }
        } else if(players[names[o]+"2"]) {
        tell_room(this_object(), names[o]+" lost his bet. ("+players[names[o]+"2"]+")\n");
        }
    if(players[names[o]] && (players[names[o]] > i || i > 21)) {
      tell_room(this_object(), names[o]+" won "+win+" bronze.\n");
      ob = present(lower_case(names[o]), this_object());
      if(!ob) {
        tell_room(this_object(), "..but because he's not here, the casino keeps his reward.\n");
      } else {
        ob->add_money(win, 3);
        wins += win;
      }
    } else if(players[names[o]]) {
      tell_room(this_object(), names[o]+" lost his bet. ("+players[names[o]]+")\n");
    }
    o += 1;
  }
  return 1;
}

end_round() {
  int tmp;
  tell_room(this_object(),"The round has ended.\n");
  if(rounds%10 == 0) {
   tmp = rounds*tbets/tbetsn;
   tmp = wins-tmp;
   log_file("BLACKJACK_WINS", ctime(time())+" Rounds: "+rounds+" Avgbet: "+tbets/tbetsn+" Total winnings: "+wins+" Wins-bets: "+tmp+"\n");
   }
  done = 0;
  game = 0;
  force = 0;
  players = ([ ]);
  bets = ([ ]);
  cards = ([ ]);
  splits = ([ ]);
}

hit() {
  string card;
  if(!cards[NAME]) {
    write("You are not in the game.\n");
    return 1;
  }
  if(players[NAME]) {
    write("You have finished already.\n");
    return 1;
  }
  deal_card(NAME);
  check_value(NAME);
  return 1;
}

get_value(name) {
  int i,value,itmp, aces;
  string tmp;
  string *a;
  aces = 0;
  tmp = cards[name];

  a = explode(tmp," ");
  for(i=0;i<sizeof(a);i++) {
     sscanf(a[i],"d%s",tmp);
     sscanf(a[i],"h%s",tmp);
     sscanf(a[i],"s%s",tmp);
     sscanf(a[i],"c%s",tmp);
     if(sscanf(tmp,"%d",itmp)) value += itmp;
     else value += 10;
     if(tmp == "A") {
        value += 1;
        aces++;
     }
  }
  //Turning ace from 11 to 1
  while(value > 21 && aces) {
        value -= 10;
        aces--;
  }
  return value;
}
  
check_value(name) {
  int value;
  string *a;
  object ob;
  value = get_value(name);
  
  //Busted
  if(value > 21) {
    if(cards[name+"split"]) {
        write("Your first hand is out of the game. ("+value+")\n");
        cards -= ([ name ]);
        cards += ([ name: cards[name+"split"] ]);
        cards -= ([ name+"split" ]);
        deal_card(name);
        return get_value(name);
    }
    if(players[name+"2"]) {
        write("Your second hand is out of the game. ("+value+")\n");
        cards -= ([ name ]);
        done++;
        check_finish();
        return value;   
    }           
    tell_room(this_object(), capitalize(name)+" is out of the game. ("+value+") \n");
    if(name != "dealer") {
      cards -= ([ name ]);
      bets -= ([ name ]);
    }
    check_finish();
    return value;
  }
  
  //Check for Blackjack
  a = explode(cards[name]," ");
  if(value == 21 && sizeof(a) == 2 && !splits[name]) {
    tell_room(this_object(), name+" got blackjack!\n");
    if(name == "dealer") {
        end_round();
    } else {
    tell_room(this_object(), name+" won "+bets[name]*5/2+" bronze.\n");
    ob = present(lower_case(name), this_object());
    if(!ob) {
        tell_room(this_object(), "..but because he's not here, the casino keeps his reward.\n");
    } else {
        ob->add_money(bets[name]*5/2, 3);
        wins += bets[name]*5/2;
    }
    cards -= ([ name ]);
    bets -= ([ name ]);
    check_finish();
    return value;
    }
  }
  
  //Autostay
  if(value == 21) {write("You have 21.\n"); stand(); }
  
  return value;
}

deal(arg) {
  int i;
  string names;
  names = m_indices(bets);
  while(i<sizeof(names)) {
    deal_card(names[i]);
    check_value(names[i]);
    i += 1;
  }
  if(!arg) { deal(1); return; }
  if(game) { deal_card("dealer"); }
  return 1;
}

deal_card(name) {
  string card, onecard;
  int value;
  card = get_card();
  onecard = card;
  if(cards[name] != 0) card = card +" "+cards[name];
  cards -= ([ name ]);
  cards += ([ name:card ]);
  value = get_value(name);
  if(name == "dealer")
    tell_room(this_object(),"The dealer gets "+CARD_NAME(onecard)+".\n");
  if(present(lower_case(name),this_object()))
    tell_object(present(lower_case(name),this_object()), "The dealer deals "+CARD_NAME(onecard)+" to you.\n");
  return 1;
}

get_card() {
  string card;
  int i;
  i = random(4);
  if(i==0) card = "c"; /*club*/
  if(i==1) card = "s"; /*spade*/
  if(i==2) card = "h"; /*hearts*/
  if(i==3) card = "d"; /*diamonds*/
  i = random(13)+1;
  if(i==1) card += "A";
  if(i==13) card += "K";
  if(i==12) card += "Q";
  if(i==11) card += "J";
  if(i>1&&i<11) card += i;
  return card;
}

bet(str) {
  int i;
  if(!str) {
    write("Usage: bet <100-50000>\n");
    return 1;
  }
  sscanf(str,"%d",i);
  if(TP->query_money(3) < i) {
    write("You don't have enough bronze.\n");
    return 1;
  }
  if(game) {
    write("There is a game going on. Wait for a while.\n");
    return 1;
  }
  if(i < 100 || i > 50000) {
    write("Usage: bet <100-50000>\n");
    return 1;
  }
  TP->reduce_money(i,3);
  write("You bet "+i+" bronze.\n");
  say(NAME+" joins the game\n");
  tbets+=i;
  tbetsn++;
  bets += ([ NAME:i ]);
  check_deal();
  return 1;
}

check_deal() {
  object ob;
  int i;

  if(!force) {
        tell_room(this_object(),"Game starts in 15 seconds or when everyone in the room has joined.\n");
        call_out("startgame",15);
        force = 1;
  }

  ob = all_inventory(this_object());
  while(i<sizeof(ob)) {
    if(living(ob[i]) && !ob[i]->query_npc()) {
      if(!bets[ob[i]->query_name()] && query_idle(ob[i]) < 60) return;
    }
    i += 1;
  }
  tell_room(this_object(),"The round has started.\n");
  game = 1;
  rounds++;
  call_out("deal", 0);
}

startgame() {
  if(!game && force) {
   tell_room(this_object(),"The round has started.\n");
   rounds++;
   game = 1;
   call_out("deal", 0);
  }
  return 1;
}

table() {
        string *pl;
        string str;
        string name;
        int i, size;
        if(!game || !sizeof(m_indices(cards))) { write("No one is playing at the moment.\n"); return 1; }
        i = 0;
        pl = m_indices(bets);
        size = sizeof(pl);
        write("Players:\n");
        name = "dealer";
        write( sprintf("%11s: %s (Total of %i)\n",capitalize(name),cards[name],get_value(name)) );
        while(i<size) {
                if(players[pl[i]]) { str = "(Hand finished)\n";
                } else if(cards[pl[i]+"split"] || players[pl[i]+"2"]) { str = "(Current hand)\n";
                } else { str = "\n"; }
                write(sprintf("%11s: %s (Total of %i) %s",pl[i],cards[pl[i]],get_value(pl[i]),str));
                if(cards[pl[i]+"split"]) {
                        str = "(Splitted hand)\n";
                        write(sprintf("%11s: %s (Total of %i) %s","",cards[pl[i]+"split"],get_value(pl[i]+"split"),str));
                }
                if(players[pl[i]+"2"]) {
                        str = "(Finished splitted hand)\n";
                        write(sprintf("%11s: %s (Total of %i) %s"," ",cards[pl[i]+"2"],get_value(pl[i]+"2"),str));
                }
                i++;
        }
        return 1;
}


rules() {
  write("The idea of the game is to get the sum of your cards as close to 21 as possible.\n");
  write("If the sum goes over 21, the player is out of the game.\n");
  write("Cards 2-10 are equal to their number. J,Q and K are equal to 10 and A is 1 or 11.\n");
  write("The sum of your cards is compared to the sum of dealers cards. The bigger sum wins.\n");
  write("If you and the dealer have the same sum, the dealer wins.\n");
  write("A blackjack is 21 with two cards. It pays back 3:2. A normal win pays back 1:1.\n");
  write("Available commands:\n");
  write("       bet <100-50000> (bronze coins)\n");
  write("       cards (shows your cards)\n");
  write("       hit (ask for a card)\n");
  write("       stand (tells the dealer that you don't want anymore cards)\n");
  write("       stay (the same as stand)\n");
  write("       double (double your bet and get only one card)\n");
  write("       split (split your hand into two separate hands)\n");
  write("       table (shows the table)\n");
  return 1;
}

init() {
  ::init();
  add_action("cards", "cards");
  add_action("bet", "bet");
  add_action("rules", "rules");
  add_action("stand", "stand");
  add_action("stand", "stay");
  add_action("hit", "hit");
  add_action("double", "double");
  add_action("table", "table");
  add_action("split", "split");
}

cards() {
  string str;
  if(!game) {
        write("There isn't a game going on.\n");
        return 1;
  }
  if(!bets[NAME]) {
        write("You are not in the game.\n");
        return 1;
  }
  if(!cards[NAME]) {
	write("You don't have any cards yet.\n");
	return 1;
  }

  if(players[NAME]) { str = "(Hand finished)\n"; }
  else if(cards[NAME+"split"] || players[NAME+"2"]) { str = "(Current hand)\n"; }
  else { str = "\n"; }
  write(sprintf("You have %s (Total of %i) %s",cards[NAME],get_value(NAME),str));
  if(cards[NAME+"split"]) {
    str = "(Splitted hand)\n";
    write(sprintf("         %s (Total of %i) %s",cards[NAME+"split"],get_value(NAME+"split"),str));
  }
  if(players[NAME+"2"]) {
    str = "(Finished splitted hand)\n";
    write(sprintf("         %s (Total of %i) %s",cards[NAME+"2"],get_value(NAME+"2"),str));
  }
  return 1;
}

reset(arg) {
  if(arg) return;
  short_desc = "The blackjack room";
  long_desc = "";
  add_exit("west", "/world/casino/middleroom");
  players = ([ ]);
  bets = ([ ]);
  cards = ([ ]);
  splits = ([ ]);
  force = 0;
  wins = 0;
  rounds = 0;
  tbets = 0;
  tbetsn = 0;
  
  items = allocate(2);
  items[0] = "table";
  items[1] = "It looks like an ordinary blackjack table. Type 'table'\n"+
                "to see the cards.\n";

  set_light(3);
  set_not_out();
  call_out("cont_check_idle",30);
  property = allocate(4);
  property[0] = "no_kill";
  property[1] = "no_skill";
  property[2] = "no_spell";
  property[3] = "no_summon";
}

long() {
  write("This is a dim room. Thick smoke hangs on the air.\n");
  write("There is a table in the middle of the room. Some\n");
  write("lamps illuminate the table. You recognize the game\n");
  write("going on as some sort of a blackjack variation.\n");
  write("If you want to join the game, see the 'rules'.\n");
  table();
  ::long();
}

catch_tell(str) {
  string tmp,tmp2;
  if(sscanf(str,"%s leaves %s.",tmp,tmp2) == 2) {
        if(!present(find_player(tmp))) {
                tell_room(this_object(),tmp+" is kicked out of the game for leaving.\n");
                cards -= ([ tmp ]);
                bets -= ([ tmp ]);
        }
  }
  return 1;
}
