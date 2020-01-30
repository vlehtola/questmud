int used = 1;
object effect = clone_object("/wizards/torspo/guild/potion/effects/1_poison_effect.c");

reset(arg) {
  if(arg) { return; }
}

id(str) { return str == "potion"; }

get() { return 1; }

short() {
 if(used == 1) {  return "A potion full of grey liquid";  }
 if(used == 2) {  return "A half full potion containing grey liquid";  }
 if(used == 3) {  return "An empty potion";  }
}

long(str) {
 if(used == 1) {
  write("The potion is full of some grey, sticky liquid. Liquid looks clear and you can\n"+
        "see through it. The potion itself is just rough, but clear, glass.\n");
 }
 if(used == 2) {
  write("The potion is half full of some grey, sticky liquid. Liquid looks clear and you\n"+
         "can see through it. The potion itself is just rough, but clear, glass.\n");
 }
 if(used ==3) {  write("An empty glass potion.\n");  }
}

query_value() {
 if(used < 3) { return 0; }
  return 5;
}

query_weight() {
 if(used == 1) { return 25; }
 if(used == 2) { return 20; }
 else { return 15; }
}

init() {
  add_action("drink", "drink");
  add_action("lubricate", "lubricate");
}

drink(str) {
 if(str == "potion") {
  if(used == 3) {  write("The potion is empty.\n"); return 1; }
  if(present("effect", this_player())) {
   write("a\n");
   return 1;
  }
  write("You drink the liquid. It tastes horrible.\n");
  used = 3;
  move_object(effect, this_player());
  effect->start();
 return 1;
 }
}

lubricate(str) {
object ob; int i;
ob = all_inventory(this_player());
 for(i=0;i < sizeof(ob); i++) { if (ob[i]->query_weapon()) {
  if(used < 3) {
   write("You spread some liquid on your weapon\n");
   used == used++;
   return 1;
   }
   else { write("But the potion is empty.\n"); return 1; }
  }
 }
  write("You don't have a weapon to lubricate\n");
  return 1;
}
