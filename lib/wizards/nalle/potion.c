object shad1,shad2,shad3,shad4;
int tsaga;
init() {
  if(this_player() == environment(this_object())) { 
    add_action("drink", "drink");
  }
}

query_value() { 
  if (tsaga == 21) { return 10; }
  return 90; 
}

query_weight() { 
  if (tsaga == 21) { return 5; }
  return 10; 
}

drink(str) {
 if (tsaga == 21) {
 if (str == "flask") {
 write("The flask is empty, and there is nothing left.\n");
 return 1;
  }
 return;
 }
 if (str == "potion") {
  tsaga = random(7) + 1;
  if (tsaga == 1) {
  write("As you drink the potion a stinging pain enters your head.\n");
  say(call_other(this_player(), "query_name", 0) + " drinks a potion, which to seems to contains lethal components.\n");
  this_player()->reduce_hp(200);
  tsaga = 21; 
  return 1;
 }
   if (tsaga == 2) {
   write("You drink the potion and suddenly start feeling ill.\n");
   say(call_other(this_player(), "query_name", 0) + " drinks a potion and starts seeming ill.\n"); 
   this_player()->reduce_hp(100);
   tsaga = 21;
   shad4 = clone_object("/wizards/nalle/potshad4.c");
   shad4->start(this_player());
   call_out("ill1", 25);
   return 1;
  }
   if (tsaga == 3) {
   write("You drink the potion but nothing seems to happen.\n");
   say(call_other(this_player(), "query_name", 0) + " drinks a potion.\n");
   tsaga = 21;
   return 1;
  }
   if (tsaga == 4) {
   write("You drink the potion and feel slightly better.\n");
   say(call_other(this_player(), "query_name", 0) + " drinks a potion and seems to feel slightly better.\n");
   this_player()->add_hp(75);
   this_player()->add_sp(120);
   tsaga = 21;
   return 1;
  }
   if (tsaga == 5) {
   write("You drink the potion and feel much better.\n");
   say(call_other(this_player(), "query_name", 0) + " drinks a potion and seems much better.\n");
   this_player()->add_hp(120);
   this_player()->add_sp(200);
   tsaga = 21;
   shad3 = clone_object("/wizards/nalle/potshad3.c");
   shad3->start(this_player());
   return 1;
   }
   if (tsaga == 6) {
   write("You drink the potion and feel a bit weak.\n");
   say(call_other(this_player(), "query_name", 0) + " drinks a potion and seems a bit weak.\n");
   this_player()->set_str(4);
   shad1 = clone_object("/wizards/nalle/potshad1.c");
   shad1->start(this_player());
   tsaga = 21;
   return 1;
   }
   if (tsaga == 7) {
   write("You drink the potion and feel a bit stupid.\n");
   say(call_other(this_player(), "query_name", 0) + " drinks a potion and seems a bit stupid.\n");
   this_player()->set_wis(2);
   shad2 = clone_object("/wizards/nalle/potshad2.c");
   shad2->start(this_player());
   tsaga = 21;
   return 1;
   }
  }
}

short() { 
if (tsaga != 21) {
   return "A multicoloured potion";
   } else {
   return "An empty flask";
 }                
}

long(str) {
 if (tsaga == 21) {
  write("An empty flask.\n");
  return 1;
  } 
  write("A potion, containing a multicoloured fluid.\n");
}


get() { return 1; }

id(str) {
    if (tsaga == 21) { return str == "flask"; }
    return str == "potion";
}



