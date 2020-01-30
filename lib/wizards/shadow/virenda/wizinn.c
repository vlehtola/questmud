#include "room.h"
#define FOODS 2
#define Level this_player()->query_level()
#define Name this_player()->query_name()
#define Speak(s)\
 write("Innkeeper says: "+s+"\n")

int ss,dod,aa,gc;
string last_eater;

#undef EXTRA_RESET
#define EXTRA_RESET\
  ss=FOODS*8;\
  dod=FOODS*4;\
  aa=FOODS*2;\
  gc=FOODS;\
  if(arg) return;\
  items=({"menu","The menu looks like this"});

ONE_EXIT("players/shadow/virenda/church","south",
"Wizroom inn",
"You are in the famous Wizroom inn. Here you can buy drinks to still your\n"+
"self, but only to a selection of people are served. If your a wizard, go\n"+
"ahead, serve your self. All drinks are provided by: 'Mr. Armageddon' \n",
1)

init() {
 add_action("buy","buy");
 add_action("buy","order");
 ::init();
}

long(s) {
 ::long(s);
 show_menu();
}

show_menu() {
 write("\n");
 if(!(ss||dod||aa||gc)) 
  Speak("We have completely sold out...come back later.");
 else {
  write("1: Shadow's Shake      ");write(ss);write(" at 100000 gp\n");
  write("2: Drink o Death       ");write(dod);write(" at 200000 gp\n");
  write("3: Arches acid         ");write(aa);write(" at 999999 gp\n");
  write("4: Gods creation       ");write(gc);write(" at 10000000 gp\n");
  write("\n");
  write("Use 'buy <number>' to buy the desired drink. The food will\n"+
        "be consumed at once. Good appetite.\n\n");
 }
 return;
}

no_food() {
 Speak("Sorry - sold out of that.");
 if(ss||dod||aa||gc)
  Speak("Why don't you try something else ?");
 else
  Speak("Why don't you come back later ?");
 return 1;
}

pays(n) {
 if(this_player()->query_money()<n) {
  Speak("Geez, Clone some money for crying out loud!!.");
  return 0;
 }
 this_player()->add_money(-n);
 return 1;
}

tease(n) {
 if(Name==last_eater)
  Speak("My - Are we thirsty today.");
 last_eater=Name;
 this_player()->heal_self(n);
 return 1;
}

buy(s) {
 if(!s) {
  Speak("So, What can I get ya ?");
  return 1;
 }
if(s=="1"||s=="<1>") {
  if(!ss) return no_food();
  if(!pays(100000)) return 1;
  if(Level>100) {
   Speak("You don't look like a codeslave to me.");
   if(dod||aa) {
    Speak("You should drink more Powerful ones.");
    return 1;
   }
   Speak("But as you do look sober - here you are.");
  }
  write("You are served a Shadow's shake - very good\n");
  say(Name+" orders a Shadow's shake\n");
  ss=ss-1;
  return tease(4);
 }
 if(s=="2"||s=="<2>") {
  if(!dod) return no_food();
  if(!pays(200000)) return 1;
  if(Level>200) {
   Speak("You look more powerful for this one.");
   if(aa) {
    Speak("You should drink Arches acid or Gods creation.");
    return 1;
   }
   Speak("But as we have no better drinks - here you are.");
  }
  write("You are served a Drink o death  - Oh, mama\n");
  say(Name+" orders a Drink o death\n");
  dod=dod-1;
  return tease(8);
 }
 if(s=="3"||s=="<3>") {
  if(!aa) return no_food();
  if(!pays(999999)) return 1;
  write("You are served an Arches acid - Hot stuff\n");
  say(Name+" orders a Arches acid\n");
  aa=aa-1;
  return tease(12);
 }
 if(s=="4"||s=="<4>"||s=="mug"||s=="beer") {
  if(!gc) return no_food();
  if(!pays(1000000)) return 1;
  gc=gc-1;
  if(!this_player()->drink_alcohol(1000000000)) {
   Speak("You look a little too drunk for that..let me take it back.");
   this_player()->add_money(1000000);
   gc=gc+1;
   return 1;
  }
  write("You drink Gods creation - Damn your good.\n");
  say(Name+" drinks a Gods Creation without a blink.\n");
  return 1;
 }
 Speak("We have no such number on the menu, try 1, 2, 3 or 4.");
 return 1;
}

