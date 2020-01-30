object user;
mapping symbols;

add_symbol(string str) {
  int num;
  if(!symbols[str]) {
    write("There is no such symbol.\n");
    return 0;
  }
  if(symbols[str] == 1) {
    write(short()+" already contains the symbol of "+str+".\n");
    return 0;
  }
  num = this_player()->query_skills("symbol knowledge");
  if(num < random(60)) {
    write("You make a terrible mistake and the whole circle is ruined.\n");
    say(this_player()->query_name()+" fumbles the drawing and the circle is ruined.\n");
    destruct(this_object());
    return 0;
  }
  if(num < random(num+20)) {
    write("You draw a symbol, but it doesn't seem right and you wipe it away.\n");
    say(this_player()->query_name()+" draws something on the ground and wipes it away.\n");
    return 0;
  }
  write("You draw the symbol of "+str+" on the circle.\n");
  say(this_player()->query_name()+" draws a symbol on the circle.\n");
  symbols[str] = 1;
  return 1;
}

query_symbols(string str) {
  int i, num, value;
  if(str) {
    if(symbols[str] == 1) return 1;
    return 0;
  }
  num = m_values(symbols);
  while(i < sizeof(num)) {
    if(num[i] == 1) value += 1;
    i += 1;
  }
  return value;
}

reset(arg) {
  if(arg) return;
  symbols = ([ ]);
  symbols += (["fire":-1 ]);
  symbols += (["water":-1 ]);
  symbols += (["air":-1 ]);
  symbols += (["earth":-1 ]);
}

long() {
  write(short()+"\n");
  write("This circle if drawn on the ground. It's purpose is to magically protect it's user.\n");
  if(symbols["water"] == 1) write("The symbol of water is drawn on the circle.\n");
  if(symbols["fire"] == 1) write("The symbol of fire is drawn on the circle.\n");
  if(symbols["air"] == 1) write("The symbol of air is drawn on the circle.\n");
  if(symbols["earth"] == 1) write("The symbol of earth is drawn on the circle.\n");
}
short() {
  return query_user()->query_name()+"'s circle of protection ("+query_symbols()+" symbols)";
}

id(str) {
  return str == "circle of protection" || str == "circle";
}

query_user() {
  if(!user) {
    say(short()+" vanishes.\n");
    destruct(this_object());
    return 1;
  }
  return user;
}

start(object ob) {
  user = ob;
}
