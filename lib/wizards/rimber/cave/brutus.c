inherit "obj/monster";
int item1, item2, item3;
int done, id, q = 0;
string filu;
object test;

reset(arg) {
 object weapon;
 string chat_str;
 done = 0;
 item1 = 0;
 item2 = 0;
 item3 = 0;
 ::reset(arg);
 if(arg) { return; }
 set_level(70);
 set_name("brutus");
 set_short("Muscular weaponsmith Brutus");
 set_alt_name("weaponsmith");
 set_long("Brutus has tanned muscular arms. He has worn leather\n"+
  "boots and brown pants. The black garnement is protecting\n"+
  "his torso from the sparks. Brutus has a kind face,\n"+
  "but it appears he is sad about something.\n");
 set_race("human");
 set_gender(1);
set_log();
 if(q == 0) {
 weapon = clone_object("/wizards/rimber/cave/obj/maul.c");
 move_object(weapon, this_object());
 init_command("wield maul");
 }
 if(!chat_str) {
   chat_str = allocate(1);
 if(q == 0) { chat_str[0] = "Brutus sniffs sadly.\n"; }
  else { chat_str[0] = "Brutus hums happily.\n"; }
  }
  load_chat(2, chat_str);
}

catch_tell(str) {
 string tmp, tmp2, filu;
 object ob;
 int id;
 if(done == 0) {
 if(sscanf(str, "%s gives %s to you.", tmp, tmp2) == 2) {
   ob = present("stone", this_object());
   if(ob) {
    if(sscanf(file_name(ob), "%s#%d", filu, id) == 2) {
     if(filu == "/wizards/rimber/cave/obj/stone") {
     say("Brutus says: 'Thank you. Maybe I could use this on something.'\n");
     item1 = 1;
     destruct(ob);
     call_out("forge", 1);
    }
   }
  }
   ob = present("warhammer", this_object());
   if(ob) {
    if(sscanf(file_name(ob), "%s#%d", filu, id) == 2) {
     if(filu == "/wizards/rimber/cave/obj/warhammer") {
     say("Brutus says: 'Hmm... I think I could modify this a bit.'\n");
     item2 = 1;
     destruct(ob);
     call_out("forge", 1);
    }
   }
  }
   ob = present("strap", this_object());
   if(ob) {
    if(sscanf(file_name(ob), "%s#%d", filu, id) == 2) {
        if(filu == "/wizards/rimber/cave/obj/strap") {
   say("Brutus says: 'This is fine leather. I could make a good handle out of this.'\n");
     item3 = 1;
     destruct(ob);
     call_out("forge", 1);
   }
   }
  }
 }
 }
 return 1;
}

int forge() {
 if(item1 == 1) {
  if(item2 == 1) {
   if(item3 == 1) {
 say("Brutus says: 'Now I can make you a real good weapon. This won't take long.'\n");
  say("Brutus starts melting the stone and tying the strap to the warhammer's shaft.\n");
   done = 1;
   call_out("ready", 18);
  }
  }
 }
}

int ready() {
  say("Brutus has tied the strap and the stone has been melted.\n");
  say("Brutus starts forging the stone to the warhammer's head.\n");
      call_out("ready2", 18);
}
int ready2() {
  say("With one quick move Brutus puts the glowing warhammer's head into the water.\n"+
  "After a moment, he takes it out and ecaminates his work.\n");
    say("With a nod he turns back to anvil and starts carving.\n");
    call_out("ready3", 15);
}
int ready3() {
  say("With Brutus turns around says: 'Look, I have never done anything like this.\n"+
"   I'm sure it is the best weapon I've ever made.\n"+
"   I have to thank you for making me happy again.\n"+
"   And I want to give this to you.\n");
     write("Brutus gives the warhammer to you.\n");
      move_object("/wizards/rimber/cave/obj/warhammer2.c", this_player());
     this_player()->set_quest("Cheer Brutus up");
  q = 1;
 reset();
 return 1;
}
