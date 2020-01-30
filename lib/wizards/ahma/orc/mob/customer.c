inherit "obj/monster";
int i = random(4);
string chat_str;

reset(arg) {
  ::reset(arg);
  if(arg) { return; }
  set_level(random(3)+18);
  if(i==0 || i==1) { set_name("woman"); } else { set_name("man"); }
  set_alt_name("customer");
  set_race("orc");
  if(i==0 || i==1) { set_gender(2); } else { set_gender(1); }
  if(i==0) { set_short("A female Orc is searching for something to buy"); }
  if(i==1) { set_short("A plump Orc lady is walking around the square"); }
  if(i==2) { set_short("A lazy-looking Orc is examining chairs"); }
  if(i==3) { set_short("A male Orc is buying some food"); }
  if(i==0 || i==1) { 
    set_long("A snobbish Orc female is wandering around the village square, examining\n" + 
             "and bargaining for various items found in wooden booths. Woman is trying\n" + 
             "to examine each item with extreme precision, acting like a professional\n" + 
             "which she obviously is not.\n");
  }
  {
    set_long("A snobbish Orc male is wandering around the village square, examining\n" + 
             "and bargaining for various items found in wooden booths. Man is trying\n" + 
             "to examine each item with extreme precision, acting like a professional\n" + 
             "which he obviously is not.\n");
  }

  if(!chat_str) {
    chat_str = allocate(3);
    if(i==0 || i==1) { femalechat(); } else { malechat(); }
  }
  load_chat(3, chat_str);
  
}

malechat() {
  chat_str[0] = "Man strokes an used carpet and sighs dreamingly.\n";
  chat_str[1] = "Man tinkles some coins in his hands.\n";
  chat_str[2] = "Man smells some fresh-baked bread.\n";
}

femalechat() { 
  chat_str[0] = "Woman examines some accessory.\n";
  chat_str[1] = "Woman tries to bargain for an used mirror.\n";
  chat_str[2] = "Woman snuffles snobbishly.\n";
}
